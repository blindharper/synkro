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
	 * Retrieves the total number of frame windows.
	 */
	virtual UInt											GetFrameWindowCount() const = 0;

	/**
	 * Retrieves frame window by index.
	 * @param index Window index.
	 * @return Requested window.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IFrameWindowEx*									GetFrameWindow( UInt index ) const = 0;

	/**
	 * Retrieves icon window.
	 */
	virtual IIconWindow*									GetIconWindow() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IWINDOWSYSTEMEX_
