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
// Purpose: Defines volume texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IVOLUMETEXTURE_
#define _SYNKRO_GFX_IVOLUMETEXTURE_


#include "config.h"
#include <gfx/ITexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Volume texture.
 */
iface IVolumeTexture :
	public ITexture
{
public:
	/**
	 * Sets texture data.
	 * @param element Texture array element for which to set data.
	 * @param level Texture surface level.
	 * @param width Texture surface width.
	 * @param height Texture surface height.
	 * @param stride Texture surface stride.
	 * @param sliceStride Texture slice stride.
	 * @param format Texture surface pixel format.
	 * @param data Texture surface data.
	 * @return True, if data were successfully updated, false otherwise.
	 */
	virtual Bool											SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, UInt sliceStride, const img::PixelFormat& format, const Byte* data ) = 0;

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


#endif // _SYNKRO_GFX_IVOLUMETEXTURE_
