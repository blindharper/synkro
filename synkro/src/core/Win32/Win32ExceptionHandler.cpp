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
// Purpose: Visual exception handler for Windows.
//==============================================================================
#include "config.h"
#include "Win32ExceptionHandler.h"
#include <core/ISynkro.h>
#include <core/Version.h>
#include <core/CallStack.h>
#include <io/Path.h>
#include <shellapi.h>
#include <resource.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

struct SendParam
{
	HWND Dlg;
	Char Url[4096];
};
static SendParam _param;

static INT_PTR CALLBACK ExceptionHandlerProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
	INT_PTR bResult = FALSE;

	switch ( msg )
	{
		case WM_INITDIALOG:
			Win32ExceptionHandler::Init( hDlg );
			bResult = FALSE;
			break;

		case WM_NOTIFY:
			switch ( ((NMHDR*)lParam)->idFrom )
			{
				case IDC_LINK:
					switch ( ((NMHDR*)lParam)->code )
					{
						case NM_CLICK:
						{
							Win32ExceptionHandler::OpenUrl( ((NMLINK*)lParam)->item.szUrl );
							bResult = FALSE;
						}
					}
					break;
			}
			return FALSE;

		case WM_COMMAND:
			switch ( LOWORD(wParam) )
			{
				case IDCANCEL:
				{
					Win32ExceptionHandler::OnButtonPress( LOWORD(wParam) );
				}
				break;
			}
			bResult = TRUE;
			break;

		case WM_DESTROY:
			::PostQuitMessage( 0 );
			return FALSE;

		case WM_CLOSE:
			::EndDialog( hDlg, 0 );
			return FALSE;
	}
	return bResult;
}

static int CALLBACK CompareItems( LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort )
{
	const Int index1 = CastInt(lParam1);
	const Int index2 = CastInt(lParam2);
	return index1 - index2;
}


//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


HINSTANCE Win32ExceptionHandler::_module = nullptr;
HWND Win32ExceptionHandler::_handle = nullptr;
HWND Win32ExceptionHandler::_list = nullptr;
Char Win32ExceptionHandler::_version[1024];
Char Win32ExceptionHandler::_message[1024];

void Win32ExceptionHandler::Initialize( Pointer module, ISynkro* synkro )
{
	_module = (HINSTANCE)module;
	String version = String::Format( L"Synkro {0}", Version::Current.ToString() );
	version.GetChars( 0, 1024, _version );
}

void Win32ExceptionHandler::Init( HWND handle )
{
	_handle = handle;
	_list = ::GetDlgItem( _handle, IDC_CALLS );

	// Set program icon.
	HICON hIcon = ::LoadIcon( _module, MAKEINTRESOURCE(IDI_SYNKRO) );
	::SendMessage( _handle, WM_SETICON, (WPARAM)ICON_BIG, (LPARAM)hIcon );

	// Display current library version.
	::SendDlgItemMessageW( _handle, IDC_VERSION, WM_SETTEXT, (WPARAM)0, (LPARAM)_version );

	// Set error message.
	::SetDlgItemText( _handle, IDC_MESSAGE, _message );

	// Determine dialog scale.
	HDC hdc = ::GetDC( _handle );
	Float scale = CastFloat(::GetDeviceCaps(hdc, LOGPIXELSX)) / 96.0f;
	::ReleaseDC( _handle, hdc );

	// Initialize call stack list.
	::SendMessageW( _list, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );
	AddListViewColumn( _list, 0, L"Call", 300*scale );
	AddListViewColumn( _list, 1, L"File", 200*scale );
	AddListViewColumn( _list, 2, L"Line", 40*scale );
	AddListViewColumn( _list, 3, L"Context", 146*scale );

	Int index = 0;
	CallItem call;
	while ( CallStack::GetCall(call) )
	{
		Path pathName( call.File );
		String parent = pathName.GetParent();
		Path pathParent( parent );
		AddListViewItem( _list, index++, call.Name, String::Format(L"{0}/{1}", pathParent.GetName(), pathName.GetName()), String::Format(L"{0}", call.Line), call.Context );
	}

	// Sort calls cause they are inserted in the reverse order.
	::SendMessageW( _list, LVM_SORTITEMS, 0, (LPARAM)CompareItems );

	// Play notification sound.
	::MessageBeep( MB_ICONHAND );
}

void Win32ExceptionHandler::Show( const String& message )
{
	message.GetChars( 0, 1024, _message );

	// Register common controls.
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof( icc );
	icc.dwICC = ICC_LINK_CLASS;
	::InitCommonControlsEx( &icc );

	// Create handler window.
	::DialogBoxParamW( _module, MAKEINTRESOURCEW(IDD_EXCEPTIONHANDLER), ::GetForegroundWindow(), ExceptionHandlerProc, (LPARAM)nullptr );
}

void Win32ExceptionHandler::OpenUrl( const WCHAR* url )
{
	SHELLEXECUTEINFOW sei;
	memset( &sei, 0, sizeof(sei) );
	sei.cbSize = sizeof(sei);
	sei.lpVerb = L"open";
	sei.lpFile = url;
	::ShellExecuteExW( &sei );
}

void Win32ExceptionHandler::OnButtonPress( WORD button )
{
	switch ( button )
	{
		case IDCANCEL:
			::EndDialog( _handle, 0 );
			break;
	}
}

void Win32ExceptionHandler::AddListViewColumn( HWND handle, Int index, const String& name, Int width )
{
	Char buf[260] = {};
	LVCOLUMNW lvc;

	memset( &lvc, 0, sizeof(lvc) );
	lvc.mask	= LVCF_TEXT | LVCF_WIDTH;
	lvc.cx		= width;
	lvc.pszText	= (LPWSTR)name.GetChars(0, 260, buf);
	::SendMessageW( handle, LVM_INSERTCOLUMNW, index, (LPARAM)&lvc );
}

void Win32ExceptionHandler::AddListViewItem( HWND handle, Int index, const String& call, const String& file, const String& line, const String& context )
{
	Char buf[260] = {};
	LVITEMW lvi;

	// Add parameter function name.
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask		= LVIF_TEXT | LVIF_PARAM;
	lvi.iItem		= 0;
	lvi.lParam		= index;
	lvi.pszText		= (LPWSTR)call.GetChars(0, 260, buf);
	index = (Int)::SendMessageW( handle, LVM_INSERTITEMW, 0, (LPARAM)&lvi );

	// Add file name.
	if ( !file.IsEmpty() )
	{
		memset( &lvi, 0, sizeof(lvi) );
		lvi.mask		= LVIF_TEXT;
		lvi.iItem		= index;
		lvi.iSubItem	= 1;
		lvi.pszText		= (LPWSTR)file.GetChars(0, 260, buf);
		::SendMessageW( handle, LVM_SETITEMW, 0, (LPARAM)&lvi );
	}

	// Add line number.
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask		= LVIF_TEXT;
	lvi.iItem		= index;
	lvi.iSubItem	= 2;
	lvi.pszText		= (LPWSTR)line.GetChars(0, 260, buf);
	::SendMessageW( handle, LVM_SETITEMW, 0, (LPARAM)&lvi );

	// Add context.
	if ( !context.IsEmpty() )
	{
		memset( &lvi, 0, sizeof(lvi) );
		lvi.mask		= LVIF_TEXT;
		lvi.iItem		= index;
		lvi.iSubItem	= 3;
		lvi.pszText		= (LPWSTR)context.GetChars(0, 260, buf);
		::SendMessageW( handle, LVM_SETITEMW, 0, (LPARAM)&lvi );
	}
}


} // core


} // synkro
