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
// Purpose: TCB spline.
//==============================================================================
#ifndef _SYNKRO_MATH_TCBSPLINE_
#define _SYNKRO_MATH_TCBSPLINE_


#include "config.h"
#include <math/Vector3.h>


namespace synkro
{


namespace math
{


// TCB spline.
class SYNKRO_API TcbSpline
{
public:
	// Constructor.
	TcbSpline();

	// Calculates input and output tangents for the point.
	void													CalculateTangents( const Vector3& point, const Vector3& prev, const Vector3& next, Float t, Float c, Float b, Vector3& input, Vector3& output );

	// Returns interpolated position.
	void													GetPoint( Float t, Float t1, Float t2, const Vector3& point1, const Vector3& point2, const Vector3& tangent1, const Vector3& tangent2, Vector3& point ) const;

private:
	Float													Hermit0( Float t ) const;
	Float													Hermit1( Float t ) const;
	Float													Hermit2( Float t ) const;
	Float													Hermit3( Float t ) const;
};


#include "TcbSpline.inl"


} // math


} // synkro


#endif // _SYNKRO_MATH_TCBSPLINE_
