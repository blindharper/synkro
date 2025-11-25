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
	Quaternion() SYNKRO_NOEXCEPT;

	/**
	 * Copy constructor.
	 */
	Quaternion( const Quaternion& other ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs quaternion from an axis and a rotation angle.
	 */
	Quaternion( const Vector3& axis, Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs quaternion from Euler angles.
	 */
	Quaternion( Float yaw, Float pitch, Float roll ) SYNKRO_NOEXCEPT;

	/**
	 * Constructs quaternion from a quadruple of scalars.
	 */
	Quaternion( Float x, Float y, Float z, Float w ) SYNKRO_NOEXCEPT;

	/**
	 * Copy by reference.
	 */
	Quaternion&												operator=( const Quaternion& other ) SYNKRO_NOEXCEPT;

	/**
	 * Adds another quaternion to this one.
	 */
	Quaternion&												operator+=( const Quaternion& other ) SYNKRO_NOEXCEPT;

	/**
	 * Subtracts another quaternion from this one.
	 */
	Quaternion&												operator-=( const Quaternion& other ) SYNKRO_NOEXCEPT;

	/**
	 * Multiplies quaternion by another one.
	 */
	Quaternion&												operator*=( const Quaternion& other ) SYNKRO_NOEXCEPT;

	/**
	 * Multiplies quaternion by a scalar.
	 */
	Quaternion&												operator*=( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Divides quaternion by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Quaternion&												operator/=( Float value );

	/**
	 * Makes quaternion normalized.
	 */
	Quaternion&												MakeNormal() SYNKRO_NOEXCEPT;

	/**
	 * Produces quaternion from Euler angles.
	 */
	Quaternion&												SetAngles( Float yaw, Float pitch, Float roll ) SYNKRO_NOEXCEPT;

	/**
	 * Returns inverted copy of the quaternion.
	 */
	Quaternion												operator-() const SYNKRO_NOEXCEPT;

	/**
	 * Returns the sum of this quaternion and another one.
	 */
	Quaternion												operator+( const Quaternion& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns the difference between this quaternion and another one.
	 */
	Quaternion												operator-( const Quaternion& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns this quaternion multiplied by another quaternion.
	 */
	Quaternion												operator*( const Quaternion& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns this quaternion multiplied by a scalar.
	 */
	Quaternion												operator*( Float value ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns this quaternion divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Quaternion												operator/( Float value ) const;

	/**
	 * Returns conjugated quaternion.
	 */
	Quaternion												Conjugate() const SYNKRO_NOEXCEPT;

	/**
	 * Returns normalized quaternion.
	 */
	Quaternion												Normalize() const SYNKRO_NOEXCEPT;

	/**
	 * Returns inverted quaternion.
	 */
	Quaternion												Inverse() const SYNKRO_NOEXCEPT;

	/**
	 * Returns true for identity quaternion.
	 */
	Bool													IsIdentity() const SYNKRO_NOEXCEPT;

	/**
	 * Returns true for equal quaternions.
	 */
	Bool													operator==( const Quaternion& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns true for unequal quaternions.
	 */
	Bool													operator!=( const Quaternion& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns quaternion's norm.
	 */
	Float													Norm() const SYNKRO_NOEXCEPT;

	/**
	 * Returns quaternion's squared norm.
	 */
	Float													NormSquared() const SYNKRO_NOEXCEPT;

	/**
	 * Returns quaternion's Euler angles.
	 */
	void													GetAngles( Float& yaw, Float& pitch, Float& roll ) const SYNKRO_NOEXCEPT;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_QUATERNION_
