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
// Purpose: Defines extended host window.
//==============================================================================
#ifndef _SYNKRO_WIN_IHOSTWINDOWEX_
#define _SYNKRO_WIN_IHOSTWINDOWEX_


#include "config.h"
#include <win/IHostWindow.h>


namespace synkro
{


namespace win
{


/**
 * Extended host window.
 */
iface IHostWindowEx :
	public IHostWindow
{
public:
	/**
	 * Retrieves the total number of view windows owned by this window.
	 */
	virtual UInt											GetWindowCount() const = 0;

	/**
	 * Retrieves view window by index.
	 * @param index Window index.
	 * @return Requested window.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IViewWindowEx*									GetWindow( UInt index ) const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IHOSTWINDOWEX_
