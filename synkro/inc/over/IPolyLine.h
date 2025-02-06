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
// Purpose: Defines polyline.
//==============================================================================
#ifndef _SYNKRO_OVER_IPOLYLINE_
#define _SYNKRO_OVER_IPOLYLINE_


#include "config.h"
#include <core/IObject.h>
#include <img/Color.h>
#include <lang/Point.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * A series of line segments.
 */
iface IPolyLine :
	public core::IObject
{
public:
	/** 
	 * Sets polyline's visibility.
	 * @param show Set to true to make polyline visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets point position coordinates.
	 * @param positions Array of point positions.
	 */
	virtual void											SetPositions( const lang::Point* positions ) = 0;

	/**
	 * Sets point colors.
	 * @param colors Array of point colors.
	 */
	virtual void											SetColors( const img::Color* colors ) = 0;

	/**
	 * Sets polyline color.
	 * @param color Color to apply to the polyline.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/** 
	 * Sets degree of polyline opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Polyline's opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets group z-order.
	 * @param order New group z-order.
	 */
	virtual void											SetGroupOrder( const Order& order ) = 0;

	/**
	 * Sets polyline's z-order.
	 * @param order New polyline's z-order.
	 */
	virtual void											SetOrder( const Order& order ) = 0;

	/**
	 * Retrieves polyline's visibility state.
	 * @return True if the polyline is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves polyline color.
	 * @param [out] color Polyline color.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves degree of polyline opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves group z-order.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves polyline's z-order.
	 */
	virtual Order											GetOrder() const = 0;

	/**
	 * Retrieves the number of points in the polyline.
	 */
	virtual UInt											GetPointCount() const = 0;

	/**
	 * Retrieves polyline width.
	 */
	virtual UInt											GetWidth() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_IPOLYLINE_
