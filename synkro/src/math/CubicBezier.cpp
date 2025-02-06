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
#include "config.h"
#include "CubicBezier.h"
#include <math/Math.h>


namespace synkro
{


namespace math
{


CubicBezier CubicBezier::Ease( 0.25, 0.1, 0.25, 1.0 );
CubicBezier CubicBezier::EaseIn( 0.42, 0.0, 1.0, 1.0 );
CubicBezier CubicBezier::EaseOut( 0.0, 0.0, 0.58, 1.0 );
CubicBezier CubicBezier::EaseInOut( 0.42, 0.0, 0.58, 1.0 );


CubicBezier::CubicBezier( Double x1, Double y1, Double x2, Double y2 )
{
	// Calculate the polynomial coefficients, implicit first and last control points are (0,0) and (1,1).
	cx = 3.0 * x1;
	bx = 3.0 * (x2 - x1) - cx;
	ax = 1.0 - cx - bx;

	cy = 3.0 * y1;
	by = 3.0 * (y2 - y1) - cy;
	ay = 1.0 - cy - by;
}

Double CubicBezier::Solve( Double x ) const
{
	return SampleCurveY( SolveCurveX(x) );
}

Double CubicBezier::SolveCurveX( Double x ) const
{
	Double t0;
	Double t1;
	Double t2;
	Double x2;
	Double d2;
	UInt i;

	// First try a few iterations of Newton's method - normally very fast.
	for ( t2 = x, i = 0; i < 8; ++i )
	{
		x2 = SampleCurveX(t2) - x;
		if ( Math::Abs(x2) < Math::Eps )
			return t2;
		d2 = SampleCurveDerivativeX( t2 );
		if ( Math::Abs(d2) < Math::Eps )
			break;
		t2 = t2 - x2 / d2;
	}

	// Fall back to the bisection method for reliability.
	t0 = 0.0;
	t1 = 1.0;
	t2 = x;

	if ( t2 < t0 )
		return t0;
	if ( t2 > t1 )
		return t1;

	while ( t0 < t1 )
	{
		x2 = SampleCurveX(t2);
		if ( Math::Abs(x2 - x) < Math::Eps )
			return t2;
		if ( x > x2 )
			t0 = t2;
		else
			t1 = t2;
		t2 = (t1 - t0) * 0.5 + t0;
	}

	// Failure.
	return t2;
}


} // math


} // synkro
