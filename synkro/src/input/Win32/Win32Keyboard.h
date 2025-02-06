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
// Purpose: Win32 keyboard.
//==============================================================================
#ifndef _SYNKRO_INPUT_WIN32KEYBOARD_
#define _SYNKRO_INPUT_WIN32KEYBOARD_


#include "config.h"
#include <input/KeyboardImpl.h>
#include <input/IKeyboard.h>
#include <input/KeyboardState.h>


namespace synkro
{


namespace input
{


// Win32 keyboard.
class Win32Keyboard :
	public KeyboardImpl<IKeyboard>
{
public:
	// Constructor.
	Win32Keyboard( const KeyboardDesc& desc );

	// IInputDevice methods.
	Bool													Update( Double delta );

	// IKeyboard methods.
	Bool													IsKeyDown( const Key& key ) const;
	Key														ToKey( Byte code ) const;
	char													ToChar( Byte code, Bool shift ) const;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_WIN32KEYBOARD_
