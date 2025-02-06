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
// Purpose: Defines plain rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IPLAINRENDERTEXTURE_
#define _SYNKRO_GFX_IPLAINRENDERTEXTURE_


#include "config.h"
#include <gfx/IRenderTexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Plain rendering texture.
 */
iface IPlainRenderTexture :
	public IRenderTexture
{
public:
	/**
	 * Unbinds depth texture so that it can be used as an input resource.
	 */
	virtual void											UnbindDepthTexture() = 0;

	/**
	 * Sets depth texture to be used for binding.
	 * @param texture Plain depth texture.
	 * @exception GrapthicsException Depth texture has incompatible dimensions.
	 */
	virtual void											SetDepthTexture( IPlainDepthTexture* texture ) = 0;

	/**
	 * Gets rendering texture surface data.
	 * @param [out] width Texture surface width.
	 * @param [out] height Texture surface height.
	 * @param [out] stride Texture surface stride.
	 * @param [out] format Texture surface pixel format.
	 * @param [out] data Texture surface data.
	 * @param [out] size Texture data size.
	 * @return True, if data were successfully read, false otherwise.
	 */
	virtual Bool											GetData( UInt* width, UInt* height, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size ) = 0;

	/**
	 * Retrieves depth texture to be used for binding.
	 * @return Plain depth texture.
	 */
	virtual IPlainDepthTexture*								GetDepthTexture() const = 0;

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


#endif // _SYNKRO_GFX_IPLAINRENDERTEXTURE_
