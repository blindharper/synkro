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
// Purpose: Defines plain rendering map.
//==============================================================================
#ifndef _SYNKRO_GFX_IPLAINRENDERMAP_
#define _SYNKRO_GFX_IPLAINRENDERMAP_


#include "config.h"
#include <gfx/IRenderMap.h>


namespace synkro
{


namespace gfx
{


/**
 * Plain rendering map.
 */
iface IPlainRenderMap :
	public IRenderMap
{
public:
	/**
	 * Retrieves color target.
	 */
	virtual IPlainRenderTexture*							GetColorTarget() const = 0;

	/**
	 * Retrieves depth target.
	 */
	virtual IPlainDepthTexture*								GetDepthTarget() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPLAINRENDERMAP_
