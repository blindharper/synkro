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
// Purpose: Defines cube texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ICUBETEXTURE_
#define _SYNKRO_GFX_ICUBETEXTURE_


#include "config.h"
#include <gfx/ITexture.h>
#include <gfx/CubeFace.h>


namespace synkro
{


namespace gfx
{


/**
 * Cube texture.
 */
iface ICubeTexture :
	public ITexture
{
public:
	/**
	 * Sets texture surface data. Texture surface should be mapped for writing.
	 * @param face Texture face for which to set data.
	 * @param level Texture surface level.
	 * @param length Cube edge length.
	 * @param stride Texture surface stride.
	 * @param format Texture surface pixel format.
	 * @param data Texture surface data.
	 * @return True, if data were successfully updated, false otherwise.
	 */
	virtual Bool											SetData( const CubeFace& face, UInt level, UInt length, UInt stride, const img::PixelFormat& format, const Byte* data ) = 0;

	/**
	 * Retrieves texture edge length.
	 */
	virtual UInt											GetLength() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ICUBETEXTURE_
