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
// Purpose: DirectInput 8 keyboard.
//==============================================================================
#include "config.h"
#include "Di8Keyboard.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


Di8Keyboard::Di8Keyboard( IDirectInput8* di, REFGUID guid, HWND window, const KeyboardDesc& desc ) :
	KeyboardImpl<IKeyboard>( desc )
{
	HRESULT hr = DI_OK;

	if ( FAILED(hr = di->CreateDevice(guid, &_device, nullptr)) )
		throw InputException( String::Format(Str::KeyboardInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInput8::CreateDevice()"), Di8::ToString(hr) );

	if ( FAILED(hr = _device->SetDataFormat(&c_dfDIKeyboard)) )
		throw InputException( String::Format(Str::KeyboardInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetDataFormat()"), Di8::ToString(hr) );

	const DWORD flags = (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if ( FAILED(hr = _device->SetCooperativeLevel(window, flags)) )
		throw InputException( String::Format(Str::KeyboardInitFail, desc.Name), String::Format(Str::CallFail, L"IDirectInputDevice8::SetCooperativeLevel()"), Di8::ToString(hr) );

	_device->EnumObjects( ListKeys, (LPVOID)this, DIDFT_BUTTON );
}

Bool Di8Keyboard::Update( Double delta )
{
	HRESULT hr = S_OK;

	Zero( _state.Keys, sizeof(_state.Keys) );
	if ( FAILED(hr = _device->GetDeviceState(sizeof(_state.Keys), (LPVOID)_state.Keys)) )
	{
		if ( SUCCEEDED(hr = _device->Acquire()) )
		{
			return SUCCEEDED(hr = _device->GetDeviceState(sizeof(_state.Keys), (LPVOID)_state.Keys) );
		}
		return false;
	}
	return true;
}

char Di8Keyboard::ToChar( Byte code, Bool shift ) const
{
	static HKL layout = ::GetKeyboardLayout( 0 );
	static BYTE state[256] = {};

	if ( ::GetKeyboardState(state) == FALSE )
		return 0;

	state[VK_SHIFT] = shift ? 0xff : 0x00;
	::SetKeyboardState( state );

	WORD result;
	const UINT vk = ::MapVirtualKeyExA( code, 1, layout );
	const int ret = ::ToAsciiEx( vk, code, state, &result, 0, layout );
	return (ret != 0) ? (char)(result & 0xff) : (char)0;
}

BOOL CALLBACK Di8Keyboard::ListKeys( const DIDEVICEOBJECTINSTANCE* obj, LPVOID ref )
{
	return DIENUM_CONTINUE;
}


} // input


} // synkro
