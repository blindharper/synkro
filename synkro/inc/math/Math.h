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
// Purpose: Defines mathematical library.
//==============================================================================
#ifndef _SYNKRO_MATH_MATH_
#define _SYNKRO_MATH_MATH_


#include "config.h"


namespace synkro
{


/**
 * The 'math' namespace contains classes applicable to
 * affine transformations and trigonometry.
 */
namespace math
{


/**
 * Contains widely-used numeric operations and constants.
 */
class SYNKRO_API Math
{
public:
	/**
	 * The base of the natural logarithm.
	 */
	static const Float										E;

	/**
	 * The ratio of the circumference of a circle to its diameter.
	 */
	static const Float										Pi;

	/**
	 * Double PI.
	 */
	static const Float										TwoPi;

	/**
	 * 1/2 PI.
	 */
	static const Float										HalfPi;

	/**
	 * 1/4 PI.
	 */
	static const Float										QuarterPi;

	/**
	 * Calculation accuracy.
	 */
	static const Float										Eps;

	/**
	 * Minimum floating-point value.
	 */
	static const Float										MinFloat;

	/**
	 * Maximum floating-point value.
	 */
	static const Float										MaxFloat;

	/**
	 * Returns the absolute value of the given number.
	 */
	static Float											Abs( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the sign of the given value.
	 */
	static Float											Sign( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the nearest integer greater than the given value.
	 */
	static Float											Ceil( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the nearest integer less than the given value.
	 */
	static Float											Floor( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the integral part of the given value.
	 */
	static Float											Trunc( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the fractional part of the given value.
	 */
	static Float											Frac( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Rounds a value to the nearest integer.
	 */
	static Float											Round( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns square root of the given value.
	 */
	static Float											Sqrt( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns inverse square root of the given value.
	 */
	static Float											InvSqrt( Float value );

	/**
	 * Returns the given value to the given power.
	 */
	static Float											Pow( Float value, Float power ) SYNKRO_NOEXCEPT;

	/**
	 * Returns exponent of the given value.
	 */
	static Float											Exp( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns natural logarithm of the given value.
	 */
	static Float											Log( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Returns base-10 logarithm of the given value.
	 */
	static Float											Log10( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Converts degrees to radians.
	 */
	static Float											ToRadians( Float degrees ) SYNKRO_NOEXCEPT;

	/**
	 * Converts radians to degrees.
	 */
	static Float											ToDegrees( Float radians ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates sine of the given angle, in radians.
	 */
	static Float											Sin( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates hyperbolic sine of the given angle, in radians.
	 */
	static Float											Sinh( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates arcsine of the given value.
	 */
	static Float											Asin( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates cosine of the given angle, in radians.
	 */
	static Float											Cos( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates hyperbolic cosine of the given angle, in radians.
	 */
	static Float											Cosh( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates arccosine of the given value.
	 */
	static Float											Acos( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates tangent of the given angle, in radians.
	 */
	static Float											Tan( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates hyperbolic tangent of the given angle, in radians.
	 */
	static Float											Tanh( Float angle ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates arctangent of the given value.
	 */
	static Float											Atan( Float value ) SYNKRO_NOEXCEPT;

	/**
	 * Calculates principal value of the arc tangent of y/x.
	 */
	static Float											Atan2( Float y, Float x ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the smaller of the two numbers.
	 */
	static Float											Min( Float x, Float y ) SYNKRO_NOEXCEPT;

	/**
	 * Returns the larger of the two numbers.
	 */
	static Float											Max( Float x, Float y ) SYNKRO_NOEXCEPT;

	/**
	 * Clamps the given value to the given minimum and maximum range.
	 */
	static Float											Clamp( Float value, Float min, Float max ) SYNKRO_NOEXCEPT;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_MATH_
