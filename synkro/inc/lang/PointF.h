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
// Purpose: Defines floating-point point.
//==============================================================================
#ifndef _SYNKRO_LANG_POINTF_
#define _SYNKRO_LANG_POINTF_


#include "config.h"


namespace synkro
{


namespace lang
{


/**
 * Floating-point point.
 */
class SYNKRO_API PointF
{
public:
	// PointF coordinates.
	Float X, Y;

	/**
	 * Constructs a point with the given coordinates.
	 * @param x Horizontal coordinate.
	 * @param y Vertical coordinate.
	 */
	PointF( Float x, Float y );

	/**
	 * Copy constructor.
	 */
	PointF( const PointF& other );

	/**
	 * Constructs an empty point.
	 */
	PointF();

	/**
	 * Sets point coordinates.
	 * @param x Horizontal coordinate.
	 * @param y Vertical coordinate.
	 */
	PointF&													Set( Float x, Float y );

	/**
	 * Copy by reference.
	 */
	PointF&													operator=( const PointF& other );

	/**
	 * Adds another point to this one.
	 */
	PointF&													operator+=( const PointF& other );

	/**
	 * Subtracts another point from this one.
	 */
	PointF&													operator-=( const PointF& other );

	/**
	 * Returns the difference between this point and another one.
	 */
	PointF													operator-( const PointF& other ) const;

	/**
	 * Tests two points for equality.
	 * @param other PointF to compare to.
	 * @return True for equal points, false otherwise.
	 */
	Bool													operator==( const PointF& other ) const;

	/**
	 * Tests two points for inequality.
	 * @param other PointF to compare to.
	 * @return True for unequal points, false otherwise.
	 */
	Bool													operator!=( const PointF& other ) const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_POINTF_
