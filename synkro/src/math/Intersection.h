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
#ifndef _SYNKRO_MATH_INTERSECTION_
#define _SYNKRO_MATH_INTERSECTION_


#include "config.h"
#include <math/Vector3.h>


namespace synkro
{


namespace math
{


// Intersection testing utilities.
class SYNKRO_API Intersection
{
public:
	// Finds ray triangle intersection. Assumes clockwise vertex order.
	// @param origin Ray origin.
	// @param direction Ray direction.
	// @param v0 The first vertex of the triangle.
	// @param v1 The second vertex of the triangle.
	// @param v2 The third vertex of the triangle.
	// @param distance [out] Receives length along ray to the intersection, if any.
	// @return True if intersection exists, false otherwise.
	static Bool												TestRayAndTriangle( const Vector3& origin, const Vector3& direction, const Vector3& v0, const Vector3& v1, const Vector3& v2, Float* distance );
};


} // math


} // synkro


#endif // _SYNKRO_MATH_INTERSECTION_
