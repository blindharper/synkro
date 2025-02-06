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
#include "config.h"
#include <math/Math.h>
#include <limits>


namespace synkro
{


namespace math
{


#undef min
#undef max


const Float Math::E = 2.718281828459045f;
const Float Math::Pi = 4.0f*atanf(1.0f);
const Float Math::TwoPi = 8.0f*atanf(1.0f);
const Float Math::HalfPi = 2.0f*atanf(1.0f);
const Float Math::QuarterPi = atanf(1.0f);
const Float Math::Eps = 1e-6f;
const Float Math::MinFloat = std::numeric_limits<Float>::min();
const Float Math::MaxFloat = std::numeric_limits<Float>::max();
const Float TO_RAD = Math::Pi/180.0f;
const Float TO_DEG = 180.0f/Math::Pi;


Float Math::Abs( Float value )
{
	return fabsf( value );
}

Float Math::Sign( Float value )
{
	return (value < 0.0f) ? -1.0f : 1.0f;
}

Float Math::Ceil( Float value )
{
	return ceilf( value );
}

Float Math::Floor( Float value )
{
	return floorf( value );
}

Float Math::Trunc( Float value )
{
	Double n;
	return modf( value, &n );
}

Float Math::Frac( Float value )
{
	Double n;
	modf( value, &n );
	return value - n;
}

Float Math::Round( Float value )
{
	const Float floor = Floor( value );
	const Float ceil = Ceil( value );

	if ( Abs(floor - value) <= Abs(ceil - value) )
		return floor;
	else
		return ceil;
}

Float Math::Sqrt( Float value )
{
	return sqrtf( value );
}

Float Math::InvSqrt( Float value )
{
	return 1.0f / sqrtf( value );
}

Float Math::Pow( Float value, Float power )
{
	return powf( value, power );
}

Float Math::Exp( Float value )
{
	return expf( value );
}

Float Math::Log( Float value )
{
	return logf( value );
}

Float Math::Log10( Float value )
{
	return log10f( value );
}

Float Math::ToRadians( Float degrees )
{
	return degrees * TO_RAD;
}

Float Math::ToDegrees( Float radians )
{
	return radians * TO_DEG;
}

Float Math::Sin( Float angle )
{
	return sinf( angle );
}

Float Math::Sinh( Float angle )
{
	return sinhf( angle );
}

Float Math::Asin( Float value )
{
	return asinf( value );
}

Float Math::Cos( Float angle )
{
	return cosf( angle );
}

Float Math::Cosh( Float angle )
{
	return coshf( angle );
}

Float Math::Acos( Float value )
{
	return acosf( value );
}

Float Math::Tan( Float angle )
{
	return tanf( angle );
}

Float Math::Tanh( Float angle )
{
	return tanhf( angle );
}

Float Math::Atan( Float value )
{
	return atanf( value );
}

Float Math::Atan2( Float y, Float x )
{
	return atan2f( y, x );
}

Float Math::Min( Float x, Float y )
{
	return __min( x, y );
}

Float Math::Max( Float x, Float y )
{
	return __max( x, y );
}

Float Math::Clamp( Float value, Float min, Float max )
{
	return __max( min, __min(value, max) );
}


} // math


} // synkro
