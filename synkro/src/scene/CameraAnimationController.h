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
// Purpose: Animation controller for camera.
//==============================================================================
#ifndef _SYNKRO_SCENE_CAMERAANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_CAMERAANIMATIONCONTROLLER_


#include "config.h"
#include "NodeAnimationControllerImpl.h"
#include <scene/ICameraAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for camera.
class CameraAnimationController :
	public NodeAnimationControllerImpl<ICameraAnimationController>
{
public:
	// Constructor.
	CameraAnimationController( ICamera* camera, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// INodeAnimationController methods.
	ICameraAnimationController*								AsCamera() const;

	// ICameraAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateFieldOfViewTrack();
	anim::IProceduralFloatTrack*							CreateFieldOfViewTrack( const anim::AnimationTrack& type );
	anim::IExpressionFloatTrack*							CreateFieldOfViewTrack( anim::IExpressionScript* script );
	anim::IExpressionFloatTrack*							CreateFieldOfViewTrack( const lang::String& expression );

private:
	ICamera*												_camera;
	anim::IAnimationFloatTrack*								_trackFieldOfView;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CAMERAANIMATIONCONTROLLER_
