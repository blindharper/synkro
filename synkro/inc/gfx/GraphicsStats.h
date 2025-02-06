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
#ifndef _SYNKRO_GFX_GRAPHICSSTATS_
#define _SYNKRO_GFX_GRAPHICSSTATS_


#include "config.h"


namespace synkro
{


namespace gfx
{


/** 
 * Rendering statistics for the last frame.
 */
class SYNKRO_API GraphicsStats
{
public:
	/** Creates default rendering statistics. */
	GraphicsStats();

	/** Number of rendered objects. */
	UInt													ObjectCount;

	/** Number of rendered primitives. */
	UInt													PrimitiveCount;

	/** Number of rendering states changes. */
	UInt													StateChangeCount;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_GRAPHICSSTATS_
