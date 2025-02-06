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
// Purpose: Defines extended mouse device.
//==============================================================================
#ifndef _SYNKRO_INPUT_IMOUSEEX_
#define _SYNKRO_INPUT_IMOUSEEX_


#include "config.h"
#include <input/IMouse.h>


namespace synkro
{


namespace input
{


/**
 * Extended mouse device.
 */
iface IMouseEx :
	public IMouse
{
public:
	/**
	 * Subscribes for click event listening.
	 * @param listener Event listener.
	 * @param buttons Buttons to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenClick( MouseListener* listener, const MouseButton& buttons ) = 0;

	/**
	 * Subscribes for double click event listening.
	 * @param listener Event listener.
	 * @param buttons Buttons to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenDoubleClick( MouseListener* listener, const MouseButton& buttons ) = 0;

	/**
	 * Subscribes for button down event listening.
	 * @param listener Event listener.
	 * @param buttons Buttons to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenButtonDown( MouseListener* listener, const MouseButton& buttons ) = 0;

	/**
	 * Subscribes for button up event listening.
	 * @param listener Event listener.
	 * @param buttons Buttons to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenButtonUp( MouseListener* listener, const MouseButton& buttons ) = 0;

	/**
	 * Subscribes for axis move event listening.
	 * @param listener Event listener.
	 * @param axis Axis to listen to.
	 * @exception BadArgumentException listener is null.
	 */
	virtual void											ListenAxisMove( MouseListener* listener, const Axis& axis ) = 0;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_IMOUSEEX_
