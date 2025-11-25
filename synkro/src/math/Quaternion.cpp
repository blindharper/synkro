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
#include "config.h"
#include <math/Quaternion.h>
#include <math/Math.h>
#include <lang/DivisionByZeroException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace math
{


const Quaternion Quaternion::Identity;


Quaternion::Quaternion() SYNKRO_NOEXCEPT :
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	w( 1.0f )
{
}

Quaternion::Quaternion( const Quaternion& other ) SYNKRO_NOEXCEPT :
	x( other.x ),
	y( other.y ),
	z( other.z ),
	w( other.w )
{
}

Quaternion::Quaternion( const Vector3& axis, Float angle ) SYNKRO_NOEXCEPT
{
	const Float a = -angle*0.5f;
	const Float s = Math::Sin( a );
	x = axis.x * s;
	y = axis.y * s;
	z = axis.z * s;
	w = Math::Cos( a );
}

Quaternion::Quaternion( Float yaw, Float pitch, Float roll ) SYNKRO_NOEXCEPT
{
	SetAngles( yaw, pitch, roll );
}

Quaternion::Quaternion( Float _x, Float _y, Float _z, Float _w ) SYNKRO_NOEXCEPT :
	x( _x ),
	y( _y ),
	z( _z ),
	w( _w )
{
}

Quaternion& Quaternion::operator=( const Quaternion& other ) SYNKRO_NOEXCEPT
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

Quaternion& Quaternion::operator+=( const Quaternion& other ) SYNKRO_NOEXCEPT
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Quaternion& Quaternion::operator-=( const Quaternion& other ) SYNKRO_NOEXCEPT
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Quaternion& Quaternion::operator*=( const Quaternion& other ) SYNKRO_NOEXCEPT
{
	(*this) = (*this)*other;
	return *this;
}

Quaternion& Quaternion::operator*=( Float value ) SYNKRO_NOEXCEPT
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return *this;
}

Quaternion& Quaternion::operator/=( Float value )
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

Quaternion& Quaternion::MakeNormal() SYNKRO_NOEXCEPT
{
	const Float norm = Norm();
	return (norm != 0.0f) ? *this/=norm : *this;
}

Quaternion& Quaternion::SetAngles( Float yaw, Float pitch, Float roll ) SYNKRO_NOEXCEPT
{
	const Float sz = Math::Sin( 0.5f*roll );
	const Float cz = Math::Cos( 0.5f*roll );
	const Float sy = Math::Sin( 0.5f*yaw );
	const Float cy = Math::Cos( 0.5f*yaw );
	const Float sx = Math::Sin( 0.5f*pitch );
	const Float cx = Math::Cos( 0.5f*pitch );

	const Float sxcy = sx * cy;
	const Float cxcy = cx * cy;
	const Float sxsy = sx * sy;
	const Float cxsy = cx * sy;

	this->x = cxsy*sz - sxcy*cz;
	this->y = -cxsy*cz - sxcy*sz;
	this->z = sxsy*cz - cxcy*sz;
	this->w = cxcy*cz + sxsy*sz;

	return *this;
}

Quaternion Quaternion::operator-() const SYNKRO_NOEXCEPT
{
	return Quaternion( -x, -y, -z, w );
}

Quaternion Quaternion::operator+( const Quaternion& other ) const SYNKRO_NOEXCEPT
{
	return Quaternion( x+other.x, y+other.y, z+other.z, w+other.w );
}

Quaternion Quaternion::operator-( const Quaternion& other ) const SYNKRO_NOEXCEPT
{
	return Quaternion( x-other.x, y-other.y, z-other.z, w-other.w );
}

Quaternion Quaternion::operator*( const Quaternion& other ) const SYNKRO_NOEXCEPT
{
	Quaternion q;
	q.x = w*other.x + x*other.w + y*other.z - z*other.y;
	q.y = w*other.y + y*other.w + z*other.x - x*other.z;
	q.z = w*other.z + z*other.w + x*other.y - y*other.x;
	q.w = w*other.w - x*other.x - y*other.y - z*other.z;
	return q;
}

Quaternion Quaternion::operator*( Float value ) const SYNKRO_NOEXCEPT
{
	return Quaternion( x*value, y*value, z*value, w*value );
}

Quaternion Quaternion::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	return Quaternion( x/value, y/value, z/value, w/value );
}

Quaternion Quaternion::Conjugate() const SYNKRO_NOEXCEPT
{
	return Quaternion( -x, -y, -z, w );
}

Quaternion Quaternion::Normalize() const SYNKRO_NOEXCEPT
{
	Quaternion q( *this );
	q.MakeNormal();
	return q;
}

Quaternion Quaternion::Inverse() const SYNKRO_NOEXCEPT
{
	return -(*this);
}

Bool Quaternion::IsIdentity() const SYNKRO_NOEXCEPT
{
	return (x == 0.0f) && (y == 0.0f) && (z == 0.0f) && (w == 1.0f);
}

Bool Quaternion::operator==( const Quaternion& other ) const SYNKRO_NOEXCEPT
{
	return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}

Bool Quaternion::operator!=( const Quaternion& other ) const SYNKRO_NOEXCEPT
{
	return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
}

Float Quaternion::Norm() const SYNKRO_NOEXCEPT
{
	return Math::Sqrt( NormSquared() );
}

Float Quaternion::NormSquared() const SYNKRO_NOEXCEPT
{
	return x*x + y*y + z*z + w*w;
}

void Quaternion::GetAngles( Float& yaw, Float& pitch, Float& roll ) const SYNKRO_NOEXCEPT
{
	const Float q = x*y + z*w;
	pitch = Math::Asin( 2.0f*q );
	if ( q == 0.5f ) // North pole
	{
		yaw = 2.0f*Math::Atan2( x, w );
		roll = 0.0f;
	}
	else if ( q == -0.5f ) // South pole
	{
		yaw = -2.0f*Math::Atan2( x, w );
		roll = 0.0f;
	}
	else
	{
		yaw = Math::Atan2( 2.0f*(y*w - x*z), 1.0f - 2.0f*(y*y - z*z) );
		roll = Math::Atan2( 2.0f*(x*w - y*z), 1.0f - 2.0f*(x*x - z*z) );
	}
}


} // math


} // synkro
