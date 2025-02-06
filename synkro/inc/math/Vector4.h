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
// Purpose: Defines 4-component vector.
//==============================================================================
#ifndef _SYNKRO_MATH_VECTOR4_
#define _SYNKRO_MATH_VECTOR4_


#include "config.h"
#include <math/Vector3.h>


namespace synkro
{


namespace math
{


/**
 * 4-component floating point value vector.
 */
class SYNKRO_API Vector4
{
public:
	// Vector components.
	union
	{
		Float v[4];
		struct
		{
			Float x, y, z, w;
		};
	};

	/**
	 * Constructs default vector.
	 */
	Vector4();

	/**
	 * Copy constructor.
	 */
	Vector4( const Vector4& other );

	/**
	 * Constructs vector from a scalar value.
	 */
	explicit Vector4( Float value );

	/**
	 * Constructs vector from an array of 4 scalars.
	 * @exception BadArgumentException Invalid pointer.
	 */
	explicit Vector4( Float* array );

	/**
	 * Constructs vector from a quadruple of scalars.
	 */
	Vector4( Float x, Float y, Float z, Float w );

	/**
	 * Constructs vector from a 3-component vector and a scalar.
	 */
	Vector4( const Vector3& other, Float w );

	/**
	 * Constructs vector from a 3-component vector.
	 */
	Vector4( const Vector3& other );

	/**
	 * Copy by reference.
	 */
	Vector4&												operator=( const Vector4& other );

	/**
	 * Adds another vector to this one.
	 */
	Vector4&												operator+=( const Vector4& other );

	/**
	 * Subtracts another vector from this one.
	 */
	Vector4&												operator-=( const Vector4& other );

	/**
	 * Multiplies vector by a scalar.
	 */
	Vector4&												operator*=( Float value );

	/**
	 * Divides vector by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector4&												operator/=( Float value );

	/**
	 * Makes vector normalized.
	 */
	Vector4&												Normalize();

	/**
	 * Returns inverted copy of the vector.
	 */
	Vector4													operator-() const;

	/**
	 * Returns the sum of this vector and another one.
	 */
	Vector4													operator+( const Vector4& other ) const;

	/**
	 * Returns the difference between this vector and another one.
	 */
	Vector4													operator-( const Vector4& other ) const;

	/**
	 * Returns this vector multiplied by a scalar.
	 */
	Vector4													operator*( Float value ) const;

	/**
	 * Returns this vector divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector4													operator/( Float value ) const;

	/**
	 * Computes cross product with another vector.
	 */
	Vector4													operator^( const Vector4& other ) const;

	/**
	 * Computes dot product with another vector.
	 */
	Float													operator*( const Vector4& other ) const;

	/**
	 * Returns true for equal vectors.
	 */
	Bool													operator==( const Vector4& other ) const;

	/**
	 * Returns true for unequal vectors.
	 */
	Bool													operator!=( const Vector4& other ) const;

	/**
	 * Returns vector length.
	 */
	Float													Length() const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_VECTOR4_
