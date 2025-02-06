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
// Purpose: Implements animation controller for abstract primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLER_


#include "config.h"
#include "PrimitiveAnimationControllerImpl.h"
#include <scene/IPrimitiveAnimationController.h>


namespace synkro
{


namespace scene
{


// Animation controller for primitive.
class PrimitiveAnimationController :
	public PrimitiveAnimationControllerImpl<IPrimitiveAnimationController>
{
public:
	// Constructor.
	PrimitiveAnimationController( IPrimitive* primitive, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_PRIMITIVEANIMATIONCONTROLLER_
