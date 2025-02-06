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
SYNKRO_INLINE Double CubicBezier::SampleCurveX( Double t ) const
{
	return ((ax * t + bx) * t + cx) * t;
}

SYNKRO_INLINE Double CubicBezier::SampleCurveY( Double t ) const
{
	return ((ay * t + by) * t + cy) * t;
}

SYNKRO_INLINE Double CubicBezier::SampleCurveDerivativeX( Double t ) const
{
	return (3.0 * ax * t + 2.0 * bx) * t + cx;
}
