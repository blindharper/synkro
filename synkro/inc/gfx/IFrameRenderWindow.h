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
// Purpose: Defines top-level rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_IFRAMERENDERWINDOW_
#define _SYNKRO_GFX_IFRAMERENDERWINDOW_


#include "config.h"
#include <gfx/IRenderWindow.h>
#include <gfx/DisplayMode.h>


namespace synkro
{


namespace gfx
{


/**
 * Top-level rendering window.
 */
iface IFrameRenderWindow :
	public IRenderWindow
{
public:
	/**
	 * Sets window display mode.
	 * @param displayMode New display mode.
	 * @return True if succeeded, false otherwise.
	 */
	virtual Bool											SetDisplayMode( const DisplayMode& displayMode ) = 0;

	/**
	 * Retrieves window display mode.
	 * @param [out] displayMode Display mode.
	 */
	virtual void											GetDisplayMode( DisplayMode& displayMode ) const = 0;

	/**
	 * Retrieves underlying frame window.
	 */
	virtual win::IFrameWindow*								GetWindow() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IFRAMERENDERWINDOW_
