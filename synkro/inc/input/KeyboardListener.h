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
// Purpose: Defines keyboard listener.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEYBOARDLISTENER_
#define _SYNKRO_INPUT_KEYBOARDLISTENER_


#include "config.h"
#include <input/Key.h>


namespace synkro
{


namespace input
{


/**
 * Keyboard listener.
 */
iface KeyboardListener
{
public:
	/**
	 * Indicates whether the listener is active.
	 * @return True if the listener wants to listen to keyboard events, false otherwise.
	 */
	virtual Bool											ListenKeyboardInput() const = 0;

	/**
	 * Processes key down event.
	 * @param device Keyboard device index.
	 * @param key Keyboard key that fired the event.
	 * @param alt Indicates whether the ALT key is pressed.
	 * @param shift Indicates whether the SHIFT key is pressed.
	 * @param control Indicates whether the CTRL key is pressed.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnKeyboardKeyDown( UInt device, const Key& key, Bool alt, Bool shift, Bool control ) = 0;

	/**
	 * Processes key up event.
	 * @param device Keyboard device index.
	 * @param key Keyboard key that fired the event.
	 * @param alt Indicates whether the ALT key is pressed.
	 * @param shift Indicates whether the SHIFT key is pressed.
	 * @param control Indicates whether the CTRL key is pressed.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnKeyboardKeyUp( UInt device, const Key& key, Bool alt, Bool shift, Bool control ) = 0;

	/**
	 * Processes key press event.
	 * @param device Keyboard device index.
	 * @param key Character corresponding to the pressed keyboard key.
	 * @return True if the event has been consumed, false otherwise.
	 */
	virtual Bool											OnKeyboardKeyPress( UInt device, Char key ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYBOARDLISTENER_
