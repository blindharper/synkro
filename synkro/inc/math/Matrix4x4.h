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
//==============================================================================
#ifndef _SYNKRO_MATH_MATRIX4X4_
#define _SYNKRO_MATH_MATRIX4X4_


#include "config.h"
#include <math/Quaternion.h>
#include <math/Vector4.h>


namespace synkro
{


namespace math
{


/**
 * Matrix of 4x4 floating-point value elements.
 */
class SYNKRO_API Matrix4x4
{
public:
	// Matrix components.
	union
	{
		Float d[16];
		Float m[4][4];
		struct
		{
			Float _00, _01, _02, _03;
			Float _10, _11, _12, _13;
			Float _20, _21, _22, _23;
			Float _30, _31, _32, _33;
		};
	};

	/** Identity matrix. */
	static const Matrix4x4									Identity;

	/** Constructs a default matrix. */
	Matrix4x4() SYNKRO_NOEXCEPT;

	/** Copy constructor. */
	Matrix4x4( const Matrix4x4& other ) SYNKRO_NOEXCEPT;

	/** Constructs identity matrix multiplied by value. */
	explicit Matrix4x4( Float value ) SYNKRO_NOEXCEPT;

	/** Constructs matrix from an array of 16 scalars. */
	explicit Matrix4x4( Float* array );

	/** Constructs matrix from 16 scalar values. */
	Matrix4x4( Float _00, Float _01, Float _02, Float _03,
			   Float _10, Float _11, Float _12, Float _13,
			   Float _20, Float _21, Float _22, Float _23,
			   Float _30, Float _31, Float _32, Float _33 ) SYNKRO_NOEXCEPT;

	/** Sets matrix to identity. */
	Matrix4x4&												MakeIdentity() SYNKRO_NOEXCEPT;

	/** Sets matrix translation. */
	Matrix4x4&												SetTranslation( const Vector3& translation ) SYNKRO_NOEXCEPT;

	/** Produces matrix for rotation on 'angle' radians around given axis. */
	Matrix4x4&												SetOrientation( const Vector3& axis, Float angle ) SYNKRO_NOEXCEPT;

	/** Produces matrix for rotation from given quaternion. */
	Matrix4x4&												SetOrientation( const Quaternion& orientation ) SYNKRO_NOEXCEPT;

	/** Sets matrix scale. */
	Matrix4x4&												SetScale( const Vector3& scale ) SYNKRO_NOEXCEPT;

	/** Scales matrix uniformly in all dimensions. */
	Matrix4x4&												SetScale( Float scale ) SYNKRO_NOEXCEPT;

	/** Produces perspective projection matrix. */
	Matrix4x4&												SetPerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back ) SYNKRO_NOEXCEPT;

	/** Adjusts matrix orientation so that it looks at the given point. */
	Matrix4x4&												SetLookAt( const Vector3& target, const Vector3& eye, const Vector3& up ) SYNKRO_NOEXCEPT;

	/** Adds another matrix to this one. */
	Matrix4x4&												operator+=( const Matrix4x4& other ) SYNKRO_NOEXCEPT;

	/** Subtracts another matrix from this one. */
	Matrix4x4&												operator-=( const Matrix4x4& other ) SYNKRO_NOEXCEPT;

	/** Multiplies matrix by another matrix. */
	Matrix4x4&												operator*=( const Matrix4x4& other ) SYNKRO_NOEXCEPT;

	/** Multiplies matrix by a scalar. */
	Matrix4x4&												operator*=( Float value ) SYNKRO_NOEXCEPT;

	/** Divides matrix by a scalar. */
	Matrix4x4&												operator/=( Float value );

	/** Returns the sum of two matrices. */
	Matrix4x4												operator+( const Matrix4x4& other ) const SYNKRO_NOEXCEPT;

	/** Returns the difference between two matrices. */
	Matrix4x4												operator-( const Matrix4x4& other ) const SYNKRO_NOEXCEPT;

	/** Returns component-wise negation of this matrix. */
	Matrix4x4												operator-() const SYNKRO_NOEXCEPT;

	/** Returns the product of two matrices. */
	Matrix4x4												operator*( const Matrix4x4& other ) const SYNKRO_NOEXCEPT;

	/** Returns matrix multiplied by a scalar. */
	Matrix4x4												operator*( Float value ) const SYNKRO_NOEXCEPT;

	/** Returns matrix divided by a scalar. */
	Matrix4x4												operator/( Float value ) const;

	/**
	 * Applies matrix transformation to the given vector.
	 * @param vector Vector to be transformed.
	 * @return Transformed vector.
	 */
	Vector3													operator*( const Vector3& vector ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests matrices for equality.
	 * @param other Matrix to compare to.
	 * @return true for equal matrices.
	 */
	Bool													operator==( const Matrix4x4& other ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests matrices for inequality.
	 * @param other Matrix to compare to.
	 * @return true for unequal matrices.
	 */
	Bool													operator!=( const Matrix4x4& other ) const SYNKRO_NOEXCEPT;

	/** Returns matrix determinant. */
	Float													Determinant() const SYNKRO_NOEXCEPT;

	/** Returns inverted matrix. */
	Matrix4x4												Inverse() const SYNKRO_NOEXCEPT;

	/** Returns transposed matrix. */
	Matrix4x4												Transpose() const SYNKRO_NOEXCEPT;

	/** Returns matrix translation. */
	Vector3													Translation() const SYNKRO_NOEXCEPT;

	/** Returns matrix translation as a 4-component vector. */
	Vector4													Translation4() const SYNKRO_NOEXCEPT;

	/** Returns matrix orientation. */
	Quaternion												Orientation() const SYNKRO_NOEXCEPT;

	/** Returns matrix scale. */
	Vector3													Scale() const SYNKRO_NOEXCEPT;

	/** Returns matrix orientation X axis. */
	Vector3													Right() const SYNKRO_NOEXCEPT;

	/** Returns matrix orientation Y axis. */
	Vector3													Up() const SYNKRO_NOEXCEPT;

	/** Returns matrix orientation Z axis. */
	Vector3													Forward() const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the given vector.
	 * @param vector Vector to be rotated.
	 * @return Rotated vector.
	 */
	Vector3													Rotate( const Vector3& vector ) const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the matrix around arbitrary axis.
	 * @param axis Axis around which to rotate the matrix.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												Rotate( const Vector3& axis, Float angle ) const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the matrix using given quaternion.
	 * @param orientation Quaternion used to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												Rotate( const Quaternion& orientation ) const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the matrix around X-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateX( Float angle ) const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the matrix around Y-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateY( Float angle ) const SYNKRO_NOEXCEPT;

	/**
	 * Rotates the matrix around Z-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateZ( Float angle ) const SYNKRO_NOEXCEPT;

	/** Returns mirror matrix for X-axis. */
	Matrix4x4												MirrorX() const SYNKRO_NOEXCEPT;

	/** Returns mirror matrix for Y-axis. */
	Matrix4x4												MirrorY() const SYNKRO_NOEXCEPT;

	/** Returns mirror matrix for Z-axis. */
	Matrix4x4												MirrorZ() const SYNKRO_NOEXCEPT;

	/**
	 * Returns perspective projection matrix.
	 * @param horzFOV Horizontal field of view.
	 * @param aspect Aspect ratio.
	 * @param front Near view-plane.
	 * @param back Far view-plane.
	 */
	Matrix4x4												PerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back ) const SYNKRO_NOEXCEPT;

	/**
	 * Returns matrix looking at the given point.
	 * @param target Point at which to look.
	 * @param position Position from which to look.
	 * @param up Vector pointing to the top.
	 */
	Matrix4x4												LookAt( const Vector3& target, const Vector3& position, const Vector3& up ) const SYNKRO_NOEXCEPT;

	/**
	 * Tests matrix for identity.
	 * @return true for identity matrix, false otherwise.
	 */
	Bool													IsIdentity() const SYNKRO_NOEXCEPT;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_MATRIX4X4_
