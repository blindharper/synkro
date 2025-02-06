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
// Purpose: Defines a pool of overlay sprites.
//==============================================================================
#ifndef _SYNKRO_OVER_ISPRITEPOOL_
#define _SYNKRO_OVER_ISPRITEPOOL_


#include "config.h"
#include <core/IObject.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <lang/RectF.h>
#include <over/Order.h>


namespace synkro
{


namespace over
{


/**
 * Overlay sprite pool.
 */
iface ISpritePool :
	public core::IObject
{
public:
	/**
	 * Enables or disables the pool. Sprites in the disabled pool are not visible.
	 * @param enable Set to true to enable the pool, set to false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Enables or disables clipping rectangle for all sprites in the pool.
	 * @param enable Set to true to enable clipping rectangle, set to false to disable it.
	 */
	virtual void											EnableRect( Bool enable ) = 0;

	/**
	 * Sets sprites clipping rectangle, in screen coordinates.
	 * @param rect Clipping rectangle.
	 */
	virtual void											SetRect( const lang::Rect& rect ) = 0;

	/**
	 * Creates a stretched sprite in the pool.
	 * @param location Sprite location.
	 * @param size Sprite size.
	 * @param frame Image frame.
	 * @return Created sprite. The pool holds a strong reference to the sprite.
	 * @exception InvalidOperationException Pool capacity is exceeded.
	 */
	virtual ISprite*										CreateSprite( const lang::Point& location, const lang::Size& size, const lang::RectF& frame ) = 0;

	/**
	 * Creates a sprite in the pool.
	 * @param location Sprite location.
	 * @param frame Image frame.
	 * @return Created sprite. The pool holds a strong reference to the sprite.
	 * @exception InvalidOperationException Pool capacity is exceeded.
	 */
	virtual ISprite*										CreateSprite( const lang::Point& location, const lang::RectF& frame ) = 0;

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
	 * Retrieves the number of sprites in the pool.
	 */
	virtual UInt											GetSpriteCount() const = 0;

	/**
	 * Retrieves sprite by index.
	 * @param index Index of the sprite to retrieve.
	 * @return Requested sprite.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ISprite*										GetSprite( UInt index ) const = 0;

	/**
	 * Retrieves sprites clipping rectangle, in screen coordinates.
	 * @param [out] rect Clipping rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves group z-order of the sprites in the pool.
	 */
	virtual Order											GetGroupOrder() const = 0;

	/**
	 * Retrieves z-order of the sprites in the pool.
	 */
	virtual Order											GetOrder() const = 0;

	/**
	 * Retrieves image used to draw sprites in the pool.
	 */
	virtual img::IImage*									GetImage() const = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_ISPRITEPOOL_
