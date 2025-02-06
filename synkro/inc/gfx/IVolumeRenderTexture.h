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
// Purpose: Defines volume rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IVOLUMERENDERTEXTURE_
#define _SYNKRO_GFX_IVOLUMERENDERTEXTURE_


#include "config.h"
#include <gfx/IRenderTexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Volume rendering texture.
 */
iface IVolumeRenderTexture :
	public IRenderTexture
{
public:
	/**
	 * Gets rendering texture surface data.
	 * @param element Texture array element for which to set data.
	 * @param [out] width Texture surface width.
	 * @param [out] height Texture surface height.
	 * @param [out] depth Texture surface depth.
	 * @param [out] stride Texture surface stride.
	 * @param [out] sliceStride Texture slice stride.
	 * @param [out] format Texture surface pixel format.
	 * @param [out] data Texture surface data.
	 * @param [out] size Texture data size.
	 * @return True, if data were successfully read, false otherwise.
	 */
	virtual Bool											GetData( UInt element, UInt* width, UInt* height, UInt* depth, UInt* stride, UInt* sliceStride, img::PixelFormat* format, Byte** data, UInt* size ) = 0;

	/**
	 * Retrieves texture width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves texture height.
	 */
	virtual UInt											GetHeight() const = 0;

	/**
	 * Retrieves texture depth.
	 */
	virtual UInt											GetDepth() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IVOLUMERENDERTEXTURE_
