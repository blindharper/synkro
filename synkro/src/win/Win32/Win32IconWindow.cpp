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
// Purpose: Win32 icon window implementation.
//==============================================================================
#include "config.h"
#include "Win32IconWindow.h"
#include <shellapi.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


// Window class name.
#define SYNKRO_WINDOW_CLASS L"Synkro.Win.Win32IconWindow"
#define WM_TRAYICONCALLBACK WM_USER+1
#define ID_TRAY_ICON 3000


namespace synkro
{


namespace win
{


static LRESULT CALLBACK wndProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{
	if ( WM_CREATE == msg )
	{
		LPCREATESTRUCT cs = (LPCREATESTRUCT)lp;
		::SetWindowLongPtrW( hwnd, GWLP_USERDATA, (LONG_PTR)cs->lpCreateParams ); // Assign 'this' pointer.
	}
	else
	{
		Win32IconWindow* wnd = (Win32IconWindow*)::GetWindowLongPtrW( hwnd, GWLP_USERDATA );
		if ( wnd )
		{
			try
			{
				return wnd->HandleMessage( msg, wp, lp );
			}
			catch ( ... )
			{
			}
		}
	}

	return ::DefWindowProcW( hwnd, msg, wp, lp );
}


Win32IconWindow::Win32IconWindow( UInt icon, const String& hint ) :
	IconWindowImpl<IIconWindow>( icon, hint ),
	_menu( nullptr ),
	_running( false )
{
	WNDCLASSEXW wcex;
	DWORD style = WS_POPUP;
	DWORD ex = 0;

	memset( &wcex, 0, sizeof(wcex) );
	wcex.cbSize			= sizeof(WNDCLASSEXW); 
	wcex.style			= CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= (WNDPROC)wndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= (HINSTANCE)::GetModuleHandle(NULL);
	wcex.hbrBackground	= (HBRUSH)::GetStockObject( DKGRAY_BRUSH );
	wcex.lpszClassName	= SYNKRO_WINDOW_CLASS;

	static Bool _registered = false;
	if ( !_registered )
	{
		if ( !::RegisterClassExW( &wcex ) )
		{
			throw Exception( L"Failed register window class." );
		}
		_registered = true;
	}

	_handle = (Pointer)::CreateWindowExW( ex, SYNKRO_WINDOW_CLASS, L"", style, 0, 0, 100, 100, (HWND)nullptr, 0, ::GetModuleHandle(NULL), (void*)this );
	if ( _handle == NULL )
	{
		::UnregisterClassW( SYNKRO_WINDOW_CLASS, ::GetModuleHandle(NULL) );
		throw Exception( L"Failed to create main window." );
	}

	// Create tray icon & popup menu.
	Char buf[512] = {};
	_menu = ::CreatePopupMenu();
	hint.GetChars( 0, 512, buf );
	NOTIFYICONDATAW nid;
	memset( &nid, 0, sizeof(nid) );
	nid.cbSize				= sizeof(nid);
	nid.hWnd				= (HWND)_handle;
	nid.uID					= ID_TRAY_ICON;
	nid.uFlags				= NIF_ICON | NIF_TIP | NIF_MESSAGE;
	nid.uCallbackMessage	= WM_TRAYICONCALLBACK;
	nid.hIcon				= (HICON)icon;
	wcscpy( nid.szTip, buf );
	::Shell_NotifyIconW( NIM_ADD, &nid );

	_running = true;
}

Win32IconWindow::~Win32IconWindow()
{
	Close();
}

Bool Win32IconWindow::Update()
{
	MSG msg;

	if ( _running && ::PeekMessageW(&msg, (HWND)_handle, 0, 0, PM_NOREMOVE) )
	{
		while ( (::PeekMessageW(&msg, (HWND)_handle, 0, 0, PM_REMOVE) != FALSE) )
		{
			::TranslateMessage( &msg );
			::DispatchMessageW( &msg );
		}
	}

	return _running;
}

void Win32IconWindow::Close()
{
	_running = false;
	if ( _handle != null )
	{
		NOTIFYICONDATAW nid;
		memset( &nid, 0, sizeof(nid) );
		nid.cbSize	= sizeof(nid);
		nid.hWnd	= (HWND)_handle;
		nid.uID		= ID_TRAY_ICON;
		::Shell_NotifyIconW( NIM_DELETE, &nid );
		::DestroyWindow( (HWND)_handle );
	}
}

void Win32IconWindow::SetPosition( Int left, Int top )
{
	// Do nothing.
}

void Win32IconWindow::SetSize( UInt width, UInt height )
{
	// Do nothing.
}

void Win32IconWindow::AddMenuItem( UInt id, UInt icon, const String& text )
{
	Char buf[512] = {};
	text.GetChars( 0, 512, buf );
	::AppendMenuW( _menu, text.IsNull() ? MF_SEPARATOR : MF_STRING, id, buf );

	MENUITEMINFO info;
	memset( &info, 0, sizeof(info) );
	info.cbSize		= sizeof(info);
	info.fMask		= MIIM_BITMAP;
	info.hbmpItem	= ::LoadBitmap( (HINSTANCE)::GetModuleHandle(NULL), MAKEINTRESOURCEW(icon) );
	::SetMenuItemInfoW( _menu, id, FALSE, &info );
}

void Win32IconWindow::SetIcon( UInt icon )
{
	// Call base implementation.
	IconWindowImpl<IIconWindow>::SetIcon( icon );

	NOTIFYICONDATAW nid;
	memset( &nid, 0, sizeof(nid) );
	nid.cbSize	= sizeof(nid);
	nid.uFlags	= NIF_ICON;
	nid.hWnd	= (HWND)_handle;
	nid.uID		= ID_TRAY_ICON;
	nid.hIcon	= (HICON)_icon;
	::Shell_NotifyIconW( NIM_MODIFY, &nid );
}

void Win32IconWindow::SetHint( const String& hint )
{
	// Call base implementation.
	IconWindowImpl<IIconWindow>::SetHint( hint );

	Char buf[512] = {};
	_hint.GetChars( 0, 512, buf );
	NOTIFYICONDATAW nid;
	memset( &nid, 0, sizeof(nid) );
	nid.cbSize	= sizeof(nid);
	nid.hWnd	= (HWND)_handle;
	nid.uID		= ID_TRAY_ICON;
	nid.uFlags	= NIF_TIP;
	wcscpy( nid.szTip, buf );
	::Shell_NotifyIconW( NIM_MODIFY, &nid );
}

LRESULT	Win32IconWindow::HandleMessage( UINT msg, WPARAM wp, LPARAM lp )
{
	POINT pt;

	switch( msg )
	{
		case WM_DESTROY:
		{
			_handle = 0;
			::PostQuitMessage( 0 );
			break;
		}

		case WM_TRAYICONCALLBACK:
			if ( (wp == ID_TRAY_ICON) && (lp == WM_RBUTTONDOWN) )
			{
				::GetCursorPos( &pt );
				::TrackPopupMenu( _menu, TPM_LEFTALIGN, pt.x, pt.y, 0, (HWND)_handle, nullptr );
			}
			return FALSE;

		case WM_COMMAND:
			FireCommandEvent( CastUInt(LOWORD(wp)) );
			return FALSE;
	}

	return ::DefWindowProcW( (HWND)_handle, msg, wp, lp );
}


} // win


} // synkro
