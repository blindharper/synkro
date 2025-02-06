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
// Purpose: Defines cubic Bezier curve.
//==============================================================================
#ifndef _SYNKRO_MATH_CUBICBEZIER_
#define _SYNKRO_MATH_CUBICBEZIER_


#include "config.h"


namespace synkro
{


namespace math
{


// Cubic Bezier curve.
class SYNKRO_API CubicBezier
{
public:
	static CubicBezier										Ease;
	static CubicBezier										EaseIn;
	static CubicBezier										EaseOut;
	static CubicBezier										EaseInOut;

	// Constructs bezier curve from two points.
	CubicBezier( Double x1, Double y1, Double x2, Double y2 );

	// Returns y coordinate for the given x coordinate.
	Double													Solve( Double x ) const;

private:
	Double													SampleCurveX( Double t ) const;
	Double													SampleCurveY( Double t ) const;
	Double													SampleCurveDerivativeX( Double t ) const;
	Double													SolveCurveX( Double x ) const;

	Double													ax, bx, cx;
	Double													ay, by, cy;
};


#include "CubicBezier.inl"


} // math


} // synkro


#endif // _SYNKRO_MATH_CUBICBEZIER_
