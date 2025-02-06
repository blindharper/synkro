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
// Purpose: Defines index data type.
//==============================================================================
#ifndef _SYNKRO_GFX_INDEXTYPE_
#define _SYNKRO_GFX_INDEXTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Index data type.
 */
SYNKRO_ENUM_BEGIN( IndexType )
	/** No indexing. Used for non-indexed data buffers. */
	SYNKRO_ENUM_CONST( IndexType, None )

	/** Unsigned 16-bit integer values. */
	SYNKRO_ENUM_CONST( IndexType, Short )

	/** Unsigned 32-bit integer values. */
	SYNKRO_ENUM_CONST( IndexType, Long )

	/** Creates index type from string. */
	IndexType( const lang::String& type );

	/**
	 * Calculates index type based on the vertex count.
	 * @param vertexCount Number of primitive vertices.
	 */
	static IndexType										Get( UInt vertexCount );

	/** Retrieves index size, in bytes. */
	UInt													Size() const;

	/** Converts index type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_INDEXTYPE_
