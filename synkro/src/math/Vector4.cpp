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
#include "config.h"
#include <math/Vector4.h>
#include <math/Math.h>
#include <core/Str.h>
#include <lang/BadArgumentException.h>
#include <lang/DivisionByZeroException.h>
#include <internal/Copy.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace math
{


Vector4::Vector4() :
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	w( 0.0f )
{
}

Vector4::Vector4( const Vector4& other ) :
	x( other.x ),
	y( other.y ),
	z( other.z ),
	w( other.w )
{
}

Vector4::Vector4( Float value ) :
	x( value ),
	y( value ),
	z( value ),
	w( value )
{
}

Vector4::Vector4( Float* array )
{
	assert( array != nullptr );

	if( array == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"array", L"nullptr" );

	Copy( v, array, 4 );
}

Vector4::Vector4( Float _x, Float _y, Float _z, Float _w ) :
	x( _x ),
	y( _y ),
	z( _z ),
	w( _w )
{
}

Vector4::Vector4( const Vector3& other, Float _w ) :
	x( other.x ),
	y( other.y ),
	z( other.z ),
	w( _w )
{
}

Vector4::Vector4( const Vector3& other ) :
	x( other.x ),
	y( other.y ),
	z( other.z ),
	w( 0.0f )
{
}

Vector4& Vector4::operator=( const Vector4& other )
{
	if ( other != *this )
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}
	return *this;
}

Vector4& Vector4::operator+=( const Vector4& other )
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4& Vector4::operator-=( const Vector4& other )
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::operator*=( Float value )
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}

Vector4& Vector4::operator/=( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	x /= value;
	y /= value;
	z /= value;
	w /= value;
	return *this;
}

Vector4& Vector4::Normalize()
{
	const Float len = Length();

	return (len != 0.0f) ? *this/=len : *this;
}

Vector4 Vector4::operator-() const
{
	return Vector4( -x, -y, -z, -w );
}

Vector4 Vector4::operator+( const Vector4& other ) const
{
	return Vector4( x+other.x, y+other.y, z+other.z, w+other.w );
}

Vector4 Vector4::operator-( const Vector4& other ) const
{
	return Vector4( x-other.x, y-other.y, z-other.z, w-other.w );
}

Vector4 Vector4::operator*( Float value ) const
{
	return Vector4( x*value, y*value, z*value, w*value );
}

Vector4 Vector4::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	return Vector4( x/value, y/value, z/value, w/value );
}

Vector4 Vector4::operator^( const Vector4& other ) const
{
	return Vector4( y*other.z - z*other.y, z*other.w - w*other.z, w*other.x - x*other.w, x*other.y - y*other.x );
}

Float Vector4::operator*( const Vector4& other ) const
{
	return x*other.x + y*other.y + z*other.z + w*other.w;
}

Bool Vector4::operator==( const Vector4& other ) const
{
	return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}

Bool Vector4::operator!=( const Vector4& other ) const
{
	return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
}

Float Vector4::Length() const
{
	return Math::Sqrt( x*x + y*y + z*z + w*w );
}


} // math


} // synkro
