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
// Purpose: Defines cube map face.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBEFACE_
#define _SYNKRO_GFX_CUBEFACE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Cube map face.
 */
SYNKRO_ENUM_BEGIN( CubeFace )
	/** Positive X face. */
	SYNKRO_ENUM_CONST( CubeFace, PositiveX )

	/** Negative X face. */
	SYNKRO_ENUM_CONST( CubeFace, NegativeX )

	/** Positive Y face. */
	SYNKRO_ENUM_CONST( CubeFace, PositiveY )

	/** Negative Y face. */
	SYNKRO_ENUM_CONST( CubeFace, NegativeY )

	/** Positive Z face. */
	SYNKRO_ENUM_CONST( CubeFace, PositiveZ )

	/** Negative Z face. */
	SYNKRO_ENUM_CONST( CubeFace, NegativeZ )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBEFACE_
