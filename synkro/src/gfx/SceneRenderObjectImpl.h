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
// Purpose: Generic scene render object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SCENERENDEROBJECTIMPL_
#define _SYNKRO_GFX_SCENERENDEROBJECTIMPL_


#include "config.h"
#include "RenderObjectImpl.h"
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IRenderView.h>
#include <gfx/CompareFunction.h>
#include "SceneRenderQueue.h"


namespace synkro
{


namespace gfx
{


// Generic scene render object implementation.
template <class T>
class SceneRenderObjectImpl :
	public RenderObjectImpl<T>
{
public:
	// Constructor & destructor.
	SceneRenderObjectImpl( SceneRenderQueue* queue, IProgram* program );
	virtual ~SceneRenderObjectImpl();

	// IRenderObject methods.
	virtual IPrimitiveEx*									GetData( IRenderView* view ) const;

	// ISceneRenderObject methods.
	virtual void											SetRenderable( IRenderView* view, Bool render );
	virtual void											SetBlendStates( IBlendStateSet* states );
	virtual void											SetDepthStencilState( IDepthStencilState* state );
	virtual void											SetRasterizerState( IRasterizerState* state );
	virtual void											SetVertexParameters( IRenderView* view, IParameterSet* params );
	virtual void											SetVertexParameters( IParameterSet* params );
	virtual void											SetVertexResources( IResourceSet* resources );
	virtual void											SetVertexSamplers( ISamplerStateSet* samplers );
	virtual void											SetHullParameters( IParameterSet* params );
	virtual void											SetHullResources( IResourceSet* resources );
	virtual void											SetHullSamplers( ISamplerStateSet* samplers );
	virtual void											SetDomainParameters( IParameterSet* params );
	virtual void											SetDomainResources( IResourceSet* resources );
	virtual void											SetDomainSamplers( ISamplerStateSet* samplers );
	virtual void											SetGeometryParameters( IParameterSet* params );
	virtual void											SetGeometryResources( IResourceSet* resources );
	virtual void											SetGeometrySamplers( ISamplerStateSet* samplers );
	virtual void											SetFragmentParameters( IParameterSet* params );
	virtual void											SetFragmentResources( IResourceSet* resources );
	virtual void											SetFragmentSamplers( ISamplerStateSet* samplers );
	virtual void											SetBoundingVolume( IPrimitive* volume );
	virtual void											SetOcclusionFunction( const CompareFunction& function );
	virtual void											SetOcclusionPassValue( UInt value );
	virtual void											SetElementRange( UInt start, UInt count );
	virtual void											SetInstanceRange( UInt start, UInt count );
	virtual Bool											IsRenderable( IRenderView* view ) const;
	virtual IBlendStateSet*									GetBlendStates() const;
	virtual IDepthStencilState*								GetDepthStencilState() const;
	virtual IRasterizerState*								GetRasterizerState() const;
	virtual IParameterSet*									GetVertexParameters( IRenderView* view ) const;
	virtual IParameterSet*									GetVertexParameters() const;
	virtual IResourceSet*									GetVertexResources() const;
	virtual ISamplerStateSet*								GetVertexSamplers() const;
	virtual IParameterSet*									GetHullParameters() const;
	virtual IResourceSet*									GetHullResources() const;
	virtual ISamplerStateSet*								GetHullSamplers() const;
	virtual IParameterSet*									GetDomainParameters() const;
	virtual IResourceSet*									GetDomainResources() const;
	virtual ISamplerStateSet*								GetDomainSamplers() const;
	virtual IParameterSet*									GetGeometryParameters() const;
	virtual IResourceSet*									GetGeometryResources() const;
	virtual ISamplerStateSet*								GetGeometrySamplers() const;
	virtual IParameterSet*									GetFragmentParameters() const;
	virtual IResourceSet*									GetFragmentResources() const;
	virtual ISamplerStateSet*								GetFragmentSamplers() const;
	virtual IPrimitive*										GetBoundingVolume() const;
	virtual CompareFunction									GetOcclusionFunction() const;
	virtual UInt											GetOcclusionPassValue() const;
	virtual UInt											GetStartElement() const;
	virtual UInt											GetElementCount() const;
	virtual UInt											GetStartInstance() const;
	virtual UInt											GetInstanceCount() const;
	virtual ISceneRenderQueue*								GetQueue() const;
	virtual ISceneRenderObjectEx*							AsEx() const;

protected:
	struct ViewData
	{
		ViewData( Bool renderable ) :
			Renderable( renderable )
		{
		}

		ViewData() :
			Renderable( true )
		{
		}

		P(IParameterSet)	VertexParams;
		P(IPrimitiveEx)		Data;
		Bool				Renderable;
	};
	typedef lang::MapPair<UInt, ViewData>					ViewEntry;

	lang::Map<UInt, ViewData>								_views;
	SceneRenderQueue*										_queue;
	P(IBlendStateSet)										_blendStates;
	P(IDepthStencilState)									_depthStencilState;
	P(IRasterizerState)										_rasterizerState;
	P(IParameterSet)										_vertexParams;
	P(IResourceSet)											_vertexResources;
	P(ISamplerStateSet)										_vertexSamplers;
	P(IParameterSet)										_hullParams;
	P(IResourceSet)											_hullResources;
	P(ISamplerStateSet)										_hullSamplers;
	P(IParameterSet)										_domainParams;
	P(IResourceSet)											_domainResources;
	P(ISamplerStateSet)										_domainSamplers;
	P(IParameterSet)										_geometryParams;
	P(IResourceSet)											_geometryResources;
	P(ISamplerStateSet)										_geometrySamplers;
	P(IParameterSet)										_fragmentParams;
	P(IResourceSet)											_fragmentResources;
	P(ISamplerStateSet)										_fragmentSamplers;
	UInt													_startElement;
	UInt													_elementCount;
	UInt													_startInstance;
	UInt													_instanceCount;
};


#include "SceneRenderObjectImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SCENERENDEROBJECTIMPL_
