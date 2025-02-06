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
// Purpose: Defines view rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_IVIEWRENDERWINDOW_
#define _SYNKRO_GFX_IVIEWRENDERWINDOW_


#include "config.h"
#include <gfx/IRenderWindow.h>


namespace synkro
{


namespace gfx
{


/**
 * View rendering window.
 */
iface IViewRenderWindow :
	public IRenderWindow
{
public:
	/**
	 * Retrieves underlying view window.
	 */
	virtual win::IViewWindow*								GetWindow() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IVIEWRENDERWINDOW_
