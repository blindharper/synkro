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
// Purpose: Defines floating-point value rectangle.
//==============================================================================
#ifndef _SYNKRO_LANG_RECTF_
#define _SYNKRO_LANG_RECTF_


#include "config.h"
#include <lang/PointF.h>


namespace synkro
{


namespace lang
{


/**
 * Floating-point value rectangle.
 */
class SYNKRO_API RectF
{
public:
	// Rectangle borders.
	Float Left, Top, Right, Bottom;

	/** Invalid rectangle. */
	static const RectF										Invalid;

	/**
	 * Constructs rectangle from a set of scalars.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 */
	RectF( Float left, Float top, Float right, Float bottom ) SYNKRO_NOEXCEPT;

	/**
	 * Copy constructor.
	 * @param other Rectangle to copy from.
	 */
	RectF( const RectF& other ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs an empty rectangle.
	 */
	RectF() SYNKRO_NOEXCEPT;

	/**
	 * Sets rectangle coordinates.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 */
	RectF&													Set( Float left, Float top, Float right, Float bottom ) SYNKRO_NOEXCEPT;

	/**
	 * Sets rectangle position.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 */
	RectF&													Move( Float left, Float top ) SYNKRO_NOEXCEPT;

	/**
	 * Adjusts rectangle position.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Offset( Float x, Float y ) SYNKRO_NOEXCEPT;

	/**
	 * Sets rectangle size.
	 * @param width New width.
	 * @param height New height.
	 */
	RectF&													SetSize( Float width, Float height ) SYNKRO_NOEXCEPT;

	/**
	 * Increases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Inflate( Float x, Float y ) SYNKRO_NOEXCEPT;

	/**
	 * Decreases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Deflate( Float x, Float y ) SYNKRO_NOEXCEPT;

	/**
	 * Centers the rectangle against another one.
	 * @param other Base rectangle.
	 */
	RectF&													Center( RectF& other ) SYNKRO_NOEXCEPT;

	/**
	 * Empties the rectangle by setting its coordinates to zero.
	 */
	RectF&													Empty() SYNKRO_NOEXCEPT;

	/**
	 * Copy by reference.
	 * @param other Rectangle to copy from.
	 */
	RectF&													operator=( const RectF& other ) SYNKRO_NOEXCEPT;

	/**
	 * Tests two rectangles for equality.
	 * @param other Rectangle to compate to.
	 * @return True for equal rectangles, false otherwise.
	 */
	Bool													operator==( const RectF& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two rectangles for inequality.
	 * @param other Rectangle to compate to.
	 * @return True for unequal rectangles, false otherwise.
	 */
	Bool													operator!=( const RectF& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Checks whether the specified point is inside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is inside the rectangle.
	 */
	Bool													IsInside( const PointF& point ) const SYNKRO_NOEXCEPT;

	/**
	 * Checks whether the specified point is outside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is outside the rectangle.
	 */
	Bool													IsOutside( const PointF& point ) const SYNKRO_NOEXCEPT;

	/**
	 * Checks whether the specified point lays on the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point lays on the rectangle borders.
	 */
	Bool													IsOnBorder( const PointF& point ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns true if all rectangle dimensions are set to zero.
	 */
	Bool													IsNull() const SYNKRO_NOEXCEPT;

	/**
	 * Returns true if either width or height of the rectangle equals to zero.
	 */
	Bool													IsEmpty() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves rectangle width.
	 */
	Float													Width() const SYNKRO_NOEXCEPT;

	/**
	 * Retrieves rectangle height.
	 */
	Float													Height() const SYNKRO_NOEXCEPT;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_RECTF_
