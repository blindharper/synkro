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
// Purpose: Defines geometric primitive type constant values.
//==============================================================================
#ifndef _SYNKRO_GFX_PRIMITIVETYPECONST_
#define _SYNKRO_GFX_PRIMITIVETYPECONST_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Geometric primitive type constant values.
enum PrimitiveTypeConst
{
	PRIMITIVE_TYPE_UNKNOWN			= 0,
	PRIMITIVE_TYPE_POINT_LIST		= 1,
	PRIMITIVE_TYPE_LINE_LIST		= 2,
	PRIMITIVE_TYPE_LINE_STRIP		= 3,
	PRIMITIVE_TYPE_TRIANGLE_LIST	= 4,
	PRIMITIVE_TYPE_TRIANGLE_STRIP	= 5,
	PRIMITIVE_TYPE_PATCH_LIST		= 6,
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PRIMITIVETYPECONST_
