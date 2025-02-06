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
#include "config.h"
#include "PrimitiveAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


PrimitiveAnimationController::PrimitiveAnimationController( IPrimitive* primitive, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PrimitiveAnimationControllerImpl<IPrimitiveAnimationController>( primitive, animationSystem, animation, listener )
{
	SetAnimation( _animation );
}


} // scene


} // synkro
