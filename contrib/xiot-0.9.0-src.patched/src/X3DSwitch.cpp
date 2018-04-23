#include <xiot/X3DSwitch.h>
#include <xiot/X3DAttributes.h>
#include <xiot/X3DTypes.h>
#include <xiot/X3DNodeHandler.h>
#include <iostream>
#include <cassert>

using namespace std;

namespace XIOT {

X3DSwitch::X3DSwitch()
: _handler(NULL)
{
}

X3DSwitch::~X3DSwitch()
{
}

void X3DSwitch::setNodeHandler(X3DNodeHandler *handler)
{
   this->_handler = handler;
}
// START GENERATED
int X3DSwitch::doStartElement(int id, const X3DAttributes& attr) const
{
	assert(_handler);

	switch(id)
	{
	case ID::Shape:
		return _handler->startShape(attr);
	case ID::Appearance:
		return _handler->startAppearance(attr);
	case ID::Material:
		return _handler->startMaterial(attr);
	case ID::IndexedFaceSet:
		return _handler->startIndexedFaceSet(attr);
	case ID::ProtoInstance:
		return _handler->startProtoInstance(attr);
	case ID::Transform:
		return _handler->startTransform(attr);
	case ID::ImageTexture:
		return _handler->startImageTexture(attr);
	case ID::TextureTransform:
		return _handler->startTextureTransform(attr);
	case ID::Coordinate:
		return _handler->startCoordinate(attr);
	case ID::Normal:
		return _handler->startNormal(attr);
	case ID::Color:
		return _handler->startColor(attr);
	case ID::ColorRGBA:
		return _handler->startColorRGBA(attr);
	case ID::TextureCoordinate:
		return _handler->startTextureCoordinate(attr);
	case ID::ROUTE:
		return _handler->startROUTE(attr);
	case ID::fieldValue:
		return _handler->startfieldValue(attr);
	case ID::Group:
		return _handler->startGroup(attr);
	case ID::LOD:
		return _handler->startLOD(attr);
	case ID::Switch:
		return _handler->startSwitch(attr);
	case ID::Script:
		return _handler->startScript(attr);
	case ID::IndexedTriangleFanSet:
		return _handler->startIndexedTriangleFanSet(attr);
	case ID::IndexedTriangleSet:
		return _handler->startIndexedTriangleSet(attr);
	case ID::IndexedTriangleStripSet:
		return _handler->startIndexedTriangleStripSet(attr);
	case ID::MultiTexture:
		return _handler->startMultiTexture(attr);
	case ID::MultiTextureCoordinate:
		return _handler->startMultiTextureCoordinate(attr);
	case ID::MultiTextureTransform:
		return _handler->startMultiTextureTransform(attr);
	case ID::IndexedLineSet:
		return _handler->startIndexedLineSet(attr);
	case ID::PointSet:
		return _handler->startPointSet(attr);
	case ID::StaticGroup:
		return _handler->startStaticGroup(attr);
	case ID::Sphere:
		return _handler->startSphere(attr);
	case ID::Box:
		return _handler->startBox(attr);
	case ID::Cone:
		return _handler->startCone(attr);
	case ID::Anchor:
		return _handler->startAnchor(attr);
	case ID::Arc2D:
		return _handler->startArc2D(attr);
	case ID::ArcClose2D:
		return _handler->startArcClose2D(attr);
	case ID::AudioClip:
		return _handler->startAudioClip(attr);
	case ID::Background:
		return _handler->startBackground(attr);
	case ID::Billboard:
		return _handler->startBillboard(attr);
	case ID::BooleanFilter:
		return _handler->startBooleanFilter(attr);
	case ID::BooleanSequencer:
		return _handler->startBooleanSequencer(attr);
	case ID::BooleanToggle:
		return _handler->startBooleanToggle(attr);
	case ID::BooleanTrigger:
		return _handler->startBooleanTrigger(attr);
	case ID::Circle2D:
		return _handler->startCircle2D(attr);
	case ID::Collision:
		return _handler->startCollision(attr);
	case ID::ColorInterpolator:
		return _handler->startColorInterpolator(attr);
	case ID::Contour2D:
		return _handler->startContour2D(attr);
	case ID::ContourPolyline2D:
		return _handler->startContourPolyline2D(attr);
	case ID::CoordinateDouble:
		return _handler->startCoordinateDouble(attr);
	case ID::CoordinateInterpolator:
		return _handler->startCoordinateInterpolator(attr);
	case ID::CoordinateInterpolator2D:
		return _handler->startCoordinateInterpolator2D(attr);
	case ID::Cylinder:
		return _handler->startCylinder(attr);
	case ID::CylinderSensor:
		return _handler->startCylinderSensor(attr);
	case ID::DirectionalLight:
		return _handler->startDirectionalLight(attr);
	case ID::Disk2D:
		return _handler->startDisk2D(attr);
	case ID::EXPORT:
		return _handler->startEXPORT(attr);
	case ID::ElevationGrid:
		return _handler->startElevationGrid(attr);
	case ID::EspduTransform:
		return _handler->startEspduTransform(attr);
	case ID::ExternProtoDeclare:
		return _handler->startExternProtoDeclare(attr);
	case ID::Extrusion:
		return _handler->startExtrusion(attr);
	case ID::FillProperties:
		return _handler->startFillProperties(attr);
	case ID::Fog:
		return _handler->startFog(attr);
	case ID::FontStyle:
		return _handler->startFontStyle(attr);
	case ID::GeoCoordinate:
		return _handler->startGeoCoordinate(attr);
	case ID::GeoElevationGrid:
		return _handler->startGeoElevationGrid(attr);
	case ID::GeoLOD:
		return _handler->startGeoLOD(attr);
	case ID::GeoLocation:
		return _handler->startGeoLocation(attr);
	case ID::GeoMetadata:
		return _handler->startGeoMetadata(attr);
	case ID::GeoOrigin:
		return _handler->startGeoOrigin(attr);
	case ID::GeoPositionInterpolator:
		return _handler->startGeoPositionInterpolator(attr);
	case ID::GeoTouchSensor:
		return _handler->startGeoTouchSensor(attr);
	case ID::GeoViewpoint:
		return _handler->startGeoViewpoint(attr);
	case ID::HAnimDisplacer:
		return _handler->startHAnimDisplacer(attr);
	case ID::HAnimHumanoid:
		return _handler->startHAnimHumanoid(attr);
	case ID::HAnimJoint:
		return _handler->startHAnimJoint(attr);
	case ID::HAnimSegment:
		return _handler->startHAnimSegment(attr);
	case ID::HAnimSite:
		return _handler->startHAnimSite(attr);
	case ID::IMPORT:
		return _handler->startIMPORT(attr);
	case ID::IS:
		return _handler->startIS(attr);
	case ID::Inline:
		return _handler->startInline(attr);
	case ID::IntegerSequencer:
		return _handler->startIntegerSequencer(attr);
	case ID::IntegerTrigger:
		return _handler->startIntegerTrigger(attr);
	case ID::KeySensor:
		return _handler->startKeySensor(attr);
	case ID::LineProperties:
		return _handler->startLineProperties(attr);
	case ID::LineSet:
		return _handler->startLineSet(attr);
	case ID::LoadSensor:
		return _handler->startLoadSensor(attr);
	case ID::MetadataDouble:
		return _handler->startMetadataDouble(attr);
	case ID::MetadataFloat:
		return _handler->startMetadataFloat(attr);
	case ID::MetadataInteger:
		return _handler->startMetadataInteger(attr);
	case ID::MetadataSet:
		return _handler->startMetadataSet(attr);
	case ID::MetadataString:
		return _handler->startMetadataString(attr);
	case ID::MovieTexture:
		return _handler->startMovieTexture(attr);
	case ID::NavigationInfo:
		return _handler->startNavigationInfo(attr);
	case ID::NormalInterpolator:
		return _handler->startNormalInterpolator(attr);
	case ID::NurbsCurve:
		return _handler->startNurbsCurve(attr);
	case ID::NurbsCurve2D:
		return _handler->startNurbsCurve2D(attr);
	case ID::NurbsOrientationInterpolator:
		return _handler->startNurbsOrientationInterpolator(attr);
	case ID::NurbsPatchSurface:
		return _handler->startNurbsPatchSurface(attr);
	case ID::NurbsPositionInterpolator:
		return _handler->startNurbsPositionInterpolator(attr);
	case ID::NurbsSet:
		return _handler->startNurbsSet(attr);
	case ID::NurbsSurfaceInterpolator:
		return _handler->startNurbsSurfaceInterpolator(attr);
	case ID::NurbsSweptSurface:
		return _handler->startNurbsSweptSurface(attr);
	case ID::NurbsSwungSurface:
		return _handler->startNurbsSwungSurface(attr);
	case ID::NurbsTextureCoordinate:
		return _handler->startNurbsTextureCoordinate(attr);
	case ID::NurbsTrimmedSurface:
		return _handler->startNurbsTrimmedSurface(attr);
	case ID::OrientationInterpolator:
		return _handler->startOrientationInterpolator(attr);
	case ID::PixelTexture:
		return _handler->startPixelTexture(attr);
	case ID::PlaneSensor:
		return _handler->startPlaneSensor(attr);
	case ID::PointLight:
		return _handler->startPointLight(attr);
	case ID::Polyline2D:
		return _handler->startPolyline2D(attr);
	case ID::Polypoint2D:
		return _handler->startPolypoint2D(attr);
	case ID::PositionInterpolator:
		return _handler->startPositionInterpolator(attr);
	case ID::PositionInterpolator2D:
		return _handler->startPositionInterpolator2D(attr);
	case ID::ProtoBody:
		return _handler->startProtoBody(attr);
	case ID::ProtoDeclare:
		return _handler->startProtoDeclare(attr);
	case ID::ProtoInterface:
		return _handler->startProtoInterface(attr);
	case ID::ProximitySensor:
		return _handler->startProximitySensor(attr);
	case ID::ReceiverPdu:
		return _handler->startReceiverPdu(attr);
	case ID::Rectangle2D:
		return _handler->startRectangle2D(attr);
	case ID::ScalarInterpolator:
		return _handler->startScalarInterpolator(attr);
	case ID::Scene:
		return _handler->startScene(attr);
	case ID::SignalPdu:
		return _handler->startSignalPdu(attr);
	case ID::Sound:
		return _handler->startSound(attr);
	case ID::SphereSensor:
		return _handler->startSphereSensor(attr);
	case ID::SpotLight:
		return _handler->startSpotLight(attr);
	case ID::StringSensor:
		return _handler->startStringSensor(attr);
	case ID::Text:
		return _handler->startText(attr);
	case ID::TextureBackground:
		return _handler->startTextureBackground(attr);
	case ID::TextureCoordinateGenerator:
		return _handler->startTextureCoordinateGenerator(attr);
	case ID::TimeSensor:
		return _handler->startTimeSensor(attr);
	case ID::TimeTrigger:
		return _handler->startTimeTrigger(attr);
	case ID::TouchSensor:
		return _handler->startTouchSensor(attr);
	case ID::TransmitterPdu:
		return _handler->startTransmitterPdu(attr);
	case ID::TriangleFanSet:
		return _handler->startTriangleFanSet(attr);
	case ID::TriangleSet:
		return _handler->startTriangleSet(attr);
	case ID::TriangleSet2D:
		return _handler->startTriangleSet2D(attr);
	case ID::TriangleStripSet:
		return _handler->startTriangleStripSet(attr);
	case ID::Viewpoint:
		return _handler->startViewpoint(attr);
	case ID::VisibilitySensor:
		return _handler->startVisibilitySensor(attr);
	case ID::WorldInfo:
		return _handler->startWorldInfo(attr);
	case ID::X3D:
		return _handler->startX3D(attr);
	case ID::component:
		return _handler->startcomponent(attr);
	case ID::connect:
		return _handler->startconnect(attr);
	case ID::field:
		return _handler->startfield(attr);
	case ID::head:
		return _handler->starthead(attr);
	case ID::humanoidBodyType:
		return _handler->starthumanoidBodyType(attr);
	case ID::meta:
		return _handler->startmeta(attr);
	case ID::CADAssembly:
		return _handler->startCADAssembly(attr);
	case ID::CADFace:
		return _handler->startCADFace(attr);
	case ID::CADLayer:
		return _handler->startCADLayer(attr);
	case ID::CADPart:
		return _handler->startCADPart(attr);
	case ID::ComposedCubeMapTexture:
		return _handler->startComposedCubeMapTexture(attr);
	case ID::ComposedShader:
		return _handler->startComposedShader(attr);
	case ID::ComposedTexture3D:
		return _handler->startComposedTexture3D(attr);
	case ID::FloatVertexAttribute:
		return _handler->startFloatVertexAttribute(attr);
	case ID::FogCoordinate:
		return _handler->startFogCoordinate(attr);
	case ID::GeneratedCubeMapTexture:
		return _handler->startGeneratedCubeMapTexture(attr);
	case ID::ImageCubeMapTexture:
		return _handler->startImageCubeMapTexture(attr);
	case ID::ImageTexture3D:
		return _handler->startImageTexture3D(attr);
	case ID::IndexedQuadSet:
		return _handler->startIndexedQuadSet(attr);
	case ID::LocalFog:
		return _handler->startLocalFog(attr);
	case ID::Matrix3VertexAttribute:
		return _handler->startMatrix3VertexAttribute(attr);
	case ID::Matrix4VertexAttribute:
		return _handler->startMatrix4VertexAttribute(attr);
	case ID::PackagedShader:
		return _handler->startPackagedShader(attr);
	case ID::PixelTexture3D:
		return _handler->startPixelTexture3D(attr);
	case ID::ProgramShader:
		return _handler->startProgramShader(attr);
	case ID::QuadSet:
		return _handler->startQuadSet(attr);
	case ID::ShaderPart:
		return _handler->startShaderPart(attr);
	case ID::ShaderProgram:
		return _handler->startShaderProgram(attr);
	case ID::TextureCoordinate3D:
		return _handler->startTextureCoordinate3D(attr);
	case ID::TextureCoordinate4D:
		return _handler->startTextureCoordinate4D(attr);
	case ID::TextureTransform3D:
		return _handler->startTextureTransform3D(attr);
	case ID::TextureTransformMatrix3D:
		return _handler->startTextureTransformMatrix3D(attr);
	case -1:
	default:
		return _handler->startUnknown(id, "", attr);
	};
}

int X3DSwitch::doEndElement(int id, const char* nodeName) const
{

	switch(id)
	{
	case ID::Shape:
		return _handler->endShape();
	case ID::Appearance:
		return _handler->endAppearance();
	case ID::Material:
		return _handler->endMaterial();
	case ID::IndexedFaceSet:
		return _handler->endIndexedFaceSet();
	case ID::ProtoInstance:
		return _handler->endProtoInstance();
	case ID::Transform:
		return _handler->endTransform();
	case ID::ImageTexture:
		return _handler->endImageTexture();
	case ID::TextureTransform:
		return _handler->endTextureTransform();
	case ID::Coordinate:
		return _handler->endCoordinate();
	case ID::Normal:
		return _handler->endNormal();
	case ID::Color:
		return _handler->endColor();
	case ID::ColorRGBA:
		return _handler->endColorRGBA();
	case ID::TextureCoordinate:
		return _handler->endTextureCoordinate();
	case ID::ROUTE:
		return _handler->endROUTE();
	case ID::fieldValue:
		return _handler->endfieldValue();
	case ID::Group:
		return _handler->endGroup();
	case ID::LOD:
		return _handler->endLOD();
	case ID::Switch:
		return _handler->endSwitch();
	case ID::Script:
		return _handler->endScript();
	case ID::IndexedTriangleFanSet:
		return _handler->endIndexedTriangleFanSet();
	case ID::IndexedTriangleSet:
		return _handler->endIndexedTriangleSet();
	case ID::IndexedTriangleStripSet:
		return _handler->endIndexedTriangleStripSet();
	case ID::MultiTexture:
		return _handler->endMultiTexture();
	case ID::MultiTextureCoordinate:
		return _handler->endMultiTextureCoordinate();
	case ID::MultiTextureTransform:
		return _handler->endMultiTextureTransform();
	case ID::IndexedLineSet:
		return _handler->endIndexedLineSet();
	case ID::PointSet:
		return _handler->endPointSet();
	case ID::StaticGroup:
		return _handler->endStaticGroup();
	case ID::Sphere:
		return _handler->endSphere();
	case ID::Box:
		return _handler->endBox();
	case ID::Cone:
		return _handler->endCone();
	case ID::Anchor:
		return _handler->endAnchor();
	case ID::Arc2D:
		return _handler->endArc2D();
	case ID::ArcClose2D:
		return _handler->endArcClose2D();
	case ID::AudioClip:
		return _handler->endAudioClip();
	case ID::Background:
		return _handler->endBackground();
	case ID::Billboard:
		return _handler->endBillboard();
	case ID::BooleanFilter:
		return _handler->endBooleanFilter();
	case ID::BooleanSequencer:
		return _handler->endBooleanSequencer();
	case ID::BooleanToggle:
		return _handler->endBooleanToggle();
	case ID::BooleanTrigger:
		return _handler->endBooleanTrigger();
	case ID::Circle2D:
		return _handler->endCircle2D();
	case ID::Collision:
		return _handler->endCollision();
	case ID::ColorInterpolator:
		return _handler->endColorInterpolator();
	case ID::Contour2D:
		return _handler->endContour2D();
	case ID::ContourPolyline2D:
		return _handler->endContourPolyline2D();
	case ID::CoordinateDouble:
		return _handler->endCoordinateDouble();
	case ID::CoordinateInterpolator:
		return _handler->endCoordinateInterpolator();
	case ID::CoordinateInterpolator2D:
		return _handler->endCoordinateInterpolator2D();
	case ID::Cylinder:
		return _handler->endCylinder();
	case ID::CylinderSensor:
		return _handler->endCylinderSensor();
	case ID::DirectionalLight:
		return _handler->endDirectionalLight();
	case ID::Disk2D:
		return _handler->endDisk2D();
	case ID::EXPORT:
		return _handler->endEXPORT();
	case ID::ElevationGrid:
		return _handler->endElevationGrid();
	case ID::EspduTransform:
		return _handler->endEspduTransform();
	case ID::ExternProtoDeclare:
		return _handler->endExternProtoDeclare();
	case ID::Extrusion:
		return _handler->endExtrusion();
	case ID::FillProperties:
		return _handler->endFillProperties();
	case ID::Fog:
		return _handler->endFog();
	case ID::FontStyle:
		return _handler->endFontStyle();
	case ID::GeoCoordinate:
		return _handler->endGeoCoordinate();
	case ID::GeoElevationGrid:
		return _handler->endGeoElevationGrid();
	case ID::GeoLOD:
		return _handler->endGeoLOD();
	case ID::GeoLocation:
		return _handler->endGeoLocation();
	case ID::GeoMetadata:
		return _handler->endGeoMetadata();
	case ID::GeoOrigin:
		return _handler->endGeoOrigin();
	case ID::GeoPositionInterpolator:
		return _handler->endGeoPositionInterpolator();
	case ID::GeoTouchSensor:
		return _handler->endGeoTouchSensor();
	case ID::GeoViewpoint:
		return _handler->endGeoViewpoint();
	case ID::HAnimDisplacer:
		return _handler->endHAnimDisplacer();
	case ID::HAnimHumanoid:
		return _handler->endHAnimHumanoid();
	case ID::HAnimJoint:
		return _handler->endHAnimJoint();
	case ID::HAnimSegment:
		return _handler->endHAnimSegment();
	case ID::HAnimSite:
		return _handler->endHAnimSite();
	case ID::IMPORT:
		return _handler->endIMPORT();
	case ID::IS:
		return _handler->endIS();
	case ID::Inline:
		return _handler->endInline();
	case ID::IntegerSequencer:
		return _handler->endIntegerSequencer();
	case ID::IntegerTrigger:
		return _handler->endIntegerTrigger();
	case ID::KeySensor:
		return _handler->endKeySensor();
	case ID::LineProperties:
		return _handler->endLineProperties();
	case ID::LineSet:
		return _handler->endLineSet();
	case ID::LoadSensor:
		return _handler->endLoadSensor();
	case ID::MetadataDouble:
		return _handler->endMetadataDouble();
	case ID::MetadataFloat:
		return _handler->endMetadataFloat();
	case ID::MetadataInteger:
		return _handler->endMetadataInteger();
	case ID::MetadataSet:
		return _handler->endMetadataSet();
	case ID::MetadataString:
		return _handler->endMetadataString();
	case ID::MovieTexture:
		return _handler->endMovieTexture();
	case ID::NavigationInfo:
		return _handler->endNavigationInfo();
	case ID::NormalInterpolator:
		return _handler->endNormalInterpolator();
	case ID::NurbsCurve:
		return _handler->endNurbsCurve();
	case ID::NurbsCurve2D:
		return _handler->endNurbsCurve2D();
	case ID::NurbsOrientationInterpolator:
		return _handler->endNurbsOrientationInterpolator();
	case ID::NurbsPatchSurface:
		return _handler->endNurbsPatchSurface();
	case ID::NurbsPositionInterpolator:
		return _handler->endNurbsPositionInterpolator();
	case ID::NurbsSet:
		return _handler->endNurbsSet();
	case ID::NurbsSurfaceInterpolator:
		return _handler->endNurbsSurfaceInterpolator();
	case ID::NurbsSweptSurface:
		return _handler->endNurbsSweptSurface();
	case ID::NurbsSwungSurface:
		return _handler->endNurbsSwungSurface();
	case ID::NurbsTextureCoordinate:
		return _handler->endNurbsTextureCoordinate();
	case ID::NurbsTrimmedSurface:
		return _handler->endNurbsTrimmedSurface();
	case ID::OrientationInterpolator:
		return _handler->endOrientationInterpolator();
	case ID::PixelTexture:
		return _handler->endPixelTexture();
	case ID::PlaneSensor:
		return _handler->endPlaneSensor();
	case ID::PointLight:
		return _handler->endPointLight();
	case ID::Polyline2D:
		return _handler->endPolyline2D();
	case ID::Polypoint2D:
		return _handler->endPolypoint2D();
	case ID::PositionInterpolator:
		return _handler->endPositionInterpolator();
	case ID::PositionInterpolator2D:
		return _handler->endPositionInterpolator2D();
	case ID::ProtoBody:
		return _handler->endProtoBody();
	case ID::ProtoDeclare:
		return _handler->endProtoDeclare();
	case ID::ProtoInterface:
		return _handler->endProtoInterface();
	case ID::ProximitySensor:
		return _handler->endProximitySensor();
	case ID::ReceiverPdu:
		return _handler->endReceiverPdu();
	case ID::Rectangle2D:
		return _handler->endRectangle2D();
	case ID::ScalarInterpolator:
		return _handler->endScalarInterpolator();
	case ID::Scene:
		return _handler->endScene();
	case ID::SignalPdu:
		return _handler->endSignalPdu();
	case ID::Sound:
		return _handler->endSound();
	case ID::SphereSensor:
		return _handler->endSphereSensor();
	case ID::SpotLight:
		return _handler->endSpotLight();
	case ID::StringSensor:
		return _handler->endStringSensor();
	case ID::Text:
		return _handler->endText();
	case ID::TextureBackground:
		return _handler->endTextureBackground();
	case ID::TextureCoordinateGenerator:
		return _handler->endTextureCoordinateGenerator();
	case ID::TimeSensor:
		return _handler->endTimeSensor();
	case ID::TimeTrigger:
		return _handler->endTimeTrigger();
	case ID::TouchSensor:
		return _handler->endTouchSensor();
	case ID::TransmitterPdu:
		return _handler->endTransmitterPdu();
	case ID::TriangleFanSet:
		return _handler->endTriangleFanSet();
	case ID::TriangleSet:
		return _handler->endTriangleSet();
	case ID::TriangleSet2D:
		return _handler->endTriangleSet2D();
	case ID::TriangleStripSet:
		return _handler->endTriangleStripSet();
	case ID::Viewpoint:
		return _handler->endViewpoint();
	case ID::VisibilitySensor:
		return _handler->endVisibilitySensor();
	case ID::WorldInfo:
		return _handler->endWorldInfo();
	case ID::X3D:
		return _handler->endX3D();
	case ID::component:
		return _handler->endcomponent();
	case ID::connect:
		return _handler->endconnect();
	case ID::field:
		return _handler->endfield();
	case ID::head:
		return _handler->endhead();
	case ID::humanoidBodyType:
		return _handler->endhumanoidBodyType();
	case ID::meta:
		return _handler->endmeta();
	case ID::CADAssembly:
		return _handler->endCADAssembly();
	case ID::CADFace:
		return _handler->endCADFace();
	case ID::CADLayer:
		return _handler->endCADLayer();
	case ID::CADPart:
		return _handler->endCADPart();
	case ID::ComposedCubeMapTexture:
		return _handler->endComposedCubeMapTexture();
	case ID::ComposedShader:
		return _handler->endComposedShader();
	case ID::ComposedTexture3D:
		return _handler->endComposedTexture3D();
	case ID::FloatVertexAttribute:
		return _handler->endFloatVertexAttribute();
	case ID::FogCoordinate:
		return _handler->endFogCoordinate();
	case ID::GeneratedCubeMapTexture:
		return _handler->endGeneratedCubeMapTexture();
	case ID::ImageCubeMapTexture:
		return _handler->endImageCubeMapTexture();
	case ID::ImageTexture3D:
		return _handler->endImageTexture3D();
	case ID::IndexedQuadSet:
		return _handler->endIndexedQuadSet();
	case ID::LocalFog:
		return _handler->endLocalFog();
	case ID::Matrix3VertexAttribute:
		return _handler->endMatrix3VertexAttribute();
	case ID::Matrix4VertexAttribute:
		return _handler->endMatrix4VertexAttribute();
	case ID::PackagedShader:
		return _handler->endPackagedShader();
	case ID::PixelTexture3D:
		return _handler->endPixelTexture3D();
	case ID::ProgramShader:
		return _handler->endProgramShader();
	case ID::QuadSet:
		return _handler->endQuadSet();
	case ID::ShaderPart:
		return _handler->endShaderPart();
	case ID::ShaderProgram:
		return _handler->endShaderProgram();
	case ID::TextureCoordinate3D:
		return _handler->endTextureCoordinate3D();
	case ID::TextureCoordinate4D:
		return _handler->endTextureCoordinate4D();
	case ID::TextureTransform3D:
		return _handler->endTextureTransform3D();
	case ID::TextureTransformMatrix3D:
		return _handler->endTextureTransformMatrix3D();
	case -1:
	default:
		return _handler->endUnknown(id, nodeName);
	};
}
// END GENERATED
}
