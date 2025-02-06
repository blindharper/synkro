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
// Purpose: Defines memory usage statistics.
//==============================================================================
#include "config.h"
#include <mem/MemoryStats.h>


namespace synkro
{


namespace mem
{


MemoryStats::MemoryStats() :
	UsedByteCount( 0 ),
	MaximumByteCount( 0 ),
	TotalByteCount( 0 )
{
}


} // mem


} // synkro
