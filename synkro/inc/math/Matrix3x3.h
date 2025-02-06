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
//==============================================================================
#ifndef _SYNKRO_MATH_MATRIX3X3_
#define _SYNKRO_MATH_MATRIX3X3_


#include "config.h"


namespace synkro
{


namespace math
{


/**
 * Matrix of 3x3 floating-point value elements.
 */
class SYNKRO_API Matrix3x3
{
public:
	// Matrix components.
	union
	{
		Float d[9];
		Float m[3][3];
		struct
		{
			Float _00, _01, _02;
			Float _10, _11, _12;
			Float _20, _21, _22;
		};
	};

	/**
	 * Identity matrix.
	 */
	static const Matrix3x3									Identity;

	/**
	 * Constructs a default matrix.
	 */
	Matrix3x3();

	/**
	 * Copy constructor.
	 */
	Matrix3x3( const Matrix3x3& other );

	/**
	 * Constructs identity matrix multiplied by scalar.
	 */
	explicit Matrix3x3( Float value );

	/**
	 * Constructs matrix from an array of 9 scalars.
	 * @exception BadArgumentException Invalid pointer.
	 */
	explicit Matrix3x3( Float* array );

	/**
	 * Constructs matrix from 9 scalar values.
	 */
	Matrix3x3( Float _00, Float _01, Float _02,
			   Float _10, Float _11, Float _12,
			   Float _20, Float _21, Float _22 );

	/**
	 * Adds another matrix to this one.
	 */
	Matrix3x3&												operator+=( const Matrix3x3& other );

	/**
	 * Subtracts another matrix from this one.
	 */
	Matrix3x3&												operator-=( const Matrix3x3& other );

	/**
	 * Multiplies matrix by a scalar.
	 */
	Matrix3x3&												operator*=( Float value );

	/**
	 * Divides matrix by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Matrix3x3&												operator/=( Float value );

	/**
	 * Returns the sum of two matrices.
	 */
	Matrix3x3												operator+( const Matrix3x3& other ) const;

	/**
	 * Returns the difference between two matrices.
	 */
	Matrix3x3												operator-( const Matrix3x3& other ) const;

	/**
	 * Returns component-wise negation of this matrix.
	 */
	Matrix3x3												operator-() const;

	/**
	 * Returns this matrix multiplied by a scalar.
	 */
	Matrix3x3												operator*( Float value ) const;

	/**
	 * Returns this matrix divided by a scalar.
	 * @exception DivisionByZeroException.
	 */
	Matrix3x3												operator/( Float value ) const;

	/**
	 * Returns matrix determinant.
	 */
	Float													Determinant() const;

	/**
	 * Returns transposed matrix.
	 */
	Matrix3x3												Transpose() const;

	/**
	 * Tests matrices for equality.
	 * @param other Matrix to compare to.
	 * @return true for equal matrices.
	 */
	Bool													operator==( const Matrix3x3& other ) const;

	/**
	 * Tests matrices for inequality.
	 * @param other Matrix to compare to.
	 * @return true for unequal matrices.
	 */
	Bool													operator!=( const Matrix3x3& other ) const;
};


} // math


} // synkro


#endif // _SYNKRO_MATH_MATRIX3X3_
