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
// Purpose: Defines a pool of overlay texts.
//==============================================================================
#ifndef _SYNKRO_OVER_ITEXTPOOL_
#define _SYNKRO_OVER_ITEXTPOOL_


#include "config.h"
#include <core/IObject.h>
#include <img/ColorGradient.h>
#include <lang/Point.h>
#include <lang/Rect.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay text pool.
 */
iface ITextPool :
	public core::IObject
{
public:
	/**
	 * Creates animation controller.
	 * @param animation Optional text pool animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual ITextPoolAnimationController*					CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Enables or disables the pool. Texts in the disabled pool are not visible.
	 * @param enable Set to true to enable the pool, set to false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Enables or disables clipping rectangle for all texts in the pool.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/**
	 * Sets texts clipping rectangle, in screen coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Sets text pool offset. Offset is applied to all texts in the pool. Default is (0.0, 0.0).
	 * @param offset New offset.
	 */
	virtual void											SetOffset( const lang::Point& offset ) = 0;

	/**
	 * Creates gradient text in the pool.
	 * @param gradient Gradient to apply to the text.
	 * @param location Text location.
	 * @param text Text string.
	 * @return Created text. The pool holds a strong reference to the text.
	 * @exception InvalidOperationException Pool capacity is exceeded.
	 */
	virtual IText*											CreateText( const img::ColorGradient& gradient, const lang::Point& location, const lang::String& text ) = 0;

	/**
	 * Creates colored text in the pool.
	 * @param color Text color.
	 * @param location Text location.
	 * @param text Text string.
	 * @return Created text. The pool holds a strong reference to the text.
	 * @exception InvalidOperationException Pool capacity is exceeded.
	 */
	virtual IText*											CreateText( const img::Color& color, const lang::Point& location, const lang::String& text ) = 0;

	/**
	 * Creates text in the pool.
	 * @param location Text location.
	 * @param text Text string.
	 * @return Created text. The pool holds a strong reference to the text.
	 * @exception InvalidOperationException Pool capacity is exceeded.
	 */
	virtual IText*											CreateText( const lang::Point& location, const lang::String& text ) = 0;

	/**
	 * Checks whether the pool is enabled.
	 */
	virtual Bool											IsEnabled() const = 0;

	/**
	 * Indicates whether the clipping rectangle is enabled.
	 */
	virtual Bool											IsRectEnabled() const = 0;

	/**
	 * Retrieves pool capacity.
	 */
	virtual UInt											GetCapacity() const = 0;

	/**
	 * Retrieves the number of texts in the pool.
	 */
	virtual UInt											GetTextCount() const = 0;

	/**
	 * Retrieves text by index.
	 * @param index Index of the text to retrieve.
	 * @return Requested text.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IText*											GetText( UInt index ) const = 0;

	/**
	 * Retrieves texts clipping rectangle, in screen coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves text pool offset.
	 * @param [out] offset Offset value.
	 */
	virtual void											GetOffset( lang::Point& offset ) const = 0;

	/**
	 * Retrieves group z-order of the texts in the pool.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves z-order of the texts in the pool.
	 */
	virtual Order											GetOrder() const = 0;

	/**
	 * Retrieves font used to draw texts in the pool.
	 */
	virtual IFont*											GetFont() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ITEXTPOOL_
