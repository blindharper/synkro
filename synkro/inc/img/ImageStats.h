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
// Purpose: Defines image statistics.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGESTATS_
#define _SYNKRO_IMG_IMAGESTATS_


#include "config.h"


namespace synkro
{


namespace img
{


/** 
 * Image statistics.
 */
class SYNKRO_API ImageStats
{
public:
	/** Creates default image statistics. */
	ImageStats();

	/** Total size of the images residing in the cache, in bytes. */
	UInt													CacheSize;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGESTATS_
