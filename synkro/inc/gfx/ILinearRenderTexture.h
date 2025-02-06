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
// Purpose: Defines linear rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ILINEARRENDERTEXTURE_
#define _SYNKRO_GFX_ILINEARRENDERTEXTURE_


#include "config.h"
#include <gfx/IRenderTexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Linear rendering texture.
 */
iface ILinearRenderTexture :
	public IRenderTexture
{
public:
	/**
	 * Gets rendering texture surface data.
	 * @param [out] length Texture surface length.
	 * @param [out] format Texture surface pixel format.
	 * @param [out] data Texture surface data.
	 * @param [out] size Texture data size.
	 * @return True, if data were successfully read, false otherwise.
	 */
	virtual Bool											GetData( UInt* length, img::PixelFormat* format, Byte** data, UInt* size ) = 0;

	/**
	 * Retrieves texture length.
	 */
	virtual UInt											GetLength() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ILINEARRENDERTEXTURE_
