//##########################################################################
//#                                                                        #
//#                CLOUDCOMPARE PLUGIN: qPoissonRecon                      #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#               COPYRIGHT: Daniel Girardeau-Montaut                      #
//#                                                                        #
//##########################################################################

#include "qPoissonRecon.h"

//dialog
#include "ui_poissonReconParamDlg.h"

//Qt
#include <QtGui>
#include <QInputDialog>
#include <QtCore>
#include <QProgressDialog>
#include <QtConcurrentRun>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>

//PoissonRecon
#include <PoissonReconLib.h>

//qCC_db
#include <ccPointCloud.h>
#include <ccMesh.h>
#include <ccProgressDialog.h>
#include <ccScalarField.h>

//CCLib
#include <DistanceComputationTools.h>
#include <CCPlatform.h>

//System
#include <algorithm>
#if defined(CC_WINDOWS)
#include "Windows.h"
#else
#include <time.h>
#include <unistd.h>
#endif

//Dedicated 'PointStream' for the ccPointCloud structure
template <class Real> class ccPointStream : public PointStream<Real>
{
public:
	ccPointStream( ccPointCloud* cloud ) : m_cloud(cloud), m_index(0) {}
	virtual void reset( void ) { m_index = 0; }
	virtual bool nextPoint( Point3D< Real >& p , Point3D< Real >& n )
	{
		if (!m_cloud || m_index == m_cloud->size())
			return false;
		//point
		const CCVector3* P = m_cloud->getPoint(m_index);
		p[0] = static_cast<Real>(P->x);
		p[1] = static_cast<Real>(P->y);
		p[2] = static_cast<Real>(P->z);

		//normal
		assert(m_cloud->hasNormals());
		const CCVector3& N = m_cloud->getPointNormal(m_index);
		n[0] = static_cast<Real>(N.x);
		n[1] = static_cast<Real>(N.y);
		n[2] = static_cast<Real>(N.z);

		//auto-forward
		++m_index;

		return true;
	}

protected:
	ccPointCloud* m_cloud;
	unsigned m_index;
};


//dialog for qPoissonRecon plugin
class PoissonReconParamDlg : public QDialog, public Ui::PoissonReconParamDialog
{
public:
	PoissonReconParamDlg(QWidget* parent = 0) : QDialog(parent), Ui::PoissonReconParamDialog()
	{
		setupUi(this);
		setWindowFlags(Qt::Tool/*Qt::Dialog | Qt::WindowStaysOnTopHint*/);
	}
};

qPoissonRecon::qPoissonRecon(QObject* parent/*=0*/)
	: QObject(parent)
	, m_action(0)
{
}

void qPoissonRecon::onNewSelection(const ccHObject::Container& selectedEntities)
{
	if (m_action)
		m_action->setEnabled(selectedEntities.size()==1 && selectedEntities[0]->isA(CC_TYPES::POINT_CLOUD));
}

void qPoissonRecon::getActions(QActionGroup& group)
{
	//default action
	if (!m_action)
	{
		m_action = new QAction(getName(),this);
		m_action->setToolTip(getDescription());
		m_action->setIcon(getIcon());
		//connect signal
		connect(m_action, SIGNAL(triggered()), this, SLOT(doAction()));
	}

	group.addAction(m_action);
}

typedef PlyValueVertex< PointCoordinateType > Vertex;
typedef CoredVectorMeshData< Vertex > PoissonMesh;

static PoissonReconLib::Parameters s_params;
static ccPointCloud* s_cloud = 0;
static PoissonMesh* s_mesh;

bool doReconstruct()
{
	//invalid parameters
	if (!s_cloud || !s_mesh)
		return false;

	ccPointStream<PointCoordinateType> pointStream(s_cloud);

	return PoissonReconLib::Reconstruct(s_params, &pointStream, *s_mesh);
}

void qPoissonRecon::doAction()
{
	assert(m_app);
	if (!m_app)
		return;

	const ccHObject::Container& selectedEntities = m_app->getSelectedEntities();

	//we need one point cloud
	size_t selNum = selectedEntities.size();
	if (selNum != 1)
	{
		m_app->dispToConsole("Select only one cloud!",ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return;
	}

	//a real point cloud
	ccHObject* ent = selectedEntities[0];
	if (!ent->isA(CC_TYPES::POINT_CLOUD))
	{
		m_app->dispToConsole("Select a cloud!",ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return;
	}

	//with normals!
	ccPointCloud* pc = static_cast<ccPointCloud*>(ent);
	if (!pc->hasNormals())
	{
		m_app->dispToConsole("Cloud must have normals!",ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return;
	}

	PoissonReconParamDlg prpDlg(m_app->getMainWindow());
	//init dialog with semi-persistent settings
	prpDlg.octreeLevelSpinBox->setValue(s_params.depth);
	prpDlg.weightDoubleSpinBox->setValue(s_params.pointWeight);
	prpDlg.fullDepthSpinBox->setValue(s_params.fullDepth);
	prpDlg.samplesPerNodeSpinBox->setValue(s_params.samplesPerNode);
	prpDlg.densityCheckBox->setChecked(s_params.density);

	if (!prpDlg.exec())
		return;

	//set parameters with dialog settings
	s_params.depth = prpDlg.octreeLevelSpinBox->value();
	s_params.pointWeight = static_cast<float>(prpDlg.weightDoubleSpinBox->value());
	s_params.fullDepth = prpDlg.fullDepthSpinBox->value();
	s_params.samplesPerNode = static_cast<float>(prpDlg.samplesPerNodeSpinBox->value());
	s_params.density = prpDlg.densityCheckBox->isChecked();

	/*** RECONSTRUCTION PROCESS ***/

	PoissonMesh mesh;

	//run in a separate thread
	bool result = false;
	{
		//start message
		m_app->dispToConsole(QString("[PoissonRecon] Job started (level %1)").arg(s_params.depth),ccMainAppInterface::STD_CONSOLE_MESSAGE);

		//progress dialog (Qtconcurrent::run can't be canceled!)
		QProgressDialog pDlg("Initialization",QString(),0,0,m_app->getMainWindow());
		pDlg.setWindowTitle("Poisson Reconstruction");
		pDlg.show();
		//QApplication::processEvents();

		//run in a separate thread
		s_cloud = pc;
		s_mesh = &mesh;

		pDlg.setLabelText(QString("Reconstruction in progress\nlevel: %1 [%2 thread(s)]").arg(s_params.depth).arg(s_params.threads));
		QApplication::processEvents();
			
		QFuture<bool> future = QtConcurrent::run(doReconstruct);

		//wait until process is finished!
		while (!future.isFinished())
		{
#if defined(CC_WINDOWS)
			::Sleep(500);
#else
			usleep(500 * 1000);
#endif

			pDlg.setValue(pDlg.value()+1);
			QApplication::processEvents();
		}

		result = future.result();

		s_mesh = 0;
		s_cloud = 0;

		pDlg.hide();
		QApplication::processEvents();
	}

	if (!result || mesh.polygonCount() < 1)
	{
		m_app->dispToConsole("Reconstruction failed!",ccMainAppInterface::ERR_CONSOLE_MESSAGE);
		return;
	}

	mesh.resetIterator();
	unsigned nic			= static_cast<unsigned>(mesh.inCorePoints.size());
	unsigned noc			= static_cast<unsigned>(mesh.outOfCorePointCount());
	unsigned nr_faces		= static_cast<unsigned>(mesh.polygonCount());
	unsigned nr_vertices	= nic+noc;

	//end message
	m_app->dispToConsole(QString("[PoissonRecon] Job finished (%1 triangles, %2 vertices)").arg(nr_faces).arg(nr_vertices),ccMainAppInterface::STD_CONSOLE_MESSAGE);

	ccPointCloud* newPC = new ccPointCloud("vertices");
	ccMesh* newMesh = new ccMesh(newPC);
	newMesh->addChild(newPC);
	
	if (newPC->reserve(nr_vertices) && newMesh->reserve(nr_faces))
	{
		ccScalarField* densitySF = 0;
		if (s_params.density)
		{
			densitySF = new ccScalarField("Density");
			if (!densitySF->reserve(nr_vertices))
			{
				m_app->dispToConsole(QString("[PoissonRecon] Failed to allocate memory for storing density!"),ccMainAppInterface::WRN_CONSOLE_MESSAGE);
				densitySF->release();
				densitySF = 0;
			}
		}

		//add 'in core' points
		{
			for (unsigned i=0; i<nic; i++)
			{
				Vertex& p = mesh.inCorePoints[i];
				CCVector3 p2(	static_cast<PointCoordinateType>(p.point.coords[0]),
								static_cast<PointCoordinateType>(p.point.coords[1]),
								static_cast<PointCoordinateType>(p.point.coords[2]) );
				newPC->addPoint(p2);

				if (densitySF)
				{
					ScalarType sf = static_cast<ScalarType>(p.value);
					densitySF->addElement(sf);
				}
			}
		}
		//add 'out of core' points
		{
			for (unsigned i=0; i<noc; i++)
			{
				Vertex p;
				mesh.nextOutOfCorePoint(p);
				CCVector3 p2(	static_cast<PointCoordinateType>(p.point.coords[0]),
								static_cast<PointCoordinateType>(p.point.coords[1]),
								static_cast<PointCoordinateType>(p.point.coords[2]) );
				newPC->addPoint(p2);

				if (densitySF)
				{
					ScalarType sf = static_cast<ScalarType>(p.value);
					densitySF->addElement(sf);
				}
			}
		}

		// density SF
		if (densitySF)
		{
			densitySF->computeMinAndMax();
			densitySF->showNaNValuesInGrey(false);
			int sfIdx = newPC->addScalarField(densitySF);
			newPC->setCurrentDisplayedScalarField(sfIdx);
			newPC->showSF(true);
			newMesh->showSF(true);
		}

		//add faces
		{
			for (unsigned i=0; i<nr_faces; i++)
			{
				std::vector<CoredVertexIndex> triangleIndexes;
				mesh.nextPolygon(triangleIndexes);

				if (triangleIndexes.size() == 3)
				{
					for (std::vector<CoredVertexIndex>::iterator it = triangleIndexes.begin(); it != triangleIndexes.end(); ++it)
						if (!it->inCore)
							it->idx += nic;

					newMesh->addTriangle(	triangleIndexes[0].idx,
											triangleIndexes[1].idx,
											triangleIndexes[2].idx );
				}
				else
				{
					//Can't handle anything else than triangles yet!
					assert(false);
				}
			}
		}

		//if the input cloud has colors, try to 'map' them on the resulting mesh
		if (pc->hasColors())
		{
			if (QMessageBox::question(m_app->getMainWindow(), "Poisson reconstruction","Import input cloud colors? (this may take some time)", QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes)
			{
				ccProgressDialog pDlg(true, m_app->getMainWindow());
				pDlg.setInfo("Importing input colors");
				pDlg.setMethodTitle("Poisson Reconstruction");

				if (newPC->interpolateColorsFrom(pc,&pDlg))
				{
					newPC->showColors(true);
					newMesh->showColors(true);
				}
				else
				{
					m_app->dispToConsole("An error occurred during color transfer (see console)", ccMainAppInterface::ERR_CONSOLE_MESSAGE);
				}
			}
		}

		newMesh->setName(QString("Mesh[%1] (level %2)").arg(pc->getName()).arg(s_params.depth));
		newPC->setVisible(false);
		newMesh->setVisible(true);
		newMesh->computeNormals(true);
		newMesh->showNormals(newMesh->hasNormals());

		//output mesh
		m_app->addToDB(newMesh);
	}
	else
	{
		delete newMesh;
		newMesh = 0;
		m_app->dispToConsole("Not enough memory!",ccMainAppInterface::ERR_CONSOLE_MESSAGE);
	}

	//currently selected entities parameters may have changed!
	m_app->updateUI();
	//currently selected entities appearance may have changed!
	m_app->refreshAll();
}

QIcon qPoissonRecon::getIcon() const
{
	return QIcon(QString::fromUtf8(":/CC/plugin/qPoissonRecon/qPoissonRecon.png"));
}

#ifndef CC_QT5
Q_EXPORT_PLUGIN2(qPoissonRecon,qPoissonRecon);
#endif