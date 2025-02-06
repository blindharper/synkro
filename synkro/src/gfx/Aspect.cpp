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
#include "config.h"
#include <gfx/Aspect.h>
#include <internal/Enum.h>
#include "AspectConst.h"


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( Aspect, Unknown,		ASPECT_UNKNOWN )
SYNKRO_DEFINE_CONST( Aspect, Aspect2x1,		ASPECT_2X1 )
SYNKRO_DEFINE_CONST( Aspect, Aspect3x2,		ASPECT_3X2 )
SYNKRO_DEFINE_CONST( Aspect, Aspect4x3,		ASPECT_4X3 )
SYNKRO_DEFINE_CONST( Aspect, Aspect5x4,		ASPECT_5X4 )
SYNKRO_DEFINE_CONST( Aspect, Aspect8x5,		ASPECT_8X5 )
SYNKRO_DEFINE_CONST( Aspect, Aspect16x9,	ASPECT_16X9 )


} // gfx


} // synkro
