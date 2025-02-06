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
#ifndef _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLER_
#define _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLER_


#include "config.h"
#include "Kernel3x3FilterAnimationControllerImpl.h"
#include <view/IKernel3x3FilterAnimationController.h>
#include <view/IKernel3x3Filter.h>


namespace synkro
{


namespace view
{


// Animation controller for 3x3-kernel filter.
class Kernel3x3FilterAnimationController :
	public Kernel3x3FilterAnimationControllerImpl<IKernel3x3FilterAnimationController>
{
public:
	// Constructor.
	Kernel3x3FilterAnimationController( IKernel3x3Filter* kernel3x3Filter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener );
};


} // view


} // synkro


#endif // _SYNKRO_CORE_KERNEL3X3FILTERANIMATIONCONTROLLER_
