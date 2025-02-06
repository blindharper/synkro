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
// Purpose: Defines geometric primitive types.
//==============================================================================
#include "config.h"
#include <gfx/PrimitiveType.h>
#include <internal/Enum.h>
#include "PrimitiveTypeConst.h"


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( PrimitiveType, Unknown,		PRIMITIVE_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( PrimitiveType, PointList,		PRIMITIVE_TYPE_POINT_LIST )
SYNKRO_DEFINE_CONST( PrimitiveType, LineList,		PRIMITIVE_TYPE_LINE_LIST )
SYNKRO_DEFINE_CONST( PrimitiveType, LineStrip,		PRIMITIVE_TYPE_LINE_STRIP )
SYNKRO_DEFINE_CONST( PrimitiveType, TriangleList,	PRIMITIVE_TYPE_TRIANGLE_LIST )
SYNKRO_DEFINE_CONST( PrimitiveType, TriangleStrip,	PRIMITIVE_TYPE_TRIANGLE_STRIP )
SYNKRO_DEFINE_CONST( PrimitiveType, PatchList,		PRIMITIVE_TYPE_PATCH_LIST )


UInt PrimitiveType::GetPrimitiveCount( const PrimitiveType& type, UInt vertexCount )
{
	switch ( type )
	{
		case PRIMITIVE_TYPE_POINT_LIST:
			return vertexCount;

		case PRIMITIVE_TYPE_LINE_LIST:
			return vertexCount/2;

		case PRIMITIVE_TYPE_LINE_STRIP:
			return vertexCount-1;

		case PRIMITIVE_TYPE_TRIANGLE_LIST:
			return vertexCount/3;

		case PRIMITIVE_TYPE_TRIANGLE_STRIP:
			return vertexCount-2;

		default:
			return 0;
	}
}


} // gfx


} // synkro
