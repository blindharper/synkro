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
// Purpose: Defines animation controller.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONCONTROLLER_
#define _SYNKRO_ANIM_IANIMATIONCONTROLLER_


#include "config.h"
#include <core/IController.h>


namespace synkro
{


namespace anim
{


/**
 * Animation controller. Updates controlled object using the underlying animation.
 */
iface IAnimationController :
	public core::IController
{
public:
	/**
	 * Sets animation assigned to the controller.
	 * @param animation Animation object.
	 * @exception BadArgumentException animation is nullptr.
	 */
	virtual void											SetAnimation( IAnimation* animation ) = 0;

	/**
	 * Retrieves animation assigned to the controller.
	 */
	virtual IAnimation*										GetAnimation() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONCONTROLLER_
