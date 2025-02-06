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
// Purpose: Defines extended joystick device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IJOYSTICKEX_
#define _SYNKRO_INPUT_IJOYSTICKEX_


#include "config.h"
#include <input/IJoystick.h>


namespace synkro
{


namespace input
{


/**
 * Extended joystick device.
 */
iface IJoystickEx :
	public IJoystick
{
public:
	/**
	 * Subscribes for button down event listening.
	 * @param listener Event listener.
	 * @param button Joystick button to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenButtonDown( JoystickListener* listener, const JoystickButton& button ) = 0;

	/**
	 * Subscribes for button up event listening.
	 * @param listener Event listener.
	 * @param button Button to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenButtonUp( JoystickListener* listener, const JoystickButton& button ) = 0;

	/**
	 * Subscribes for axis move event listening.
	 * @param listener Event listener.
	 * @param axis Axis to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenAxisMove( JoystickListener* listener, const Axis& axis ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IJOYSTICKEX_
