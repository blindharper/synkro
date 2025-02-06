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
// Purpose: Defines extended frame window.
//==============================================================================
#ifndef _SYNKRO_WIN_IFRAMEWINDOWEX_
#define _SYNKRO_WIN_IFRAMEWINDOWEX_


#include "config.h"
#include <win/IFrameWindow.h>


namespace synkro
{


namespace win
{


/**
 * Extended frame window.
 */
iface IFrameWindowEx :
	public IFrameWindow
{
public:
	/**
	 * Registers window event listener.
	 * @param listener Event listener.
	 */
	virtual void											Listen( WindowListener* listener ) = 0;

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


#endif // _SYNKRO_WIN_IFRAMEWINDOWEX_
