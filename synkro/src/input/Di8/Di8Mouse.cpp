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
#include "config.h"
#include "Di8Mouse.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Di8Mouse::Di8Mouse( IDirectInput8* di, REFGUID guid, HWND window, const MouseDesc& desc ) :
	MouseImpl<IMouse>( desc )
{
	HRESULT hr = DI_OK;

	if ( FAILED(hr = di->CreateDevice(guid, &_device, nullptr)) )
		throw InputException( String::Format(Str::MouseInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInput8::CreateDevice()"), Di8::ToString(hr) );

	if ( FAILED(hr = _device->SetDataFormat(&c_dfDIMouse2)) )
		throw InputException( String::Format(Str::MouseInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetDataFormat()"), Di8::ToString(hr) );

	const DWORD flags = (DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	if ( FAILED(hr = _device->SetCooperativeLevel(window, flags)) )
		throw InputException( String::Format(Str::MouseInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetCooperativeLevel()"), Di8::ToString(hr) );
}

Bool Di8Mouse::Update( Double delta )
{
	Bool ok = true;
	DIMOUSESTATE2 state;

	Zero( _state.Buttons, sizeof(_state.Buttons) );
	Zero( _state.Axes, sizeof(_state.Axes) );

	if ( FAILED(_device->GetDeviceState(sizeof(DIMOUSESTATE2), &state)) )
	{
		ok = false;
		if ( SUCCEEDED(_device->Acquire()) )
		{
			ok = SUCCEEDED( _device->GetDeviceState(sizeof(DIMOUSESTATE2), &state) );
		}
	}

	if ( ok )
	{
		Copy( _state.Buttons, state.rgbButtons, 5 );
		Copy( _state.Axes, (Int*)&state.lX, 3 );
	}

	return ok;
}


} // input


} // synkro
