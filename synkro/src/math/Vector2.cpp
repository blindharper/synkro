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
// Purpose: Defines 2-component vector.
//==============================================================================
#include "config.h"
#include <math/Vector2.h>
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


Vector2::Vector2() :
	x( 0.0f ),
	y( 0.0f )
{
}

Vector2::Vector2( const Vector2& other ) :
	x( other.x ),
	y( other.y )
{
}

Vector2::Vector2( Float value ) :
	x( value ),
	y( value )
{
}

Vector2::Vector2( Float* array )
{
	assert( array != nullptr );

	if( array == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"array", L"nullptr" );

	Copy( v, array, 2 );
}

Vector2::Vector2( Float _x, Float _y ) :
	x( _x ),
	y( _y )
{
}

Vector2& Vector2::operator=( const Vector2& other )
{
	if ( other != *this )
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

Vector2& Vector2::operator+=( const Vector2& other )
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=( const Vector2& other )
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=( Float value )
{
	x *= value;
	y *= value;
	return *this;
}

Vector2& Vector2::operator/=( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	x /= value;
	y /= value;
	return *this;
}

Vector2& Vector2::Normalize()
{
	const Float len = Length();

	return (len != 0.0f) ? *this/=len : *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2( -x, -y );
}

Vector2 Vector2::operator+( const Vector2& other ) const
{
	return Vector2( x+other.x, y+other.y );
}

Vector2 Vector2::operator-( const Vector2& other ) const
{
	return Vector2( x-other.x, y-other.y );
}

Vector2 Vector2::operator*( Float value ) const
{
	return Vector2( x*value, y*value );
}

Vector2 Vector2::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	return Vector2( x/value, y/value );
}

Float Vector2::operator*( const Vector2& other ) const
{
	return x*other.x + y*other.y;
}

Bool Vector2::operator==( const Vector2& other ) const
{
	return (x == other.x) && (y == other.y);
}

Bool Vector2::operator!=( const Vector2& other ) const
{
	return (x != other.x) || (y != other.y);
}

Float Vector2::Length() const
{
	return Math::Sqrt( x*x + y*y );
}


} // math


} // synkro
