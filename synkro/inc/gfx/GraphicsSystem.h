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
// Purpose: Defines graphics system types.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSSYSTEM_
#define _SYNKRO_GFX_GRAPHICSSYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics system types.
 */
SYNKRO_ENUM_BEGIN( GraphicsSystem )
	/** Custom graphics system. */
	SYNKRO_ENUM_CONST( GraphicsSystem, Custom )

	/** DirectX 11 based graphics system. */
	SYNKRO_ENUM_CONST( GraphicsSystem, DirectX11 )

	/** Converts graphics system type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSSYSTEM_
