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
template <class T>
SYNKRO_INLINE SceneRenderObjectImpl<T>::SceneRenderObjectImpl( SceneRenderQueue* queue, IProgram* program ) :
	RenderObjectImpl<T>( program ),
	_views( A(ViewEntry) ),
	_queue( queue ),
	_startElement( 0 ),
	_elementCount( 0 ),
	_startInstance( 0 ),
	_instanceCount( 0 )
{
}

template <class T>
SYNKRO_INLINE SceneRenderObjectImpl<T>::~SceneRenderObjectImpl()
{
}

template <class T>
SYNKRO_INLINE IPrimitiveEx* SceneRenderObjectImpl<T>::GetData( IRenderView* view ) const
{
	IPrimitiveEx* data = _views.ContainsKey(view->ID()) ? _views[view->ID()].Data : nullptr;
	return (data != nullptr) ? data : _data;
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetRenderable( IRenderView* view, Bool render )
{
	if ( !_views.ContainsKey(view->ID()) )
	{
		_views[view->ID()] = ViewData( render );
	}
	_views[view->ID()].Renderable = render;
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetBlendStates( IBlendStateSet* states )
{
	if ( states != _blendStates )
	{
		_blendStates = states;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetDepthStencilState( IDepthStencilState* state )
{
	if ( state != _depthStencilState )
	{
		_depthStencilState = state;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetRasterizerState( IRasterizerState* state )
{
	if ( state != _rasterizerState )
	{
		_rasterizerState = state;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetVertexParameters( IRenderView* view, IParameterSet* params )
{
	if ( !_views.ContainsKey(view->ID()) )
	{
		_views[view->ID()] = ViewData();
	}
	_views[view->ID()].VertexParams = params;
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetVertexParameters( IParameterSet* params )
{
	if ( params != _vertexParams )
	{
		_vertexParams = params;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetVertexResources( IResourceSet* resources )
{
	if ( resources != _vertexResources )
	{
		_vertexResources = resources;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetVertexSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _vertexSamplers )
	{
		_vertexSamplers = samplers;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetHullParameters( IParameterSet* params )
{
	if ( params != _hullParams )
	{
		_hullParams = params;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetHullResources( IResourceSet* resources )
{
	if ( resources != _hullResources )
	{
		_hullResources = resources;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetHullSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _hullSamplers )
	{
		_hullSamplers = samplers;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetDomainParameters( IParameterSet* params )
{
	if ( params != _domainParams )
	{
		_domainParams = params;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetDomainResources( IResourceSet* resources )
{
	if ( resources != _domainResources )
	{
		_domainResources = resources;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetDomainSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _domainSamplers )
	{
		_domainSamplers = samplers;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetGeometryParameters( IParameterSet* params )
{
	if ( params != _geometryParams )
	{
		_geometryParams = params;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetGeometryResources( IResourceSet* resources )
{
	if ( resources != _geometryResources )
	{
		_geometryResources = resources;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetGeometrySamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _geometrySamplers )
	{
		_geometrySamplers = samplers;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetFragmentParameters( IParameterSet* params )
{
	if ( params != _fragmentParams )
	{
		_fragmentParams = params;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetFragmentResources( IResourceSet* resources )
{
	if ( resources != _fragmentResources )
	{
		_fragmentResources = resources;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetFragmentSamplers( ISamplerStateSet* samplers )
{
	if ( samplers != _fragmentSamplers )
	{
		_fragmentSamplers = samplers;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetBoundingVolume( IPrimitive* volume )
{
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetOcclusionFunction( const CompareFunction& function )
{
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetOcclusionPassValue( UInt value )
{
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetElementRange( UInt start, UInt count )
{
	if ( (start != _startElement) || (count != _elementCount) )
	{
		UInt maxElementCount = (_data->GetIndexCount() > 0) ? _data->GetIndexCount() : _data->GetVertexCount();
		assert( start+count <= maxElementCount );

		if ( start+count > maxElementCount )
			throw lang::BadArgumentException( core::Str::InvalidArgument, L"start+count" );

		_startElement = start;
		_elementCount = count;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SceneRenderObjectImpl<T>::SetInstanceRange( UInt start, UInt count )
{
	if ( (start != _startInstance) || (count != _instanceCount) )
	{
		assert( start+count <= _data->GetInstanceCount() );

		if ( start+count > _data->GetInstanceCount() )
			throw lang::BadArgumentException( core::Str::InvalidArgument, L"start+count" );

		_startInstance = start;
		_instanceCount = count;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE Bool SceneRenderObjectImpl<T>::IsRenderable( IRenderView* view ) const
{
	return _views.ContainsKey(view->ID()) ? _views[view->ID()].Renderable : true;
}

template <class T>
SYNKRO_INLINE IBlendStateSet* SceneRenderObjectImpl<T>::GetBlendStates() const
{
	return _blendStates;
}

template <class T>
SYNKRO_INLINE IDepthStencilState* SceneRenderObjectImpl<T>::GetDepthStencilState() const
{
	return _depthStencilState;
}

template <class T>
SYNKRO_INLINE IRasterizerState* SceneRenderObjectImpl<T>::GetRasterizerState() const
{
	return _rasterizerState;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetVertexParameters( IRenderView* view ) const
{
	IParameterSet* vertexParams = _views.ContainsKey(view->ID()) ? _views[view->ID()].VertexParams : nullptr;
	return (vertexParams != nullptr) ? vertexParams : _vertexParams;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetVertexParameters() const
{
	return _vertexParams;
}

template <class T>
SYNKRO_INLINE IResourceSet* SceneRenderObjectImpl<T>::GetVertexResources() const
{
	return _vertexResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SceneRenderObjectImpl<T>::GetVertexSamplers() const
{
	return _vertexSamplers;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetHullParameters() const
{
	return _hullParams;
}

template <class T>
SYNKRO_INLINE IResourceSet* SceneRenderObjectImpl<T>::GetHullResources() const
{
	return _hullResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SceneRenderObjectImpl<T>::GetHullSamplers() const
{
	return _hullSamplers;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetDomainParameters() const
{
	return _domainParams;
}

template <class T>
SYNKRO_INLINE IResourceSet* SceneRenderObjectImpl<T>::GetDomainResources() const
{
	return _domainResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SceneRenderObjectImpl<T>::GetDomainSamplers() const
{
	return _domainSamplers;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetGeometryParameters() const
{
	return _geometryParams;
}

template <class T>
SYNKRO_INLINE IResourceSet* SceneRenderObjectImpl<T>::GetGeometryResources() const
{
	return _geometryResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SceneRenderObjectImpl<T>::GetGeometrySamplers() const
{
	return _geometrySamplers;
}

template <class T>
SYNKRO_INLINE IParameterSet* SceneRenderObjectImpl<T>::GetFragmentParameters() const
{
	return _fragmentParams;
}

template <class T>
SYNKRO_INLINE IResourceSet* SceneRenderObjectImpl<T>::GetFragmentResources() const
{
	return _fragmentResources;
}

template <class T>
SYNKRO_INLINE ISamplerStateSet* SceneRenderObjectImpl<T>::GetFragmentSamplers() const
{
	return _fragmentSamplers;
}

template <class T>
SYNKRO_INLINE IPrimitive* SceneRenderObjectImpl<T>::GetBoundingVolume() const
{
	return 0;
}

template <class T>
SYNKRO_INLINE CompareFunction SceneRenderObjectImpl<T>::GetOcclusionFunction() const
{
	return 0;
}

template <class T>
SYNKRO_INLINE UInt SceneRenderObjectImpl<T>::GetOcclusionPassValue() const
{
	return 0;
}

template <class T>
SYNKRO_INLINE UInt SceneRenderObjectImpl<T>::GetStartElement() const
{
	return _startElement;
}

template <class T>
SYNKRO_INLINE UInt SceneRenderObjectImpl<T>::GetElementCount() const
{
	return _elementCount;
}

template <class T>
SYNKRO_INLINE UInt SceneRenderObjectImpl<T>::GetStartInstance() const
{
	return _startInstance;
}

template <class T>
SYNKRO_INLINE UInt SceneRenderObjectImpl<T>::GetInstanceCount() const
{
	return _instanceCount;
}

template <class T>
SYNKRO_INLINE ISceneRenderQueue* SceneRenderObjectImpl<T>::GetQueue() const
{
	return _queue;
}

template <class T>
SYNKRO_INLINE ISceneRenderObjectEx* SceneRenderObjectImpl<T>::AsEx() const
{
	return nullptr;
}
