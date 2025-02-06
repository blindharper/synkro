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
// Purpose: Implements pseudo-random number generator.
//==============================================================================
#include "config.h"
#include <lang/Random.h>
#include <internal/Lerp.h>


namespace synkro
{


namespace lang
{


static Int GetNext( UInt& seed )
{
	// Linear congruential generator (LCG):
	// I(k) = ( a * I(k-1) + c ) % m

	// Minimal standard RNG (Park and Miller 1988):
	constexpr int a = 16807;
	constexpr int c = 0;
	constexpr int m = 2147483647;

	// Sample 2 times, use only bits 8-16 from second sample.
	seed = ( a * seed + c ) % m;
	Int v = seed;
	seed = ( a * seed + c ) % m;
	v += (seed >> 8) & 0xff;
	return v;
}

Random::Random( UInt seed ) :
	_seed( seed )
{
	GetInt();
}

Random::Random()
{
	_seed = CastUInt( time(NULL) );
	GetInt();
}

Int Random::GetInt( Int minValue, Int maxValue )
{
	Double s = CastDouble( GetFloat() );
	return Lerp( minValue, maxValue, s );
}

Int Random::GetInt( Int maxValue )
{
	return GetInt( 0, maxValue );
}

Int Random::GetInt()
{
	return GetInt( 0, INT_MAX );
}

Bool Random::GetBool()
{
	Int v = GetNext( _seed );
	v &= 256;
	return (v != 0);
}

Float Random::GetFloat()
{
	Int v = GetNext( _seed );
	v &= 0x7ffffff;
	return CastFloat(v)/CastFloat(0x8000000);
}

Double Random::GetDouble()
{
	Int v = GetNext( _seed );
	v &= 0x7ffffff;
	return CastDouble(v)/CastDouble(0x8000000);
}

void Random::GetBytes( UInt count, Byte* value )
{
	assert( value != nullptr );

	for ( UInt i = 0; i < count; ++i )
	{
		value[i] = CastByte( GetFloat()*255.0f );
	}
}


} // lang


} // synkro
