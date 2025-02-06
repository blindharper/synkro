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
// Purpose: Defines overlay.
//==============================================================================
#ifndef _SYNKRO_OVER_IOVERLAY_
#define _SYNKRO_OVER_IOVERLAY_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <over/FontStyle.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay. Manages on-screen sprites and texts.
 */
iface IOverlay :
	public core::IObject
{
public:
	/**
	 * Creates monochrome polyline.
	 * @param pointCount Number of points making up the polyline.
	 * @param width Polyline width.
	 * @param color Polyline color.
	 * @return Created polyline.
	 */
	virtual IPolyLine*										CreatePolyLine( UInt pointCount, UInt width, const img::Color& color ) = 0;

	/**
	 * Creates colored polyline.
	 * @param pointCount Number of points making up the polyline.
	 * @param width Polyline width.
	 * @return Created polyline.
	 */
	virtual IPolyLine*										CreatePolyLine( UInt pointCount, UInt width ) = 0;

	/**
	 * Creates monochrome quad.
	 * @param groupOrder Group z-order.
	 * @param order Sprite z-order.
	 * @param location Quad location.
	 * @param size Quad size.
	 * @param color Quad color.
	 * @return Created quad.
	 */
	virtual IQuad*											CreateQuad( const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size, const img::Color& color ) = 0;

	/**
	 * Creates monochrome quad.
	 * @param location Quad location.
	 * @param size Quad size.
	 * @param color Quad color.
	 * @return Created quad.
	 */
	virtual IQuad*											CreateQuad( const lang::Point& location, const lang::Size& size, const img::Color& color ) = 0;

	/**
	 * Creates sprite pool.
	 * @param image Image used to draw sprites in the pool.
	 * @param groupOrder Group z-order.
	 * @param order Sprite z-order.
	 * @param capacity Number of sprites the pool can hold.
	 * @return Created sprite pool.
	 */
	virtual ISpritePool*									CreateSpritePool( img::IImage* image, const Order& groupOrder, const Order& order, UInt capacity ) = 0;

	/**
	 * Creates a dedicated stretched sprite with the given z-order.
	 * @param image Sprite image.
	 * @param groupOrder Group z-order.
	 * @param order Sprite z-order.
	 * @param location Sprite location.
	 * @param size Sprite size.
	 * @return Created sprite.
	 */
	virtual ISprite*										CreateSprite( img::IImage* image, const Order& groupOrder, const Order& order, const lang::Point& location, const lang::Size& size ) = 0;

	/**
	 * Creates a dedicated sprite with the given z-order.
	 * @param image Sprite image.
	 * @param groupOrder Group z-order.
	 * @param order Sprite z-order.
	 * @param location Sprite location.
	 * @return Created sprite.
	 */
	virtual ISprite*										CreateSprite( img::IImage* image, const Order& groupOrder, const Order& order, const lang::Point& location ) = 0;

	/**
	 * Creates a dedicated stretched sprite with default z-order.
	 * @param image Sprite image.
	 * @param location Sprite location.
	 * @param size Sprite size.
	 * @return Created sprite.
	 */
	virtual ISprite*										CreateSprite( img::IImage* image, const lang::Point& location, const lang::Size& size ) = 0;

	/**
	 * Creates a dedicated sprite with default z-order.
	 * @param image Sprite image.
	 * @param location Sprite location.
	 * @return Created sprite.
	 */
	virtual ISprite*										CreateSprite( img::IImage* image, const lang::Point& location ) = 0;

	/**
	 * Creates text pool.
	 * @param font Font used to draw texts in the pool. Set to null to apply default font.
	 * @param groupOrder Group z-order.
	 * @param order Text z-order.
	 * @param capacity Number of characters the pool can hold.
	 * @return Created text pool.
	 */
	virtual ITextPool*										CreateTextPool( IFont* font, const Order& groupOrder, const Order& order, UInt capacity ) = 0;

	/**
	 * Retrieves font by name.
	 * @param name Unique font name.
	 * @return Requested font, if one exists, or null otherwise.
	 */
	virtual IFont*											GetFont( const lang::String& name ) const = 0;

	/**
	 * Retrieves underlying rendering window.
	 */
	virtual gfx::IRenderWindow*								GetRenderWindow() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_IOVERLAY_
