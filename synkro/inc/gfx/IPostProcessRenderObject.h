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
// Purpose: Defines post-processing rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_IPOSTPROCESSRENDEROBJECT_
#define _SYNKRO_GFX_IPOSTPROCESSRENDEROBJECT_


#include "config.h"
#include <gfx/IRenderObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Post-processing effect.
 */
iface IPostProcessRenderObject :
	public IRenderObject
{
public:
	/**
	 * Sets custom input resource for the post-processing.
	 * @param input Post-processing input resource. If set to null, the output of the previous post-processor is used.
	 */
	virtual void											SetInput( IResource* input ) = 0;

	/**
	 * Sets custom rendering target for the object.
	 * @param target Target to keep rendering results.
	 * @exception InvalidOperationException Target is already used with another object.
	 */
	virtual void											SetTarget( IPlainRenderTexture* target ) = 0;

	/**
	 * Sets stencil for the object.
	 * @param stencil Stencil to used to get the effect.
	 * @exception InvalidOperationException Stencil has invalid format.
	 */
	virtual void											SetStencil( IPlainDepthTexture* stencil ) = 0;

	/**
	 * Sets scissor rectangle used to render the effect. The rectangle is specified in the owner window's coordinates.
	 */
	virtual void											SetScissorRect( IRect* rect ) = 0;

	/**
	 * Sets stencil state used to render the effect.
	 */
	virtual void											SetStencilState( IDepthStencilState* state ) = 0;

	/**
	 * Sets parameters for program's fragment stage.
	 */
	virtual void											SetFragmentParameters( IParameterSet* params ) = 0;

	/**
	 * Sets resources for program's fragment stage.
	 */
	virtual void											SetFragmentResources( IResourceSet* resources ) = 0;

	/**
	 * Sets sampler states for program's fragment stage.
	 */
	virtual void											SetFragmentSamplers( ISamplerStateSet* samplers ) = 0;

	/**
	 * Sets the number of times to render the object.
	 */
	virtual void											SetPassCount( UInt count ) = 0;

	/**
	 * Sets object's order in the processing chain.
	 */
	virtual void											SetOrder( UInt order ) = 0;

	/**
	 * Retrieves custom input resource for the post-processing.
	 */
	virtual IResource*										GetInput() const = 0;

	/**
	 * Retrieves custom rendering target for the object.
	 */
	virtual IPlainRenderTexture*							GetTarget() const = 0;

	/**
	 * Retrieves stencil for the object.
	 */
	virtual IPlainDepthTexture*								GetStencil() const = 0;

	/**
	 * Retrieves scissor rectangle used to render the effect.
	 */
	virtual IRect*											GetScissorRect() const = 0;

	/**
	 * Retrieves stencil state used to render the effect.
	 */
	virtual IDepthStencilState*								GetStencilState() const = 0;

	/**
	 * Retrieves parameters for program's fragment stage.
	 */
	virtual IParameterSet*									GetFragmentParameters() const = 0;

	/**
	 * Retrieves resources for program's fragment stage.
	 */
	virtual IResourceSet*									GetFragmentResources() const = 0;

	/**
	 * Retrieves sampler states for program's fragment stage.
	 */
	virtual ISamplerStateSet*								GetFragmentSamplers() const = 0;

	/**
	 * Retrieves the number of times the object is rendered.
	 */
	virtual UInt											GetPassCount() const = 0;

	/**
	 * Retrieves object's order in the processing chain.
	 */
	virtual UInt											GetOrder() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IPOSTPROCESSRENDEROBJECT_
