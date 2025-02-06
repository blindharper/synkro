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
// Purpose: Post-processing rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_POSTPROCESSRENDEROBJECT_
#define _SYNKRO_GFX_POSTPROCESSRENDEROBJECT_


#include "config.h"
#include "Classes.h"
#include "RenderObjectImpl.h"
#include <gfx/IRect.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/IPlainDepthTexture.h>
#include <gfx/IPostProcessRenderObject.h>


namespace synkro
{


namespace gfx
{


// PostProcess rendering object implementation.
class PostProcessRenderObject :
	public RenderObjectImpl<IPostProcessRenderObject>
{
public:
	// Constructor.
	PostProcessRenderObject( PostProcessRenderQueue* queue, IProgram* program, UInt order );

	// IPostProcessRenderObject methods.
	void													SetInput( IResource* input );
	void													SetTarget( IPlainRenderTexture* target );
	void													SetStencil( IPlainDepthTexture* stencil );
	void													SetScissorRect( IRect* rect );
	void													SetStencilState( IDepthStencilState* state );
	void													SetFragmentParameters( IParameterSet* params );
	void													SetFragmentResources( IResourceSet* resources );
	void													SetFragmentSamplers( ISamplerStateSet* samplers );
	void													SetPassCount( UInt count );
	void													SetOrder( UInt order );
	IResource*												GetInput() const;
	IPlainRenderTexture*									GetTarget() const;
	IPlainDepthTexture*										GetStencil() const;
	IRect*													GetScissorRect() const;
	IDepthStencilState*										GetStencilState() const;
	IParameterSet*											GetFragmentParameters() const;
	IResourceSet*											GetFragmentResources() const;
	ISamplerStateSet*										GetFragmentSamplers() const;
	UInt													GetPassCount() const;
	UInt													GetOrder() const;

private:
	PostProcessRenderQueue*									_queue;
	P(IResource)											_input;
	P(IPlainRenderTexture)									_target;
	P(IPlainDepthTexture)									_stencil;
	P(IRect)												_scissorRect;
	P(IDepthStencilState)									_stencilState;
	P(IParameterSet)										_fragmentParams;
	P(IResourceSet)											_fragmentResources;
	P(ISamplerStateSet)										_fragmentSamplers;
	UInt													_passCount;
	UInt													_order;
};


#include "PostProcessRenderObject.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_POSTPROCESSRENDEROBJECT_
