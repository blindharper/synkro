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
// Purpose: Generic sky object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SKYRENDEROBJECTIMPL_
#define _SYNKRO_GFX_SKYRENDEROBJECTIMPL_


#include "config.h"
#include "RenderObjectImpl.h"
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>


namespace synkro
{


namespace gfx
{


// Generic sky object implementation.
template <class T>
class SkyRenderObjectImpl :
	public RenderObjectImpl<T>
{
public:
	// Constructor & destructor.
	SkyRenderObjectImpl( IGraphicsSystemEx* graphicsSystem, IProgram* program );
	virtual ~SkyRenderObjectImpl();

	// ISkyRenderObject methods.
	virtual void											SetFragmentResources( IResourceSet* resources );
	virtual void											SetFragmentSamplers( ISamplerStateSet* samplers );
	virtual IDepthStencilState*								GetDepthStencilState() const;
	virtual IRasterizerState*								GetRasterizerState() const;
	virtual IResourceSet*									GetFragmentResources() const;
	virtual ISamplerStateSet*								GetFragmentSamplers() const;
	virtual UInt											GetElementCount() const;

protected:
	P(IDepthStencilState)									_depthStencilState;
	P(IRasterizerState)										_rasterizerState;
	P(IResourceSet)											_fragmentResources;
	P(ISamplerStateSet)										_fragmentSamplers;
	UInt													_elementCount;
};


#include "SkyRenderObjectImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SKYRENDEROBJECTIMPL_
