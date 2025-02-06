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
// Purpose: Defines abstract resource.
//==============================================================================
#ifndef _SYNKRO_GFX_IRESOURCE_
#define _SYNKRO_GFX_IRESOURCE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract resource.
 */
iface IResource :
	public core::IObject
{
public:
	/**
	 * Casts resource to buffer.
	 * @return Non-null for buffer resource, nullptr otherwise.
	 */
	virtual IBuffer*										AsBuffer() const = 0;

	/**
	 * Casts resource to texture.
	 * @return Non-null for texture resource, nullptr otherwise.
	 */
	virtual ITexture*										AsTexture() const = 0;

	/**
	 * Casts resource to rendering texture.
	 * @return Non-null for rendering texture resource, nullptr otherwise.
	 */
	virtual IRenderTexture*									AsRenderTexture() const = 0;

	/**
	 * Casts resource to depth-stencil texture.
	 * @return Non-null for depth-stencil texture resource, nullptr otherwise.
	 */
	virtual IDepthTexture*									AsDepthTexture() const = 0;	
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRESOURCE_
