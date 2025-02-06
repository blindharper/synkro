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
// Purpose: Defines screen aspect ratio.
//==============================================================================
#ifndef _SYNKRO_GFX_ASPECT_
#define _SYNKRO_GFX_ASPECT_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Screen aspect ratio.
 */
SYNKRO_ENUM_BEGIN( Aspect )
	/** Unknown ratio. */
	SYNKRO_ENUM_CONST( Aspect, Unknown )

	/** 2:1. */
	SYNKRO_ENUM_CONST( Aspect, Aspect2x1 )

	/** 3:2. */
	SYNKRO_ENUM_CONST( Aspect, Aspect3x2 )

	/** 4:3. */
	SYNKRO_ENUM_CONST( Aspect, Aspect4x3 )

	/** 5:4. */
	SYNKRO_ENUM_CONST( Aspect, Aspect5x4 )

	/** 8:5. */
	SYNKRO_ENUM_CONST( Aspect, Aspect8x5 )

	/** 16:9. */
	SYNKRO_ENUM_CONST( Aspect, Aspect16x9 )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ASPECT_
