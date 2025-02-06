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
#ifndef _SYNKRO_CORE_WIN32CONFIGURATIONEDITOR_
#define _SYNKRO_CORE_WIN32CONFIGURATIONEDITOR_


#include "config.h"
#include <core/IConfiguration.h>
#include <commctrl.h>


namespace synkro
{


namespace core
{


// Configuration editor for Windows.
class Win32ConfigurationEditor
{
public:
	static Pointer											Initialize( Pointer module, ISynkro* synkro );
	static void												Show( IConfiguration* config );
	static void												Finalize();
	static void												OpenUrl( const WCHAR* url );
	static void												DisplayHint( const Param* param );
	static void												DisplayHint( UInt idxParam );
	static void												BeginEditing( UInt idxParam );
	static void												EndEditing( Bool apply );
	static void												CycleValue( UInt idxParam );
	static void												UpdateValue( UInt idxParam, const lang::String& value );
	static lang::String										GetValue( UInt idxParam );
	static void												OnButtonPress( WORD button );
	static Bool												GetResult();

private:
	static ISynkro*											_synkro;
	static HINSTANCE										_module;
	static HWND												_handle;
	static HWND												_list;
	static HWND												_editor;
	static HWND												_editor2;
	static HIMAGELIST										_images;
	static HFONT											_fontParam;
	static HFONT											_fontHint;
	static IConfiguration*									_config;
	static Float											_scale;
	static Bool												_result;

	static HFONT											CreateParamFont();
	static HFONT											CreateHintFont();
	static void												AddColumn( HWND handle, Int index, const lang::String& name, int width );
	static Int												AddItem( HWND handle, Int index, const lang::String& item );
	static void												GetTextSize( HFONT font, const lang::String& text, Int* width, Int* height );
	static void												AddListViewColumn( HWND handle, Int index, const lang::String& name, int width );
	static void												AddListViewItem( HWND handle, Int index, const lang::String& param, const lang::String& value );
	static void												InitParamList();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_WIN32CONFIGURATIONEDITOR_
