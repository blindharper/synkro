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
// Purpose: Defines depth-stencil texture.
//==============================================================================
#ifndef _SYNKRO_GFX_IDEPTHTEXTURE_
#define _SYNKRO_GFX_IDEPTHTEXTURE_


#include "config.h"
#include <gfx/IResource.h>
#include <gfx/DepthFormat.h>


namespace synkro
{


namespace gfx
{


/**
 * Depth-stencil texture.
 */
iface IDepthTexture :
	public IResource
{
public:
	/**
	 * Clears texture buffers with the default values.
	 */
	virtual void											Clear() = 0;

	/**
	 * Sets the value used to clear depth buffer.
	 * @param depth Depth value.
	 */
	virtual void											SetDefaultDepth( Float depth ) = 0;

	/**
	 * Sets the value used to clear stencil buffer.
	 * @param stencil Stencil value.
	 */
	virtual void											SetDefaultStencil( Byte stencil ) = 0;

	/**
	 * Retrieves depth value used to clear depth buffer.
	 */
	virtual Float											GetDefaultDepth() const = 0;

	/**
	 * Retrieves the value used to clear stencil buffer.
	 */
	virtual Byte											GetDefaultStencil() const = 0;

	/**
	 * Retrieves texture depth format.
	 */
	virtual DepthFormat										GetFormat() const = 0;

	/**
	 * Indicates whether the texture contains stencil data.
	 */
	virtual Bool											HasStencil() const = 0;

	/**
	 * Casts texture to plain depth texture.
	 * @return Non-null for plain depth texture, nullptr otherwise.
	 */
	virtual IPlainDepthTexture*								AsPlain() const = 0;

	/**
	 * Casts texture to cube depth texture.
	 * @return Non-null for cube depth texture, nullptr otherwise.
	 */
	virtual ICubeDepthTexture*								AsCube() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IDEPTHTEXTURE_
