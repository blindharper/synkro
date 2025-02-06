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
// Purpose: Defines plain depth texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IPLAINDEPTHTEXTURE_
#define _SYNKRO_GFX_IPLAINDEPTHTEXTURE_


#include "config.h"
#include <gfx/IDepthTexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Plain depth texture.
 */
iface IPlainDepthTexture :
	public IDepthTexture
{
public:
	/**
	 * Retrieves texture width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves texture height.
	 */
	virtual UInt											GetHeight() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPLAINDEPTHTEXTURE_
