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
// Purpose: Animation controller for scene node.
//==============================================================================
#include "config.h"
#include "NodeAnimationController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


NodeAnimationController::NodeAnimationController( INode* node, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	NodeAnimationControllerImpl<INodeAnimationController>( node, animationSystem, animations, listener )
{
}


} // scene


} // synkro
