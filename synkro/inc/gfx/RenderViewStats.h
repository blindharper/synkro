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
// Purpose: Defines rendering view statistics.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERVIEWSTATS_
#define _SYNKRO_GFX_RENDERVIEWSTATS_


#include "config.h"


namespace synkro
{


namespace gfx
{


/** 
 * Rendering view statistics.
 */
class SYNKRO_API RenderViewStats
{
public:
	/** Creates default rendering view statistics. */
	RenderViewStats();

	/** Rate at which the view is rendered. */
	Float													FramesPerSecond;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERVIEWSTATS_
