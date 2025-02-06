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
// Purpose: Defines base rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERTEXTURE_
#define _SYNKRO_GFX_IRENDERTEXTURE_


#include "config.h"
#include <gfx/IResource.h>
#include <img/PixelFormat.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


/**
 * Base rendering texture.
 */
iface IRenderTexture :
	public IResource
{
public:
	/**
	 * Binds texture to the pipeline as a rendering target.
	 * @return True, if the texture has been successfully bound, false otherwise.
	 */
	virtual Bool											Bind() = 0;

	/**
	 * Clears texture with the default color.
	 */
	virtual void											Clear() = 0;

	/**
	 * Presents results of the rendering to the texture.
	 * @return True, if succeded, false otherwise.
	 */
	virtual Bool											Present() = 0;

	/**
	 * Sets color used to clear texture's color buffer.
	 * @param color Default color value.
	 */
	virtual void											SetDefaultColor( const math::Vector4& color ) = 0;

	/**
	 * Retrieves color used to clear texture's color buffer.
	 * @param [out] color Default color value.
	 */
	virtual void											GetDefaultColor( math::Vector4& color ) const = 0;

	/**
	 * Retrieves texture pixel format.
	 */
	virtual img::PixelFormat								GetFormat() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERTEXTURE_
