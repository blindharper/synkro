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
// Purpose: Defines extended window system.
//==============================================================================
#ifndef _SYNKRO_WIN_IWINDOWSYSTEMEX_
#define _SYNKRO_WIN_IWINDOWSYSTEMEX_


#include "config.h"
#include <win/IWindowSystem.h>


namespace synkro
{


namespace win
{


/**
 * Extended window system.
 */
iface IWindowSystemEx :
	public IWindowSystem
{
public:
	/**
	 * Retrieves frame window.
	 */
	virtual IFrameWindowEx*									GetFrameWindow() const = 0;

	/**
	 * Retrieves host window.
	 */
	virtual IHostWindowEx*									GetHostWindow() const = 0;

	/**
	 * Retrieves icon window.
	 */
	virtual IIconWindow*									GetIconWindow() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IWINDOWSYSTEMEX_
