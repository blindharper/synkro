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
#ifndef _SYNKRO_MEM_MEMORYSTATS_
#define _SYNKRO_MEM_MEMORYSTATS_


#include "config.h"


namespace synkro
{


namespace mem
{


/** 
 * Memory usage statistics.
 */
class SYNKRO_API MemoryStats
{
public:
	/** Creates default memory statistics. */
	MemoryStats();

	/** Number of bytes currently used. */
	UInt													UsedByteCount;

	/** Maximum number of bytes used simultaneously. */
	UInt													MaximumByteCount;

	/** All-time number of bytes allocated. */
	UInt													TotalByteCount;
};


} // mem


} // synkro


#endif // _SYNKRO_MEM_MEMORYSTATS_
