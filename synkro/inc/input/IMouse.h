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
// Purpose: Defines mouse device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IMOUSE_
#define _SYNKRO_INPUT_IMOUSE_


#include "config.h"
#include <input/IInputDevice.h>
#include <input/MouseButton.h>
#include <input/MouseState.h>
#include <input/MouseDesc.h>
#include <input/Axis.h>


namespace synkro
{


namespace input
{


/**
 * Mouse device.
 */
iface IMouse :
	public IInputDevice
{
public:
	/**
	 * Indicates if a particular mouse button is currently pressed.
	 * @param button Button to test.
	 * @return True if the button is pressed, false otherwise.
	 */
	virtual Bool											IsButtonDown( const MouseButton& button ) const = 0;

	/**
	 * Indicates if a particular mouse button is currently released.
	 * @param button Button to test.
	 * @return True if the button is released, false otherwise.
	 */
	virtual Bool											IsButtonUp( const MouseButton& button ) const = 0;

	/**
	 * Retrieves relative movement for a particular axis since the last state poll.
	 * @param axis Axis to retrieve the movement for.
	 * @return Relative axis movement.
	 */
	virtual Int												GetAxisMovement( const Axis& axis ) const = 0;

	/**
	 * Retrieves mouse state.
	 * @param [out] state Mouse state.
	 */
	virtual void											GetState( MouseState& state ) const = 0;

	/**
	 * Retrieves mouse description.
	 * @param [out] desc Mouse description.
	 */
	virtual void											GetDesc( MouseDesc& desc ) const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IMOUSE_
