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
// Purpose: Defines viewport window.
//==============================================================================
#ifndef _SYNKRO_WIN_IVIEWWINDOW_
#define _SYNKRO_WIN_IVIEWWINDOW_


#include "config.h"
#include <win/IWindow.h>


namespace synkro
{


namespace win
{


/**
 * Viewport window. Designed for use in GUI applications.
 */
iface IViewWindow :
	public IWindow
{
public:
	/** 
	 * Sets window visibility.
	 * @param show Set to true to make window visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Indicates whether the window is currently visible.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves parent window.
	 */
	virtual IFrameWindow*									GetParent() const = 0;
};


} // win


} // synkro


#endif // _SYNKRO_WIN_IVIEWWINDOW_
