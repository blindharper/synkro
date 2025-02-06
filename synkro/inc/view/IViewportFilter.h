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
// Purpose: Defines viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTFILTER_
#define _SYNKRO_VIEW_IVIEWPORTFILTER_


#include "config.h"
#include <core/IObject.h>
#include <lang/Rect.h>


namespace synkro
{


namespace view
{


/**
 * Viewport filter. Provides post-processing functionality.
 */
iface IViewportFilter :
	public core::IObject
{
public:
	/**
	 * Creates viewport filter controller.
	 * @param animation Optional filter animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual IViewportFilterAnimationController*				CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Updates filter's internal state.
	 */
	virtual void											Update() = 0;

	/**
	 * Enables or disables filter.
	 * @param enable True to enable filter, false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/** 
	 * Enables or disables clipping rectangle.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/**
	 * Sets clipping rectangle, in window coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Sets filter's order in the processing chain.
	 */
	virtual void											SetOrder( UInt order ) = 0;

	/**
	 * Checks whether the filter is enabled.
	 */
	virtual Bool											IsEnabled() const = 0;

	/** 
	 * Indicates whether the clipping rectangle is enabled.
	 */
	virtual Bool											IsRectEnabled() const = 0;

	/**
	 * Retrieves clipping rectangle, in window coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves filter's order in the processing chain.
	 */
	virtual UInt											GetOrder() const = 0;

	/**
	 * Casts filter to simple filter.
	 * @return Non-null for simple filter, nullptr otherwise.
	 */
	virtual ISimpleFilter*									AsSimple() const = 0;

	/**
	 * Casts filter to color filter.
	 * @return Non-null for color filter, nullptr otherwise.
	 */
	virtual IColorFilter*									AsColor() const = 0;

	/**
	 * Casts filter to depth filter.
	 * @return Non-null for depth filter, nullptr otherwise.
	 */
	virtual IDepthFilter*									AsDepth() const = 0;

	/**
	 * Casts filter to kernel 3x3 filter.
	 * @return Non-null for kernel 3x3 filter, nullptr otherwise.
	 */
	virtual IKernel3x3Filter*								AsKernel3x3() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTFILTER_
