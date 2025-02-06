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
SYNKRO_INLINE void SceneRenderObject::SetRenderable( IRenderView* view, Bool render )
{
	_views[view->ID()] = render;
}

SYNKRO_INLINE void SceneRenderObject::SetBlendStates( IBlendStateSet* states )
{
	if ( states != _blendStates )
	{
		_blendStates = states;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetDepthStencilState( IDepthStencilState* state )
{
	if ( state != _depthStencilState )
	{
		_depthStencilState = state;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetRasterizerState( IRasterizerState* state )
{
	if ( state != _rasterizerState )
	{
		_rasterizerState = state;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetVertexParameters( IParameterSet* params )
{
	if ( params != _vertexParams )
	{
		_vertexParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetVertexResources( IResourceSet* resources )
{
	if ( resources != _vertexResources )
	{
		_vertexResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetVertexSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _vertexSamplers )
	{
		_vertexSamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetHullParameters( IParameterSet* params )
{
	if ( params != _hullParams )
	{
		_hullParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetHullResources( IResourceSet* resources )
{
	if ( resources != _hullResources )
	{
		_hullResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetHullSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _hullSamplers )
	{
		_hullSamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetDomainParameters( IParameterSet* params )
{
	if ( params != _domainParams )
	{
		_domainParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetDomainResources( IResourceSet* resources )
{
	if ( resources != _domainResources )
	{
		_domainResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetDomainSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _domainSamplers )
	{
		_domainSamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetGeometryParameters( IParameterSet* params )
{
	if ( params != _geometryParams )
	{
		_geometryParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetGeometryResources( IResourceSet* resources )
{
	if ( resources != _geometryResources )
	{
		_geometryResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetGeometrySamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _geometrySamplers )
	{
		_geometrySamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetFragmentParameters( IParameterSet* params )
{
	if ( params != _fragmentParams )
	{
		_fragmentParams = params;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetFragmentResources( IResourceSet* resources )
{
	if ( resources != _fragmentResources )
	{
		_fragmentResources = resources;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetFragmentSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _fragmentSamplers )
	{
		_fragmentSamplers = samplers;
		_dirty = true;
	}
}

SYNKRO_INLINE void SceneRenderObject::SetBoundingVolume( IPrimitive* volume )
{
}

SYNKRO_INLINE void SceneRenderObject::SetOcclusionFunction( const CompareFunction& function )
{
}

SYNKRO_INLINE void SceneRenderObject::SetOcclusionPassValue( UInt value )
{
}

SYNKRO_INLINE Bool SceneRenderObject::IsRenderable( IRenderView* view ) const
{
	return _views.ContainsKey(view->ID()) ? _views[view->ID()] : true;
}

SYNKRO_INLINE IBlendStateSet* SceneRenderObject::GetBlendStates() const
{
	return _blendStates;
}

SYNKRO_INLINE IDepthStencilState* SceneRenderObject::GetDepthStencilState() const
{
	return _depthStencilState;
}

SYNKRO_INLINE IRasterizerState* SceneRenderObject::GetRasterizerState() const
{
	return _rasterizerState;
}

SYNKRO_INLINE IParameterSet* SceneRenderObject::GetVertexParameters() const
{
	return _vertexParams;
}

SYNKRO_INLINE IResourceSet* SceneRenderObject::GetVertexResources() const
{
	return _vertexResources;
}

SYNKRO_INLINE ISamplerStateSet* SceneRenderObject::GetVertexSamplers() const
{
	return _vertexSamplers;
}

SYNKRO_INLINE IParameterSet* SceneRenderObject::GetHullParameters() const
{
	return _hullParams;
}

SYNKRO_INLINE IResourceSet* SceneRenderObject::GetHullResources() const
{
	return _hullResources;
}

SYNKRO_INLINE ISamplerStateSet* SceneRenderObject::GetHullSamplers() const
{
	return _hullSamplers;
}

SYNKRO_INLINE IParameterSet* SceneRenderObject::GetDomainParameters() const
{
	return _domainParams;
}

SYNKRO_INLINE IResourceSet* SceneRenderObject::GetDomainResources() const
{
	return _domainResources;
}

SYNKRO_INLINE ISamplerStateSet* SceneRenderObject::GetDomainSamplers() const
{
	return _domainSamplers;
}

SYNKRO_INLINE IParameterSet* SceneRenderObject::GetGeometryParameters() const
{
	return _geometryParams;
}

SYNKRO_INLINE IResourceSet* SceneRenderObject::GetGeometryResources() const
{
	return _geometryResources;
}

SYNKRO_INLINE ISamplerStateSet* SceneRenderObject::GetGeometrySamplers() const
{
	return _geometrySamplers;
}

SYNKRO_INLINE IParameterSet* SceneRenderObject::GetFragmentParameters() const
{
	return _fragmentParams;
}

SYNKRO_INLINE IResourceSet* SceneRenderObject::GetFragmentResources() const
{
	return _fragmentResources;
}

SYNKRO_INLINE ISamplerStateSet* SceneRenderObject::GetFragmentSamplers() const
{
	return _fragmentSamplers;
}

SYNKRO_INLINE IPrimitive* SceneRenderObject::GetBoundingVolume() const
{
	return 0;
}

SYNKRO_INLINE CompareFunction SceneRenderObject::GetOcclusionFunction() const
{
	return 0;
}

SYNKRO_INLINE UInt SceneRenderObject::GetOcclusionPassValue() const
{
	return 0;
}

SYNKRO_INLINE UInt SceneRenderObject::GetStartElement() const
{
	return _startElement;
}

SYNKRO_INLINE UInt SceneRenderObject::GetElementCount() const
{
	return _elementCount;
}

SYNKRO_INLINE UInt SceneRenderObject::GetStartInstance() const
{
	return _startInstance;
}

SYNKRO_INLINE UInt SceneRenderObject::GetInstanceCount() const
{
	return _instanceCount;
}

SYNKRO_INLINE ISceneRenderQueue* SceneRenderObject::GetQueue() const
{
	return _queue;
}
