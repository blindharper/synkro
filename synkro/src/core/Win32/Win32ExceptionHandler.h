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
#ifndef _SYNKRO_CORE_WIN32EXCEPTIONHANDLER_
#define _SYNKRO_CORE_WIN32EXCEPTIONHANDLER_


#include "config.h"
#include <lang/String.h>
#include <commctrl.h>


namespace synkro
{


namespace core
{


// Visual exception handler for Windows.
class Win32ExceptionHandler
{
public:
	static void												Initialize( Pointer module, ISynkro* synkro );
	static void												Init( HWND handle );
	static void												Show( const lang::String& message );
	static void												OpenUrl( const WCHAR* url );
	static void												OnButtonPress( WORD button );

private:
	static HINSTANCE										_module;
	static HWND												_handle;
	static HWND												_list;
	static Char												_version[1024];
	static Char												_message[1024];

	static void												AddListViewColumn( HWND handle, Int index, const lang::String& name, int width );
	static void												AddListViewItem( HWND handle, Int index, const lang::String& call, const lang::String& file, const lang::String& line, const lang::String& context );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_WIN32EXCEPTIONHANDLER_
