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
// Purpose: Defines host window.
//==============================================================================
#ifndef _SYNKRO_WIN_IHOSTWINDOW_
#define _SYNKRO_WIN_IHOSTWINDOW_


#include "config.h"
#include <win/IWindow.h>
#include <lang/String.h>


namespace synkro
{


namespace win
{


/**
 * Non-renderable top-level window. Used as a host for view windows.
 */
iface IHostWindow :
	public IWindow
{
public:
	/**
	 * Sets text displayed in the window caption.
	 * @param title New window title.
	 */
	virtual void											SetTitle( const lang::String& title ) = 0;

	/**
	 * Retrieves window title.
	 */
	virtual lang::String									GetTitle() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IHOSTWINDOW_
