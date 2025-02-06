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
// Purpose: DirectInput 8 mouse.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8MOUSE_
#define _SYNKRO_INPUT_DI8MOUSE_


#include "config.h"
#include <input/MouseImpl.h>
#include <input/IMouse.h>
#include "Di8BaseInputDevice.h"
#include "Di8BaseInputDeviceImpl.h"


namespace synkro
{


namespace input
{


// DirectInput 8 mouse.
class Di8Mouse :
	public MouseImpl<IMouse>,
	public Di8BaseInputDeviceImpl<Di8BaseInputDevice>
{
public:
	// Constructor.
	Di8Mouse( IDirectInput8* di, REFGUID guid, HWND window, const MouseDesc& desc );

	// IInputDevice methods.
	Bool													Update( Double delta );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8MOUSE_
