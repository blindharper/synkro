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
// Purpose: Animation controller for fog effect.
//==============================================================================
#ifndef _SYNKRO_SCENE_FOGANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_FOGANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/IFogAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for fog effect.
class FogAnimationController :
	public anim::PlaybackControllerImpl<IFogAnimationController>
{
public:
	// Constructor.
	FogAnimationController( IFog* fog, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// IFogAnimationController methods.
	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IProceduralColorTrack*							CreateColorTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateDensityTrack();
	anim::IProceduralFloatTrack*							CreateDensityTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateStartTrack();
	anim::IProceduralFloatTrack*							CreateStartTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateEndTrack();
	anim::IProceduralFloatTrack*							CreateEndTrack( const anim::AnimationTrack& type );

private:
	IFog*													_fog;
	anim::IAnimationColorTrack*								_trackColor;
	anim::IAnimationFloatTrack*								_trackDensity;
	anim::IAnimationFloatTrack*								_trackStart;
	anim::IAnimationFloatTrack*								_trackEnd;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_FOGANIMATIONCONTROLLER_
