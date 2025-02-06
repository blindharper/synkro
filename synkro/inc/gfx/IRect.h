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
// Purpose: Defines abstract rectangle.
//==============================================================================
#ifndef _SYNKRO_GFX_IRECT_
#define _SYNKRO_GFX_IRECT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract rectangle.
 */
iface IRect :
	public core::IObject
{
public:
	/**
	 * Binds rectangle to the pipeline.
	 */
	virtual void											Bind() = 0;

	/**
	 * Sets rectangle's origin and dimensions.
	 * @param left Left rectangle coordinate relative to the current target.
	 * @param top Top rectangle coordinate relative to the current target.
	 * @param right Right coordinate of the rectangle, in pixels.
	 * @param bottom Bottom coordinate of the rectangle, in pixels.
	 */
	virtual void											SetBounds( Int left, Int top, Int right, Int bottom ) = 0;

	/**
	 * Sets rectangle's origin.
	 * @param left Left rectangle coordinate relative to the current target.
	 * @param top Top rectangle coordinate relative to the current target.
	 */
	virtual void											SetLocation( Int left, Int top ) = 0;

	/**
	 * Sets rectangle's dimensions.
	 * @param width Rectangle width.
	 * @param height Rectangle height.
	 */
	virtual void											SetSize( UInt width, UInt height ) = 0;

	/**
	 * Retrieves rectangle's origin and dimensions.
	 * @param [out] left Coordinate of left rectangle border.
	 * @param [out] top Coordinate of top rectangle border.
	 * @param [out] right Rectangle right.
	 * @param [out] bottom Rectangle bottom.
	 */
	virtual void											GetBounds( Int& left, Int& top, Int& right, Int& bottom ) const = 0;

	/**
	 * Retrieves rectangle's origin.
	 * @param [out] left Left rectangle coordinate relative to the current target.
	 * @param [out] top Top rectangle coordinate relative to the current target.
	 */
	virtual void											GetLocation( Int& left, Int& top ) const = 0;

	/**
	 * Retrieves rectangle's dimensions.
	 * @param [out] width Rectangle width.
	 * @param [out] height Rectangle height.
	 */
	virtual void											GetSize( UInt& width, UInt& height ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRECT_
