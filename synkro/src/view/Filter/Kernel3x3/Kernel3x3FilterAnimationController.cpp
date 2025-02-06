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
// Purpose: Animation controller for 3x3-kernel filter.
//==============================================================================
#include "config.h"
#include "Kernel3x3FilterAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


Kernel3x3FilterAnimationController::Kernel3x3FilterAnimationController( IKernel3x3Filter* kernel3x3Filter, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	Kernel3x3FilterAnimationControllerImpl<IKernel3x3FilterAnimationController>( kernel3x3Filter, animationSystem, animation, listener )
{
	SetAnimation( _animation );
}


} // view


} // synkro
