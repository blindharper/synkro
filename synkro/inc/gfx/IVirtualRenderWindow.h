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
// Purpose: Defines virtual rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_IVIRTUALRENDERWINDOW_
#define _SYNKRO_GFX_IVIRTUALRENDERWINDOW_


#include "config.h"
#include <gfx/IRenderWindow.h>


namespace synkro
{


namespace gfx
{


/**
 * Virtual rendering window.
 */
iface IVirtualRenderWindow :
	public IRenderWindow
{
public:
	/** 
	 * Enables overlay for this window.
	 */
	virtual void											EnableOverlay() = 0;

	/**
	 * Retrieves window's rendering view.
	 */
	virtual IRenderView*									GetView() const = 0;

	/**
	 * Retrieves rendering target.
	 */
	virtual IPlainRenderTexture*							GetTarget() const = 0;

	/**
	 * Retrieves overlay rendering queue.
	 */
	virtual IOverlayRenderQueue*							GetOverlayQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IVIRTUALRENDERWINDOW_
