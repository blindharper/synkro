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
// Purpose: Defines recording animation controller.
//==============================================================================
#ifndef _SYNKRO_ANIM_IRECORDANIMATIONCONTROLLER_
#define _SYNKRO_ANIM_IRECORDANIMATIONCONTROLLER_


#include "config.h"
#include <anim/IAnimationController.h>


namespace synkro
{


namespace anim
{


/**
 * Recording animation controller. Used to record animation.
 */
iface IRecordAnimationController :
	public IAnimationController
{
public:
	/**
	 * Sets sampling step, in seconds. Default is 1.0.
	 * @param step Sampling step.
	 */
	virtual void											SetStep( Double step ) = 0;

	/**
	 * Retrieves sampling step.
	 */
	virtual Double											GetStep() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IRECORDANIMATIONCONTROLLER_
