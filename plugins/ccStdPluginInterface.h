//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
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
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef CC_STD_PLUGIN_INTERFACE_HEADER
#define CC_STD_PLUGIN_INTERFACE_HEADER

//Qt
#include <QWidget>
#include <QActionGroup>

//qCC_db
#include <ccHObject.h>

//qCC
#include "ccPluginInterface.h"
#include "ccMainAppInterface.h"

//UI Modification flags
#define CC_PLUGIN_REFRESH_GL_WINDOWS            0x00000001
#define CC_PLUGIN_REFRESH_ENTITY_BROWSER        0x00000002
#define CC_PLUGIN_EXPAND_DB_TREE                0x00000004

//! Standard CC plugin interface
/** Version 1.5
	The plugin is now responsible for its own actions (QAction ;)
	and the associated ccMainAppInterface member should give it
	access to everything it needs in the main application.
**/
class ccStdPluginInterface : public ccPluginInterface
{
public:

	//! Default constructor
	ccStdPluginInterface() : ccPluginInterface(), m_app(0) {}
	//! Destructor
	virtual ~ccStdPluginInterface() {}

	//inherited from ccPluginInterface
	virtual CC_PLUGIN_TYPE getType() const { return CC_STD_PLUGIN; }

	//! Sets application entry point
	/** Called just after plugin creation by qCC
	**/
	virtual void setMainAppInterface(ccMainAppInterface* app);

	//! A callback poiner to the main app interface for being used by plugins
	/**  Any plugin (and its tools) may need to access methods of this interface
	**/
	virtual ccMainAppInterface * getMainAppInterface() { return m_app; }

	//! Returns action(s)
	virtual void getActions(QActionGroup& group) = 0;

	//! This method is called by the main application whenever the entity selection changes
	/** Does nothing by default. Should be re-implemented by the plugin if necessary.
		\param selectedEntities currently selected entities
	**/
	virtual void onNewSelection(const ccHObject::Container& selectedEntities) { /*ignored by default*/ }

protected:

	//! Main application interface
	ccMainAppInterface* m_app;
};

Q_DECLARE_INTERFACE(ccStdPluginInterface,"edf.rd.CloudCompare.ccStdPluginInterface/1.4")

#endif //CC_STD_PLUGIN_INTERFACE_HEADER
