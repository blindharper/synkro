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
// Purpose: Defines timer listener.
//==============================================================================
#ifndef _SYNKRO_CORE_TIMERLISTENER_
#define _SYNKRO_CORE_TIMERLISTENER_


#include "config.h"


namespace synkro
{


namespace core
{


/**
 * Timer listener.
 */
iface TimerListener
{
public:
	/**
	 * Handles timer tick event.
	 * @param timer Unique identifier of the timer that triggered the event.
	 */
	virtual void											OnTimerTick( UInt timer ) = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_TIMERLISTENER_
