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
// Purpose: Defines 3-component vector.
//==============================================================================
#ifndef _SYNKRO_MATH_VECTOR3_
#define _SYNKRO_MATH_VECTOR3_


#include "config.h"


namespace synkro
{


namespace math
{


/**
 * 3-component floating point value vector.
 */
class SYNKRO_API Vector3
{
public:
	// Vector components.
	union
	{
		Float v[3];
		struct
		{
			Float x, y, z;
		};
	};

	/**
	 * Invalid vector.
	 */
	static const Vector3									Invalid;

	/**
	 * Origin of coordinates.
	 */
	static const Vector3									Origin;

	/**
	 * X-unit axis.
	 */
	static const Vector3									X;

	/**
	 * Y-unit axis.
	 */
	static const Vector3									Y;

	/**
	 * Z-unit axis.
	 */
	static const Vector3									Z;

	/**
	 * Constructs default vector.
	 */
	Vector3();

	/**
	 * Copy constructor.
	 */
	Vector3( const Vector3& other );

	/**
	 * Constructs vector from a scalar value.
	 */
	explicit Vector3( Float value );

	/**
	 * Constructs vector from an array of 3 scalars.
	 * @exception BadArgumentException Invalid pointer.
	 */
	explicit Vector3( Float* array );

	/**
	 * Constructs vector from a triplet of scalars.
	 */
	Vector3( Float x, Float y, Float z );

	/**
	 * Copy by reference.
	 */
	Vector3&												operator=( const Vector3& other );

	/**
	 * Adds another vector to this one.
	 */
	Vector3&												operator+=( const Vector3& other );

	/**
	 * Subtracts another vector from this one.
	 */
	Vector3&												operator-=( const Vector3& other );

	/**
	 * Multiplies vector by a scalar.
	 */
	Vector3&												operator*=( Float value );

	/**
	 * Divides vector by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector3&												operator/=( Float value );

	/**
	 * Makes vector normalized.
	 */
	Vector3&												Normalize();

	/**
	 * Returns inverted copy of the vector.
	 */
	Vector3													operator-() const;

	/**
	 * Returns the sum of this vector and another one.
	 */
	Vector3													operator+( const Vector3& other ) const;

	/**
	 * Returns the difference between this vector and another one.
	 */
	Vector3													operator-( const Vector3& other ) const;

	/**
	 * Returns this vector multiplied by a scalar.
	 */
	Vector3													operator*( Float value ) const;

	/**
	 * Returns this vector divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Vector3													operator/( Float value ) const;

	/**
	 * Computes cross product with another vector.
	 */
	Vector3													operator^( const Vector3& other ) const;

	/**
	 * Computes dot product with another vector.
	 */
	Float													operator*( const Vector3& other ) const;

	/**
	 * Returns true for equal vectors.
	 */
	Bool													operator==( const Vector3& other ) const;

	/**
	 * Returns true for unequal vectors.
	 */
	Bool													operator!=( const Vector3& other ) const;

	/**
	 * Returns vector length.
	 */
	Float													Length() const;

	/**
	 * Returns vector squared length.
	 */
	Float													LengthSquared() const;

	/**
	 * Rotates the vector around arbitrary axis.
	 * @param axis Axis around which to rotate the vector.
	 * @param angle Angle, in radians, for which to rotate the vector.
	 * @return Rotated vector.
	 */
	Vector3													Rotate( const Vector3& axis, Float angle ) const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_VECTOR3_
