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
#include "config.h"
#include "Di8InputSystem.h"
#include "Di8Joystick.h"
#include "Di8Keyboard.h"
#include "Di8Mouse.h"
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>
#include <internal/SafeRelease.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::win;

//------------------------------------------------------------------------------


// DirectInput 8 library name.
#define DI8_DLL L"dinput8.dll"


namespace synkro
{


namespace input
{


static BOOL CALLBACK ListInputDevice( const DIDEVICEINSTANCE* desc, LPVOID ref )
{
	Di8InputSystem* sys = reinterpret_cast<Di8InputSystem*>( ref );

	switch ( desc->dwDevType & 0xFF )
	{
		case DI8DEVTYPE_KEYBOARD:
			sys->AddKeyboard( desc->guidInstance, desc->tszProductName );
			break;

		case DI8DEVTYPE_MOUSE:
			sys->AddMouse( desc->guidInstance, desc->tszProductName );
			break;

		case DI8DEVTYPE_JOYSTICK:
			sys->AddJoystick( desc->guidInstance, desc->tszProductName );
			break;

		default:
			sys->AddDevice( desc->tszProductName );
			break;
	}

	return DIENUM_CONTINUE;
}


//------------------------------------------------------------------------------


Di8InputSystem::Di8InputSystem( Pointer module, IWindowSystemEx* windowSystem, ILog* log ) :
	InputSystemImpl<IInputSystem>( log ),
	_guids( A(DeviceGuid) ),
	_windowSystem( windowSystem ),
	_dll( nullptr ),
	_di8( nullptr )
{
	typedef HRESULT (WINAPI *LPDIRECTINPUT8CREATE)( HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN );
	HRESULT hr = DI_OK;

	// Make sure DirectInput 8 is installed.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"DirectInput 8") );
	if ( (_dll = ::LoadLibrary(DI8_DLL)) == nullptr )
		throw InputException( String::Format(Str::InitializeFail, L"DirectInput 8"), String::Format(Str::NotFound, DI8_DLL) );

	// Initialize DirectInput 8.
	LPDIRECTINPUT8CREATE pDirectInput8Create = (LPDIRECTINPUT8CREATE)::GetProcAddress( _dll, "DirectInput8Create" );
	if ( (pDirectInput8Create == nullptr) || FAILED(hr = pDirectInput8Create( (HINSTANCE)module, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_di8, nullptr)) )
		throw InputException( String::Format(Str::InitializeFail, L"DirectInput 8"), Di8::ToString(hr) );

	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Done) );

	// Enumerate available devices.
	if ( FAILED(hr = _di8->EnumDevices(DI8DEVCLASS_ALL, ListInputDevice, this, DIEDFL_ATTACHEDONLY)) )
	{
		AddMouse( GUID_SysMouse, L"Default" );
		AddJoystick( GUID_Joystick, L"Default" );
		AddKeyboard( GUID_SysKeyboard, L"Default" );
	}
}

Di8InputSystem::~Di8InputSystem()
{
	SafeRelease( _di8 );
	::FreeLibrary( _dll );
}

IMouse* Di8InputSystem::CreateMouse( UInt index )
{
	assert( index < _mice.Size() );

	if ( index >= _mice.Size() )
		throw OutOfRangeException( index, _mice.Size() );

	UInt idx = 0;
	for ( UInt i = 0; i < _guids.Size(); ++i )
	{
		if ( (_guids[i].Type == DI8DEVTYPE_MOUSE) && (idx++ == index) )
		{
			HWND wnd = (_windowSystem->GetFrameWindowCount() > 0) ? (HWND)(_windowSystem->GetFrameWindow(0)->GetHandle()) : nullptr;
			return new Di8Mouse( _di8, _guids[i].Guid, wnd, _mice[index] );
		}
	}

	return nullptr;
}

IJoystick* Di8InputSystem::CreateJoystick( UInt index )
{
	assert( index < _joysticks.Size() );

	if ( index >= _joysticks.Size() )
		throw OutOfRangeException( index, _joysticks.Size() );

	UInt idx = 0;
	for ( UInt i = 0; i < _guids.Size(); ++i )
	{
		if ( (_guids[i].Type == DI8DEVTYPE_JOYSTICK) && (idx++ == index) )
		{
			HWND wnd = (_windowSystem->GetFrameWindowCount() > 0) ? (HWND)(_windowSystem->GetFrameWindow(0)->GetHandle()) : nullptr;
			return new Di8Joystick( _di8, _guids[i].Guid, wnd, _joysticks[index] );
		}
	}

	return nullptr;
}

IKeyboard* Di8InputSystem::CreateKeyboard( UInt index )
{
	assert( index < _keyboards.Size() );

	if ( index >= _keyboards.Size() )
		throw OutOfRangeException( index, _keyboards.Size() );

	UInt idx = 0;
	for ( UInt i = 0; i < _guids.Size(); ++i )
	{
		if ( (_guids[i].Type == DI8DEVTYPE_KEYBOARD) && (idx++ == index) )
		{
			HWND wnd = (_windowSystem->GetFrameWindowCount() > 0) ? (HWND)(_windowSystem->GetFrameWindow(0)->GetHandle()) : nullptr;
			return new Di8Keyboard( _di8, _guids[i].Guid, wnd, _keyboards[index] );
		}
	}

	return nullptr;
}

void Di8InputSystem::AddDevice( const String& name )
{
	LogWarning( MessagePriority::Normal, Formatter::Format(Str::InputDeviceDetected, name) );
}

void Di8InputSystem::AddKeyboard( REFGUID guid, const String& name )
{
	IDirectInputDevice8* device = nullptr;
	if ( SUCCEEDED(_di8->CreateDevice(guid, &device, nullptr)) )
	{
		DIDEVCAPS caps;
		caps.dwSize = sizeof( caps );
		if ( SUCCEEDED(device->GetCapabilities(&caps)) )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::KeyboardDetected, name) );
			_guids.Add( DeviceGuid(guid, DI8DEVTYPE_KEYBOARD) );
			_keyboards.Add( KeyboardDesc(name, CastUInt(caps.dwButtons)) );
			device->Release();
		}
	}
}

void Di8InputSystem::AddMouse( REFGUID guid, const String& name )
{
	IDirectInputDevice8* device = nullptr;
	if ( SUCCEEDED(_di8->CreateDevice(guid, &device, nullptr)) )
	{
		DIDEVCAPS caps;
		caps.dwSize = sizeof( caps );
		if ( SUCCEEDED(device->GetCapabilities(&caps)) )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::MouseDetected, name) );
			_guids.Add( DeviceGuid(guid, DI8DEVTYPE_MOUSE) );
			_mice.Add( MouseDesc(name, CastUInt(caps.dwAxes), CastUInt(caps.dwButtons)) );
			device->Release();
		}
	}
}

void Di8InputSystem::AddJoystick( REFGUID guid, const String& name )
{
	IDirectInputDevice8* device = nullptr;
	if ( SUCCEEDED(_di8->CreateDevice(guid, &device, nullptr)) )
	{
		DIDEVCAPS caps;
		caps.dwSize = sizeof( caps );
		if ( SUCCEEDED(device->GetCapabilities(&caps)) )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::JoystickDetected, name) );
			_guids.Add( DeviceGuid(guid, DI8DEVTYPE_JOYSTICK) );
			_joysticks.Add( JoystickDesc(name, CastUInt(caps.dwAxes), CastUInt(caps.dwButtons), (caps.dwFlags & DIDC_FORCEFEEDBACK) != 0) );
			device->Release();
		}
	}
}


} // input


} // synkro
