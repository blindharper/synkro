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
// Purpose: Defines extended keyboard device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IKEYBOARDEX_
#define _SYNKRO_INPUT_IKEYBOARDEX_


#include "config.h"
#include <input/IKeyboard.h>


namespace synkro
{


namespace input
{


/**
 * Extended keyboard device.
 */
iface IKeyboardEx :
	public IKeyboard
{
public:
	/**
	 * Subscribes for key down event listening.
	 * @param listener Event listener.
	 * @param keys Array of keyboard keys to listen to.
	 * @param count Array size.
	 * @param discrete True to listen to discrete events, false to listen for continuous events.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenKeyDown( KeyboardListener* listener, const Key* keys, UInt count, Bool discrete ) = 0;

	/**
	 * Subscribes for key down event listening.
	 * @param listener Event listener.
	 * @param key Keyboard key to listen to.
	 * @param discrete True to listen to discrete events, false to listen for continuous events.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenKeyDown( KeyboardListener* listener, const Key& key, Bool discrete ) = 0;

	/**
	 * Subscribes for key up event listening.
	 * @param listener Event listener.
	 * @param keys Array of keyboard keys to listen to.
	 * @param count Array size.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenKeyUp( KeyboardListener* listener, const Key* keys, UInt count ) = 0;

	/**
	 * Subscribes for key up event listening.
	 * @param listener Event listener.
	 * @param key Keyboard key to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenKeyUp( KeyboardListener* listener, const Key& key ) = 0;

	/**
	 * Subscribes for key press event listening.
	 * @param listener Event listener.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenKeyPress( KeyboardListener* listener ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IKEYBOARDEX_
