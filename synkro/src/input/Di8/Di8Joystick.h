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
// Purpose: DirectInput 8 joystick.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8JOYSTICK_
#define _SYNKRO_INPUT_DI8JOYSTICK_


#include "config.h"
#include <input/JoystickImpl.h>
#include <input/IJoystick.h>
#include "Di8BaseInputDevice.h"
#include "Di8BaseInputDeviceImpl.h"


namespace synkro
{


namespace input
{


// DirectInput 8 joystick.
class Di8Joystick :
	public JoystickImpl<IJoystick>,
	public Di8BaseInputDeviceImpl<Di8BaseInputDevice>
{
public:
	// Constructor.
	Di8Joystick( IDirectInput8* di, REFGUID guid, HWND window, const JoystickDesc& desc );

	// IInputDevice methods.
	Bool													Update( Double delta );

private:
	static BOOL CALLBACK									ListJoystickAxes( const DIDEVICEOBJECTINSTANCE* obj, LPVOID ref );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8JOYSTICK_
