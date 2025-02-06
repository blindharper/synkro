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
// Purpose: Defines linear texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ILINEARTEXTURE_
#define _SYNKRO_GFX_ILINEARTEXTURE_


#include "config.h"
#include <gfx/ITexture.h>


namespace synkro
{


namespace gfx
{


/**
 * Linear texture.
 */
iface ILinearTexture :
	public ITexture
{
public:
	/**
	 * Sets texture surface data.
	 * @param element Texture array element for which to set data.
	 * @param level Texture surface level.
	 * @param length Texture surface length.
	 * @param format Texture surface pixel format.
	 * @param data Texture surface data.
	 * @return True, if data were successfully updated, false otherwise.
	 */
	virtual Bool											SetData( UInt element, UInt level, UInt length, const img::PixelFormat& format, const Byte* data ) = 0;

	/**
	 * Writes data to the texture.
	 * @param data Data to write.
	 * @param size Data size.
	 */
	virtual void											Write( const Byte* data, UInt size ) = 0;

	/**
	 * Retrieves texture length.
	 */
	virtual UInt											GetLength() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ILINEARTEXTURE_
