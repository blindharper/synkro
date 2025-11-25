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
#include <lang/DivisionByZeroException.h>
#include <limits>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


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


Float Math::Abs( Float value ) SYNKRO_NOEXCEPT
{
	return fabsf( value );
}

Float Math::Sign( Float value ) SYNKRO_NOEXCEPT
{
	return (value < 0.0f) ? -1.0f : 1.0f;
}

Float Math::Ceil( Float value ) SYNKRO_NOEXCEPT
{
	return ceilf( value );
}

Float Math::Floor( Float value ) SYNKRO_NOEXCEPT
{
	return floorf( value );
}

Float Math::Trunc( Float value ) SYNKRO_NOEXCEPT
{
	Double n;
	return modf( value, &n );
}

Float Math::Frac( Float value ) SYNKRO_NOEXCEPT
{
	Double n;
	modf( value, &n );
	return value - n;
}

Float Math::Round( Float value ) SYNKRO_NOEXCEPT
{
	const Float floor = Floor( value );
	const Float ceil = Ceil( value );

	if ( Abs(floor - value) <= Abs(ceil - value) )
		return floor;
	else
		return ceil;
}

Float Math::Sqrt( Float value ) SYNKRO_NOEXCEPT
{
	return sqrtf( value );
}

Float Math::InvSqrt( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	return 1.0f / sqrtf( value );
}

Float Math::Pow( Float value, Float power ) SYNKRO_NOEXCEPT
{
	return powf( value, power );
}

Float Math::Exp( Float value ) SYNKRO_NOEXCEPT
{
	return expf( value );
}

Float Math::Log( Float value ) SYNKRO_NOEXCEPT
{
	return logf( value );
}

Float Math::Log10( Float value ) SYNKRO_NOEXCEPT
{
	return log10f( value );
}

Float Math::ToRadians( Float degrees ) SYNKRO_NOEXCEPT
{
	return degrees * TO_RAD;
}

Float Math::ToDegrees( Float radians ) SYNKRO_NOEXCEPT
{
	return radians * TO_DEG;
}

Float Math::Sin( Float angle ) SYNKRO_NOEXCEPT
{
	return sinf( angle );
}

Float Math::Sinh( Float angle ) SYNKRO_NOEXCEPT
{
	return sinhf( angle );
}

Float Math::Asin( Float value ) SYNKRO_NOEXCEPT
{
	return asinf( value );
}

Float Math::Cos( Float angle ) SYNKRO_NOEXCEPT
{
	return cosf( angle );
}

Float Math::Cosh( Float angle ) SYNKRO_NOEXCEPT
{
	return coshf( angle );
}

Float Math::Acos( Float value ) SYNKRO_NOEXCEPT
{
	return acosf( value );
}

Float Math::Tan( Float angle ) SYNKRO_NOEXCEPT
{
	return tanf( angle );
}

Float Math::Tanh( Float angle ) SYNKRO_NOEXCEPT
{
	return tanhf( angle );
}

Float Math::Atan( Float value ) SYNKRO_NOEXCEPT
{
	return atanf( value );
}

Float Math::Atan2( Float y, Float x ) SYNKRO_NOEXCEPT
{
	return atan2f( y, x );
}

Float Math::Min( Float x, Float y ) SYNKRO_NOEXCEPT
{
	return __min( x, y );
}

Float Math::Max( Float x, Float y ) SYNKRO_NOEXCEPT
{
	return __max( x, y );
}

Float Math::Clamp( Float value, Float min, Float max ) SYNKRO_NOEXCEPT
{
	return __max( min, __min(value, max) );
}


} // math


} // synkro
