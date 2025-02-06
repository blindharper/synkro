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
#include "config.h"
#include <math/Vector3.h>
#include <math/Math.h>
#include <math/Math.h>
#include <core/Str.h>
#include <lang/BadArgumentException.h>
#include <lang/DivisionByZeroException.h>
#include <internal/Copy.h>
#include <limits>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace math
{


#undef min


const Vector3 Vector3::Invalid( FLT_MIN, FLT_MIN, FLT_MIN );
const Vector3 Vector3::Origin( 0.0f, 0.0f, 0.0f );
const Vector3 Vector3::X( 1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Y( 0.0f, 1.0f, 0.0f );
const Vector3 Vector3::Z( 0.0f, 0.0f, 1.0f );


Vector3::Vector3() :
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f )
{
}

Vector3::Vector3( const Vector3& other ) :
	x( other.x ),
	y( other.y ),
	z( other.z )
{
}

Vector3::Vector3( Float value ) :
	x( value ),
	y( value ),
	z( value )
{
}

Vector3::Vector3( Float* array )
{
	assert( array != nullptr );

	if( array == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"array", L"nullptr" );

	Copy( v, array, 3 );
}

Vector3::Vector3( Float _x, Float _y, Float _z ) :
	x( _x ),
	y( _y ),
	z( _z )
{
}

Vector3& Vector3::operator=( const Vector3& other )
{
	if ( other != *this )
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

Vector3& Vector3::operator+=( const Vector3& other )
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator-=( const Vector3& other )
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator*=( Float value )
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

Vector3& Vector3::operator/=( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	x /= value;
	y /= value;
	z /= value;
	return *this;
}

Vector3& Vector3::Normalize()
{
	const Float len = Length();

	return (len != 0.0f) ? *this/=len : *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3( -x, -y, -z );
}

Vector3 Vector3::operator+( const Vector3& other ) const
{
	return Vector3( x+other.x, y+other.y, z+other.z );
}

Vector3 Vector3::operator-( const Vector3& other ) const
{
	return Vector3( x-other.x, y-other.y, z-other.z );
}

Vector3 Vector3::operator*( Float value ) const
{
	return Vector3( x*value, y*value, z*value );
}

Vector3 Vector3::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	return Vector3( x/value, y/value, z/value );
}

Vector3 Vector3::operator^( const Vector3& other ) const
{
	return Vector3( y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x );
}

Float Vector3::operator*( const Vector3& other ) const
{
	return x*other.x + y*other.y + z*other.z;
}

Bool Vector3::operator==( const Vector3& other ) const
{
	return (x == other.x) && (y == other.y) && (z == other.z);
}

Bool Vector3::operator!=( const Vector3& other ) const
{
	return (x != other.x) || (y != other.y) || (z != other.z);
}

Float Vector3::Length() const
{
	return Math::Sqrt( x*x + y*y + z*z );
}

Float Vector3::LengthSquared() const
{
	return x*x + y*y + z*z;
}

Vector3 Vector3::Rotate( const Vector3& axis, Float angle ) const
{
	const Vector3 vec = *this;
	Vector3 unitAxis = axis; unitAxis.Normalize();
	const Float halfAngle = 0.5f*angle;
	const Float s = Math::Sin( halfAngle );
	const Float c = Math::Cos( halfAngle );
	const Float x = unitAxis.x * s;
	const Float y = unitAxis.y * s;
	const Float z = unitAxis.z * s;
	const Float w = c;
	const Float xx = x*x;
	const Float xy = x*y;
	const Float xz = x*z;
	const Float yy = y*y;
	const Float yz = y*z;
	const Float zz = z*z;
	const Float wx = w*x;
	const Float wy = w*y;
	const Float wz = w*z;

	return Vector3
	(
		vec.x*(1.0f-2.0f*(yy+zz)) + vec.y*(2.0f*(xy-wz)) + vec.z*(2.0f*(xz+wy)),
		vec.x*(2.0f*(xy+wz)) + vec.y*(1.0f-2.0f*(xx+zz)) + vec.z*(2.0f*(yz-wx)),
		vec.x*(2.0f*(xz-wy)) + vec.y*(2.0f*(yz+wx)) + vec.z*(1.0f-2.0f*(xx+yy))
	);
}


} // math


} // synkro
