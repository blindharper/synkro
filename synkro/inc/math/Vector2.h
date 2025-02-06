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
// Purpose: Defines 2-component vector.
//==============================================================================
#ifndef _SYNKRO_MATH_VECTOR2_
#define _SYNKRO_MATH_VECTOR2_


#include "config.h"


namespace synkro
{


namespace math
{


/**
 * 2-component floating point value vector.
 */
class SYNKRO_API Vector2
{
public:
	// Vector components.
	union
	{
		Float v[2];
		struct
		{
			Float x, y;
		};
	};

	/**
	 * Constructs default vector.
	 */
	Vector2();

	/**
	 * Copy constructor.
	 */
	Vector2( const Vector2& other );

	/**
	 * Constructs vector from a scalar value.
	 */
	explicit Vector2( Float value );

	/**
	 * Constructs vector from an array of 2 scalars.
	 * @exception BadArgumentException Invalid pointer.
	 */
	explicit Vector2( Float* array );

	/**
	 * Constructs vector from a pair of scalars.
	 */
	Vector2( Float x, Float y );

	/**
	 * Copy by reference.
	 */
	Vector2&												operator=( const Vector2& other );

	/**
	 * Adds another vector to this one.
	 */
	Vector2&												operator+=( const Vector2& other );

	/**
	 * Subtracts another vector from this one.
	 */
	Vector2&												operator-=( const Vector2& other );

	/**
	 * Multiplies vector by a scalar.
	 */
	Vector2&												operator*=( Float value );

	/**
	 * Divides vector by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector2&												operator/=( Float value );

	/**
	 * Makes vector normalized.
	 */
	Vector2&												Normalize();

	/**
	 * Returns inverted copy of the vector.
	 */
	Vector2													operator-() const;

	/**
	 * Returns the sum of this vector and another one.
	 */
	Vector2													operator+( const Vector2& other ) const;

	/**
	 * Returns the difference between this vector and another one.
	 */
	Vector2													operator-( const Vector2& other ) const;

	/**
	 * Returns this vector multiplied by a scalar.
	 */
	Vector2													operator*( Float value ) const;

	/**
	 * Returns this vector divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector2													operator/( Float value ) const;

	/**
	 * Computes dot product with another vector.
	 */
	Float													operator*( const Vector2& other ) const;

	/**
	 * Returns true for equal vectors.
	 */
	Bool													operator==( const Vector2& other ) const;

	/**
	 * Returns true for unequal vectors.
	 */
	Bool													operator!=( const Vector2& other ) const;

	/**
	 * Returns vector length.
	 */
	Float													Length() const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_VECTOR2_
