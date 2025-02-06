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
#include "config.h"
#include <gfx/CubeFace.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( CubeFace, PositiveX,	0 )
SYNKRO_DEFINE_CONST( CubeFace, NegativeX,	1 )
SYNKRO_DEFINE_CONST( CubeFace, PositiveY,	2 )
SYNKRO_DEFINE_CONST( CubeFace, NegativeY,	3 )
SYNKRO_DEFINE_CONST( CubeFace, PositiveZ,	4 )
SYNKRO_DEFINE_CONST( CubeFace, NegativeZ,	5 )


} // gfx


} // synkro
