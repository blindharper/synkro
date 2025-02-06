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
#include "config.h"
#include "LightAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


LightAnimationController::LightAnimationController( ILight* light, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	LightAnimationControllerImpl<ILightAnimationController>( light, animationSystem, animation, listener )
{
	SetAnimation( _animation );
}


} // scene


} // synkro
