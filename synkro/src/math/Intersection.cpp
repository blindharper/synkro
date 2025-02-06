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
// Purpose: Defines intersection testing utilities.
//==============================================================================
#include "config.h"
#include "Intersection.h"
#include <math/Math.h>


namespace synkro
{


namespace math
{


Bool Intersection::TestRayAndTriangle( const Vector3& origin, const Vector3& direction, const Vector3& v0, const Vector3& v1, const Vector3& v2, Float* distance )
{
	// Find vectors for two edges sharing 0.
	const Vector3 edge1 = v1 - v0;
	const Vector3 edge2 = v2 - v0;

	// Begin calculating determinant.
	const Vector3 pvec = direction ^ edge2;

	// If determinant is near zero, ray lies in plane of triangle.
	const Float det = edge1 * pvec;

	// The culling branch.
	if ( Math::Abs(det) <= Math::MinFloat )
		return false;
	const Float invdet = 1.0f/det;

	// Calculate distance from 0 to ray origin.
	const Vector3 tvec = origin - v0;

	// Calculate U parameter and test bounds.
	const Float u = (tvec*pvec)*invdet;
	if ( (u < 0.0f) || (u > 1.0f) )
		return false;

	// Prepare to test V parameter.
	const Vector3 qvec = tvec ^ edge1;

	// Calculate V parameter and test bounds.
	const Float v = (direction*qvec)*invdet;
	if ( (v < 0.0f) || (u+v > 1.0f) )
		return false;

	// Ray intersects triangle.
	const Float s = Math::Abs( (edge2*qvec)*invdet );
	*distance = s;
	return true;
}


} // math


} // synkro
