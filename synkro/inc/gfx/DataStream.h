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
// Purpose: Defines data stream types.
//==============================================================================
#ifndef _SYNKRO_GFX_DATASTREAM_
#define _SYNKRO_GFX_DATASTREAM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Data stream types. Indicates data stream semantics.
 */
SYNKRO_ENUM_BEGIN( DataStream )
	/** Unknown stream. */
	SYNKRO_ENUM_CONST( DataStream, Unknown )

	/** Transformed position stream. */
	SYNKRO_ENUM_CONST( DataStream, Position2D )

	/** Untransformed position stream. */
	SYNKRO_ENUM_CONST( DataStream, Position3D )

	/** Untransformed position stream in 4D. */
	SYNKRO_ENUM_CONST( DataStream, Position4D )

	/** Normal stream. */
	SYNKRO_ENUM_CONST( DataStream, Normal )

	/** Color stream. */
	SYNKRO_ENUM_CONST( DataStream, Color )

	/** Bone indices stream. Each element contains 4 indices. */
	SYNKRO_ENUM_CONST( DataStream, Bones )

	/** Bone weights stream. Each element contains 4 weights. */
	SYNKRO_ENUM_CONST( DataStream, Weights )

	/** 2D-texture coordinate stream. */
	SYNKRO_ENUM_CONST( DataStream, TexCoord2D )

	/** 3D-texture coordinate stream. */
	SYNKRO_ENUM_CONST( DataStream, TexCoord3D )

	/** 4x4-matrix transformation stream. */
	SYNKRO_ENUM_CONST( DataStream, Transform )

	/** Instance ID stream. */
	SYNKRO_ENUM_CONST( DataStream, ID )

	/** Creates data stream type from string. */
	DataStream( const lang::String& type );

	/** Converts data stream type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATASTREAM_
