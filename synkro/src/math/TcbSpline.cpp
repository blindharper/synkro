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
#include "config.h"
#include "TcbSpline.h"


namespace synkro
{


namespace math
{


TcbSpline::TcbSpline()
{
}

void TcbSpline::CalculateTangents( const Vector3& point, const Vector3& prev, const Vector3& next, Float t, Float c, Float b, Vector3& input, Vector3& output )
{
	const Float t1 = (1.0f-t);
	const Float c1 = (1.0f-c);
	const Float c2 = (1.0f+c);
	const Float b1 = (1.0f-b);
	const Float b2 = (1.0f+b);

	const Float ki1 = 0.5f*t1*c2*b1;
	const Float ki2 = 0.5f*t1*c1*b2;

	const Float ko1 = 0.5f*t1*c1*b1;
	const Float ko2 = 0.5f*t1*c2*b2;

	const Vector3 pp = point - prev;
	const Vector3 pn = next - point;

	input = pn*ki1 + pp*ki2;
	output = pn*ko1 + pp*ko2;
}

void TcbSpline::GetPoint( Float t, Float t1, Float t2, const Vector3& point1, const Vector3& point2, const Vector3& tangent1, const Vector3& tangent2, Vector3& point ) const
{
	const Float dt = t2 - t1;
	const Float s = (t - t1)/dt;
	point = point1*Hermit0(s) + point2*Hermit1(s) + tangent1*Hermit2(s)*dt + tangent2*Hermit3(s)*dt;
}


} // math


} // synkro
