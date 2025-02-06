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
// Purpose: Defines quaternion.
//==============================================================================
#ifndef _SYNKRO_MATH_QUATERNION_
#define _SYNKRO_MATH_QUATERNION_


#include "config.h"
#include <math/Vector3.h>


namespace synkro
{


namespace math
{


/**
 * Quaternion.
 */
class SYNKRO_API Quaternion
{
public:
	// Quaternion components.
	union
	{
		Float q[4];
		struct
		{
			Float x, y, z, w;
		};
	};

	/**
	 * Identity quaternion.
	 */
	static const Quaternion									Identity;

	/**
	 * Constructs default quaternion.
	 */
	Quaternion();

	/**
	 * Copy constructor.
	 */
	Quaternion( const Quaternion& other );

	/**
	 * Constructs quaternion from an axis and a rotation angle.
	 */
	Quaternion( const Vector3& axis, Float angle );

	/**
	 * Constructs quaternion from Euler angles.
	 */
	Quaternion( Float yaw, Float pitch, Float roll );

	/**
	 * Constructs quaternion from a quadruple of scalars.
	 */
	Quaternion( Float x, Float y, Float z, Float w );

	/**
	 * Copy by reference.
	 */
	Quaternion&												operator=( const Quaternion& other );

	/**
	 * Adds another quaternion to this one.
	 */
	Quaternion&												operator+=( const Quaternion& other );

	/**
	 * Subtracts another quaternion from this one.
	 */
	Quaternion&												operator-=( const Quaternion& other );

	/**
	 * Multiplies quaternion by another one.
	 */
	Quaternion&												operator*=( const Quaternion& other );

	/**
	 * Multiplies quaternion by a scalar.
	 */
	Quaternion&												operator*=( Float value );

	/**
	 * Divides quaternion by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Quaternion&												operator/=( Float value );

	/**
	 * Makes quaternion normalized.
	 */
	Quaternion&												MakeNormal();

	/**
	 * Produces quaternion from Euler angles.
	 */
	Quaternion&												SetAngles( Float yaw, Float pitch, Float roll );

	/**
	 * Returns inverted copy of the quaternion.
	 */
	Quaternion												operator-() const;

	/**
	 * Returns the sum of this quaternion and another one.
	 */
	Quaternion												operator+( const Quaternion& other ) const;

	/**
	 * Returns the difference between this quaternion and another one.
	 */
	Quaternion												operator-( const Quaternion& other ) const;

	/**
	 * Returns this quaternion multiplied by another quaternion.
	 */
	Quaternion												operator*( const Quaternion& other ) const;

	/**
	 * Returns this quaternion multiplied by a scalar.
	 */
	Quaternion												operator*( Float value ) const;

	/**
	 * Returns this quaternion divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Quaternion												operator/( Float value ) const;

	/**
	 * Returns conjugated quaternion.
	 */
	Quaternion												Conjugate() const;

	/**
	 * Returns normalized quaternion.
	 */
	Quaternion												Normalize() const;

	/**
	 * Returns inverted quaternion.
	 */
	Quaternion												Inverse() const;

	/**
	 * Returns true for identity quaternion.
	 */
	Bool													IsIdentity() const;

	/**
	 * Returns true for equal quaternions.
	 */
	Bool													operator==( const Quaternion& other ) const;

	/**
	 * Returns true for unequal quaternions.
	 */
	Bool													operator!=( const Quaternion& other ) const;

	/**
	 * Returns quaternion's norm.
	 */
	Float													Norm() const;

	/**
	 * Returns quaternion's squared norm.
	 */
	Float													NormSquared() const;

	/**
	 * Returns quaternion's Euler angles.
	 */
	void													GetAngles( Float& yaw, Float& pitch, Float& roll ) const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_QUATERNION_
