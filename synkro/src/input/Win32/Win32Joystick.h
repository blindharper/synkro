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
// Purpose: Win32 joystick.
//==============================================================================
#ifndef _SYNKRO_INPUT_WIN32JOYSTICK_
#define _SYNKRO_INPUT_WIN32JOYSTICK_


#include "config.h"
#include <input/JoystickImpl.h>
#include <input/IJoystick.h>


namespace synkro
{


namespace input
{


// Win32 joystick.
class Win32Joystick :
	public JoystickImpl<IJoystick>
{
public:
	// Constructor.
	Win32Joystick( const JoystickDesc& desc );

	// IInputDevice methods.
	Bool													Update( Double delta );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_WIN32JOYSTICK_
