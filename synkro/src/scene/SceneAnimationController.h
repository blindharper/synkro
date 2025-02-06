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
// Purpose: Animation controller for scene.
//==============================================================================
#ifndef _SYNKRO_SCENE_SCENEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_SCENEANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/ISceneAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for scene.
class SceneAnimationController :
	public anim::PlaybackControllerImpl<ISceneAnimationController>
{
public:
	// Constructor.
	SceneAnimationController( ISceneEx* scene, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ISceneAnimationController methods.
	anim::IKeyframedColorTrack*								CreateAmbientLightColorTrack();
	anim::IProceduralColorTrack*							CreateAmbientLightColorTrack( const anim::AnimationTrack& type );
	anim::IExpressionColorTrack*							CreateAmbientLightColorTrack( anim::IExpressionScript* script );
	anim::IExpressionColorTrack*							CreateAmbientLightColorTrack( const lang::String& expression );
	anim::IKeyframedFloatTrack*								CreateAmbientLightIntensityTrack();
	anim::IProceduralFloatTrack*							CreateAmbientLightIntensityTrack( const anim::AnimationTrack& type );
	anim::IExpressionFloatTrack*							CreateAmbientLightIntensityTrack( anim::IExpressionScript* script );
	anim::IExpressionFloatTrack*							CreateAmbientLightIntensityTrack( const lang::String& expression );

private:
	ISceneEx*												_scene;
	anim::IAnimationColorTrack*								_trackAmbientColor;
	anim::IAnimationFloatTrack*								_trackAmbientIntensity;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SCENEANIMATIONCONTROLLER_
