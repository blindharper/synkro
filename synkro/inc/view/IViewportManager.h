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
// Purpose: Defines viewport manager.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTMANAGER_
#define _SYNKRO_VIEW_IVIEWPORTMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <lang/String.h>
#include <lang/Rect.h>
#include <lang/Point.h>
#include <img/Color.h>


namespace synkro
{


namespace view
{


/**
 * Viewport manager.
 */
iface IViewportManager :
	public core::ISystem
{
public:
	/**
	 * Creates a viewport and adds it to the view manager.
	 * @param window Rendering window in which to create rendering view.
	 * @param rect Viewport rectangle.
	 * @param camera Camera used to render the viewport.
	 * @param color Viewport background color.
	 */
	virtual IViewport*										CreateViewport( gfx::IFrameRenderWindowEx* window, const lang::Rect& rect, scene::ICamera* camera, const img::Color& color ) = 0;

	/**
	 * Creates a viewport and adds it to the view manager.
	 * @param view Underlying rendering view.
	 * @param camera Camera used to render the viewport.
	 */
	virtual IViewport*										CreateViewport( gfx::IRenderView* view, scene::ICamera* camera ) = 0;

	/**
	 * Creates viewport transition controller.
	 * @param listener Controller listener.
	 */
	virtual IViewportTransitionController*					CreateTransitionController( ViewportListener* listener ) = 0;

	/**
	 * Retrieves the total number of viewports.
	 */
	virtual UInt											GetViewportCount() const = 0;

	/**
	 * Retrieves a viewport by index.
	 * @param index Index of the viewport to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IViewport*										GetViewport( UInt index ) const = 0;

	/**
	 * Retrieves a viewport by underlying rendering view.
	 * @param view Underlying rendering view.
	 * @exception BadArgumentException Bad view.
	 */
	virtual IViewport*										GetViewport( gfx::IRenderView* view ) const = 0;

	/**
	 * Retrieves viewport at the given location.
	 * @param window Rendering window to search for viewports.
	 * @param location Location to test.
	 * @exception BadArgumentException Bad window.
	 */
	virtual IViewport*										GetViewport( gfx::IFrameRenderWindowEx* window, const lang::Point& location ) const = 0;

	/**
	 * Retrieves active viewport.
	 */
	virtual IViewport*										GetActiveViewport() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTMANAGER_
