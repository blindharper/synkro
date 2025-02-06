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
// Purpose: Defines whole number rectangle.
//==============================================================================
#ifndef _SYNKRO_LANG_RECT_
#define _SYNKRO_LANG_RECT_


#include "config.h"
#include <lang/Point.h>
#include <lang/Size.h>


namespace synkro
{


namespace lang
{


/**
 * Whole number rectangle.
 */
class SYNKRO_API Rect
{
public:
	// Rectangle borders.
	Int Left, Top, Right, Bottom;

	/** Invalid rectangle. */
	static const Rect										Invalid;

	/**
	 * Constructs rectangle from a set of scalars.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 */
	Rect( Int left, Int top, Int right, Int bottom );

	/**
	 * Constructs rectangle from corner and dimensions.
	 * @param topLeft Top left corner.
	 * @param size Rectangle size.
	 */
	Rect( const Point& topLeft, const Size& size );

	/**
	 * Copy constructor.
	 * @param other Rectangle to copy from.
	 */
	Rect( const Rect& other );

	/**
	 * Constructs an empty rectangle.
	 */
	Rect();

	/**
	 * Sets rectangle coordinates.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 * @param right Right coordinate.
	 * @param bottom Bottom coordinate.
	 */
	Rect&													Set( Int left, Int top, Int right, Int bottom );

	/**
	 * Sets rectangle corners.
	 * @param topLeft Top left corner.
	 * @param bottomRight Bottom right corner.
	 */
	Rect&													Set( const Point& topLeft, const Point& bottomRight );

	/**
	 * Sets rectangle corner and dimensions.
	 * @param topLeft Top left corner.
	 * @param size Rectangle size.
	 */
	Rect&													Set( const Point& topLeft, const Size& size );

	/**
	 * Sets rectangle position.
	 * @param left Left coordinate.
	 * @param top Top coordinate.
	 */
	Rect&													Move( Int left, Int top );

	/**
	 * Adjusts rectangle position.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	Rect&													Offset( Int x, Int y );

	/**
	 * Sets rectangle size.
	 * @param width New width.
	 * @param height New height.
	 */
	Rect&													SetSize( Int width, Int height );

	/**
	 * Increases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	Rect&													Inflate( Int x, Int y );

	/**
	 * Decreases rectangle dimensions.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	Rect&													Deflate( Int x, Int y );

	/**
	 * Centers the rectangle within another one.
	 * @param other Base rectangle.
	 */
	Rect&													Center( const Rect& other );

	/**
	 * Intersects this rectangle with another one.
	 * @param other Rectangle to intersect with.
	 */
	Rect&													Intersect( const Rect& other );

	/**
	 * Empties the rectangle by setting its coordinates to zero.
	 */
	Rect&													Empty();

	/**
	 * Copy by reference.
	 * @param other Rectangle to copy from.
	 */
	Rect&													operator=( const Rect& other );

	/**
	 * Tests two rectangles for equality.
	 * @param other Rectangle to compate to.
	 * @return True for equal rectangles, false otherwise.
	 */
	Bool													operator==( const Rect& other ) const;

	/**
	 * Tests two rectangles for inequality.
	 * @param other Rectangle to compate to.
	 * @return True for unequal rectangles, false otherwise.
	 */
	Bool													operator!=( const Rect& other ) const;

	/**
	 * Returns inflated rectangle.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	Rect													Inflated( Int x, Int y ) const;

	/**
	 * Returns deflated rectangle.
	 * @param x Horizontal offset.
	 * @param y Vertical offset.
	 */
	Rect													Deflated( Int x, Int y ) const;

	/**
	 * Returns rectangle centered within another one.
	 * @param other Base rectangle.
	 * @return Centered rectangle.
	 */
	Rect													Centered( const Rect& other ) const;

	/**
	 * Returns intersection with another rectangle.
	 * @param other Rectangle to intersect with.
	 * @return rectangles intersection.
	 */
	Rect													Intersection( const Rect& other ) const;

	/**
	 * Checks whether the specified point is inside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is inside the rectangle.
	 */
	Bool													IsInside( const Point& point ) const;

	/**
	 * Checks whether the specified point is outside the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point is outside the rectangle.
	 */
	Bool													IsOutside( const Point& point ) const;

	/**
	 * Checks whether the specified point lays on the rectangle borders.
	 * @param point Point to test.
	 * @return True if the point lays on the rectangle borders.
	 */
	Bool													IsOnBorder( const Point& point ) const;

	/**
	 * Returns true if all rectangle dimensions are set to zero.
	 */
	Bool													IsNull() const;

	/**
	 * Returns true if either width or height of the rectangle equals to zero.
	 */
	Bool													IsEmpty() const;

	/**
	 * Retrieves top left corner.
	 */
	Point													TopLeft() const;

	/**
	 * Retrieves bottom right corner.
	 */
	Point													BottomRight() const;

	/**
	 * Retrieves rectangle width.
	 */
	Int														Width() const;

	/**
	 * Retrieves rectangle height.
	 */
	Int														Height() const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_RECT_
