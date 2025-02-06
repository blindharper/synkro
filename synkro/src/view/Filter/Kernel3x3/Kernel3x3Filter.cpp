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
// Purpose: 3x3-kernel filter implementation.
//==============================================================================
#include "config.h"
#include "Kernel3x3Filter.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


Kernel3x3Filter::Kernel3x3Filter( IViewport* viewport, IAnimationSystem* animationSystem, IProgram* program ) :
	Kernel3x3FilterImpl<IKernel3x3Filter>( viewport, animationSystem, program )
{
}

IViewportFilterAnimationController* Kernel3x3Filter::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new Kernel3x3FilterAnimationController( this, _animationSystem, animation, listener ) : _ctrlAnimation;
}


} // view


} // synkro
