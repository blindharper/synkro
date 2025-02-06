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
// Purpose: Animation controller for cone light source.
//==============================================================================
#ifndef _SYNKRO_SCENE_CONELIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_CONELIGHTANIMATIONCONTROLLER_


#include "config.h"
#include "LightAnimationControllerImpl.h"
#include <scene/IConeLightAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for cone light source.
class ConeLightAnimationController :
	public LightAnimationControllerImpl<IConeLightAnimationController>
{
public:
	// Constructor.
	ConeLightAnimationController( IConeLight* coneLight, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ILightAnimationController methods.
	IConeLightAnimationController*							AsCone() const;

	// IConeLightAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateRangeTrack();
	anim::IProceduralFloatTrack*							CreateRangeTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateInnerAngleTrack();
	anim::IProceduralFloatTrack*							CreateInnerAngleTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateOuterAngleTrack();
	anim::IProceduralFloatTrack*							CreateOuterAngleTrack( const anim::AnimationTrack& type );
	anim::IKeyframedFloatTrack*								CreateFalloffTrack();
	anim::IProceduralFloatTrack*							CreateFalloffTrack( const anim::AnimationTrack& type );

private:
	IConeLight*												_coneLight;
	anim::IAnimationFloatTrack*								_trackRange;
	anim::IAnimationFloatTrack*								_trackInnerAngle;
	anim::IAnimationFloatTrack*								_trackOuterAngle;
	anim::IAnimationFloatTrack*								_trackFalloff;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CONELIGHTANIMATIONCONTROLLER_
