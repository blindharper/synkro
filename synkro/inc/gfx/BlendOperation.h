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
// Purpose: Defines blending operation.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDOPERATION_
#define _SYNKRO_GFX_BLENDOPERATION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Blending operation.
 */
SYNKRO_ENUM_BEGIN( BlendOperation )
	/** The result is the destination added to the source. Result = Source + Destination. */
	SYNKRO_ENUM_CONST( BlendOperation, Add )

	/** The result is the destination subtracted from to the source. Result = Source - Destination. */
	SYNKRO_ENUM_CONST( BlendOperation, Sub )

	/** The result is the source subtracted from the destination. Result = Destination - Source. */
	SYNKRO_ENUM_CONST( BlendOperation, RevSub )

	/** The result is the minimum of the source and destination. Result = MIN(Source, Destination). */
	SYNKRO_ENUM_CONST( BlendOperation, Min )

	/** The result is the maximum of the source and destination. Result = MAX(Source, Destination). */
	SYNKRO_ENUM_CONST( BlendOperation, Max )

	/** Creates stereo mode from string. */
	BlendOperation( const lang::String& operation );

	/** Converts stereo mode to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDOPERATION_
