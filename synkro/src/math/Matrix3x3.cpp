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
// Purpose: Defines 3x3 matrix.
//=============================================================================
#include "config.h"
#include <math/Matrix3x3.h>
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

const Matrix3x3 Matrix3x3::Identity;

Matrix3x3::Matrix3x3()
{
	for ( UInt i = 0; i < 9; ++i )
	{
		d[i] = 0.0f;
	}
}

Matrix3x3::Matrix3x3( const Matrix3x3& other )
{
	Copy( d, other.d, 9 );
}

Matrix3x3::Matrix3x3( Float value )
{
	for ( UInt i = 0; i < 3; ++i )
	{
		for ( UInt j = 0; j < 3; ++j )
		{
			m[i][j] = (i!=j) ? 0.0f : value;
		}
	}
}

Matrix3x3::Matrix3x3( Float* array )
{
	assert( array != nullptr );

	if( array == nullptr )
		throw BadArgumentException( Str::InvalidPointer, L"array", L"nullptr" );

	Copy( d, array, 9 );
}

Matrix3x3::Matrix3x3( Float _00, Float _01, Float _02,
					  Float _10, Float _11, Float _12,
					  Float _20, Float _21, Float _22 )
{
	this->_00 = _00; this->_01 = _01; this->_02 = _02;
	this->_10 = _10; this->_11 = _11; this->_12 = _12;
	this->_20 = _20; this->_21 = _21; this->_22 = _22;
}

Matrix3x3& Matrix3x3::operator+=( const Matrix3x3& other )
{
	for ( UInt i = 0; i < 9; ++i )
	{
		d[i] += other.d[i];
	}
	return *this;
}

Matrix3x3& Matrix3x3::operator-=( const Matrix3x3& other )
{
	for ( UInt i = 0; i < 9; ++i )
	{
		d[i] -= other.d[i];
	}
	return *this;
}

Matrix3x3& Matrix3x3::operator*=( Float value )
{
	for ( UInt i = 0; i < 9; ++i )
	{
		d[i] *= value;
	}
	return *this;
}

Matrix3x3& Matrix3x3::operator/=( Float value )
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	const Float denom = 1.0f/value;
	for ( UInt i = 0; i < 9; ++i )
	{
		d[i] *= denom;
	}
	return *this;
}

Matrix3x3 Matrix3x3::operator+( const Matrix3x3& other ) const
{
	return Matrix3x3(*this) += other;
}

Matrix3x3 Matrix3x3::operator-( const Matrix3x3& other ) const
{
	return Matrix3x3(*this) -= other;
}

Matrix3x3 Matrix3x3::operator-() const
{
	return Matrix3x3(*this) *= -1.0f;
}

Matrix3x3 Matrix3x3::operator*( Float value ) const
{
	return Matrix3x3( m[0][0]*value, m[0][1]*value, m[0][2]*value,
					  m[1][0]*value, m[1][1]*value, m[1][2]*value,
					  m[2][0]*value, m[2][1]*value, m[2][2]*value );
}

Matrix3x3 Matrix3x3::operator/( Float value ) const
{
	assert( value != 0.0f );

	if ( value == 0.0f )
		throw DivisionByZeroException();

	const Float denom = 1.0f/value;
	return Matrix3x3( m[0][0]*denom, m[0][1]*denom, m[0][2]*denom,
					  m[1][0]*denom, m[1][1]*denom, m[1][2]*denom,
					  m[2][0]*denom, m[2][1]*denom, m[2][2]*denom );
}

Float Matrix3x3::Determinant() const
{
	return m[0][0]*(m[1][1]*m[2][2] - m[2][1]*m[1][2]) -
		   m[0][1]*(m[1][0]*m[2][2] - m[2][0]*m[1][2]) +
		   m[0][2]*(m[1][0]*m[2][1] - m[2][0]*m[1][1]);
}

Matrix3x3 Matrix3x3::Transpose() const
{
	Matrix3x3 mat;
	for ( UInt i = 0; i < 3; ++i )
	{
		for ( UInt j = 0; j < 3; ++j )
		{
			mat.m[i][j] = m[j][i];
		}
	}
	return mat;
}

Bool Matrix3x3::operator==( const Matrix3x3& other ) const
{
	for ( UInt i = 0; i < 9; ++i )
	{
		if ( d[i] != other.d[i] )
		{
			return false;
		}
	}
	return true;
}

Bool Matrix3x3::operator!=( const Matrix3x3& other ) const
{
	for ( UInt i = 0; i < 9; ++i )
	{
		if ( d[i] != other.d[i] )
		{
			return true;
		}
	}
	return false;
}


} // math


} // synkro
