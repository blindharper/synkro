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
	static Float											Abs( Float value );

	/**
	 * Returns the sign of the given value.
	 */
	static Float											Sign( Float value );

	/**
	 * Returns the nearest integer greater than the given value.
	 */
	static Float											Ceil( Float value );

	/**
	 * Returns the nearest integer less than the given value.
	 */
	static Float											Floor( Float value );

	/**
	 * Returns the integral part of the given value.
	 */
	static Float											Trunc( Float value );

	/**
	 * Returns the fractional part of the given value.
	 */
	static Float											Frac( Float value );

	/**
	 * Rounds a value to the nearest integer.
	 */
	static Float											Round( Float value );

	/**
	 * Returns square root of the given value.
	 */
	static Float											Sqrt( Float value );

	/**
	 * Returns inverse square root of the given value.
	 */
	static Float											InvSqrt( Float value );

	/**
	 * Returns the given value to the given power.
	 */
	static Float											Pow( Float value, Float power );

	/**
	 * Returns exponent of the given value.
	 */
	static Float											Exp( Float value );

	/**
	 * Returns natural logarithm of the given value.
	 */
	static Float											Log( Float value );

	/**
	 * Returns base-10 logarithm of the given value.
	 */
	static Float											Log10( Float value );

	/**
	 * Converts degrees to radians.
	 */
	static Float											ToRadians( Float degrees );

	/**
	 * Converts radians to degrees.
	 */
	static Float											ToDegrees( Float radians );

	/**
	 * Calculates sine of the given angle, in radians.
	 */
	static Float											Sin( Float angle );

	/**
	 * Calculates hyperbolic sine of the given angle, in radians.
	 */
	static Float											Sinh( Float angle );

	/**
	 * Calculates arcsine of the given value.
	 */
	static Float											Asin( Float value );

	/**
	 * Calculates cosine of the given angle, in radians.
	 */
	static Float											Cos( Float angle );

	/**
	 * Calculates hyperbolic cosine of the given angle, in radians.
	 */
	static Float											Cosh( Float angle );

	/**
	 * Calculates arccosine of the given value.
	 */
	static Float											Acos( Float value );

	/**
	 * Calculates tangent of the given angle, in radians.
	 */
	static Float											Tan( Float angle );

	/**
	 * Calculates hyperbolic tangent of the given angle, in radians.
	 */
	static Float											Tanh( Float angle );

	/**
	 * Calculates arctangent of the given value.
	 */
	static Float											Atan( Float value );

	/**
	 * Calculates principal value of the arc tangent of y/x.
	 */
	static Float											Atan2( Float y, Float x );

	/**
	 * Returns the smaller of the two numbers.
	 */
	static Float											Min( Float x, Float y );

	/**
	 * Returns the larger of the two numbers.
	 */
	static Float											Max( Float x, Float y );

	/**
	 * Clamps the specified value to the given minimum and maximum range.
	 */
	static Float											Clamp( Float value, Float min, Float max );
};


} // math


} // synkro


#endif // _SYNKRO_MATH_MATH_
