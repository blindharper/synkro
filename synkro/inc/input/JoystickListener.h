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
// Purpose: Defines joystick listener.
//==============================================================================
#ifndef _SYNKRO_INPUT_JOYSTICKLISTENER_
#define _SYNKRO_INPUT_JOYSTICKLISTENER_


#include "config.h"
#include <input/Axis.h>
#include <input/JoystickButton.h>


namespace synkro
{


namespace input
{


/**
 * Joystick listener.
 */
iface JoystickListener
{
public:
	/**
	 * Indicates whether the listener is active.
	 * @return True if the listener wants to listen to joystick events, false otherwise.
	 */
	virtual Bool											ListenJoystickInput() const = 0;

	/**
	 * Processes button down event.
	 * @param device Joystick device index.
	 * @param button Joystick button.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnJoystickButtonDown( UInt device, const JoystickButton& button ) = 0;

	/**
	 * Processes button up event.
	 * @param device Joystick device index.
	 * @param button Joystick button.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnJoystickButtonUp( UInt device, const JoystickButton& button ) = 0;

	/**
	 * Processes axis movement event.
	 * @param device Joystick device index.
	 * @param axis Axis that fired the event.
	 * @param delta Amount of movement.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnJoystickAxisMove( UInt device, const Axis& axis, Int delta ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_JOYSTICKLISTENER_
