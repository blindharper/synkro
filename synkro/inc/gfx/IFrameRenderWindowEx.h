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
// Purpose: Defines extended frame rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_IFRAMERENDERWINDOWEX_
#define _SYNKRO_GFX_IFRAMERENDERWINDOWEX_


#include "config.h"
#include <gfx/IFrameRenderWindow.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended frame rendering window.
 */
iface IFrameRenderWindowEx :
	public IFrameRenderWindow
{
public:
	/**
	 * Creates custom rendering view.
	 * @param left Left coordinate of the view.
	 * @param top Top coordinate of the view.
	 * @param width View width.
	 * @param height View height.
	 * @param sampleCount Number of samples per texel.
	 * @param color View background color.
	 * @return Created view.
	 */
	virtual IRenderView*									CreateView( Int left, Int top, UInt width, UInt height, UInt sampleCount, const math::Vector4& color ) = 0;

	/**
	 * Sets intermediate rendering target. Used to get window's contents as it is presented to the user.
	 * @param target Custom rendering target.
	 */
	virtual void											SetTarget( IPlainRenderTexture* target ) = 0;

	/** 
	 * Enables overlay for this window.
	 */
	virtual void											EnableOverlay() = 0;

	/**
	 * Retrieves the total number of window's views.
	 */
	virtual UInt											GetViewCount() const = 0;

	/**
	 * Retrieves window view by index.
	 * @param index Index of the view to retrieve.
	 * @return Requested view.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IRenderView*									GetView( UInt index ) const = 0;

	/**
	 * Retrieves intermediate rendering target.
	 */
	virtual IPlainRenderTexture*							GetTarget() const = 0;

	/**
	 * Retrieves overlay rendering queue.
	 */
	virtual IOverlayRenderQueue*							GetOverlayQueue() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IFRAMERENDERWINDOWEX_
