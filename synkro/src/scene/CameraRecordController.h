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
// Purpose: Camera record controller implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_CAMERARECORDCONTROLLER_
#define _SYNKRO_SCENE_CAMERARECORDCONTROLLER_


#include "config.h"
#include "NodeRecordControllerImpl.h"
#include <scene/ICameraRecordController.h>
#include <scene/ICamera.h>
#include <scene/CameraProperty.h>


namespace synkro
{


namespace scene
{


// Camera record controller implementation.
class CameraRecordController :
	public NodeRecordControllerImpl<ICameraRecordController>
{
public:
	// Constructor.
	CameraRecordController( ICamera* camera, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation );

	// IController methods.
	void													Update( Double delta );

	// ICameraRecordController methods.
	anim::IKeyframedFloatTrack*								CreateFieldOfViewTrack();

private:
	ICamera*												_camera;
	P(anim::IKeyframedFloatTrack)							_trackFov;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CAMERARECORDCONTROLLER_
