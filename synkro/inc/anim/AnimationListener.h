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
// Purpose: Defines animation listener.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONLISTENER_
#define _SYNKRO_ANIM_ANIMATIONLISTENER_


#include "config.h"


namespace synkro
{


namespace anim
{


/**
 * Animation listener.
 */
iface AnimationListener
{
public:
	/**
	 * Processes "Animation Stopped" event.
	 * @param sender Event sender.
	 */
	virtual void											OnAnimationStop( IAnimationController* sender ) = 0;

	/**
	 * Processes "Animation Loop" event.
	 * @param sender Event sender.
	 */
	virtual void											OnAnimationLoop( IAnimationController* sender ) = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONLISTENER_
