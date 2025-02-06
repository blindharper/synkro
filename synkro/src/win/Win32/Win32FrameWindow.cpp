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
// Purpose: Win32 frame window implementation.
//==============================================================================
#include "config.h"
#include "Win32FrameWindow.h"
#include <win/IMonitor.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


// Window class name.
#define SYNKRO_WINDOW_CLASS L"Synkro.Win.Win32FrameWindow"


namespace synkro
{


namespace win
{


static LRESULT CALLBACK wndProc( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp )
{
	if ( msg == WM_CREATE )
	{
		LPCREATESTRUCT cs = (LPCREATESTRUCT)lp;
		::SetWindowLongPtrW( hwnd, GWLP_USERDATA, (LONG_PTR)cs->lpCreateParams );
	}
	else
	{
		Win32FrameWindow* wnd = (Win32FrameWindow*)::GetWindowLongPtrW( hwnd, GWLP_USERDATA );
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


Win32FrameWindow::Win32FrameWindow( Bool popup, Bool sizeable, const String& title, UInt icon, UInt width, UInt height ) :
	FrameWindowImpl<IFrameWindow>( popup, sizeable, true, title, icon, width, height )
{
	Create( popup, sizeable, title, icon, 0, 0, width, height );
}

Win32FrameWindow::Win32FrameWindow( IMonitor* monitor ) :
	FrameWindowImpl<IFrameWindow>( monitor )
{
	Point location; monitor->GetLocation( location );
	Size size; monitor->GetSize( size );
	Create( true, false, String::Empty, 0, location.X, location.Y, size.Width, size.Height );
}

Win32FrameWindow::~Win32FrameWindow()
{
	Close();
}

Bool Win32FrameWindow::Update()
{
	MSG msg;

	_closing = false;

	if ( ::PeekMessageW( &msg, 0, 0, 0, PM_NOREMOVE ) )
	{
		Bool gotMsg = true;

		while ( (msg.message != WM_QUIT) && gotMsg )
		{
			gotMsg = _active ? ::PeekMessageW( &msg, 0, 0, 0, PM_REMOVE ) != 0 :
								::GetMessageW( &msg, nullptr, 0, 0 ) != 0;
			::TranslateMessage( &msg );
			::DispatchMessage( &msg );
		}

		return (msg.message != WM_QUIT);
	}

	return true;
}

void Win32FrameWindow::Close()
{
	if ( _handle != null )
	{
		::SetWindowLongPtrW( (HWND)_handle, GWLP_USERDATA, (LONG_PTR)0 );
		::SendMessage( (HWND)_handle, WM_CLOSE, 0, 0 );
		_handle = null;
	}
}

void Win32FrameWindow::SetPosition( Int left, Int top )
{
	// Call base implementation.
	WindowImpl<IFrameWindow>::SetPosition( left, top );

	::SetWindowPos( (HWND)_handle, 0, left, top, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}

void Win32FrameWindow::SetSize( UInt width, UInt height )
{
	// Call base implementation.
	WindowImpl<IFrameWindow>::SetSize( width, height );

	::SetWindowPos( (HWND)_handle, 0, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER );
}

void Win32FrameWindow::Center()
{
	Int left = 0; Int top = 0;
	const UInt width = GetWidth();
	const UInt height = GetHeight();

	const UInt screenWidth = (UInt)::GetSystemMetrics( SM_CXSCREEN );
	if ( width < screenWidth )
		left = (screenWidth - width)/2;

	const UInt screenHeight = (UInt)::GetSystemMetrics( SM_CYSCREEN );
	if ( height < screenHeight )
		top = (screenHeight - height)/2;

	SetPosition( left, top );
}

void Win32FrameWindow::Activate()
{
	::SetForegroundWindow( (HWND)_handle );
}

void Win32FrameWindow::SetPopup( Bool popup )
{
	if ( popup != _popup )
	{
		RECT rcWnd;
		::GetWindowRect( (HWND)_handle, &rcWnd );
		const DWORD style = popup ? WS_POPUP : WS_BORDER | WS_SYSMENU | (_sizeable ? WS_THICKFRAME : WS_DLGFRAME);
		const DWORD ex = popup ? WS_EX_TOPMOST : 0;
	
		if ( popup )
		{
			rcWnd.right -= rcWnd.left;
			rcWnd.bottom -= rcWnd.top;
			rcWnd.left = 0; rcWnd.top = 0;
			::AdjustWindowRectEx( &rcWnd, style, FALSE, ex );
		}
		else
		{
			const UInt captionHeight = (UInt)::GetSystemMetrics( SM_CYCAPTION );
			rcWnd.bottom += (captionHeight + 16);
			rcWnd.right += 16;
		}

		::SetWindowLong( (HWND)_handle, GWL_EXSTYLE, ex );
		::SetWindowLong( (HWND)_handle, GWL_STYLE, style );
		::SetWindowPos( (HWND)_handle, HWND_TOP, rcWnd.left, rcWnd.top, (rcWnd.right-rcWnd.left),
						(rcWnd.bottom-rcWnd.top), SWP_NOZORDER|SWP_SHOWWINDOW );

		::ShowCursor( popup ? FALSE : TRUE );
		_popup = popup;
	}
}

void Win32FrameWindow::SetTitle( const String& title )
{
	Char buf[512] = {};
	::SetWindowTextW( (HWND)_handle, title.GetChars(0, 512, buf) );
}

void Win32FrameWindow::Create( Bool popup, Bool sizeable, const String& title, UInt icon, Int left, Int top, UInt width, UInt height )
{
	Char buf[512] = {};
	WNDCLASSEXW wcex;
	HINSTANCE instance = nullptr;
	const DWORD style = popup ? WS_POPUP : WS_BORDER | WS_SYSMENU | (sizeable ? WS_THICKFRAME : WS_DLGFRAME);
	const DWORD ex = popup ? WS_EX_TOPMOST : 0;
	if ( !popup )
	{
		const UInt captionHeight = (UInt)::GetSystemMetrics( SM_CYCAPTION );
		height += captionHeight;
	}
	RECT rcWnd = { (LONG)left, (LONG)top, (LONG)width, (LONG)height };

	if ( popup )
	{
		::AdjustWindowRectEx( &rcWnd, style, FALSE, ex );
		::ShowCursor( FALSE );
	}

	memset( &wcex, 0, sizeof(wcex) );
	wcex.cbSize			= sizeof(WNDCLASSEXW); 
	wcex.style			= CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc	= (WNDPROC)wndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= (HINSTANCE)instance;
	wcex.hCursor		= ::LoadCursor( null, IDC_ARROW );
	wcex.hbrBackground	= (HBRUSH)::GetStockObject( BLACK_BRUSH );
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= SYNKRO_WINDOW_CLASS;
	wcex.hIcon			= (HICON)icon;
	wcex.hIconSm		= (HICON)icon;

	static Bool _registered = false;
	if ( !_registered )
	{
		if ( !::RegisterClassExW( &wcex ) )
		{
			throw Exception( L"Failed to register Windows Frame Window class." );
		}
		_registered = true;
	}

	_handle = (Pointer)::CreateWindowEx( ex, SYNKRO_WINDOW_CLASS, title.GetChars(0, 512, buf), style, rcWnd.left, rcWnd.top, (rcWnd.right-rcWnd.left), (rcWnd.bottom-rcWnd.top), 0, 0, instance, (void*)this );
	if ( _handle == null )
	{
		::UnregisterClassW( SYNKRO_WINDOW_CLASS, instance );
		throw Exception( L"Failed to create Windows Frame Window." );
	}

	_left = left; _top = top; _width = width; _height = height;
	if ( !_popup ) { Center(); }

	HDC hdc = ::GetDC( (HWND)_handle );
	_dpi =::GetDeviceCaps( hdc, LOGPIXELSX );
	::ReleaseDC( (HWND)_handle, hdc );
	
	::ShowWindow( (HWND)_handle, SW_SHOWNORMAL );
	::UpdateWindow( (HWND)_handle );
}

LRESULT	Win32FrameWindow::HandleMessage( UINT msg, WPARAM wp, LPARAM lp )
{
	switch( msg )
	{
		case WM_DESTROY:
		{
			_handle = 0;
			::ShowCursor( TRUE );
			::PostQuitMessage( 0 );
			break;
		}

		case WM_ACTIVATE:
		{
			_active = ( LOWORD(wp) != WA_INACTIVE );
		}
		return FALSE;

		case WM_CLOSE:
		{
			_closing = true;
		}
		return FALSE;

		case WM_SIZE:
		{
			RECT rc;
			if ( ::GetClientRect((HWND)_handle, &rc) == TRUE )
			{
				_left = CastInt(rc.left);
				_top = CastInt(rc.top);
				_width = (UInt)(rc.right - rc.left);
				_height = (UInt)(rc.bottom - rc.top);
			}
		}
		return FALSE;

		case WM_KEYDOWN:
		{
			if ( wp == VK_ESCAPE )
			{
				_closing = true;
			}
		}
		return FALSE;
	}

	return ::DefWindowProcW( (HWND)_handle, msg, wp, lp );
}

//------------------------------------------------------------------------------

Win32FrameWindowStub::Win32FrameWindowStub( Pointer handle ) :
	FrameWindowImpl<IFrameWindow>( false, false, false, L"", 0, 0, 0 )
{
	_handle = handle;
	if ( ::IsWindow((HWND)_handle) == 0 )
		throw Exception( L"Invalid window handle." );

	HDC hdc = ::GetDC( (HWND)_handle );
	_dpi =::GetDeviceCaps( hdc, LOGPIXELSX );
	::ReleaseDC( (HWND)_handle, hdc );
}

void Win32FrameWindowStub::Close()
{
	// Do nothing.
}

void Win32FrameWindowStub::SetPosition( Int left, Int top )
{
	// Do nothing.
}

void Win32FrameWindowStub::SetSize( UInt width, UInt height )
{
	// Do nothing.
}

Bool Win32FrameWindowStub::Update()
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

void Win32FrameWindowStub::Center()
{
	Int left = 0; Int top = 0;
	const UInt width = GetWidth();
	const UInt height = GetHeight();

	const UInt screenWidth = (UInt)::GetSystemMetrics( SM_CXSCREEN );
	if ( width < screenWidth )
		left = (screenWidth - width)/2;

	const UInt screenHeight = (UInt)::GetSystemMetrics( SM_CYSCREEN );
	if ( height < screenHeight )
		top = (screenHeight - height)/2;

	SetPosition( left, top );
}

void Win32FrameWindowStub::Activate()
{
	// Do nothing.
}

void Win32FrameWindowStub::SetPopup( Bool popup )
{
	// Do nothing.
}

void Win32FrameWindowStub::SetTitle( const String& title )
{
	Char buf[512] = {};
	::SetWindowTextW( (HWND)_handle, title.GetChars(0, 512, buf) );
}


} // win


} // synkro
