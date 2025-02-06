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
#ifndef _SYNKRO_SCENE_NODEANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_NODEANIMATIONCONTROLLER_


#include "config.h"
#include "NodeAnimationControllerImpl.h"


namespace synkro
{


namespace scene
{


// Animation controller for scene node.
class NodeAnimationController :
	public NodeAnimationControllerImpl<INodeAnimationController>
{
public:
	// Constructor.
	NodeAnimationController( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NODEANIMATIONCONTROLLER_
