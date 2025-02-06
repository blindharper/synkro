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
// Purpose: Defines graphics device types.
//==============================================================================
#ifndef _SYNKRO_GFX_GRAPHICSDEVICETYPE_
#define _SYNKRO_GFX_GRAPHICSDEVICETYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics device types.
 */
SYNKRO_ENUM_BEGIN( GraphicsDeviceType )
	/** Unknown device type. */
	SYNKRO_ENUM_CONST( GraphicsDeviceType, Unknown )

	/** Hardware device. */
	SYNKRO_ENUM_CONST( GraphicsDeviceType, Hardware )

	/** Software device. */
	SYNKRO_ENUM_CONST( GraphicsDeviceType, Software )

	/** Reference device. */
	SYNKRO_ENUM_CONST( GraphicsDeviceType, Reference )
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSDEVICETYPE_
