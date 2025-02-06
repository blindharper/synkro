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
// Purpose: Defines joystick device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IJOYSTICK_
#define _SYNKRO_INPUT_IJOYSTICK_


#include "config.h"
#include <input/IInputDevice.h>
#include <input/JoystickButton.h>
#include <input/JoystickState.h>
#include <input/JoystickDesc.h>
#include <input/Axis.h>


namespace synkro
{


namespace input
{


/**
 * Joystick device.
 */
iface IJoystick :
	public IInputDevice
{
public:
	/**
	 * Indicates if a particular joystick button is currently pressed.
	 * @param button Button to test.
	 * @return True if the button is pressed, false otherwise.
	 */
	virtual Bool											IsButtonDown( const JoystickButton& button ) const = 0;

	/**
	 * Indicates if a particular joystick button is currently released.
	 * @param button Button to test.
	 * @return True if the button is released, false otherwise.
	 */
	virtual Bool											IsButtonUp( const JoystickButton& button ) const = 0;

	/**
	 * Retrieves relative movement for a particular axis since the last state poll.
	 * @param axis Axis to retrieve the movement for.
	 * @return Relative axis movement.
	 */
	virtual Int												GetAxisMovement( const Axis& axis ) const = 0;

	/**
	 * Retrieves joystick state.
	 * @param [out] state Joystick state.
	 */
	virtual void											GetState( JoystickState& state ) const = 0;

	/**
	 * Retrieves joystick description.
	 * @param [out] desc Joystick description.
	 */
	virtual void											GetDesc( JoystickDesc& desc ) const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IJOYSTICK_
