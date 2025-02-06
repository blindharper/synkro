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
// Purpose: Defines base texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ITEXTURE_
#define _SYNKRO_GFX_ITEXTURE_


#include "config.h"
#include <gfx/IResource.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace gfx
{


/**
 * Base texture resource.
 */
iface ITexture :
	public IResource
{
public:
	/**
	 * Makes texture generate all texture levels.
	 * For this method to work, there must be valid data at level 0.
	 */
	virtual void											GenerateLevels() = 0;

	/**
	 * Retrieves the total number of elements in the texture array.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves the total number of texture levels.
	 * This may differ from level count requested when the texture is created.
	 */
	virtual UInt											GetLevelCount() const = 0;

	/**
	 * Retrieves texture pixel format.
	 */
	virtual img::PixelFormat								GetFormat() const = 0;

	/**
	 * Casts texture to linear texture.
	 * @return Non-null for linear texture, nullptr otherwise.
	 */
	virtual ILinearTexture*									AsLinear() const = 0;

	/**
	 * Casts texture to plain texture.
	 * @return Non-null for plain texture, nullptr otherwise.
	 */
	virtual IPlainTexture*									AsPlain() const = 0;

	/**
	 * Casts texture to cube texture.
	 * @return Non-null for cube texture, nullptr otherwise.
	 */
	virtual ICubeTexture*									AsCube() const = 0;

	/**
	 * Casts texture to volume texture.
	 * @return Non-null for volume texture, nullptr otherwise.
	 */
	virtual IVolumeTexture*									AsVolume() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ITEXTURE_
