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
// Purpose: Configuration editor for Windows.
//==============================================================================
#include "config.h"
#include "Win32ConfigurationEditor.h"
#include <lang/Vector.h>
#include <lang/Convert.h>
#include <core/ConfigurationException.h>
#include <core/ISynkro.h>
#include <core/Version.h>
#include <core/Param.h>
#include <shellapi.h>
#include <resource.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------

static WNDPROC OrgListProc = nullptr;
static Bool listKeyDownProcessed = false;

static LRESULT CALLBACK ParamListProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	HWND hTmp = nullptr;
	Char text[1024] = {};
	char buf[260] = {};
	int pos = 0;

	switch ( msg )
	{
		case WM_KEYDOWN:
			if ( listKeyDownProcessed )
			{
				listKeyDownProcessed = false;
				return TRUE;
			}
			else
			{
				listKeyDownProcessed = true;
				break;
			}

		case WM_COMMAND:
			switch ( HIWORD(wParam) )
			{
				case CBN_DROPDOWN:
					break;

				case CBN_CLOSEUP:
					Win32ConfigurationEditor::EndEditing( true );
					break;
			}
			break;

		case WM_NOTIFY:
			LPNMHDR pNMHdr = (LPNMHDR)lParam;
			switch ( pNMHdr->code )
			{
				case UDN_DELTAPOS:
				{
					LPNMUPDOWN pNMUpDown = (LPNMUPDOWN)lParam;
					hTmp = (HWND)::GetWindowLongPtr( pNMUpDown->hdr.hwndFrom, GWLP_USERDATA );
					sprintf( buf, "%d", pNMUpDown->iDelta+pNMUpDown->iPos );
					::SendMessage( pNMUpDown->hdr.hwndFrom, UDM_SETPOS32, 0, pNMUpDown->iPos );
	
					pos = pNMUpDown->iDelta+pNMUpDown->iPos;
					if ( pos < 0 )
						pos = 0;

					if ( pos > 100 )
						pos = 100;

					Convert::ToString( pos ).GetChars( 0, 1024, text );
					::SetWindowTextW( hTmp, text );
				}
				break;
			}
			return FALSE;
	}

	return ::CallWindowProc( OrgListProc, hWnd, msg, wParam, lParam );
}

static WNDPROC OrgComboboxProc = nullptr;
static Bool comboboxKeyDownProcessed = false;

static LRESULT CALLBACK ParamComboboxProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch ( msg )
	{
		case WM_KEYDOWN:
			if ( comboboxKeyDownProcessed )
			{
				comboboxKeyDownProcessed = false;
				return TRUE;
			}
			else
			{
				comboboxKeyDownProcessed = true;
				break;
			}
	}

	return ::CallWindowProc( OrgComboboxProc, hWnd, msg, wParam, lParam );
}

static INT_PTR CALLBACK ConfigurationEditorProc( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
	INT_PTR bResult = FALSE;

	switch ( msg )
	{
		case WM_NOTIFY:
			switch ( ((NMHDR*)lParam)->idFrom )
			{
				case IDC_PARAMLIST:
					switch ( ((NMHDR*)lParam)->code )
					{
						case LVN_ITEMCHANGING:
						{
							bResult = FALSE;
							break;
						}

						case LVN_ITEMCHANGED:
						{
							const UInt activeParam = (UInt)(((NMLISTVIEW*)lParam)->iItem);
							Win32ConfigurationEditor::DisplayHint( activeParam );
						}
						break;

						case NM_RCLICK:
						{
							Win32ConfigurationEditor::EndEditing( true );
							bResult = FALSE;
							break;
						}

						case NM_CLICK:
						{
							Win32ConfigurationEditor::EndEditing( true );
							if ( (UInt)(((NMITEMACTIVATE*)lParam)->iSubItem) == 1 )
							{
								const UInt activeParam = (UInt)(((NMITEMACTIVATE*)lParam)->iItem);
								Win32ConfigurationEditor::BeginEditing( activeParam );
							}
							bResult = FALSE;
							break;
						}

						case NM_DBLCLK:
						{
							if ( (UInt)(((NMITEMACTIVATE*)lParam)->iSubItem) == 0 )
							{
								const UInt activeParam = (UInt)(((NMITEMACTIVATE*)lParam)->iItem);
								Win32ConfigurationEditor::CycleValue( activeParam );
							}
							bResult = FALSE;
							break;
						}
					}
					break;

				case IDC_LINK:
					switch ( ((NMHDR*)lParam)->code )
					{
						case NM_CLICK:
						{
							Win32ConfigurationEditor::OpenUrl( ((NMLINK*)lParam)->item.szUrl );
							bResult = FALSE;
							break;
						}
					}
					break;
			}
			return FALSE;

		case WM_COMMAND:
			if ( HIWORD(wParam) == BN_SETFOCUS )
			{
				Win32ConfigurationEditor::DisplayHint( none );
				bResult = FALSE;
				break;
			}
			else
			{
				switch ( LOWORD(wParam) )
				{
					case IDB_RUN: case IDCANCEL:
					{
						Win32ConfigurationEditor::OnButtonPress( LOWORD(wParam) );
					}
					break;
				}
			}
			bResult = TRUE;
			break;

		case WM_DESTROY:
			::PostQuitMessage( 0 );
			return FALSE;

		case WM_CLOSE:
			::DestroyWindow( hDlg );
			return FALSE;
	}
	return bResult;
}


//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ISynkro* Win32ConfigurationEditor::_synkro = nullptr;
HINSTANCE Win32ConfigurationEditor::_module = nullptr;
HWND Win32ConfigurationEditor::_handle = nullptr;
HWND Win32ConfigurationEditor::_list = nullptr;
HWND Win32ConfigurationEditor::_editor = nullptr;
HWND Win32ConfigurationEditor::_editor2 = nullptr;
HIMAGELIST Win32ConfigurationEditor::_images = nullptr;
HFONT Win32ConfigurationEditor::_fontParam = nullptr;
HFONT Win32ConfigurationEditor::_fontHint = nullptr;
IConfiguration* Win32ConfigurationEditor::_config = nullptr;
Float Win32ConfigurationEditor::_scale = 1.0f;
Bool Win32ConfigurationEditor::_result = false;

Pointer Win32ConfigurationEditor::Initialize( Pointer module, ISynkro* synkro )
{
	_module = (HINSTANCE)module;

	// Register common controls.
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof( icc );
	icc.dwICC = ICC_LINK_CLASS | ICC_UPDOWN_CLASS;
	::InitCommonControlsEx( &icc );

	// Create editor window.
	_synkro = synkro;
	_handle = ::CreateDialogParamW( _module, MAKEINTRESOURCEW(IDD_CONFIGEDITOR), nullptr, ConfigurationEditorProc, (LPARAM)nullptr );

	// Save window handles.
	_list = ::GetDlgItem( _handle, IDC_PARAMLIST );

	// Set program icon.
	HICON hIcon = ::LoadIcon( _module, MAKEINTRESOURCE(IDI_SYNKRO) );
	::SendMessage( _handle, WM_SETICON, (WPARAM)ICON_BIG, (LPARAM)hIcon );

	// Determine dialog scale.
	HDC hdc = ::GetDC( _handle );
	_scale = CastFloat(::GetDeviceCaps(hdc, LOGPIXELSX)) / 96.0f;
	::ReleaseDC( _handle, hdc );

	// Create control fonts.
	_fontParam = CreateParamFont();
	::SendDlgItemMessageW( _handle, IDC_PARAM, WM_SETFONT, (WPARAM)_fontParam, (LPARAM)TRUE );
	_fontHint = CreateHintFont();
	::SendDlgItemMessageW( _handle, IDC_HINT, WM_SETFONT, (WPARAM)_fontHint, (LPARAM)TRUE );

	// Display current library version.
	Char text[1024] = {};
	String version = String::Format( L"Synkro {0}", Version::Current.ToString() );
	version.GetChars( 0, 1024, text );
	::SendDlgItemMessageW( _handle, IDC_VERSION, WM_SETTEXT, (WPARAM)0, (LPARAM)text );

	// Initialize parameter list.
	::SendMessageW( _list, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT );
	OrgListProc = (WNDPROC)::SetWindowLongPtr( _list, GWLP_WNDPROC, (LONG_PTR)ParamListProc );
	AddListViewColumn( _list, 0, L"Parameter", 150*_scale );
	AddListViewColumn( _list, 1, L"Value", 246*_scale );

	return (Pointer)_handle;
}

void Win32ConfigurationEditor::Show( IConfiguration* config )
{
	_config = config;

	InitParamList();
	::SetFocus( _list );

	// Clear parameter name & description.
	DisplayHint( none );

	// Show editor window.
	::ShowWindow( _handle, SW_SHOW );
}

void Win32ConfigurationEditor::Finalize()
{
	if ( _fontParam != nullptr )
		::DeleteObject( _fontParam );

	if ( _fontHint != nullptr )
		::DeleteObject( _fontHint );

	if ( _images != nullptr )
		::ImageList_Destroy( _images );
}

void Win32ConfigurationEditor::OpenUrl( const WCHAR* url )
{
	SHELLEXECUTEINFOW sei;
	memset( &sei, 0, sizeof(sei) );
	sei.cbSize = sizeof(sei);
	sei.lpVerb = L"open";
	sei.lpFile = url;
	::ShellExecuteExW( &sei );
}

void Win32ConfigurationEditor::DisplayHint( const Param* param )
{
	Char name[1024] = {};
	Char desc[1024] = {};

	if ( param != nullptr )
	{
		param->Name.GetChars( 0, 1024, name );
		param->Description.GetChars( 0, 1024, desc );
	}

	::SetDlgItemTextW( _handle, IDC_PARAM, param ? name : L"" );
	::SetDlgItemTextW( _handle, IDC_HINT, param ? desc : L"" );
}

void Win32ConfigurationEditor::DisplayHint( UInt idxParam )
{
	const Param* param = nullptr;

	if ( idxParam != none )
	{
		Char buf[128] = {};
		LVITEM lvi;
		memset( &lvi, 0, sizeof(lvi) );
		lvi.mask = LVIF_TEXT;
		lvi.iSubItem = 0;
		lvi.pszText = (LPWSTR)buf;
		lvi.cchTextMax = 128;
		::SendMessage( _list, LVM_GETITEMTEXT, (WPARAM)idxParam, (LPARAM)&lvi );
		param = _config->GetParam( String(lvi.pszText) );
	}

	DisplayHint( param );
}

void Win32ConfigurationEditor::BeginEditing( UInt idxParam )
{
	Char buf[128] = {};
	LVITEM lvi;
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask = LVIF_TEXT;
	lvi.iSubItem = 0;
	lvi.pszText = (LPWSTR)buf;
	lvi.cchTextMax = 128;
	UInt len = (UInt)::SendMessage( _list, LVM_GETITEMTEXT, (WPARAM)idxParam, (LPARAM)&lvi );

	const Param* param = _config->GetParam( String(lvi.pszText) );
	if ( param != nullptr )
	{
		RECT rc;
		ListView_GetSubItemRect( _list, idxParam, 1, LVIR_BOUNDS, &rc );
		HFONT font = (HFONT)::SendMessageW( _handle, WM_GETFONT, (WPARAM)0, (LPARAM)0 );

		if ( param->Type == ParamType::Boolean )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_COMBOBOXW, L"", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | CBS_HASSTRINGS | CBS_DROPDOWNLIST, rc.left+1, rc.top-3, CastInt(rc.right-rc.left-1), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG_PTR)idxParam );

			::SendMessageW( _editor, CB_ADDSTRING, 0, (LPARAM)L"false" );
			::SendMessageW( _editor, CB_ADDSTRING, 0, (LPARAM)L"true" );
			
			Bool value; _config->Get( param->Name, &value );
			::SendMessageW( _editor, CB_SETCURSEL, (WPARAM)(value ? 1 : 0), 0 );
			::SetFocus( _editor );
		}
		else if ( param->Type == ParamType::Integer )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_EDITW, L"0", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | ES_NUMBER | ES_RIGHT | ES_AUTOHSCROLL, rc.left+3, rc.top, CastInt(rc.right-rc.left-16), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG_PTR)idxParam );

			_editor2 = ::CreateWindowExW( WS_EX_CLIENTEDGE, UPDOWN_CLASSW, L"", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | UDS_ARROWKEYS | UDS_ALIGNRIGHT | UDS_HOTTRACK, CastInt(rc.right-16), rc.top, 16, CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor2, UDM_SETBUDDY, (WPARAM)_editor2, (LPARAM)0 );
			::SendMessageW( _editor2, UDM_SETRANGE32, (WPARAM)0, (LPARAM)100 );
			::SetWindowLongPtr( _editor2, GWLP_USERDATA, (LONG_PTR)_editor );

			Int value; _config->Get( param->Name, &value );
			::SendMessageW( _editor2, UDM_SETPOS32, (WPARAM)0, (LPARAM)value );

			Char text[1024] = {};
			Convert::ToString( value ).GetChars( 0, 1024, text );
			::SetWindowTextW( _editor, text );
			::SetFocus( _editor );
		}
		else if ( param->Type == ParamType::String )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_EDITW, L"", ES_AUTOHSCROLL | WS_CHILDWINDOW | WS_VISIBLE, rc.left+3, rc.top, CastInt(rc.right-rc.left-3), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG)idxParam );
			
			Char text[1024] = {};
			String value; _config->Get( param->Name, &value );
			value.GetChars( 0, 1024, text );
			::SetWindowTextW( _editor, text );
			::SetFocus( _editor );
		}
		else if ( param->Type == ParamType::List )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_EDITW, L"", ES_AUTOHSCROLL | WS_CHILDWINDOW | WS_VISIBLE, rc.left+3, rc.top, CastInt(rc.right-rc.left-3), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG)idxParam );

			Char text[1024] = {};
			String value = GetValue( idxParam );
			value.GetChars( 0, 1024, text );
			::SetWindowTextW( _editor, text );
			::SetFocus( _editor );
		}
		else if ( param->Type == ParamType::Flag )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_COMBOBOXW, L"", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | CBS_HASSTRINGS | CBS_DROPDOWNLIST, rc.left+1, rc.top-3, CastInt(rc.right-rc.left-1), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG)idxParam );

			_editor2 = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_LISTVIEWW, L"", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | LVS_REPORT | LVS_SINGLESEL | LVS_ALIGNLEFT | LVS_NOCOLUMNHEADER, rc.left+1, rc.top+17, CastInt(rc.right-rc.left-1), CastInt(80), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor2, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );
			AddListViewColumn( _editor2, 0, L"", (rc.right-rc.left-25) );
			
			// Add items.
			const Int count = param->Data.EntryCount( L'|' );
			for ( Int i = 0; i < count; ++i )
			{
				String entry = param->Data.Entry( i, L'|' );
				AddListViewItem( _editor2, i, entry, String::Empty );
			}

			UInt value; _config->Get( param->Name, (Int*)&value );
			for ( UInt i = 0; value > 0; ++i )
			{
				if ( (value & 0x00000001) != 0 )
				{
					ListView_SetCheckState( _editor2, i, TRUE );
				}
				value >>= 1;
			}
		}
		else if ( param->Type == ParamType::Enumeration )
		{
			_editor = ::CreateWindowExW( WS_EX_CLIENTEDGE, WC_COMBOBOXW, L"", WS_TABSTOP | WS_CHILDWINDOW | WS_VISIBLE | CBS_HASSTRINGS | CBS_DROPDOWNLIST, rc.left+1, rc.top-3, CastInt(rc.right-rc.left-1), CastInt(rc.bottom-rc.top), _list, (HMENU)nullptr, (HINSTANCE)nullptr, (LPVOID)0 );
			::SendMessageW( _editor, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE );
			::SetWindowLongPtr( _editor, GWLP_USERDATA, (LONG)idxParam );
			OrgComboboxProc = (WNDPROC)::SetWindowLongPtr( _editor, GWLP_WNDPROC, (LONG_PTR)ParamComboboxProc );

			// Add items.
			Char tmp[260] = {};
			const Int count = param->Data.EntryCount( L'|' );
			for ( Int i = 0; i < count; ++i )
			{
				String entry = param->Data.Entry( i, L'|' );
				entry.GetChars( 0, 260, tmp );
				::SendMessageW( _editor, CB_ADDSTRING, 0, (LPARAM)tmp );
			}

			// Set drop-down list dimensions.
			LONG itemHeight = (LONG)::SendMessageW( _editor, CB_GETITEMHEIGHT, -1, 0 );
			LONG itemWidth = (LONG)::SendMessageW( _editor, CB_GETDROPPEDWIDTH, 0, 0 );
			::SetWindowPos( _editor, 0, 0, 0, itemWidth, itemHeight*count, SWP_NOMOVE | SWP_NOZORDER );

			UInt value; _config->Get( param->Name, (Int*)&value );
			::SendMessageW( _editor, CB_SETCURSEL, (WPARAM)value, 0 );
			::SetFocus( _editor );
		}
	}
}

void Win32ConfigurationEditor::EndEditing( Bool apply )
{
	Char buf[128] = {};
	LVITEM lvi;
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask = LVIF_TEXT;
	lvi.iSubItem = 0;
	lvi.pszText = (LPWSTR)buf;
	lvi.cchTextMax = 128;
	UInt idxParam = (UInt)::GetWindowLongPtr( _editor, GWLP_USERDATA );
	UInt len = (UInt)::SendMessage( _list, LVM_GETITEMTEXT, (WPARAM)idxParam, (LPARAM)&lvi );

	const Param* param = _config->GetParam( String(lvi.pszText) );
	if ( (param != nullptr) && (_editor != nullptr) && apply )
	{
		if ( param->Type == ParamType::Boolean )
		{
			const UInt idx = (UInt)::SendMessageW( _editor, CB_GETCURSEL, 0, 0 );
			const Bool value = (idx != 0);

			_config->Set( param->Name, value );
			UpdateValue( idxParam, Convert::ToString(value) );
		}
		else if ( param->Type == ParamType::Integer )
		{
			Char text[1024] = {};
			::GetWindowTextW( _editor, text, 1024 );
			UInt value = Convert::ToUInt( String(text) );

			_config->Set( param->Name, value );
			UpdateValue( idxParam, Convert::ToString(value) );
		}
		else if ( param->Type == ParamType::String )
		{
			Char text[1024] = {};
			::GetWindowTextW( _editor, text, 1024 );
			String value( text );

			_config->Set( param->Name, value );
			UpdateValue( idxParam, value );
		}
		else if ( param->Type == ParamType::Flag )
		{
			UInt value = 0;

			const UInt count = (UInt)ListView_GetItemCount( _editor2 );
			for ( UInt i = 0; i < count; ++i )
			{
				const BOOL checked = ListView_GetCheckState( _editor2, i );
				if ( checked != 0 )
				{
					value |= (1 << i);
				}
			}

			_config->Set( param->Name, value );
			String strValue; _config->Get( param->Name, &strValue );
			UpdateValue( idxParam, strValue );
		}
		else if ( param->Type == ParamType::Enumeration )
		{
			const UInt idx = (UInt)::SendMessageW( _editor, CB_GETCURSEL, 0, 0 );
			String value = param->Data.Entry( idx, L'|' );

			_config->Set( param->Name, idx );
			UpdateValue( idxParam, value );
		}

		if ( _editor2 != nullptr )
		{
			::DestroyWindow( _editor2 );
			_editor2 = nullptr;
		}

		::DestroyWindow( _editor );
		_editor = nullptr;
	}

	::InvalidateRect( _list, nullptr, TRUE );
}

void Win32ConfigurationEditor::CycleValue( UInt idxParam )
{
	Char buf[128] = {};
	LVITEM lvi;
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask = LVIF_TEXT;
	lvi.iSubItem = 0;
	lvi.pszText = (LPWSTR)buf;
	lvi.cchTextMax = 128;
	UInt len = (UInt)::SendMessage( _list, LVM_GETITEMTEXT, (WPARAM)idxParam, (LPARAM)&lvi );

	const Param* param = _config->GetParam( String(lvi.pszText) );
	if ( param != nullptr )
	{
		if ( param->Type == ParamType::Boolean )
		{
			Bool value; _config->Get( param->Name, &value );
			value = !value; _config->Set( param->Name, value );
			UpdateValue( idxParam, Convert::ToString(value) );
		}
		else if ( param->Type == ParamType::Enumeration )
		{
			UInt value; _config->Get( param->Name, (Int*)&value );
			UInt count = param->Data.EntryCount( L'|' );
			if ( ++value >= count ) { value = 0; };
			_config->Set( param->Name, value );
			UpdateValue( idxParam, param->Data.Entry(value, L'|') );
		}
	}
}

void Win32ConfigurationEditor::UpdateValue( UInt idxParam, const String& value )
{
	Char buf[1024] = {};
	value.GetChars( 0, 1024, buf );
	ListView_SetItemText( _list, idxParam, 1, buf );
}

String Win32ConfigurationEditor::GetValue( UInt idxParam )
{
	Char buf[260] = {};
	ListView_GetItemText( _list, idxParam, 1, buf, 260 );
	return String( buf );
}

BOOL CALLBACK EnumChildProc( HWND hwnd, LPARAM lParam )
{
	IConfiguration* config = (IConfiguration*)lParam;
	const Param* param = (const Param*)::GetWindowLongPtr( hwnd, GWLP_USERDATA );
	if ( param != nullptr )
	{
		Char text[1024] = {};
		if ( param->Type == ParamType::Boolean )
		{
			Bool value; config->Get( param->Name, &value );
			::SendMessage( hwnd, BM_SETCHECK, (WPARAM)value ? BST_CHECKED : BST_UNCHECKED, 0 );
		}
		else if ( param->Type == ParamType::Integer )
		{
			Int value; config->Get( param->Name, &value );
			Convert::ToString( value ).GetChars( 0, 1024, text );
			::SetWindowTextW( hwnd, text );
		}
		else if ( param->Type == ParamType::String )
		{
			String value; config->Get( param->Name, &value );
			value.GetChars( 0, 1024, text );
			::SetWindowTextW( hwnd, text );
		}
		else if ( param->Type == ParamType::List )
		{
		}
		else if ( param->Type == ParamType::Flag )
		{
			UInt value; config->Get( param->Name, (Int*)&value );
			for ( UInt i = 0; value > 0; ++i )
			{
				if ( (value & 0x00000001) != 0 )
				{
					ListView_SetCheckState( hwnd, i, TRUE );
				}
				value >>= 1;
			}
		}
		else if ( param->Type == ParamType::Enumeration )
		{
			UInt value; config->Get( param->Name, (Int*)&value );
			::SendMessageW( hwnd, CB_SETCURSEL, (WPARAM)value, 0 );
		}
	}

	return TRUE;
}

void Win32ConfigurationEditor::OnButtonPress( WORD button )
{
	switch ( button )
	{
		case IDB_RUN:
			try
			{
				_config->Validate();
				_result = true;
				::DestroyWindow( _handle );
			}
			catch ( const ConfigurationException& ex )
			{
				Char chars[1024] = {};
				ex.Message().GetChars( 0, 1024, chars );
				::MessageBoxW( _handle, chars, L"Configuration Error", MB_OK | MB_ICONERROR );
			}
			break;

		case IDCANCEL:
			_result = false;
			::DestroyWindow( _handle );
			break;
	}
}

Bool Win32ConfigurationEditor::GetResult()
{
	return _result;
}

HFONT Win32ConfigurationEditor::CreateParamFont()
{
	LOGFONT lfont;
	memset( &lfont, 0, sizeof(lfont) );
	lfont.lfHeight			= 14*_scale;
	lfont.lfWidth			= 6*_scale;
	lfont.lfWeight			= FW_BOLD;
	lfont.lfCharSet			= DEFAULT_CHARSET;
	lfont.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lfont.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	lfont.lfQuality			= ANTIALIASED_QUALITY;
	lfont.lfPitchAndFamily	= DEFAULT_PITCH;
	wcscpy( lfont.lfFaceName, L"MS Sans Serif" );

	return ::CreateFontIndirect( &lfont );
}

HFONT Win32ConfigurationEditor::CreateHintFont()
{
	LOGFONT lfont;
	memset( &lfont, 0, sizeof(lfont) );
	lfont.lfHeight			= 15*_scale;
	lfont.lfWidth			= 8*_scale;
	lfont.lfWeight			= FW_NORMAL;
	lfont.lfCharSet			= DEFAULT_CHARSET;
	lfont.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lfont.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	lfont.lfQuality			= ANTIALIASED_QUALITY;
	lfont.lfPitchAndFamily	= DEFAULT_PITCH;
	wcscpy( lfont.lfFaceName, L"MS Sans Serif" );

	return ::CreateFontIndirect( &lfont );
}

void Win32ConfigurationEditor::AddColumn( HWND handle, Int index, const String& name, int width )
{
	Char buf[260] = {};
	LVCOLUMNW lvc;

	memset( &lvc, 0, sizeof(lvc) );
	lvc.mask	= LVCF_TEXT | LVCF_WIDTH;
	lvc.cx		= width;
	lvc.pszText	= (LPWSTR)name.GetChars(0, 260, buf);
	::SendMessageW( handle, LVM_INSERTCOLUMNW, index, (LPARAM)&lvc );
}

Int Win32ConfigurationEditor::AddItem( HWND handle, Int index, const String& item )
{
	Char buf[260] = {};
	LVITEMW lvi;

	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask		= LVIF_TEXT;
	lvi.iItem		= index;
	lvi.pszText		= (LPWSTR)item.GetChars(0, 260, buf);
	return (Int)::SendMessageW( handle, LVM_INSERTITEMW, 0, (LPARAM)&lvi );
}

void Win32ConfigurationEditor::GetTextSize( HFONT font, const String& text, Int* width, Int* height )
{
	Char buf[512] = {};
	SIZE size;
	HFONT oldFont;

	HDC hDC = ::GetDC( nullptr );
	oldFont = (HFONT)::SelectObject( hDC, font );
	text.GetChars( 0, 512, buf );
	::GetTextExtentPoint32W( hDC, (LPCWSTR)buf, text.Length(), &size );
	::SelectObject( hDC, oldFont );
	::ReleaseDC( nullptr, hDC );
	*width = size.cx;
	*height = size.cy;
}

void Win32ConfigurationEditor::AddListViewColumn( HWND handle, Int index, const String& name, Int width )
{
	Char buf[260] = {};
	LVCOLUMNW lvc;

	memset( &lvc, 0, sizeof(lvc) );
	lvc.mask	= LVCF_TEXT | LVCF_WIDTH;
	lvc.cx		= width;
	lvc.pszText	= (LPWSTR)name.GetChars(0, 260, buf);
	::SendMessageW( handle, LVM_INSERTCOLUMNW, index, (LPARAM)&lvc );
}

void Win32ConfigurationEditor::AddListViewItem( HWND handle, Int index, const String& param, const String& value )
{
	Char buf[260] = {};
	LVITEMW lvi;

	// Add parameter name.
	memset( &lvi, 0, sizeof(lvi) );
	lvi.mask		= LVIF_TEXT;
	lvi.iItem		= index;
	lvi.pszText		= (LPWSTR)param.GetChars(0, 260, buf);
	index = (Int)::SendMessageW( handle, LVM_INSERTITEMW, 0, (LPARAM)&lvi );

	// Add parameter value.
	if ( !value.IsEmpty() )
	{
		memset( &lvi, 0, sizeof(lvi) );
		lvi.mask		= LVIF_TEXT;
		lvi.iItem		= index;
		lvi.iSubItem	= 1;
		lvi.pszText		= (LPWSTR)value.GetChars(0, 260, buf);
		::SendMessageW( handle, LVM_SETITEMW, 0, (LPARAM)&lvi );
	}
}

void Win32ConfigurationEditor::InitParamList()
{
	String name = _config->GetFirstParam();
	for ( ; !name.IsEmpty(); name = _config->GetNextParam() )
	{
		Int idx = 0;
		const Param* param = _config->GetParam( name );

		if ( param->Type == ParamType::String )
		{
			String value; _config->Get( name, &value );
			AddListViewItem( _list, idx++, name, value );
		}
		else if ( param->Type == ParamType::List )
		{
			String value; _config->Get( name, &value );
			const UInt itemCount = value.EntryCount( L'|' );
			for ( UInt k = itemCount; k > 0; --k )
			{
				AddListViewItem( _list, idx++, name, value.Entry(k-1, L'|') );
			}
		}
		else if ( param->Type == ParamType::Integer )
		{
			Int value; _config->Get( name, &value );
			AddListViewItem( _list, idx++, name, Convert::ToString(value) );
		}
		else if ( param->Type == ParamType::Enumeration )
		{
			String value; _config->Get( name, &value );
			AddListViewItem( _list, idx++, name, value );
		}
		else if ( param->Type == ParamType::Flag )
		{
			String value; _config->Get( name, &value );
			AddListViewItem( _list, idx++, name, value );
		}
		else if ( param->Type == ParamType::Boolean )
		{
			Bool value; _config->Get( name, &value );
			AddListViewItem( _list, idx++, name, Convert::ToString(value) );
		}
	}
}


} // core


} // synkro
