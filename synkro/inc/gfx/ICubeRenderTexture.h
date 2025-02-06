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
// Purpose: Defines cube rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ICUBERENDERTEXTURE_
#define _SYNKRO_GFX_ICUBERENDERTEXTURE_


#include "config.h"
#include <gfx/IRenderTexture.h>
#include <gfx/CubeFace.h>


namespace synkro
{


namespace gfx
{


/**
 * Cube rendering texture.
 */
iface ICubeRenderTexture :
	public IRenderTexture
{
public:
	/**
	 * Binds a particular texture face to the pipeline.
	 * @param face Cube face to bind.
	 * @return True, if the texture face has been successfully bound, false otherwise.
	 */
	virtual Bool											BindFace( const CubeFace& face ) = 0;

	/**
	 * Gets rendering texture surface data.
	 * @param face Cube face to get data from.
	 * @param [out] length Texture surface edge length.
	 * @param [out] stride Texture surface stride.
	 * @param [out] format Texture surface pixel format.
	 * @param [out] data Texture surface data.
	 * @param [out] size Texture data size.
	 * @return True, if data were successfully read, false otherwise.
	 */
	virtual Bool											GetData( const CubeFace& face, UInt* length, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size ) = 0;

	/**
	 * Retrieves texture edge length.
	 */
	virtual UInt											GetLength() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ICUBERENDERTEXTURE_
