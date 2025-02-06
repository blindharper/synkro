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
// Purpose: Defines cube rendering map.
//==============================================================================
#ifndef _SYNKRO_GFX_ICUBERENDERMAP_
#define _SYNKRO_GFX_ICUBERENDERMAP_


#include "config.h"
#include <gfx/IRenderMap.h>


namespace synkro
{


namespace gfx
{


/**
 * Cube rendering map.
 */
iface ICubeRenderMap :
	public IRenderMap
{
public:
	/**
	 * Retrieves color target.
	 */
	virtual ICubeRenderTexture*								GetColorTarget() const = 0;

	/**
	 * Retrieves depth target.
	 */
	virtual ICubeDepthTexture*								GetDepthTarget() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ICUBERENDERMAP_
