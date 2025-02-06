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
#ifndef _SYNKRO_VIEW_KERNEL3X3FILTER_
#define _SYNKRO_VIEW_KERNEL3X3FILTER_


#include "config.h"
#include "Kernel3x3FilterImpl.h"
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace view
{


// 3x3-kernel filter implementation.
class Kernel3x3Filter :
	public Kernel3x3FilterImpl<IKernel3x3Filter>
{
public:
	// Constructor.
	Kernel3x3Filter( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program );

	// IViewportFilter methods.
	IViewportFilterAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

private:
	anim::IAnimationSystem*									_animationSystem;
	P(IKernel3x3FilterAnimationController)					_ctrlAnimation;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_KERNEL3X3FILTER_
