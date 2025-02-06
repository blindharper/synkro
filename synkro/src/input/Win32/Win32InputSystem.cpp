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
#include "config.h"
#include "Win32InputSystem.h"
#include "Win32Joystick.h"
#include "Win32Keyboard.h"
#include "Win32Mouse.h"
#include "Win32.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::win;

//------------------------------------------------------------------------------


// WinMM library name.
#define WINMM_DLL L"winmm.dll"


namespace synkro
{


namespace input
{


Win32InputSystem::Win32InputSystem( ILog* log ) :
	InputSystemImpl<IInputSystem>( log ),
	_dll( nullptr )
{
	typedef UINT (WINAPI* LPJOYGETNUMDEVS)();
	typedef MMRESULT (WINAPI* LPJOYGETDEVCAPSW)( UINT_PTR, LPJOYCAPSW, UINT );

	// Make sure WinMM is installed.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"Win32 Input System") );
	if ( (_dll = ::LoadLibrary(WINMM_DLL)) == nullptr )
		throw InputException( String::Format(Str::InitializeFail, L"Win32 Input System"), String::Format(Str::NotFound, WINMM_DLL) );

	// Get required entry points.
	LPJOYGETNUMDEVS pJoyGetNumDevs = (LPJOYGETNUMDEVS)GetEntryPoint( "joyGetNumDevs" );
	LPJOYGETDEVCAPSW pJoyGetDevCaps = (LPJOYGETDEVCAPSW)GetEntryPoint( "joyGetDevCapsW" );
	Win32::JoyGetPosEx = (LPJOYGETPOSEX)GetEntryPoint( "joyGetPosEx" );

	// Add keyboard device.
	LogInfo( MessagePriority::Low, Formatter::Format(Str::KeyboardDetected, L"Default Keyboard") );
	_keyboards.Add( KeyboardDesc(L"Default Keyboard", 104) );

	// Add mouse device.
	const int mouseButtons = ::GetSystemMetrics( SM_CMOUSEBUTTONS );
	if ( mouseButtons > 0 )
	{
		LogInfo( MessagePriority::Low, Formatter::Format(Str::MouseDetected, L"Default Mouse") );
		const int wheel = ::GetSystemMetrics( SM_MOUSEWHEELPRESENT );
		_mice.Add( MouseDesc(L"Default Mouse", (wheel > 0) ? 3 : 2, CastUInt(mouseButtons)) );
	}

	// Add joystick devices.
	const UINT joystickCount = pJoyGetNumDevs();
	for ( UINT i = 0; i < joystickCount; ++i )
	{
		JOYCAPS caps;
		if ( pJoyGetDevCaps(i, &caps, sizeof(caps)) == JOYERR_NOERROR )
		{
			String name( caps.szPname );
			LogInfo( MessagePriority::Low, Formatter::Format(Str::JoystickDetected, name) );
			_joysticks.Add( JoystickDesc(name, caps.wMaxAxes, caps.wMaxButtons, false) );
		}
	}

	::ShowCursor( FALSE );
}

Win32InputSystem::~Win32InputSystem()
{
	::FreeLibrary( _dll );
	::ShowCursor( TRUE );
}

IMouse* Win32InputSystem::CreateMouse( UInt index )
{
	assert( index < _mice.Size() );

	if ( index >= _mice.Size() )
		throw OutOfRangeException( index, _mice.Size() );

	return new Win32Mouse( _mice[index] );
}

IJoystick* Win32InputSystem::CreateJoystick( UInt index )
{
	assert( index < _joysticks.Size() );

	if ( index >= _joysticks.Size() )
		throw OutOfRangeException( index, _joysticks.Size() );

	return new Win32Joystick( _joysticks[index] );
}

IKeyboard* Win32InputSystem::CreateKeyboard( UInt index )
{
	assert( index < _keyboards.Size() );

	if ( index >= _keyboards.Size() )
		throw OutOfRangeException( index, _keyboards.Size() );

	return new Win32Keyboard( _keyboards[index] );
}

FARPROC Win32InputSystem::GetEntryPoint( const char* name )
{
	FARPROC proc = ::GetProcAddress( _dll, name );
	if ( proc == nullptr )
		throw InputException( String::Format(Str::InitializeFail, L"Win32 Input System"), String::Format(Str::NotFound, name), String::Empty );
	return proc;
}


} // input


} // synkro
