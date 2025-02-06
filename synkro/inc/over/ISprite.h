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
// Purpose: Defines overlay sprite.
//==============================================================================
#ifndef _SYNKRO_OVER_ISPRITE_
#define _SYNKRO_OVER_ISPRITE_


#include "config.h"
#include <core/IObject.h>
#include <lang/Rect.h>
#include <lang/RectF.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay sprite.
 */
iface ISprite :
	public core::IObject
{
public:
	/**
	 * Creates sprite animation controller.
	 * @param animation Optional sprite animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual ISpriteAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Sets sprite's visibility.
	 * @param show Set to true to make sprite visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets sprite stretch mode.
	 * @param stretch Specifies whether to stretch image to fit sprite size.
	 */
	virtual void											Stretch( Bool stretch ) = 0;

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
	 * Sets center of sprite rotation.
	 * @param center Rotation center.
	 */
	virtual void											SetCenter( const lang::Point& center ) = 0;

	/**
	 * Sets sprite's location.
	 * @param location New sprite location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets sprite location's x coordinate.
	 * @param x Sprite location's x coordinate.
	 */
	virtual void											SetLocationX( Int x ) = 0;

	/**
	 * Sets sprite location's y coordinate.
	 * @param y Sprite location's y coordinate.
	 */
	virtual void											SetLocationY( Int y ) = 0;

	/**
	 * Sets sprite's size.
	 * @param size New sprite's size.
	 */
	virtual void											SetSize( const lang::Size& size ) = 0;

	/**
	 * Sets sprite's orientation.
	 * @param orientation Sprite orientation, in radians.
	 */
	virtual void											SetOrientation( Float orientation ) = 0;

	/** 
	 * Sets degree of sprite opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Sprite's opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets a portion of the image that is displayed on the sprite.
	 * By default, dedicated sprites display the entire image.
	 * @param frame Image frame.
	 */
	virtual void											SetFrame( const lang::RectF& frame ) = 0;

	/**
	 * Sets group z-order.
	 * @param order New group z-order.
	 */
	virtual void											SetGroupOrder( const Order& order ) = 0;

	/**
	 * Sets sprite's z-order.
	 * @param order New sprite's z-order.
	 */
	virtual void											SetOrder( const Order& order ) = 0;

	/**
	 * Retrieves sprite's visibility state.
	 * @return True if the sprite is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves sprite stretching mode.
	 */
	virtual Bool											IsStretched() const = 0;

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
	 * Retrieves center of sprite rotation.
	 * @param [out] center Rotation center.
	 */
	virtual void											GetCenter( lang::Point& center ) const = 0;

	/**
	 * Retrieves sprite's location.
	 * @param [out] location Sprite's location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves sprite's size.
	 * @param [out] size Sprite's size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves sprite's orientation, in radians.
	 */
	virtual Float											GetOrientation() const = 0;

	/**
	 * Retrieves degree of sprite opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves a portion of the image that is displayed on the sprite.
	 * @param [out] frame Image frame.
	 */
	virtual void											GetFrame( lang::RectF& frame ) const = 0;

	/**
	 * Retrieves group z-order.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves sprite's z-order.
	 */
	virtual Order											GetOrder() const = 0;

	/**
	 * Retrieves sprite image.
	 */
	virtual img::IImage*									GetImage() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ISPRITE_
