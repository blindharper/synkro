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
// Purpose: Win32 host window implementation.
//==============================================================================
#include "config.h"
#include "Win32HostWindow.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace win
{


Win32HostWindow::Win32HostWindow( Pointer handle ) :
	WindowImpl<IHostWindow>( 0, 0, 0, 0 )
{
	_handle = handle;
	if ( ::IsWindow((HWND)_handle) == 0 )
		throw Exception( L"Invalid window handle." );

	HDC hdc = ::GetDC( (HWND)_handle );
	_dpi =::GetDeviceCaps( hdc, LOGPIXELSX );
	::ReleaseDC( (HWND)_handle, hdc );
}

void Win32HostWindow::Close()
{
	// Do nothing.
}

void Win32HostWindow::SetPosition( Int left, Int top )
{
	// Do nothing.
}

void Win32HostWindow::SetSize( UInt width, UInt height )
{
	// Do nothing.
}

Bool Win32HostWindow::Update()
{
	MSG msg;

	if ( ::PeekMessageW( &msg, 0, 0, 0, PM_NOREMOVE ) )
	{
		Bool gotMsg = true;

		while ( (msg.message != WM_QUIT) && gotMsg )
		{
			gotMsg = ::PeekMessageW( &msg, 0, 0, 0, PM_REMOVE ) != 0;
			if ( !::IsDialogMessageW((HWND)_handle, &msg) )
			{
				::TranslateMessage( &msg );
				::DispatchMessage( &msg );
			}
		}

		return (msg.message != WM_QUIT);
	}

	return true;
}

void Win32HostWindow::SetTitle( const String& title )
{
	Char buf[512] = {};
	::SetWindowTextW( (HWND)_handle, title.GetChars(0, 512, buf) );
	_title = title;
}

String Win32HostWindow::GetTitle() const
{
	return _title;
}


} // win


} // synkro
