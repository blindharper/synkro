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
// Purpose: Defines extended view window.
//==============================================================================
#ifndef _SYNKRO_WIN_IVIEWWINDOWEX_
#define _SYNKRO_WIN_IVIEWWINDOWEX_


#include "config.h"
#include <win/IViewWindow.h>


namespace synkro
{


namespace win
{


/**
 * Extended view window.
 */
iface IViewWindowEx :
	public IViewWindow
{
public:
	/**
	 * Registers window event listener.
	 * @param listener Event listener.
	 */
	virtual void											Listen( WindowListener* listener ) = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IVIEWWINDOWEX_
