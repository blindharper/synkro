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
// Purpose: Defines faces culling mode.
//==============================================================================
#ifndef _SYNKRO_GFX_CULLMODE_
#define _SYNKRO_GFX_CULLMODE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Faces culling mode.
 */
SYNKRO_ENUM_BEGIN( CullMode )
	/** Do not perform any culling. */
	SYNKRO_ENUM_CONST( CullMode, None )

	/** Cull front faces. */
	SYNKRO_ENUM_CONST( CullMode, Front )

	/** Cull back faces. */
	SYNKRO_ENUM_CONST( CullMode, Back )

	/** Creates cull mode from string. */
	CullMode( const lang::String& mode );

	/** Converts cull mode to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CULLMODE_
