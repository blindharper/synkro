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
// Purpose: Win32 view window implementation.
//==============================================================================
#include "config.h"
#include "Win32ViewWindow.h"
#include <win/IFrameWindow.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


// Window class name.
#define SYNKRO_WINDOW_CLASS L"Synkro.Win.Win32ViewWindow"


namespace synkro
{


namespace win
{


static LRESULT CALLBACK wndProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{
	return ::DefWindowProcW( hwnd, msg, wp, lp );
}

Win32ViewWindow::Win32ViewWindow( IFrameWindow* parent, Int left, Int top, UInt width, UInt height ) :
	ViewWindowImpl<IViewWindow>( parent, left, top, width, height )
{
	WNDCLASSEXW wcex;
	HINSTANCE instance = nullptr;
	const DWORD style = WS_CHILD | WS_VISIBLE;
	RECT rcWnd = { (LONG)left, (LONG)top, (LONG)(left+width), (LONG)(top+height) };

	memset( &wcex, 0, sizeof(wcex) );
	wcex.cbSize			= sizeof(WNDCLASSEXW); 
	wcex.style			= CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= (WNDPROC)wndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= (HINSTANCE)instance;
	wcex.hCursor		= ::LoadCursor( nullptr, IDC_ARROW );
	wcex.hbrBackground	= (HBRUSH)::GetStockObject( GRAY_BRUSH );
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= SYNKRO_WINDOW_CLASS;
	wcex.hIconSm		= 0;

	static Bool _registered = false;
	if ( !_registered )
	{
		if ( !::RegisterClassExW( &wcex ) )
		{
			throw Exception( L"Failed register Windows View Window class." );
		}
		_registered = true;
	}

	_handle = (Pointer)::CreateWindowExW( 0, SYNKRO_WINDOW_CLASS, L"", style, rcWnd.left, rcWnd.top, (rcWnd.right-rcWnd.left), (rcWnd.bottom-rcWnd.top), (HWND)parent->GetHandle(), 0, instance, nullptr );
	if ( !_handle )
	{
		::UnregisterClassW( SYNKRO_WINDOW_CLASS, instance );
		throw Exception( L"Failed to create Windows View Window." );
	}

	HDC hdc = ::GetDC( (HWND)_handle );
	_dpi =::GetDeviceCaps( hdc, LOGPIXELSX );
	::ReleaseDC( (HWND)_handle, hdc );
}

Win32ViewWindow::~Win32ViewWindow()
{
	Close();
}

void Win32ViewWindow::Close()
{
	if ( _handle != null )
	{
		::SendMessage( (HWND)_handle, WM_CLOSE, 0, 0 );
		_handle = null;
	}
}

void Win32ViewWindow::SetPosition( Int left, Int top )
{
	// Call base implementation.
	WindowImpl<IViewWindow>::SetPosition( left, top );

	::SetWindowPos( (HWND)_handle, 0, left, top, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}

void Win32ViewWindow::SetSize( UInt width, UInt height )
{
	// Call base implementation.
	WindowImpl<IViewWindow>::SetSize( width, height );

	::SetWindowPos( (HWND)_handle, 0, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER );
}

void Win32ViewWindow::Show( Bool show )
{
	// Call base implementation.
	ViewWindowImpl<IViewWindow>::Show( show );

	::ShowWindow( (HWND)_handle, show ? SW_SHOWNORMAL : SW_HIDE );
}


} // win


} // synkro
