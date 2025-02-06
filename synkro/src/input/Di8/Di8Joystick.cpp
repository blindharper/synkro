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
#include "config.h"
#include "Di8Joystick.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Di8Joystick::Di8Joystick( IDirectInput8* di, REFGUID guid, HWND window, const JoystickDesc& desc ) :
	JoystickImpl<IJoystick>( desc )
{
	HRESULT hr = DI_OK;

	if ( FAILED(hr = di->CreateDevice(guid, &_device, nullptr)) )
		throw InputException( String::Format(Str::JoystickInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInput8::CreateDevice()"), Di8::ToString(hr) );

	if ( FAILED(hr = _device->SetDataFormat(&c_dfDIJoystick2)) )
		throw InputException( String::Format(Str::JoystickInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetDataFormat()"), Di8::ToString(hr) );

	const DWORD flags = (DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	if ( FAILED(hr = _device->SetCooperativeLevel(window, flags)) )
		throw InputException( String::Format(Str::JoystickInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetCooperativeLevel()"), Di8::ToString(hr) );

	_device->EnumObjects( ListJoystickAxes, (LPVOID)_device, DIDFT_AXIS );
}

Bool Di8Joystick::Update( Double delta )
{
	Bool ok = true;
	DIJOYSTATE2 state;

	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );

	if ( FAILED(_device->GetDeviceState(sizeof(DIJOYSTATE2), &state)) )
	{
		ok = false;
		if ( SUCCEEDED(_device->Acquire()) )
		{
			if ( SUCCEEDED(_device->Poll()) )
			{
				ok = SUCCEEDED( _device->GetDeviceState(sizeof(DIJOYSTATE2), &state) );
			}
		}
	}

	if ( ok )
	{
		Copy( _state.Buttons, state.rgbButtons, 32 );
		Copy( _state.Axes, (Int*)&state.lX, 3 );
	}

	return ok;
}

BOOL CALLBACK Di8Joystick::ListJoystickAxes( const DIDEVICEOBJECTINSTANCE* obj, LPVOID ref )
{
	IDirectInputDevice8* joystick = reinterpret_cast<IDirectInputDevice8*>( ref );

	if ( obj->dwType & DIDFT_AXIS )
	{
		DIPROPRANGE diprg; 
		diprg.diph.dwSize		= sizeof(DIPROPRANGE); 
		diprg.diph.dwHeaderSize	= sizeof(DIPROPHEADER); 
		diprg.diph.dwHow		= DIPH_BYID; 
		diprg.diph.dwObj		= obj->dwType;
		diprg.lMin				= 0; 
		diprg.lMax				= 0xffff; 

		// Set axis range.
		if ( FAILED(joystick->SetProperty(DIPROP_RANGE, &diprg.diph)) )
			return DIENUM_STOP;
	}

	return DIENUM_CONTINUE;
}


} // input


} // synkro
