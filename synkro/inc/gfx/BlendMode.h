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
// Purpose: Defines blending mode.
//==============================================================================
#ifndef _SYNKRO_GFX_BLENDMODE_
#define _SYNKRO_GFX_BLENDMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Source and destination blending mode.
 */
SYNKRO_ENUM_BEGIN( BlendMode )
	/** Unknown blend factor. */
	SYNKRO_ENUM_CONST( BlendMode, Unknown )

	/** Blend factor is (0, 0, 0, 0). */
	SYNKRO_ENUM_CONST( BlendMode, Zero )
	
	/** Blend factor is (1, 1, 1, 1). */
	SYNKRO_ENUM_CONST( BlendMode, One )
	
	/** Blend factor is (Rs, Gs, Bs, As). */
	SYNKRO_ENUM_CONST( BlendMode, SrcColor )
	
	/** Blend factor is (1 - Rs, 1 - Gs, 1 - Bs, 1 - As). */
	SYNKRO_ENUM_CONST( BlendMode, InvSrcColor )
	
	/** Blend factor is (As, As, As, As). */
	SYNKRO_ENUM_CONST( BlendMode, SrcAlpha )
	
	/** Blend factor is ( 1 - As, 1 - As, 1 - As, 1 - As). */
	SYNKRO_ENUM_CONST( BlendMode, InvSrcAlpha )
	
	/** Blend factor is (Ad, Ad, Ad, Ad). */
	SYNKRO_ENUM_CONST( BlendMode, DstAlpha )
	
	/** Blend factor is (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad). */
	SYNKRO_ENUM_CONST( BlendMode, InvDstAlpha )
	
	/** Blend factor is (Rd, Gd, Bd, Ad). */
	SYNKRO_ENUM_CONST( BlendMode, DstColor )
	
	/** Blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad). */
	SYNKRO_ENUM_CONST( BlendMode, InvDstColor )
	
	/** Blend factor is (f, f, f, 1); f = min(As, 1 - Ad). */
	SYNKRO_ENUM_CONST( BlendMode, SrcAlphaSat )

	/** Creates blend mode from string. */
	BlendMode( const lang::String& mode );

	/** Converts blend mode to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BLENDMODE_
