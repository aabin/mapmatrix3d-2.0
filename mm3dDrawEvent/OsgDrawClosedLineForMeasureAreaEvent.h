#pragma once
#include "OSG_Plus.h"
#include "osgDrawClosedLineDBclickEvent.h"

class COsgDrawClosedLineForMeasureAreaEvent : public COsgDrawClosedLineDBclickEvent
{
public:
	COsgDrawClosedLineForMeasureAreaEvent(osgViewer::Viewer *viewer, osg::Group *root, osg::Group* editSceneGroup, osg::Group* tempGroup) :
		COsgDrawClosedLineDBclickEvent(viewer, root, editSceneGroup, tempGroup), COsgDrawMultiClosedLineEvent(viewer, root, editSceneGroup, tempGroup), CBaseUserEvent(viewer)
	{
		mViewer = viewer;
		mRoot = root;
		mEditSceneGroup = editSceneGroup;
		mTempGroup = tempGroup;
		InterfaceBaseDrawerFactory IBaseDrawerFactory;
		IBaseDrawer = IBaseDrawerFactory.create();

		isActivated = false;
	}

protected:
	virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa);

	virtual void UpdateActivatedStatus(std::vector<OperatingState> vecOpState);

	virtual void DoubleClickDrawClosedLineOperate(osg::Vec3d worldPt, std::vector<osg::Vec3d> VecWorldCoord, osg::ref_ptr<osg::Group> editSceneGroup, osg::Matrix worldMatrix);

protected:
	std::vector<osg::Vec3d> vecWorldCoord;

	osgViewer::Viewer *mViewer;
	osg::Group *mRoot;
	osg::Group* mEditSceneGroup;
	osg::Group* mTempGroup;
	InterfaceBaseDrawer* IBaseDrawer;

	bool isActivated;
};