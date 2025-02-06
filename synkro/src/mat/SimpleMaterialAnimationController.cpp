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
// Purpose: Animation controller for simple material.
//==============================================================================
#include "config.h"
#include "SimpleMaterialAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace mat
{


SimpleMaterialAnimationController::SimpleMaterialAnimationController( ISimpleMaterial* material, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	SimpleMaterialAnimationControllerImpl<ISimpleMaterialAnimationController>( material, animationSystem, animation, listener )
{
	SetAnimation( _animation );
}


} // mat


} // synkro
