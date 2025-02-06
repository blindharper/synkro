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
#ifndef _SYNKRO_WIN_WIN32ICONWINDOW_
#define _SYNKRO_WIN_WIN32ICONWINDOW_


#include "config.h"
#include <win/IconWindowImpl.h>
#include <win/IIconWindow.h>


namespace synkro
{


namespace win
{


// Win32 icon window implementation.
class Win32IconWindow :
	public IconWindowImpl<IIconWindow>
{
public:
	// Constructor & destructor.
	Win32IconWindow( UInt icon, const lang::String& hint );
	~Win32IconWindow();

	// IWindow methods.
	Bool													Update();
	void													Close();
	void													SetPosition( Int left, Int top );
	void													SetSize( UInt width, UInt height );

	// IIconWindow methods.
	void													AddMenuItem( UInt id, UInt icon, const lang::String& text );
	void													SetIcon( UInt icon );
	void													SetHint( const lang::String& hint );

	// Other methods
	virtual LRESULT											HandleMessage( UINT msg, WPARAM wp, LPARAM lp );

private:
	HMENU													_menu;
	Bool													_running;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32ICONWINDOW_
