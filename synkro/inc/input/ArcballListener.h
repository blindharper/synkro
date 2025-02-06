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
// Purpose: Defines arcball listener.
//==============================================================================
#ifndef _SYNKRO_INPUT_ARCBALLLISTENER_
#define _SYNKRO_INPUT_ARCBALLLISTENER_


#include "config.h"
#include <math/Quaternion.h>


namespace synkro
{


namespace input
{


/**
 * Arcball listener.
 */
iface ArcballListener
{
public:
	/**
	 * Indicates whether the listener is active.
	 * @return True if the listener wants to listen to arcball events, false otherwise.
	 */
	virtual Bool											ListenArcballInput() const = 0;

	/**
	 * Processes orientation event.
	 * @param orientation Current orientation.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnArcballOriented( const math::Quaternion& orientation ) = 0;

	/**
	 * Processes zoom event.
	 * @param delta Zoom amount.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnArcballZoom( Int delta ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_ARCBALLLISTENER_
