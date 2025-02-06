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
// Purpose: Defines sky rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_ISKYRENDEROBJECT_
#define _SYNKRO_GFX_ISKYRENDEROBJECT_


#include "config.h"
#include <gfx/IRenderObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Sky rendering object.
 */
iface ISkyRenderObject :
	public IRenderObject
{
public:
	/**
	 * Sets resources for program's fragment stage.
	 */
	virtual void											SetFragmentResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's fragment stage.
	 */
	virtual void											SetFragmentSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Retrieves depth-stencil state used to render the object.
	 */
	virtual IDepthStencilState*								GetDepthStencilState() const = 0;

	/**
	 * Retrieves rasterizer state used to render the object.
	 */
	virtual IRasterizerState*								GetRasterizerState() const = 0;

	/**
	 * Retrieves resources for program's fragment stage.
	 */
	virtual IResourceSet*									GetFragmentResources() const = 0;

	/**
	 * Retrieves sampler states for program's fragment stage.
	 */
	virtual ISamplerStateSet*								GetFragmentSamplers() const = 0;

	/**
	 * Retrieves the number of elements to render.
	 */
	virtual UInt											GetElementCount() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ISKYRENDEROBJECT_
