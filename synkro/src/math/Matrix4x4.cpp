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
// Purpose: Defines 4x4 matrix.
//=============================================================================
#include "config.h"
#include <math/Matrix4x4.h>
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


// Calculates 3x3 matrix determinant. a,b,c identify rows, i,j,k - columns.
SYNKRO_INLINE static Float Det3( const Matrix4x4& mtx, Int a, Int b, Int c, Int i, Int j, Int k )
{
	return	mtx.m[a][i]*(mtx.m[b][j]*mtx.m[c][k] - mtx.m[b][k]*mtx.m[c][j]) -
			mtx.m[b][i]*(mtx.m[a][j]*mtx.m[c][k] - mtx.m[a][k]*mtx.m[c][j]) +
			mtx.m[c][i]*(mtx.m[a][j]*mtx.m[b][k] - mtx.m[a][k]*mtx.m[b][j]);
}

//------------------------------------------------------------------------------

const Matrix4x4 Matrix4x4::Identity;

Matrix4x4::Matrix4x4()
{
	MakeIdentity();
}

Matrix4x4::Matrix4x4( const Matrix4x4& other )
{
	Copy( d, other.d, 16 );
}

Matrix4x4::Matrix4x4( Float value )
{
	for ( UInt i = 0; i < 4; ++i )
	{
		for ( UInt j = 0; j < 4; ++j )
		{
			m[i][j] = (i==j) ? value : 0.0f;
		}
	}
}

Matrix4x4::Matrix4x4( Float* array )
{
	assert( array != nullptr );

	if( array == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"array", L"nullptr" );

	Copy( d, array, 16 );
}

Matrix4x4::Matrix4x4( Float _00, Float _01, Float _02, Float _03,
					  Float _10, Float _11, Float _12, Float _13,
					  Float _20, Float _21, Float _22, Float _23,
					  Float _30, Float _31, Float _32, Float _33 )
{
	this->_00 = _00; this->_01 = _01; this->_02 = _02; this->_03 = _03;
	this->_10 = _10; this->_11 = _11; this->_12 = _12; this->_13 = _13;
	this->_20 = _20; this->_21 = _21; this->_22 = _22; this->_23 = _23;
	this->_30 = _30; this->_31 = _31; this->_32 = _32; this->_33 = _33;
}

Matrix4x4& Matrix4x4::MakeIdentity()
{
	for ( UInt i = 0; i < 4; ++i )
	{
		for ( UInt j = 0; j < 4; ++j )
		{
			m[i][j] = (i==j) ? 1.0f : 0.0f;
		}
	}
	return *this;
}

Matrix4x4& Matrix4x4::SetTranslation( const Vector3& translation )
{
	Copy( &m[3][0], &translation.x, 3 );
	return *this;
}

Matrix4x4& Matrix4x4::SetOrientation( const Vector3& axis, Float angle )
{
	return *this = Rotate( axis, angle );
}

Matrix4x4& Matrix4x4::SetOrientation( const Quaternion& orientation )
{
	return *this = Rotate( orientation );
}

Matrix4x4& Matrix4x4::SetScale( const Vector3& scale )
{
	m[0][0] = scale.x;
	m[1][1] = scale.y;
	m[2][2] = scale.z;
	return *this;
}

Matrix4x4& Matrix4x4::SetScale( Float scale )
{
	m[0][0] = m[1][1] = m[2][2] = scale;
	return *this;
}

Matrix4x4& Matrix4x4::SetPerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back )
{
	return *this = PerspectiveProjection( horzFOV, aspect, front, back );
}

Matrix4x4& Matrix4x4::SetLookAt( const Vector3& target, const Vector3& position, const Vector3& up )
{
	return *this = LookAt( target, position, up );
}

Matrix4x4& Matrix4x4::operator+=( const Matrix4x4& other )
{
	for ( UInt i = 0; i < 16; ++i )
	{
		d[i] += other.d[i];
	}
	return *this;
}

Matrix4x4& Matrix4x4::operator-=( const Matrix4x4& other )
{
	for ( UInt i = 0; i < 16; ++i )
	{
		d[i] -= other.d[i];
	}	
	return *this;
}

Matrix4x4& Matrix4x4::operator*=( const Matrix4x4& other )
{
	return *this = *this * other;
}

Matrix4x4& Matrix4x4::operator*=( Float value )
{
	for ( UInt i = 0; i < 16; ++i )
	{
		d[i] *= value;
	}
	return *this;
}

Matrix4x4& Matrix4x4::operator/=( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	const Float denom = 1.0f/value;
	for ( UInt i = 0; i < 16; ++i )
	{
		d[i] *= denom;
	}
	return *this;
}

Matrix4x4 Matrix4x4::operator+( const Matrix4x4& other ) const
{
	return Matrix4x4(*this) += other;
}

Matrix4x4 Matrix4x4::operator-( const Matrix4x4& other ) const
{
	return Matrix4x4(*this) -= other;
}

Matrix4x4 Matrix4x4::operator-() const
{
	return Matrix4x4(*this) *= -1.0f;
}

Matrix4x4 Matrix4x4::operator*( const Matrix4x4& other ) const
{
	Float res[16];

	res[0]	= other.d[0]*d[0]	+ other.d[1]*d[4]	+ other.d[2]*d[8]	+ other.d[3]*d[12];
	res[1]	= other.d[0]*d[1]	+ other.d[1]*d[5]	+ other.d[2]*d[9]	+ other.d[3]*d[13];
	res[2]	= other.d[0]*d[2]	+ other.d[1]*d[6]	+ other.d[2]*d[10]	+ other.d[3]*d[14];
	res[3]	= other.d[0]*d[3]	+ other.d[1]*d[7]	+ other.d[2]*d[11]	+ other.d[3]*d[15];

	res[4]	= other.d[4]*d[0]	+ other.d[5]*d[4]	+ other.d[6]*d[8]	+ other.d[7]*d[12];
	res[5]	= other.d[4]*d[1]	+ other.d[5]*d[5]	+ other.d[6]*d[9]	+ other.d[7]*d[13];
	res[6]	= other.d[4]*d[2]	+ other.d[5]*d[6]	+ other.d[6]*d[10]	+ other.d[7]*d[14];
	res[7]	= other.d[4]*d[3]	+ other.d[5]*d[7]	+ other.d[6]*d[11]	+ other.d[7]*d[15];

	res[8]	= other.d[8]*d[0]	+ other.d[9]*d[4]	+ other.d[10]*d[8]	+ other.d[11]*d[12];
	res[9]	= other.d[8]*d[1]	+ other.d[9]*d[5]	+ other.d[10]*d[9]	+ other.d[11]*d[13];
	res[10]	= other.d[8]*d[2]	+ other.d[9]*d[6]	+ other.d[10]*d[10]	+ other.d[11]*d[14];
	res[11]	= other.d[8]*d[3]	+ other.d[9]*d[7]	+ other.d[10]*d[11]	+ other.d[11]*d[15];

	res[12]	= other.d[12]*d[0]	+ other.d[13]*d[4]	+ other.d[14]*d[8]	+ other.d[15]*d[12];
	res[13]	= other.d[12]*d[1]	+ other.d[13]*d[5]	+ other.d[14]*d[9]	+ other.d[15]*d[13];
	res[14]	= other.d[12]*d[2]	+ other.d[13]*d[6]	+ other.d[14]*d[10]	+ other.d[15]*d[14];
	res[15]	= other.d[12]*d[3]	+ other.d[13]*d[7]	+ other.d[14]*d[11]	+ other.d[15]*d[15];

	return Matrix4x4( res );
}

Matrix4x4 Matrix4x4::operator*( Float value ) const
{
	return Matrix4x4( m[0][0]*value, m[0][1]*value, m[0][2]*value, m[0][3]*value,
					  m[1][0]*value, m[1][1]*value, m[1][2]*value, m[1][3]*value,
					  m[2][0]*value, m[2][1]*value, m[2][2]*value, m[2][3]*value,
					  m[3][0]*value, m[3][1]*value, m[3][2]*value, m[3][3]*value );
}

Matrix4x4 Matrix4x4::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	const Float denom = 1.0f/value;
	return Matrix4x4( m[0][0]*denom, m[0][1]*denom, m[0][2]*denom, m[0][3]*denom,
					  m[1][0]*denom, m[1][1]*denom, m[1][2]*denom, m[1][3]*denom,
					  m[2][0]*denom, m[2][1]*denom, m[2][2]*denom, m[2][3]*denom,
					  m[3][0]*denom, m[3][1]*denom, m[3][2]*denom, m[3][3]*denom );
}

Vector3 Matrix4x4::operator*( const Vector3& vec ) const
{
	Vector3 res
	(
		vec.x*m[0][0] + vec.y*m[1][0] + vec.z*m[2][0] + m[3][0],
		vec.x*m[0][1] + vec.y*m[1][1] + vec.z*m[2][1] + m[3][1],
		vec.x*m[0][2] + vec.y*m[1][2] + vec.z*m[2][2] + m[3][2]
	);

	const Float denom = vec.x*m[0][3] + vec.y*m[1][3] + vec.z*m[2][3] + m[3][3];
	if ( denom != 1.0f )
		res /= denom;

	return res;
}

Bool Matrix4x4::operator==( const Matrix4x4& other ) const
{
	for ( UInt i = 0; i < 16; ++i )
	{
		if ( d[i] != other.d[i] )
		{
			return false;
		}
	}
	return true;
}

Bool Matrix4x4::operator!=( const Matrix4x4& other ) const
{
	for ( UInt i = 0; i < 16; ++i )
	{
		if ( d[i] != other.d[i] )
		{
			return true;
		}
	}
	return false;
}

Float Matrix4x4::Determinant() const
{
	return	m[0][0]*Det3(*this, 1,2,3, 1,2,3) -
			m[0][1]*Det3(*this, 1,2,3, 0,2,3) +
			m[0][2]*Det3(*this, 1,2,3, 0,1,3) -
			m[0][3]*Det3(*this, 1,2,3, 0,1,2);
}

Matrix4x4 Matrix4x4::Inverse() const
{
	Matrix4x4 r( 1.0f );
	Matrix4x4 t( *this );
	
	for ( UInt i = 0; i < 4; ++i )
	{
		const Float d = t.m[i][i];
		if ( d != 1.0f )
		{
			for ( UInt j = 0; j < 4; ++j )
			{
				r.m[i][j] /= d;
				t.m[i][j] /= d;
			}
		}

		for ( UInt j = 0; j < 4; ++j )
		{
			if ( j != i )
			{
				if ( t.m[j][i] != 0.0f )
				{
					Float fac = t.m[j][i];
					for ( UInt k = 0; k < 4; ++k )
					{
						t.m[j][k] -= fac * t.m[i][k];
						r.m[j][k] -= fac * r.m[i][k];
					}
				}
			}
		}
	}

	return r;
}

Matrix4x4 Matrix4x4::Transpose() const
{
	Matrix4x4 mat;
	for ( UInt i = 0; i < 4; ++i )
	{
		for ( UInt j = 0; j < 4; ++j )
		{
			mat.m[i][j] = m[j][i];
		}
	}
	return mat;
}

Vector3 Matrix4x4::Translation() const
{
	return Vector3( (Float*)&this->m[3][0] );
}

Vector4 Matrix4x4::Translation4() const
{
	return Vector4( (Float*)&this->m[3][0] );
}

Quaternion Matrix4x4::Orientation() const
{
	Quaternion rot;

	const Float trace = m[0][0] + m[1][1] + m[2][2];

	if ( trace > 0.0f )
	{
		const Float t = trace + 1.0f;
		const Float s = Math::InvSqrt( t ) * 0.5f;

		rot.x = (m[2][1] - m[1][2]) * s;
		rot.y = (m[0][2] - m[2][0]) * s;
		rot.z = (m[1][0] - m[0][1]) * s;
		rot.w = s * t;
	}
	else
	{
		static UInt next[3] = { 1, 2, 0 };
		UInt i = 0;

		if ( m[1][1] > m[0][0] )
		{
			i = 1;
		}

		if ( m[2][2] > m[i][i] )
		{
			i = 2;
		}

		const UInt j = next[i];
		const UInt k = next[j];

		const Float t = m[i][i] - m[j][j] - m[k][k] + 1.0f;
		const Float s = Math::InvSqrt( t ) * 0.5f;

		rot.q[3] = (m[k][j] - m[j][k]) * s;
		rot.q[j] = (m[j][i] + m[i][j]) * s;
		rot.q[k] = (m[k][i] + m[i][k]) * s;
		rot.q[i] = s * t;
	}

	return rot;
}

Vector3 Matrix4x4::Scale() const
{
	return Vector3( m[0][0], m[1][1], m[2][2] );
}

Vector3 Matrix4x4::Right() const
{
	return Vector3( m[0][0], m[1][0], m[2][0] );
}

Vector3 Matrix4x4::Up() const
{
	return Vector3( m[0][1], m[1][1], m[2][1] );
}

Vector3 Matrix4x4::Forward() const
{
	return Vector3( m[0][2], m[1][2], m[2][2] );
}

Vector3 Matrix4x4::Rotate( const Vector3& vec ) const
{
	Vector3 res
	(
		vec.x*m[0][0] + vec.y*m[1][0] + vec.z*m[2][0],
		vec.x*m[0][1] + vec.y*m[1][1] + vec.z*m[2][1],
		vec.x*m[0][2] + vec.y*m[1][2] + vec.z*m[2][2]
	);
	return res;
}

Matrix4x4 Matrix4x4::Rotate( const Vector3& axis, Float angle ) const
{
	Matrix4x4 res( 1.0f );

	const Float c = Math::Cos( angle );
	const Float s = Math::Sin( angle );

	Vector3 a = axis;
	a.Normalize();

	res.m[0][0] = a.x * a.x + ( 1.0f - a.x * a.x ) * c;
	res.m[0][1] = a.x * a.y * ( 1.0f - c ) + a.z * s;
	res.m[0][2] = a.x * a.z * ( 1.0f - c ) - a.y * s;

	res.m[1][0] = a.x * a.y * ( 1.0f - c ) - a.z * s;
	res.m[1][1] = a.y * a.y + ( 1.0f - a.y * a.y ) * c;
	res.m[1][2] = a.y * a.z * ( 1.0f - c ) + a.x * s;

	res.m[2][0] = a.x * a.z * ( 1.0f - c ) + a.y * s;
	res.m[2][1] = a.y * a.z * ( 1.0f - c ) - a.x * s;
	res.m[2][2] = a.z * a.z + ( 1.0f - a.z * a.z ) * c;

	return res;
}

Matrix4x4 Matrix4x4::Rotate( const Quaternion& orientation ) const
{
	Matrix4x4 res( 1.0f );

	const Float n = orientation.Norm();
	const Float d = (n > 0.0f) ? (2.0f / n) : 0.0f;

	const Float tx = d*orientation.x;
	const Float ty = d*orientation.y;
	const Float tz = d*orientation.z;
	const Float wx = tx*orientation.w;
	const Float wy = ty*orientation.w;
	const Float wz = tz*orientation.w;
	const Float xx = tx*orientation.x;
	const Float xy = ty*orientation.x;
	const Float xz = tz*orientation.x;
	const Float yy = ty*orientation.y;
	const Float yz = tz*orientation.y;
	const Float zz = tz*orientation.z;

	res.m[0][0] = 1.0f - (yy+zz);
	res.m[0][1] = xy + wz;
	res.m[0][2] = xz - wy;
	res.m[1][0] = xy - wz;
	res.m[1][1] = 1.0f - (xx+zz);
	res.m[1][2] = yz + wx;
	res.m[2][0] = xz + wy;
	res.m[2][1] = yz - wx;
	res.m[2][2] = 1.0f - (xx+yy);

	return res;
}

Matrix4x4 Matrix4x4::RotateX( Float angle ) const
{
	Matrix4x4 res( 1.0f );
	const Float c = Math::Cos( angle );
	const Float s = Math::Sin( angle );
	res.m[1][1] = c;
	res.m[2][1] = -s;
	res.m[1][2] = s;
	res.m[2][2] = c;
	return res;
}

Matrix4x4 Matrix4x4::RotateY( Float angle ) const
{
	Matrix4x4 res( 1.0f );
	const Float c = Math::Cos( angle );
	const Float s = Math::Sin( angle );
	res.m[0][0] = c;
	res.m[2][0] = s;
	res.m[0][2] = -s;
	res.m[2][2] = c;
	return res;
}

Matrix4x4 Matrix4x4::RotateZ( Float angle ) const
{
	Matrix4x4 res( 1.0f );
	const Float c = Math::Cos( angle );
	const Float s = Math::Sin( angle );
	res.m[0][0] = c;
	res.m[1][0] = -s;
	res.m[0][1] = s;
	res.m[1][1] = c;
	return res;
}

Matrix4x4 Matrix4x4::MirrorX() const
{
	Matrix4x4 res( 1.0f );
	res.m[0][0] = -1.0f;
	return res;
}

Matrix4x4 Matrix4x4::MirrorY() const
{
	Matrix4x4 res( 1.0f );
	res.m[1][1] = -1.0f;
	return res;
}

Matrix4x4 Matrix4x4::MirrorZ() const
{
	Matrix4x4 res( 1.0f );
	res.m[2][2] = -1.0f;
	return res;
}

Matrix4x4 Matrix4x4::PerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back ) const
{
	const Float w = Math::Abs( 1.0f/Math::Tan(horzFOV*0.5f) ); // 1/tan(x) == cot(x)
	const Float vw = 2.0f*front/w;
	const Float vh = vw/aspect;
	const Float h = 2.0f*front/vh;
	const Float q = back/(back - front);

	Matrix4x4 res( 0.0f );
	res.m[0][0] = w;
	res.m[1][1] = h;
	res.m[2][2] = q;
	res.m[3][2] = -q*front;
	res.m[2][3] = 1.0f;
	return res;
}

Matrix4x4 Matrix4x4::LookAt( const Vector3& target, const Vector3& eye, const Vector3& up ) const
{
	const Vector3 z = (target - eye).Normalize();
	const Vector3 x = (up^z).Normalize();
	const Vector3 y = z^x;

	Matrix4x4 res( 0.0f );

	res.m[0][0] = x.x;
	res.m[0][1] = y.x;
	res.m[0][2] = z.x;

	res.m[1][0] = x.y;
	res.m[1][1] = y.y;
	res.m[1][2] = z.y;

	res.m[2][0] = x.z;
	res.m[2][1] = y.z;
	res.m[2][2] = z.z;

	res.m[3][0] = -(x*eye);
	res.m[3][1] = -(y*eye);
	res.m[3][2] = -(z*eye);

	res.m[3][3] = 1.0f;

	return res;
}

Bool Matrix4x4::IsIdentity() const
{
	for ( UInt i = 0; i < 4; ++i )
	{
		for ( UInt j = 0; j < 4; ++j )
		{
			if ( m[i][j] != ((i!=j) ? 0.0f : 1.0f) ) 
				return false;
		}
	}
	return true;
}


} // math


} // synkro
