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
// Purpose: DirectInput 8 keyboard.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8KEYBOARD_
#define _SYNKRO_INPUT_DI8KEYBOARD_


#include "config.h"
#include <input/KeyboardImpl.h>
#include <input/IKeyboard.h>
#include "Di8BaseInputDevice.h"
#include "Di8BaseInputDeviceImpl.h"


namespace synkro
{


namespace input
{


// DirectInput 8 keyboard device.
class Di8Keyboard :
	public KeyboardImpl<IKeyboard>,
	public Di8BaseInputDeviceImpl<Di8BaseInputDevice>
{
public:
	// Constructor.
	Di8Keyboard( IDirectInput8* di, REFGUID guid, HWND window, const KeyboardDesc& desc );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IKeyboard methods.
	Bool													IsKeyDown( const Key& key ) const;
	Key														ToKey( Byte code ) const;
	char													ToChar( Byte code, Bool shift ) const;

private:
	static BOOL CALLBACK									ListKeys( const DIDEVICEOBJECTINSTANCE* obj, LPVOID ref );
};


#include "Di8Keyboard.inl"


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8KEYBOARD_
