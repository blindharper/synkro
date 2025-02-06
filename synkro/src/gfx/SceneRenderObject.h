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
// Purpose: Scene rendering object implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_SCENERENDEROBJECT_
#define _SYNKRO_GFX_SCENERENDEROBJECT_


#include "config.h"
#include "RenderObjectImpl.h"
#include <gfx/ISceneRenderObject.h>
#include <gfx/IProgram.h>
#include <gfx/IProgramStage.h>
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


// Scene rendering object implementation.
class SceneRenderObject :
	public RenderObjectImpl<ISceneRenderObject>
{
public:
	// Constructor & destructor.
	SceneRenderObject( SceneRenderQueue* queue, IPrimitive* data );
	~SceneRenderObject();

	// ISceneRenderObject methods.
	void													SetRenderable( IRenderView* view, Bool render );
	void													SetBlendStates( IBlendStateSet* states );
	void													SetDepthStencilState( IDepthStencilState* state );
	void													SetRasterizerState( IRasterizerState* state );
	void													SetVertexParameters( IParameterSet* params );
	void													SetVertexResources( IResourceSet* resources );
	void													SetVertexSamplers( ISamplerStateSet* samplers );
	void													SetHullParameters( IParameterSet* params );
	void													SetHullResources( IResourceSet* resources );
	void													SetHullSamplers( ISamplerStateSet* samplers );
	void													SetDomainParameters( IParameterSet* params );
	void													SetDomainResources( IResourceSet* resources );
	void													SetDomainSamplers( ISamplerStateSet* samplers );
	void													SetGeometryParameters( IParameterSet* params );
	void													SetGeometryResources( IResourceSet* resources );
	void													SetGeometrySamplers( ISamplerStateSet* samplers );
	void													SetFragmentParameters( IParameterSet* params );
	void													SetFragmentResources( IResourceSet* resources );
	void													SetFragmentSamplers( ISamplerStateSet* samplers );
	void													SetBoundingVolume( IPrimitive* volume );
	void													SetOcclusionFunction( const CompareFunction& function );
	void													SetOcclusionPassValue( UInt value );
	void													SetElementRange( UInt start, UInt count );
	void													SetInstanceRange( UInt start, UInt count );
	Bool													IsRenderable( IRenderView* view ) const;
	IBlendStateSet*											GetBlendStates() const;
	IDepthStencilState*										GetDepthStencilState() const;
	IRasterizerState*										GetRasterizerState() const;
	IParameterSet*											GetVertexParameters() const;
	IResourceSet*											GetVertexResources() const;
	ISamplerStateSet*										GetVertexSamplers() const;
	IParameterSet*											GetHullParameters() const;
	IResourceSet*											GetHullResources() const;
	ISamplerStateSet*										GetHullSamplers() const;
	IParameterSet*											GetDomainParameters() const;
	IResourceSet*											GetDomainResources() const;
	ISamplerStateSet*										GetDomainSamplers() const;
	IParameterSet*											GetGeometryParameters() const;
	IResourceSet*											GetGeometryResources() const;
	ISamplerStateSet*										GetGeometrySamplers() const;
	IParameterSet*											GetFragmentParameters() const;
	IResourceSet*											GetFragmentResources() const;
	ISamplerStateSet*										GetFragmentSamplers() const;
	IPrimitive*												GetBoundingVolume() const;
	CompareFunction											GetOcclusionFunction() const;
	UInt													GetOcclusionPassValue() const;
	UInt													GetStartElement() const;
	UInt													GetElementCount() const;
	UInt													GetStartInstance() const;
	UInt													GetInstanceCount() const;
	ISceneRenderQueue*										GetQueue() const;

	lang::String											ResourceKey;
	lang::String											DataKey;
	lang::String											InstanceKey;

private:
	typedef lang::MapPair<UInt, Bool>						ViewEntry;

	lang::Map<UInt, Bool>									_views;
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


#include "SceneRenderObject.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_SCENERENDEROBJECT_
