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
	Matrix4x4();

	/** Copy constructor. */
	Matrix4x4( const Matrix4x4& other );

	/** Constructs identity matrix multiplied by value. */
	explicit Matrix4x4( Float value );

	/** Constructs matrix from an array of 16 scalars. */
	explicit Matrix4x4( Float* array );

	/** Constructs matrix from 16 scalar values. */
	Matrix4x4( Float _00, Float _01, Float _02, Float _03,
			   Float _10, Float _11, Float _12, Float _13,
			   Float _20, Float _21, Float _22, Float _23,
			   Float _30, Float _31, Float _32, Float _33 );

	/** Sets matrix to identity. */
	Matrix4x4&												MakeIdentity();

	/** Sets matrix translation. */
	Matrix4x4&												SetTranslation( const Vector3& translation );

	/** Produces matrix for rotation on 'angle' radians around given axis. */
	Matrix4x4&												SetOrientation( const Vector3& axis, Float angle );

	/** Produces matrix for rotation from given quaternion. */
	Matrix4x4&												SetOrientation( const Quaternion& orientation );

	/** Sets matrix scale. */
	Matrix4x4&												SetScale( const Vector3& scale );

	/** Scales matrix uniformly in all dimensions. */
	Matrix4x4&												SetScale( Float scale );

	/** Produces perspective projection matrix. */
	Matrix4x4&												SetPerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back );

	/** Adjusts matrix orientation so that it looks at the specified point. */
	Matrix4x4&												SetLookAt( const Vector3& target, const Vector3& eye, const Vector3& up );

	/** Adds another matrix to this one. */
	Matrix4x4&												operator+=( const Matrix4x4& other );

	/** Subtracts another matrix from this one. */
	Matrix4x4&												operator-=( const Matrix4x4& other );

	/** Multiplies matrix by another matrix. */
	Matrix4x4&												operator*=( const Matrix4x4& other );

	/** Multiplies matrix by a scalar. */
	Matrix4x4&												operator*=( Float value );

	/** Divides matrix by a scalar. */
	Matrix4x4&												operator/=( Float value );

	/** Returns the sum of two matrices. */
	Matrix4x4												operator+( const Matrix4x4& other ) const;

	/** Returns the difference between two matrices. */
	Matrix4x4												operator-( const Matrix4x4& other ) const;

	/** Returns component-wise negation of this matrix. */
	Matrix4x4												operator-() const;

	/** Returns the product of two matrices. */
	Matrix4x4												operator*( const Matrix4x4& other ) const;

	/** Returns matrix multiplied by a scalar. */
	Matrix4x4												operator*( Float value ) const;

	/** Returns matrix divided by a scalar. */
	Matrix4x4												operator/( Float value ) const;

	/**
	 * Applies matrix transformation to the specified vector.
	 * @param vector Vector to be transformed.
	 * @return Transformed vector.
	 */
	Vector3													operator*( const Vector3& vector ) const;

	/**
	 * Tests matrices for equality.
	 * @param other Matrix to compare to.
	 * @return true for equal matrices.
	 */
	Bool													operator==( const Matrix4x4& other ) const;

	/**
	 * Tests matrices for inequality.
	 * @param other Matrix to compare to.
	 * @return true for unequal matrices.
	 */
	Bool													operator!=( const Matrix4x4& other ) const;

	/** Returns matrix determinant. */
	Float													Determinant() const;

	/** Returns inverted matrix. */
	Matrix4x4												Inverse() const;

	/** Returns transposed matrix. */
	Matrix4x4												Transpose() const;

	/** Returns matrix translation. */
	Vector3													Translation() const;

	/** Returns matrix translation as a 4-component vector. */
	Vector4													Translation4() const;

	/** Returns matrix orientation. */
	Quaternion												Orientation() const;

	/** Returns matrix scale. */
	Vector3													Scale() const;

	/** Returns matrix orientation X axis. */
	Vector3													Right() const;

	/** Returns matrix orientation Y axis. */
	Vector3													Up() const;

	/** Returns matrix orientation Z axis. */
	Vector3													Forward() const;

	/**
	 * Rotates the specified vector.
	 * @param vector Vector to be rotated.
	 * @return Rotated vector.
	 */
	Vector3													Rotate( const Vector3& vector ) const;

	/**
	 * Rotates the matrix around arbitrary axis.
	 * @param axis Axis around which to rotate the matrix.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												Rotate( const Vector3& axis, Float angle ) const;

	/**
	 * Rotates the matrix using given quaternion.
	 * @param orientation Quaternion used to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												Rotate( const Quaternion& orientation ) const;

	/**
	 * Rotates the matrix around X-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateX( Float angle ) const;

	/**
	 * Rotates the matrix around Y-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateY( Float angle ) const;

	/**
	 * Rotates the matrix around Z-axis.
	 * @param angle Angle, in radians, for which to rotate the matrix.
	 * @return Rotated matrix.
	 */
	Matrix4x4												RotateZ( Float angle ) const;

	/** Returns mirror matrix for X-axis. */
	Matrix4x4												MirrorX() const;

	/** Returns mirror matrix for Y-axis. */
	Matrix4x4												MirrorY() const;

	/** Returns mirror matrix for Z-axis. */
	Matrix4x4												MirrorZ() const;

	/**
	 * Returns perspective projection matrix.
	 * @param horzFOV Horizontal field of view.
	 * @param aspect Aspect ratio.
	 * @param front Near view-plane.
	 * @param back Far view-plane.
	 */
	Matrix4x4												PerspectiveProjection( Float horzFOV, Float aspect, Float front, Float back ) const;

	/**
	 * Returns matrix looking at the specified point.
	 * @param target Point at which to look.
	 * @param position Position from which to look.
	 * @param up Vector pointing to the top.
	 */
	Matrix4x4												LookAt( const Vector3& target, const Vector3& position, const Vector3& up ) const;

	/**
	 * Tests matrix for identity.
	 * @return true for identity matrix, false otherwise.
	 */
	Bool													IsIdentity() const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_MATRIX4X4_
