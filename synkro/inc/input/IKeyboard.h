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
// Purpose: Defines keyboard device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IKEYBOARD_
#define _SYNKRO_INPUT_IKEYBOARD_


#include "config.h"
#include <input/IInputDevice.h>
#include <input/KeyboardState.h>
#include <input/KeyboardDesc.h>
#include <input/Key.h>


namespace synkro
{


namespace input
{


/**
 * Keyboard device.
 */
iface IKeyboard :
	public IInputDevice
{
public:
	/**
	 * Indicates if a particular keyboard key is currently pressed.
	 * @param key Key to test.
	 * @return True if the key is pressed, false otherwise.
	 */
	virtual Bool											IsKeyDown( const Key& key ) const = 0;

	/**
	 * Indicates if a particular keyboard key is currently released.
	 * @param key Key to test.
	 * @return True if the key is released, false otherwise.
	 */
	virtual Bool											IsKeyUp( const Key& key ) const = 0;

	/**
	 * Converts key scancode to a logical key.
	 * @param code Key scancode.
	 * @return Keyboard key corresponding to the specified scancode.
	 */
	virtual Key												ToKey( Byte code ) const = 0;

	/**
	 * Converts key scancode to a ASCII character.
	 * @param code Key scancode.
	 * @param shift Indicates whether the Shift key is pressed.
	 * @return Character corresponding to the specified scancode.
	 */
	virtual char											ToChar( Byte code, Bool shift ) const = 0;

	/**
	 * Retrieves keyboard state.
	 * @param [out] state Keyboard state.
	 */
	virtual void											GetState( KeyboardState& state ) const = 0;

	/**
	 * Retrieves keyboard description.
	 * @param [out] desc Keyboard description.
	 */
	virtual void											GetDesc( KeyboardDesc& desc ) const = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IKEYBOARD_
