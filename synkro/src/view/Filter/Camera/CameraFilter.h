//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Camera viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_CAMERAFILTER_
#define _SYNKRO_VIEW_CAMERAFILTER_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include <view/ICameraFilter.h>
#include <scene/ICamera.h>


namespace synkro
{


namespace view
{


// Camera viewport filter implementation.
class CameraFilter :
	public ViewportFilterImpl<ICameraFilter>
{
public:
	// Constructor.
	CameraFilter( IViewport* viewport, gfx::IProgram* program );

	// IViewportFilter methods.
	void													Update();
	ICameraFilter*											AsCamera() const;

	// ICameraFilter methods.
	void													SetCamera( scene::ICamera* camera );
	scene::ICamera*											GetCamera() const;

private:
	P(scene::ICamera)										_camera;
	gfx::ProgramParam*										_paramFront;
	gfx::ProgramParam*										_paramBack;
};


#include "CameraFilter.inl"


} // view


} // synkro


#endif // _SYNKRO_VIEW_CAMERAFILTER_
