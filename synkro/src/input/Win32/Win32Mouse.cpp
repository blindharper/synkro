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
// Purpose: Win32 mouse.
//==============================================================================
#include "config.h"
#include "Win32Mouse.h"
#include <windowsX.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace input
{


static Byte _buttons[4] = { 0, 0, 0, 0 };
static Int _axes[3] = { 0, 0, 0 };
static POINT _pt;

static LRESULT CALLBACK MouseHookProc( int nCode, WPARAM wParam, LPARAM lParam )
{
	if ( nCode < 0 )
	{
		// Do not process the message.
		return ::CallNextHookEx( nullptr, nCode, wParam, lParam );
	}

	POINT pt;
	MSLLHOOKSTRUCT* data = (MSLLHOOKSTRUCT*)lParam;
	switch ( wParam )
	{
		case WM_LBUTTONDOWN:	_buttons[0] = 0x80; break;
		case WM_LBUTTONUP:		_buttons[0] = 0x00; break;
		case WM_RBUTTONDOWN:	_buttons[1] = 0x80; break;
		case WM_RBUTTONUP:		_buttons[1] = 0x00; break;
		case WM_MBUTTONDOWN:	_buttons[2] = 0x80; break;
		case WM_MBUTTONUP:		_buttons[2] = 0x00; break;
		case WM_MOUSEMOVE:
			::GetCursorPos( &pt );
			_axes[0] = pt.x-_pt.x;
			_axes[1] = pt.y-_pt.y;
			_pt = pt;
			break;
		case WM_MOUSEWHEEL:		_axes[2] = data->mouseData/WHEEL_DELTA; break;
		default:				break;
	}

	return ::CallNextHookEx( nullptr, nCode, wParam, lParam );
}

Win32Mouse::Win32Mouse( const MouseDesc& desc ) :
	MouseImpl<IMouse>( desc ),
	_hookMouse( nullptr )
{
	::GetCursorPos( &_pt );
	_hookMouse = ::SetWindowsHookEx( WH_MOUSE_LL, (HOOKPROC)MouseHookProc, nullptr, 0 );
}

Win32Mouse::~Win32Mouse()
{
	::UnhookWindowsHookEx( _hookMouse );
}

Bool Win32Mouse::Update( Double delta )
{
	Copy( _state.Buttons, _buttons, 3 );
	Copy( _state.Axes, _axes, 3 );

	Zero( _buttons, sizeof(_buttons) );
	Zero( _axes, sizeof(_axes) );

	return true;
}


} // input


} // synkro
