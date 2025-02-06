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
// Purpose: Linear interpolation routine.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_LERP_
#define _SYNKRO_INTERNAL_LERP_


#include <img/ColorGradient.h>
#include <lang/Point.h>
#include <lang/PointF.h>
#include <lang/Rect.h>
#include <lang/RectF.h>
#include <lang/Size.h>
#include <lang/Range.h>
#include <math/Math.h>
#include <math/Vector3.h>
#include <math/Quaternion.h>
#include <math/Matrix4x4.h>
#include <internal/Clamp.h>


// Linear interpolation routine.
template <class T> SYNKRO_INLINE T Lerp( const T& a, const T& b, synkro::Double s )
{
	if ( s < 0.0 )
		s = 0.0;

	if ( s > 1.0 )
		s = 1.0;

	return a + s*(b-a);
}

// Lerp for boolean.
template <> SYNKRO_INLINE synkro::Bool Lerp<synkro::Bool>( const synkro::Bool& a, const synkro::Bool& b, synkro::Double s )
{
	return b;
}

// Lerp for color.
template <> SYNKRO_INLINE synkro::img::Color Lerp<synkro::img::Color>( const synkro::img::Color& a, const synkro::img::Color& b, synkro::Double s )
{
	const synkro::Float red = Lerp( a.R, b.R, s );
	const synkro::Float green = Lerp( a.G, b.G, s );
	const synkro::Float blue = Lerp( a.B, b.B, s );
	return synkro::img::Color( red, green, blue );
}

// Lerp for color gradient.
template <> SYNKRO_INLINE synkro::img::ColorGradient Lerp<synkro::img::ColorGradient>( const synkro::img::ColorGradient& a, const synkro::img::ColorGradient& b, synkro::Double s )
{
	const synkro::img::Color start = Lerp( a.Start, b.Start, s );
	const synkro::img::Color end = Lerp( a.End, b.End, s );
	return synkro::img::ColorGradient( a.Type, start, end );
}

// Lerp for whole number point.
template <> SYNKRO_INLINE synkro::lang::Point Lerp<synkro::lang::Point>( const synkro::lang::Point& a, const synkro::lang::Point& b, synkro::Double s )
{
	const synkro::Int x = Lerp( a.X, b.X, s );
	const synkro::Int y = Lerp( a.Y, b.Y, s );
	return synkro::lang::Point( x, y );
}

// Lerp for floating-value point.
template <> SYNKRO_INLINE synkro::lang::PointF Lerp<synkro::lang::PointF>( const synkro::lang::PointF& a, const synkro::lang::PointF& b, synkro::Double s )
{
	const synkro::Float x = Lerp( a.X, b.X, s );
	const synkro::Float y = Lerp( a.Y, b.Y, s );
	return synkro::lang::PointF( x, y );
}

// Lerp for size.
template <> SYNKRO_INLINE synkro::lang::Size Lerp<synkro::lang::Size>( const synkro::lang::Size& a, const synkro::lang::Size& b, synkro::Double s )
{
	const synkro::UInt width = Lerp( a.Width, b.Width, s );
	const synkro::UInt height = Lerp( a.Height, b.Height, s );
	return synkro::lang::Size( width, height );
}

// Lerp for range.
template <> SYNKRO_INLINE synkro::lang::Range Lerp<synkro::lang::Range>( const synkro::lang::Range& a, const synkro::lang::Range& b, synkro::Double s )
{
	const synkro::Int start = Lerp( CastInt(a.Start), CastInt(b.Start), s );
	const synkro::Int length = Lerp( CastInt(a.Length), CastInt(b.Length), s );
	return synkro::lang::Range( CastUInt(start), CastUInt(length) );
}

// Lerp for whole number rectangle.
template <> SYNKRO_INLINE synkro::lang::Rect Lerp<synkro::lang::Rect>( const synkro::lang::Rect& a, const synkro::lang::Rect& b, synkro::Double s )
{
	const synkro::Int left = Lerp( a.Left, b.Left, s );
	const synkro::Int top = Lerp( a.Top, b.Top, s );
	const synkro::Int right = Lerp( a.Right, b.Right, s );
	const synkro::Int bottom = Lerp( a.Bottom, b.Bottom, s );
	return synkro::lang::Rect( left, top, right, bottom );
}

// Lerp for floating-point rectangle.
template <> SYNKRO_INLINE synkro::lang::RectF Lerp<synkro::lang::RectF>( const synkro::lang::RectF& a, const synkro::lang::RectF& b, synkro::Double s )
{
	const synkro::Float left = Lerp( a.Left, b.Left, s );
	const synkro::Float top = Lerp( a.Top, b.Top, s );
	const synkro::Float right = Lerp( a.Right, b.Right, s );
	const synkro::Float bottom = Lerp( a.Bottom, b.Bottom, s );
	return synkro::lang::RectF( left, top, right, bottom );
}

// Lerp for vector3.
template <> SYNKRO_INLINE synkro::math::Vector3 Lerp<synkro::math::Vector3>( const synkro::math::Vector3& a, const synkro::math::Vector3& b, synkro::Double s )
{
	const synkro::Float x = Lerp( a.x, b.x, s );
	const synkro::Float y = Lerp( a.y, b.y, s );
	const synkro::Float z = Lerp( a.z, b.z, s );
	return synkro::math::Vector3( x, y, z );
}

// Lerp for quaternion.
template <> SYNKRO_INLINE synkro::math::Quaternion Lerp<synkro::math::Quaternion>( const synkro::math::Quaternion& a, const synkro::math::Quaternion& b, synkro::Double s )
{
	const synkro::Float cos = Clamp( a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w, -1.0f, 1.0f );
	const synkro::Float angle = synkro::math::Math::Acos( cos );
	const synkro::Float sin = synkro::math::Math::Sin( angle );
	if ( sin < synkro::math::Math::MinFloat )
	{
		return a;
	}

	const synkro::Float invsin = 1.0f / sin;
	const synkro::Float ca = invsin * synkro::math::Math::Sin( (1.0f - CastFloat(s)) * angle );
	const synkro::Float cb = invsin * synkro::math::Math::Sin( CastFloat(s) * angle );
	return a*ca + b*cb;
}

// Lerp for 4x4 matrix.
template <> SYNKRO_INLINE synkro::math::Matrix4x4 Lerp<synkro::math::Matrix4x4>( const synkro::math::Matrix4x4& a, const synkro::math::Matrix4x4& b, synkro::Double s )
{
	const synkro::Float m00 = Lerp( a._00, b._00, s );
	const synkro::Float m01 = Lerp( a._01, b._01, s );
	const synkro::Float m02 = Lerp( a._02, b._02, s );
	const synkro::Float m03 = Lerp( a._03, b._03, s );

	const synkro::Float m10 = Lerp( a._10, b._10, s );
	const synkro::Float m11 = Lerp( a._11, b._11, s );
	const synkro::Float m12 = Lerp( a._12, b._12, s );
	const synkro::Float m13 = Lerp( a._13, b._13, s );

	const synkro::Float m20 = Lerp( a._20, b._20, s );
	const synkro::Float m21 = Lerp( a._21, b._21, s );
	const synkro::Float m22 = Lerp( a._22, b._22, s );
	const synkro::Float m23 = Lerp( a._23, b._23, s );

	const synkro::Float m30 = Lerp( a._30, b._30, s );
	const synkro::Float m31 = Lerp( a._31, b._31, s );
	const synkro::Float m32 = Lerp( a._32, b._32, s );
	const synkro::Float m33 = Lerp( a._33, b._33, s );

	return synkro::math::Matrix4x4( m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 );
}


#endif // _SYNKRO_INTERNAL_LERP_
