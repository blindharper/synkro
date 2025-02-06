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
// Purpose: Defines scene rendering queue.
//==============================================================================
#include "config.h"
#include "SceneRenderQueue.h"
#include "SceneRenderObject.h"
#include "SkyboxRenderObject.h"
#include "SkysphereRenderObject.h"
#include "LineRenderQueue.h"
#include "Program.h"
#include "BlendStateSet.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include "SamplerState.h"
#include "SamplerStateSet.h"
#include "ResourceSet.h"
#include "ParameterSet.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IProgramStage.h>
#include <gfx/IIndexBuffer.h>
#include <gfx/IDataBufferSet.h>
#include <gfx/IRenderView.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


InstanceItem::InstanceItem( SceneRenderObject* object ) :
	Object( object ),
	StartElement( object->GetStartElement() ),
	ElementCount( object->GetElementCount() ),
	StartInstance( object->GetStartInstance() ),
	InstanceCount( object->GetInstanceCount() ),
	VertexParams( nullptr ),
	GeometryParams( nullptr ),
	FragmentParams( nullptr ),
	VertexSamplers( nullptr ),
	GeometrySamplers( nullptr ),
	FragmentSamplers( nullptr )
{
}

InstanceItem::InstanceItem() :
	Object( nullptr ),
	StartElement( 0 ),
	ElementCount( 0 ),
	StartInstance( 0 ),
	InstanceCount( 0 ),
	VertexParams( nullptr ),
	GeometryParams( nullptr ),
	FragmentParams( nullptr ),
	VertexSamplers( nullptr ),
	GeometrySamplers( nullptr ),
	FragmentSamplers( nullptr )
{
}

String InstanceItem::Key() const
{
	const UInt vp = (VertexParams != nullptr) ? VertexParams->ID() : 0;
	const UInt gp = (GeometryParams != nullptr) ? GeometryParams->ID() : 0;
	const UInt fp = (FragmentParams != nullptr) ? FragmentParams->ID() : 0;	
	const UInt vs = (VertexSamplers != nullptr) ? VertexSamplers->ID() : 0;
	const UInt gs = (GeometrySamplers != nullptr) ? GeometrySamplers->ID() : 0;
	const UInt fs = (FragmentSamplers != nullptr) ? FragmentSamplers->ID() : 0;
	return String::Format( L"{0}.{1}.{2}.{3}.{4}.{5}.{6}.{7}.{6}.{7}", vp, gp, fp, vs, gs, fs, StartElement, ElementCount, StartInstance, InstanceCount );
}

DataItem::DataItem( IPrimitive* data ) :
	Instances( A(InstanceEntry) ),
	Data( data ),
	Program( nullptr ),
	BlendStates( nullptr ),
	DepthStencilState( nullptr ),
	RasterizerState( nullptr )
{
}

DataItem::DataItem() :
	Instances( A(InstanceEntry) ),
	Data( nullptr ),
	Program( nullptr ),
	BlendStates( nullptr ),
	DepthStencilState( nullptr ),
	RasterizerState( nullptr )
{
}

String DataItem::Key() const
{
	return String::Format( L"{0}.{1}.{2}.{3}.{4}", Data->ID(), Program->ID(), BlendStates->ID(), DepthStencilState->ID(), RasterizerState->ID() );
}

ResourceItem::ResourceItem() :
	Buffers( A(BufferEntry) ),
	VertexResources( nullptr ),
	GeometryResources( nullptr ),
	FragmentResources( nullptr )
{
}

String ResourceItem::Key() const
{
	const UInt vr = (VertexResources != nullptr) ? VertexResources->ID() : 0;
	const UInt gr = (GeometryResources != nullptr) ? GeometryResources->ID() : 0;
	const UInt fr = (FragmentResources != nullptr) ? FragmentResources->ID() : 0;
	return String::Format( L"{0}.{1}.{2}", vr, gr, fr );
}

//------------------------------------------------------------------------------


SceneRenderQueue::SceneRenderQueue( IGraphicsSystemEx* graphicsSystem ) :
	_resources( A(ResourceEntry) ),
	_dirty( A(SceneRenderObject*) ),
	_lineQueue( new LineRenderQueue(graphicsSystem) ),
	_graphicsSystem( graphicsSystem ),
	_sky( nullptr )
{
	// Initialize shared stuff.
	_blendStates = (BlendStateSet*)_graphicsSystem->GetDevice()->GetBlendStates()->Clone();
	_depthStencilState = (DepthStencilState*)_graphicsSystem->GetDevice()->GetDepthStencilState()->Clone();	
	_rasterizerState = (RasterizerState*)_graphicsSystem->GetDevice()->GetRasterizerState()->Clone();
}

SceneRenderQueue::~SceneRenderQueue()
{
}

ISceneRenderObject* SceneRenderQueue::CreateObject( IPrimitive* data, Bool occluder )
{
	SceneRenderObject* obj = new SceneRenderObject( this, data );
	_dirty.Add( obj );
	return obj;
}

ISkyRenderObject* SceneRenderQueue::CreateSkysphereObject( Float radius )
{
	return _sky = new SkysphereRenderObject( _graphicsSystem, radius );
}

ISkyRenderObject* SceneRenderQueue::CreateSkyboxObject()
{
	return _sky = new SkyboxRenderObject( _graphicsSystem );
}

void SceneRenderQueue::RemoveObject( SceneRenderObject* object )
{
	if ( _resources.ContainsKey(object->ResourceKey) )
	{
		ResourceItem& res0 = _resources[object->ResourceKey];
		if ( res0.Buffers.ContainsKey(object->DataKey) )
		{
			DataItem& data0 = res0.Buffers[object->DataKey];
			if ( data0.Instances.ContainsKey(object->InstanceKey) )
			{
				data0.Instances.Remove( object->InstanceKey );
				if ( data0.Instances.Size() == 0 )
				{
					res0.Buffers.Remove( object->DataKey );
				}
				if ( res0.Buffers.Size() == 0 )
				{
					_resources.Remove( object->ResourceKey );
				}
			}
		}
	}
}

void SceneRenderQueue::Process( IRenderView* view, Bool overlay, const FillMode& fill, const PixelChannel& mask, IParameterSet* vertexParams, GraphicsStats& stats )
{
	SynkroProfile( "SceneRenderQueue.Process" );

	// Skip processing if the queue is disabled.
	if ( !_enabled )
		return;

	_data = nullptr; _program = nullptr;
	BlendStateSet* blendStates = nullptr; DepthStencilState* depthStencilState = nullptr; RasterizerState* rasterizerState = nullptr;
	_vertexParams = nullptr; _vertexResources = nullptr; _vertexSamplers = nullptr;
	_fragmentParams = nullptr; _fragmentResources = nullptr; _fragmentSamplers = nullptr;

	for ( UInt i = 0; i < _dirty.Size(); ++i )
	{
		SceneRenderObject* obj = _dirty[i];

		// Remove object from hierarchy.
		RemoveObject( obj );

		// Add object to hierarchy.
		ResourceItem res;
		if ( obj->GetVertexResources() != nullptr )
			res.VertexResources = (ResourceSet*)obj->GetVertexResources();
		else if ( obj->GetProgram() != nullptr )
			res.VertexResources = (ResourceSet*)obj->GetProgram()->GetVertexStage()->GetResources();
		else
			res.VertexResources = (ResourceSet*)obj->GetData()->GetProgram()->GetVertexStage()->GetResources();

		if ( obj->GetFragmentResources() != nullptr )
			res.FragmentResources = (ResourceSet*)obj->GetFragmentResources();
		else if ( obj->GetProgram() != nullptr )
			res.FragmentResources = (ResourceSet*)obj->GetProgram()->GetFragmentStage()->GetResources();
		else
			res.FragmentResources = (ResourceSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetResources();

		obj->ResourceKey = res.Key();
		if ( !_resources.ContainsKey(obj->ResourceKey) )
			_resources[obj->ResourceKey] = res;

		// Assemble data item.
		DataItem data( obj->GetData() );
		data.Program = (obj->GetProgram() != nullptr) ? (Program*)obj->GetProgram() : (Program*)obj->GetData()->GetProgram();
		data.BlendStates = (obj->GetBlendStates() != nullptr) ? (BlendStateSet*)obj->GetBlendStates() : _blendStates;
		data.DepthStencilState = (obj->GetDepthStencilState() != nullptr) ? (DepthStencilState*)obj->GetDepthStencilState() : _depthStencilState;
		data.RasterizerState = (obj->GetRasterizerState() != nullptr) ? (RasterizerState*)obj->GetRasterizerState() : _rasterizerState;
		data.OrgFillMode = data.RasterizerState->GetFillMode();

		obj->DataKey = data.Key();
		if ( !_resources[obj->ResourceKey].Buffers.ContainsKey(obj->DataKey) )
			_resources[obj->ResourceKey].Buffers[obj->DataKey] = data;

		// Assemble instance item.
		InstanceItem inst( obj );

		if ( obj->GetVertexParameters() != nullptr )
			inst.VertexParams = (ParameterSet*)obj->GetVertexParameters();
		else if ( obj->GetProgram() != nullptr )
			inst.VertexParams = (ParameterSet*)obj->GetProgram()->GetVertexStage()->GetParameters();
		else
			inst.VertexParams = (ParameterSet*)obj->GetData()->GetProgram()->GetVertexStage()->GetParameters();

		if ( obj->GetFragmentParameters() != nullptr )
			inst.FragmentParams = (ParameterSet*)obj->GetFragmentParameters();
		else if ( obj->GetProgram() != nullptr )
			inst.FragmentParams = (ParameterSet*)obj->GetProgram()->GetFragmentStage()->GetParameters();
		else
			inst.FragmentParams = (ParameterSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetParameters();

		if ( obj->GetVertexSamplers() != nullptr )
			inst.VertexSamplers = (SamplerStateSet*)obj->GetVertexSamplers();
		else if ( obj->GetProgram() != nullptr )
			inst.VertexSamplers = (SamplerStateSet*)obj->GetProgram()->GetVertexStage()->GetSamplers();
		else
			inst.VertexSamplers = (SamplerStateSet*)obj->GetData()->GetProgram()->GetVertexStage()->GetSamplers();

		if ( obj->GetFragmentSamplers() != nullptr )
			inst.FragmentSamplers = (SamplerStateSet*)obj->GetFragmentSamplers();
		else if ( obj->GetProgram() != nullptr )
			inst.FragmentSamplers = (SamplerStateSet*)obj->GetProgram()->GetFragmentStage()->GetSamplers();
		else
			inst.FragmentSamplers = (SamplerStateSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetSamplers();

		obj->InstanceKey = inst.Key();
		if ( !_resources[obj->ResourceKey].Buffers[obj->DataKey].Instances.ContainsKey(obj->InstanceKey) )
			_resources[obj->ResourceKey].Buffers[obj->DataKey].Instances[obj->InstanceKey] = inst;

		// Reset "dirty" flag.
		obj->ResetDirty();
	}
	_dirty.Clear();

	// Bind parent program parameters.
	if ( vertexParams != nullptr )
		vertexParams->Bind();

	// Draw the sky, if any.
	if ( _sky != nullptr )
	{
		_sky->GetProgram()->Bind();
		_sky->GetDepthStencilState()->Bind();
		_sky->GetRasterizerState()->Bind();
		_sky->GetFragmentResources()->Bind();
		_sky->GetFragmentSamplers()->Bind();
		_sky->GetData()->GetInputBuffers()->Bind();
		if ( _sky->GetData()->GetIndexBuffer() != nullptr )
			_sky->GetData()->GetIndexBuffer()->Bind();
		_sky->GetData()->Draw( 0, _sky->GetElementCount(), 0, 0 );
	}

	// Process the queue.
	MapIterator<String, ResourceItem> itRes = _resources.Begin();
	MapIterator<String, ResourceItem> itResEnd = _resources.End();
	for ( ; itRes != itResEnd ; ++itRes )
	{
		// Bind resources.
		if ( (_vertexResources != itRes.Value().VertexResources) /*|| _vertexResources->IsDirty()*/ )
		{
			_vertexResources = itRes.Value().VertexResources;
			_vertexResources->SetDirty();
			_vertexResources->Bind();
		}

		if ( (_fragmentResources != itRes.Value().FragmentResources) /*|| _fragmentResources->IsDirty()*/ )
		{
			_fragmentResources = itRes.Value().FragmentResources;
			_fragmentResources->SetDirty();
			_fragmentResources->Bind();
		}

		// Iterate through data.
		MapIterator<String, DataItem> itData = itRes.Value().Buffers.Begin();
		MapIterator<String, DataItem> itDataEnd = itRes.Value().Buffers.End();
		for ( ; itData != itDataEnd ; ++itData )
		{
			// Bind data buffers.
			if ( _data != itData.Value().Data )
			{
				_data = itData.Value().Data;
				_data->GetInputBuffers()->Bind();

				if ( _data->GetIndexBuffer() != nullptr )
					_data->GetIndexBuffer()->Bind();
			}

			// Bind program and states.
			if ( _program != itData.Value().Program )
			{
				_program = itData.Value().Program;
				_program->Bind();
			}

			if ( blendStates != itData.Value().BlendStates )
			{
				blendStates = itData.Value().BlendStates;
				blendStates->SetWriteChannels( mask );
				blendStates->Bind();
				stats.StateChangeCount += 1;
			}

			if ( depthStencilState != itData.Value().DepthStencilState )
			{
				depthStencilState = itData.Value().DepthStencilState;
				depthStencilState->Bind();
				stats.StateChangeCount += 1;
			}

			if ( rasterizerState != itData.Value().RasterizerState )
			{
				rasterizerState = itData.Value().RasterizerState;
				// Force solid objects in wireframe render view to become wireframe.
				if ( fill == FillMode::Wireframe )
				{
					rasterizerState->SetFillMode( FillMode::Wireframe );
				}
				else
				{
					rasterizerState->SetFillMode( itData.Value().OrgFillMode );
				}
				rasterizerState->Bind();
				stats.StateChangeCount += 1;
			}

			// Iterate through instances.
			MapIterator<String, InstanceItem> itInstance = itData.Value().Instances.Begin();
			MapIterator<String, InstanceItem> itInstanceEnd = itData.Value().Instances.End();
			for ( ; itInstance != itInstanceEnd ; ++itInstance )
			{
				ISceneRenderObject* obj = (ISceneRenderObject*)itInstance.Value().Object;

				// Skip disabled items.
				if ( !obj->IsEnabled() )
					continue;

				// Skip objects not renderable in this view.
				if ( !obj->IsRenderable(view) )
					continue;

				// Verify 'overlay' mode.
				const Bool draw = (overlay && view->IsOverlay(obj)) || (!overlay && !view->IsOverlay(obj));
				if ( !draw )
					continue;

				// Check if the instance data is dirty.
				if ( itInstance.Value().Object->IsDirty() )
				{
					itInstance.Value().Object->ResourceKey = itRes.Key();
					itInstance.Value().Object->DataKey = itData.Key();
					itInstance.Value().Object->InstanceKey = itInstance.Key();
					_dirty.Add( itInstance.Value().Object );
				}
				const InstanceItem& item = itInstance.Value();

				// Bind samplers.
				if ( _vertexSamplers != item.VertexSamplers )
				{
					_vertexSamplers = item.VertexSamplers;
					_vertexSamplers->Bind();
					stats.StateChangeCount += 1;
				}

				if ( _fragmentSamplers != item.FragmentSamplers )
				{
					_fragmentSamplers = item.FragmentSamplers;
					_fragmentSamplers->Bind();
					stats.StateChangeCount += 1;
				}

				// Bind parameters.
				if ( _vertexParams != item.VertexParams )
				{
					_vertexParams = item.VertexParams;
					_vertexParams->Bind();
				}

				if ( _fragmentParams != item.FragmentParams )
				{
					_fragmentParams = item.FragmentParams;
					_fragmentParams->Bind();
				}

				// Draw primitive.
				stats.PrimitiveCount += _data->Draw( item.StartElement, item.ElementCount, item.StartInstance, item.InstanceCount );
				stats.ObjectCount += (item.InstanceCount != 0) ? item.InstanceCount : 1;
			}
		}
	}
}


} // gfx


} // synkro
