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
// Purpose: Defines data usage hint.
//==============================================================================
#include "config.h"
#include <gfx/DataUsage.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( DataUsage, Default,	0 )
SYNKRO_DEFINE_CONST( DataUsage, Static,		1 )
SYNKRO_DEFINE_CONST( DataUsage, Dynamic,	2 )
SYNKRO_DEFINE_CONST( DataUsage, Stream,		3 )


} // gfx


} // synkro
