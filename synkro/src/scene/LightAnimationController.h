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
// Purpose: Animation controller for light source.
//==============================================================================
#ifndef _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLER_


#include "config.h"
#include "LightAnimationControllerImpl.h"
#include <scene/ILight.h>


namespace synkro
{


namespace scene
{


// Animation controller for light source.
class LightAnimationController :
	public LightAnimationControllerImpl<ILightAnimationController>
{
public:
	// Constructor.
	LightAnimationController( ILight* light, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LIGHTANIMATIONCONTROLLER_
