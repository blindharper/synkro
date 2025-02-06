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
// Purpose: Defines rendering statistics.
//==============================================================================
#include "config.h"
#include <gfx/GraphicsStats.h>


namespace synkro
{


namespace gfx
{


GraphicsStats::GraphicsStats() :
	ObjectCount( 0 ),
	PrimitiveCount( 0 ),
	StateChangeCount( 0 ) 
{
}


} // gfx


} // synkro
