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
// Purpose: Defines overlay font.
//==============================================================================
#ifndef _SYNKRO_OVER_IFONT_
#define _SYNKRO_OVER_IFONT_


#include "config.h"
#include <core/IObject.h>
#include <core/Language.h>
#include <img/ColorGradient.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <lang/String.h>
#include <over/FontStyle.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay font.
 */
iface IFont :
	public core::IObject
{
public:
	/**
	 * Creates gradient text with the given z-order.
	 * @param gradient Gradient to apply to the text.
	 * @param location Text location.
	 * @param text Text string.
	 * @param groupOrder Group z-order.
	 * @param order Text z-order.
	 * @return Created text.
	 */
	virtual IText*											CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text, const Order& groupOrder, const Order& order ) = 0;

	/**
	 * Creates gradient text.
	 * @param gradient Gradient to apply to the text.
	 * @param location Text location.
	 * @param text Text string.
	 * @return Created text.
	 */
	virtual IText*											CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text ) = 0;

	/**
	 * Creates colored text with the given z-order.
	 * @param color Text color.
	 * @param location Text location.
	 * @param text Text string.
	 * @param groupOrder Group z-order.
	 * @param order Text z-order.
	 * @return Created text.
	 */
	virtual IText*											CreateText( const img::Color& color, const lang::Point& location, const lang::String& text, const Order& groupOrder, const Order& order ) = 0;

	/**
	 * Creates colored text.
	 * @param color Text color.
	 * @param location Text location.
	 * @param text Text string.
	 * @return Created text.
	 */
	virtual IText*											CreateText( const img::Color& color, const lang::Point& location, const lang::String& text ) = 0;

	/**
	 * Calculates the dimensions of the specified text.
	 * @param text Text to calculate the dimensions for.
	 * @param [out] size Text dimensions.
	 */
	virtual void											GetTextSize( const lang::String& text, lang::Size& size ) const = 0;

	/**
	 * Retrieves font family name. For vector fonts only.
	 */
	virtual lang::String									GetFamily() const = 0;

	/**
	 * Retrieves font size. For vector fonts only.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves font style.
	 */
	virtual FontStyle										GetStyle() const = 0;

	/**
	 * Retrieves font language.
	 */
	virtual core::Language									GetLanguage() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_IFONT_
