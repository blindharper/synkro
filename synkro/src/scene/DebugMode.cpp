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
// Purpose: Defines scene debug mode.
//==============================================================================
#include "config.h"
#include <scene/DebugMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( DebugMode, None,			0x00 )
SYNKRO_DEFINE_CONST( DebugMode, Gizmos,			0x01 )
SYNKRO_DEFINE_CONST( DebugMode, Helpers,		0x02 )
SYNKRO_DEFINE_CONST( DebugMode, Curves,			0x04 )
SYNKRO_DEFINE_CONST( DebugMode, Constraints,	0x08 )
SYNKRO_DEFINE_CONST( DebugMode, Normals,		0x10 )


} // scene


} // synkro
