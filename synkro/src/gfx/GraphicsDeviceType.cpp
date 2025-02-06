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
#include "config.h"
#include <gfx/GraphicsDeviceType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( GraphicsDeviceType, Unknown,	0 )
SYNKRO_DEFINE_CONST( GraphicsDeviceType, Hardware,	1 )
SYNKRO_DEFINE_CONST( GraphicsDeviceType, Software,	2 )
SYNKRO_DEFINE_CONST( GraphicsDeviceType, Reference,	3 )


} // gfx


} // synkro
