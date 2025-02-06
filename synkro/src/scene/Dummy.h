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
// Purpose: Dummy node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_DUMMY_
#define _SYNKRO_SCENE_DUMMY_


#include "config.h"
#include "NodeImpl.h"
#include <scene/INode.h>
#include <scene/INodeAnimationController.h>
#include "BaseNode.h"
#include "DebugHelper.h"


namespace synkro
{


namespace scene
{


// Dummy node implementation.
class Dummy :
	public NodeImpl<INode>,
	public BaseNode
{
public:
	// Constructors.
	Dummy( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize );
	Dummy( const Dummy& other );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// BaseNode methods.
	void													Update();

private:
	P(INodeAnimationController)								_ctrlAnimation;
	DebugHelper												_dummy;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DUMMY_
