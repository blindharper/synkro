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
#ifndef _SYNKRO_WIN_WIN32HOSTWINDOW_
#define _SYNKRO_WIN_WIN32HOSTWINDOW_


#include "config.h"
#include <win/WindowImpl.h>
#include <win/IHostWindow.h>


namespace synkro
{


namespace win
{


// Windows host window.
class Win32HostWindow :
	public WindowImpl<IHostWindow>
{
public:
	// Constructor.
	Win32HostWindow( Pointer handle );

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );

	// IHostWindow methods.
	void													SetTitle( const lang::String& title );
	lang::String											GetTitle() const;

private:
	lang::String											_title;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32HOSTWINDOW_
