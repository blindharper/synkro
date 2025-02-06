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
// Purpose: DirectInput 8 input system.
//==============================================================================
#ifndef _SYNKRO_INPUT_DI8INPUTSYSTEM_
#define _SYNKRO_INPUT_DI8INPUTSYSTEM_


#include "config.h"
#include <input/InputSystemImpl.h>
#include <input/IInputSystem.h>
#include "Di8.h"


namespace synkro
{


namespace input
{


// DirectInput 8 input system.
class Di8InputSystem :
	public InputSystemImpl<IInputSystem>
{
public:
	// Constructor & destructor.
	Di8InputSystem( Pointer module, win::IWindowSystemEx* windowSystem, diag::ILog* log );
	~Di8InputSystem();

	// IInputSystem methods.
	IMouse*													CreateMouse( UInt index );
	IJoystick*												CreateJoystick( UInt index );
	IKeyboard*												CreateKeyboard( UInt index );

	// Other methods.
	void													AddDevice( const lang::String& name );
	void													AddKeyboard( REFGUID guid, const lang::String& name );
	void													AddMouse( REFGUID guid, const lang::String& name );
	void													AddJoystick( REFGUID guid, const lang::String& name );

private:
	struct DeviceGuid
	{
		DeviceGuid( REFGUID guid, DWORD type ) :
			Guid( guid ),
			Type( type )
		{
		}
		
		DeviceGuid() :
			Type( 0 )
		{
		}

		GUID	Guid;
		DWORD	Type;
	};

	lang::Vector<DeviceGuid>								_guids;
	win::IWindowSystemEx*									_windowSystem;
	HMODULE													_dll;
	IDirectInput8*											_di8;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8INPUTSYSTEM_
