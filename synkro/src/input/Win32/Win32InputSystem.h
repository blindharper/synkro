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
// Purpose: Win32 input system.
//==============================================================================
#ifndef _SYNKRO_INPUT_WIN32INPUTSYSTEM_
#define _SYNKRO_INPUT_WIN32INPUTSYSTEM_


#include "config.h"
#include <input/InputSystemImpl.h>
#include <input/IInputSystem.h>


namespace synkro
{


namespace input
{


// Win32 input system.
class Win32InputSystem :
	public InputSystemImpl<IInputSystem>
{
public:
	// Constructor & destructor.
	Win32InputSystem( diag::ILog* log );
	~Win32InputSystem();

	// IInputSystem methods.
	IMouse*													CreateMouse( UInt index );
	IJoystick*												CreateJoystick( UInt index );
	IKeyboard*												CreateKeyboard( UInt index );

private:
	HMODULE													_dll;

	FARPROC													GetEntryPoint( const char* name );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_WIN32INPUTSYSTEM_
