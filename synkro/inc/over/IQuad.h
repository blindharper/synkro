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
// Purpose: Defines a quad.
//==============================================================================
#ifndef _SYNKRO_OVER_IQUAD_
#define _SYNKRO_OVER_IQUAD_


#include "config.h"
#include <core/IObject.h>
#include <img/Color.h>
#include <lang/Rect.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Monochrome quad.
 */
iface IQuad :
	public core::IObject
{
public:
	/** 
	 * Sets quad's visibility.
	 * @param show Set to true to make quad visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/** 
	 * Enables or disables clipping rectangle.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/**
	 * Sets text clipping rectangle, in screen coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Sets quad's location.
	 * @param location New quad location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets quad's size.
	 * @param size New quad's size.
	 */
	virtual void											SetSize( const lang::Size& size ) = 0;

	/**
	 * Sets quad color.
	 * @param color Color to apply to the quad.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/** 
	 * Sets degree of quad opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Quad's opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets group z-order.
	 * @param order New group z-order.
	 */
	virtual void											SetGroupOrder( const Order& order ) = 0;

	/**
	 * Sets quad's z-order.
	 * @param order New quad's z-order.
	 */
	virtual void											SetOrder( const Order& order ) = 0;

	/**
	 * Retrieves quad's visibility state.
	 * @return True if the quad is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/** 
	 * Indicates whether the clipping rectangle is enabled.
	 */
	virtual Bool											IsRectEnabled() const = 0;

	/**
	 * Retrieves text clipping rectangle, in screen coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves quad's location.
	 * @param [out] location Quad's location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves quad's size.
	 * @param [out] size Quad's size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves quad's color.
	 * @param [out] color Quad color.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves degree of object opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves group z-order.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves quad's z-order.
	 */
	virtual Order											GetOrder() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_IQUAD_
