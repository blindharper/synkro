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
// Purpose: Defines rendering texture set.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERTEXTURESET_
#define _SYNKRO_GFX_IRENDERTEXTURESET_


#include "config.h"
#include <core/IObject.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


/**
 * Rendering texture collection. Used as rendering targets.
 */
iface IRenderTextureSet :
	public core::IObject
{
public:
	/**
	 * Binds textures to the pipeline.
	 * @return True, if the textures has been successfully bound, false otherwise.
	 */
	virtual Bool											Bind() = 0;

	/**
	 * Clears all the textures with the default color.
	 */
	virtual void											Clear() = 0;

	/**
	 * Presents results of the rendering to the textures.
	 * @return True, if succeded, false otherwise.
	 */
	virtual Bool											Present() = 0;

	/**
	 * Sets texture at the given index.
	 * @param index Texture index.
	 * @param texture Texture to set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											Set( UInt index, IRenderTexture* texture ) = 0;

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
	 * Retrieves the total number of textures in the set.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves texture by index.
	 * @param index Texture index.
	 * @return Requested texture.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IRenderTexture*									Get( UInt index ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERTEXTURESET_
