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
// Purpose: Defines overlay text.
//==============================================================================
#ifndef _SYNKRO_OVER_ITEXT_
#define _SYNKRO_OVER_ITEXT_


#include "config.h"
#include <core/IObject.h>
#include <lang/Rect.h>
#include <img/ColorGradient.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay text.
 */
iface IText :
	public core::IObject
{
public:
	/**
	 * Creates text controller.
	 * @param animation Optional text animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual ITextAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Sets text visibility.
	 * @param show Set to true to make text visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Removes all text contents.
	 */
	virtual void											Clear() = 0;

	/**
	 * Sets text wrap mode.
	 * @param wrap Specifies whether to wrap text to fit text rectangle.
	 */
	virtual void											Wrap( Bool wrap ) = 0;

	/** 
	 * Enables or disables clipping rectangle.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/** 
	 * Enables or disables rotation center.
	 * @param enable Set to true to enable rotation center, set to false to disable it.
	 */
	virtual void											EnableCenter( Bool enable ) = 0;

	/**
	 * Sets text clipping rectangle, in screen coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Sets center of text rotation.
	 * @param center Rotation center.
	 */
	virtual void											SetCenter( const lang::Point& center ) = 0;

	/**
	 * Sets text location.
	 * @param location New text location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets text location's x coordinate.
	 * @param x Text location's x coordinate.
	 */
	virtual void											SetLocationX( Int x ) = 0;

	/**
	 * Sets text location's y coordinate.
	 * @param y Text location's y coordinate.
	 */
	virtual void											SetLocationY( Int y ) = 0;

	/**
	 * Sets text orientation.
	 * @param orientation Text orientation, in radians.
	 */
	virtual void											SetOrientation( Float orientation ) = 0;

	/**
	 * Sets text scale. Default is 1.0.
	 * @param scale Text scale.
	 */
	virtual void											SetScale( Float scale ) = 0;

	/**
	 * Sets text gradient.
	 * @param gradient Color gradient to apply to the text.
	 */
	virtual void											SetGradient( const img::ColorGradient& gradient ) = 0;

	/**
	 * Sets text color.
	 * @param color Color to apply to the text.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/** 
	 * Sets degree of text opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Text opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets group z-order.
	 * @param order New group z-order.
	 */
	virtual void											SetGroupOrder( const Order& order ) = 0;

	/**
	 * Sets text z-order.
	 * @param order New text z-order.
	 */
	virtual void											SetOrder( const Order& order ) = 0;

	/**
	 * Sets text content.
	 * @param text Text content.
	 */
	virtual void											SetText( const lang::String& text ) = 0;

	/**
	 * Retrieves text visibility.
	 * @return True if the text is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves text wrap mode.
	 */
	virtual Bool											IsWrapped() const = 0;

	/** 
	 * Indicates whether the clipping rectangle is enabled.
	 */
	virtual Bool											IsRectEnabled() const = 0;

	/** 
	 * Indicates whether the rotation center is enabled.
	 */
	virtual Bool											IsCenterEnabled() const = 0;

	/**
	 * Retrieves text clipping rectangle, in screen coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves center of text rotation.
	 * @param [out] center Rotation center.
	 */
	virtual void											GetCenter( lang::Point& center ) const = 0;

	/**
	 * Retrieves text location.
	 * @param [out] location Text location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves text orientation, in radians.
	 */
	virtual Float											GetOrientation() const = 0;

	/**
	 * Retrieves text scale.
	 */
	virtual Float											GetScale() const = 0;

	/**
	 * Retrieves text gradient.
	 * @param [out] gradient Text gradient.
	 */
	virtual void											GetGradient( img::ColorGradient& gradient ) const = 0;

	/**
	 * Retrieves text color.
	 * @param [out] color Object color.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves degree of text opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves group z-order.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves text z-order.
	 */
	virtual Order											GetOrder() const = 0;

	/**
	 * Retrieves text string.
	 */
	virtual lang::String									GetText() const = 0;

	/**
	 * Retrieves font used to draw text.
	 */
	virtual IFont*											GetFont() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ITEXT_
