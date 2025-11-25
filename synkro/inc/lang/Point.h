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
// Purpose: Defines Whole number point.
//==============================================================================
#ifndef _SYNKRO_LANG_POINT_
#define _SYNKRO_LANG_POINT_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Whole number point.
 */
class SYNKRO_API Point
{
public:
	// Point coordinates.
	Int X, Y;

	/**
	 * Constructs a point with the given coordinates.
	 * @param x Horizontal coordinate.
	 * @param y Vertical coordinate.
	 */
	Point( Int x, Int y ) SYNKRO_NOEXCEPT;

	/**
	 * Copy constructor.
	 */
	Point( const Point& other ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs an empty point.
	 */
	Point() SYNKRO_NOEXCEPT;

	/**
	 * Sets point coordinates.
	 * @param x Horizontal coordinate.
	 * @param y Vertical coordinate.
	 */
	Point&													Set( Int x, Int y ) SYNKRO_NOEXCEPT;

	/**
	 * Adjusts point coordinates by the given offset.
	 * @param x Horizontal adjustment.
	 * @param y Vertical adjustment.
	 */
	Point													Offset( Int x, Int y ) const SYNKRO_NOEXCEPT;

	/**
	 * Copy by reference.
	 */
	Point&													operator=( const Point& other ) SYNKRO_NOEXCEPT;

	/**
	 * Adds another point to this one.
	 */
	Point&													operator+=( const Point& other ) SYNKRO_NOEXCEPT;

	/**
	 * Subtracts another point from this one.
	 */
	Point&													operator-=( const Point& other ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the sum of this point and another one.
	 * @param other Point to add to this one.
	 */
	Point													operator+( const Point& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns the difference between this point and another one.
	 * @param other Point to subtract from this one.
	 */
	Point													operator-( const Point& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two points for equality.
	 * @param other Point to compare to.
	 * @return True for equal points, false otherwise.
	 */
	Bool													operator==( const Point& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests two points for inequality.
	 * @param other Point to compare to.
	 * @return True for unequal points, false otherwise.
	 */
	Bool													operator!=( const Point& other ) const SYNKRO_NOEXCEPT;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_POINT_
