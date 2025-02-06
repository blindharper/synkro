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
	RectF( Float left, Float top, Float right, Float bottom );

	/**
	 * Copy constructor.
	 * @param other Rectangle to copy from.
	 */
	RectF( const RectF& other );

	/**
	 * Constructs an empty rectangle.
	 */
	RectF();

	/**
	 * Sets rectangle coordinates.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 */
	RectF&													Set( Float left, Float top, Float right, Float bottom );

	/**
	 * Sets rectangle position.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 */
	RectF&													Move( Float left, Float top );

	/**
	 * Adjusts rectangle position.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Offset( Float x, Float y );

	/**
	 * Sets rectangle size.
	 * @param width New width.
	 * @param height New height.
	 */
	RectF&													SetSize( Float width, Float height );

	/**
	 * Increases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Inflate( Float x, Float y );

	/**
	 * Decreases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	RectF&													Deflate( Float x, Float y );

	/**
	 * Centers the rectangle against another one.
	 * @param other Base rectangle.
	 */
	RectF&													Center( RectF& other );

	/**
	 * Empties the rectangle by setting its coordinates to zero.
	 */
	RectF&													Empty();

	/**
	 * Copy by reference.
	 * @param other Rectangle to copy from.
	 */
	RectF&													operator=( const RectF& other );

	/**
	 * Tests two rectangles for equality.
	 * @param other Rectangle to compate to.
	 * @return True for equal rectangles, false otherwise.
	 */
	Bool													operator==( const RectF& other ) const;

	/**
	 * Tests two rectangles for inequality.
	 * @param other Rectangle to compate to.
	 * @return True for unequal rectangles, false otherwise.
	 */
	Bool													operator!=( const RectF& other ) const;

	/**
	 * Checks whether the specified point is inside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is inside the rectangle.
	 */
	Bool													IsInside( const PointF& point ) const;

	/**
	 * Checks whether the specified point is outside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is outside the rectangle.
	 */
	Bool													IsOutside( const PointF& point ) const;

	/**
	 * Checks whether the specified point lays on the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point lays on the rectangle borders.
	 */
	Bool													IsOnBorder( const PointF& point ) const;

	/**
	 * Returns true if all rectangle dimensions are set to zero.
	 */
	Bool													IsNull() const;

	/**
	 * Returns true if either width or height of the rectangle equals to zero.
	 */
	Bool													IsEmpty() const;

	/**
	 * Retrieves rectangle width.
	 */
	Float													Width() const;

	/**
	 * Retrieves rectangle height.
	 */
	Float													Height() const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_RECTF_
