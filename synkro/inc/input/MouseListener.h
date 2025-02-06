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
// Purpose: Defines mouse listener.
//==============================================================================
#ifndef _SYNKRO_INPUT_MOUSELISTENER_
#define _SYNKRO_INPUT_MOUSELISTENER_


#include "config.h"
#include <input/Axis.h>
#include <input/MouseButton.h>


namespace synkro
{


namespace input
{


/**
 * Mouse listener.
 */
iface MouseListener
{
public:
	/**
	 * Indicates whether the listener is active.
	 * @return True if the listener wants to listen to mouse events, false otherwise.
	 */
	virtual Bool											ListenMouseInput() const = 0;

	/**
	 * Processes click event.
	 * @param device Mouse device index.
	 * @param buttons Pressed buttons.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnMouseClick( UInt device, const MouseButton& buttons ) = 0;

	/**
	 * Processes double click event.
	 * @param device Mouse device index.
	 * @param buttons Pressed buttons.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnMouseDoubleClick( UInt device, const MouseButton& buttons ) = 0;

	/**
	 * Processes button down event.
	 * @param device Mouse device index.
	 * @param buttons Pressed buttons.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnMouseButtonDown( UInt device, const MouseButton& buttons ) = 0;

	/**
	 * Processes button up event.
	 * @param device Mouse device index.
	 * @param buttons Unpressed buttons.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnMouseButtonUp( UInt device, const MouseButton& buttons ) = 0;

	/**
	 * Processes axis movement event.
	 * @param device Mouse device index.
	 * @param axis Axis that fired the event.
	 * @param delta Amount of movement.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnMouseAxisMove( UInt device, const Axis& axis, Int delta ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_MOUSELISTENER_
