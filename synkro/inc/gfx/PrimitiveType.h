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
#ifndef _SYNKRO_GFX_PRIMITIVETYPE_
#define _SYNKRO_GFX_PRIMITIVETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Geometric primitive type.
 */
SYNKRO_ENUM_BEGIN( PrimitiveType )
	/** Unknown primitive type. */
	SYNKRO_ENUM_CONST( PrimitiveType, Unknown )

	/** A collection of vertices rendered as isolated points. */
	SYNKRO_ENUM_CONST( PrimitiveType, PointList )

	/** A list of isolated straight line segments. */
	SYNKRO_ENUM_CONST( PrimitiveType, LineList )

	/** A list of connected line segments. */
	SYNKRO_ENUM_CONST( PrimitiveType, LineStrip )

	/** A list of isolated triangles. */
	SYNKRO_ENUM_CONST( PrimitiveType, TriangleList )

	/** A series of connected triangles. */
	SYNKRO_ENUM_CONST( PrimitiveType, TriangleStrip )

	/** A list of isolated patches. */
	SYNKRO_ENUM_CONST( PrimitiveType, PatchList )

	/**
	 * Returns the number of primitives of the given type that
	 * can be created from the given number of vertices.
	 * @param type Primitive type.
	 * @param vertexCount Number of vertices.
	 * @return The number of primitives.
	 */
	static UInt												GetPrimitiveCount( const PrimitiveType& type, UInt vertexCount );
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PRIMITIVETYPE_
