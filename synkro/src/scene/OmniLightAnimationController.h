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
// Purpose: Animation controller for omni light source.
//==============================================================================
#ifndef _SYNKRO_SCENE_OMNILIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_OMNILIGHTANIMATIONCONTROLLER_


#include "config.h"
#include "LightAnimationControllerImpl.h"
#include <scene/IOmniLightAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for omni light source.
class OmniLightAnimationController :
	public LightAnimationControllerImpl<IOmniLightAnimationController>
{
public:
	// Constructor.
	OmniLightAnimationController( IOmniLight* omniLight, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// IAnimationController methods.
	void													SetAnimation( anim::IAnimation* animation );

	// ILightAnimationController methods.
	IOmniLightAnimationController*							AsOmni() const;

	// IOmniLightAnimationController methods.
	anim::IKeyframedFloatTrack*								CreateRangeTrack();
	anim::IProceduralFloatTrack*							CreateRangeTrack( const anim::AnimationTrack& type );

private:
	IOmniLight*												_omniLight;
	anim::IAnimationFloatTrack*								_trackRange;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OMNILIGHTANIMATIONCONTROLLER_
