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
// Purpose: Overlay rendering queue implementation.
//==============================================================================
#include "config.h"
#include "OverlayRenderQueue.h"
#include "OverlayRenderObject.h"
#include "Primitive.h"
#include "Program.h"
#include "SamplerState.h"
#include "SamplerStateSet.h"
#include "ResourceSet.h"
#include "ParameterSet.h"
#include <gfx/IGraphicsDevice.h>
#include <gfx/IRenderWindow.h>
#include <gfx/IProgramStage.h>
#include <gfx/IIndexBuffer.h>
#include <gfx/IDataBufferSet.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


OverlayRenderItem::OverlayRenderItem( OverlayRenderObject* object ) :
	Object( object ),
	Program( nullptr ),
	Data( (Primitive*)object->GetData() ),
	BlendStates( nullptr ),
	RasterizerState( nullptr ),
	VertexParams( nullptr ),
	FragmentParams( nullptr ),
	FragmentResources( nullptr ),
	FragmentSamplers( nullptr ),
	ElementCount( 0 )
{
}

OverlayRenderItem::OverlayRenderItem() :
	Object( nullptr ),
	Program( nullptr ),
	Data( nullptr ),
	ScissorRect( nullptr ),
	BlendStates( nullptr ),
	RasterizerState( nullptr ),
	VertexParams( nullptr ),
	FragmentParams( nullptr ),
	FragmentResources( nullptr ),
	FragmentSamplers( nullptr ),
	ElementCount( 0 )
{
}

Bool OverlayRenderItem::operator<( const OverlayRenderItem& other ) const
{
	return this->Object->GetOrder() > other.Object->GetOrder();
}


//------------------------------------------------------------------------------


OverlayRenderQueue::OverlayRenderQueue( IGraphicsDevice* device, UInt width, UInt height ) :
	_items( A(OverlayRenderItem) ),
	_window( nullptr ),
	_ndc( nullptr, width, height ),
	_dirty( true )
{
	Init( device );
}

OverlayRenderQueue::OverlayRenderQueue( IGraphicsDevice* device, IRenderWindow* window ) :
	_items( A(OverlayRenderItem) ),
	_window( window ),
	_ndc( window, window->GetWidth(), window->GetHeight() ),
	_dirty( true )
{
	Init( device );
}

IOverlayRenderObject* OverlayRenderQueue::CreateObject( IPrimitive* data )
{
	OverlayRenderObject* object = new OverlayRenderObject( this, data, &_ndc );
	_items.Add( OverlayRenderItem(object) );
	return object;
}

void OverlayRenderQueue::RemoveObject( OverlayRenderObject* object )
{
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		if ( _items[i].Object == object )
		{
			_items.Remove( i );
			break;
		}
	}
}

void OverlayRenderQueue::Update()
{
	_ndc.Update();
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		_items[i].Data->Update();
	}
}

UInt OverlayRenderQueue::Process()
{
	SynkroProfile( "OverlayRenderQueue.Process" );

	Primitive* data = nullptr; Program* program = nullptr; BlendStateSet* blendStates = nullptr; RasterizerState* rasterizerState = nullptr;
	ParameterSet* vertexParams = nullptr; ParameterSet* fragmentParams = nullptr; ResourceSet* fragmentResources = nullptr; SamplerStateSet* fragmentSamplers = nullptr;
	UInt primitiveCount = 0;

	// Re-sort "_items" by z-order.
	if ( _dirty )
	{
		_items.Sort();
		_dirty = false;
	}

	// Bind shared stuff.
	_depthStencilState->Bind();

	// Process items.
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		// Skip disabled items.
		if ( !_items[i].Object->IsEnabled() )
			continue;

		// Validate item if needed.
		if ( _items[i].Object->IsDirty() )
		{
			ValidateItem( _items[i] );
			_items[i].Object->ResetDirty();
		}

		// Bind input buffer.
		if ( data != _items[i].Data )
		{
			data = _items[i].Data;
			_items[i].Data->GetInputBuffers()->Bind();
			if ( _items[i].Data->GetIndexBuffer() != nullptr )
				_items[i].Data->GetIndexBuffer()->Bind();
		}

		// Bind program.
		if ( program != _items[i].Program )
		{
			program = _items[i].Program;
			program->Bind();
		}

		// Bind states.
		if ( blendStates != _items[i].BlendStates )
		{
			blendStates = _items[i].BlendStates;
			blendStates->Bind();
		}

		if ( rasterizerState != _items[i].RasterizerState )
		{
			rasterizerState = _items[i].RasterizerState;
			rasterizerState->Bind();
		}

		// Bind scissor rectangle.
		if ( _items[i].ScissorRect != nullptr )
		{
			_items[i].ScissorRect->Bind();
		}

		// Bind vertex stage stuff.
		if ( vertexParams != _items[i].VertexParams )
		{
			vertexParams = _items[i].VertexParams;
			vertexParams->Bind();
		}

		// Bind fragment stage stuff.
		if ( fragmentParams != _items[i].FragmentParams )
		{
			fragmentParams = _items[i].FragmentParams;
			fragmentParams->Bind();
		}
		
		if ( (fragmentResources != _items[i].FragmentResources) || fragmentResources->IsDirty() )
		{
			fragmentResources = _items[i].FragmentResources;
			//fragmentResources->SetDirty(); // NB: This causes memory corruption! (since it's empty???)
			fragmentResources->Bind();
		}

		if ( fragmentSamplers != _items[i].FragmentSamplers )
		{
			fragmentSamplers = _items[i].FragmentSamplers;
			fragmentSamplers->Bind();
		}

		// Perform drawing.
		primitiveCount += data->Draw( 0, _items[i].ElementCount, 0, 0 );
	}

	return primitiveCount;
}

void OverlayRenderQueue::Init( IGraphicsDevice* device )
{
	// Initialize shared stuff.
	_blendStates = (BlendStateSet*)device->GetBlendStates()->Clone();
	_blendStates->Enable( false );
	
	_depthStencilState = (DepthStencilState*)device->GetDepthStencilState()->Clone();
	_depthStencilState->EnableDepth( false );
	_depthStencilState->EnableStencil( false );
	
	_rasterizerState = (RasterizerState*)device->GetRasterizerState()->Clone();
	_rasterizerState->SetFillMode( FillMode::Solid );
	_rasterizerState->SetCullMode( CullMode::None );
	_rasterizerState->EnableScissor( false );

	_rasterizerStateScissor = (RasterizerState*)device->GetRasterizerState()->Clone();
	_rasterizerStateScissor->SetFillMode( FillMode::Solid );
	_rasterizerStateScissor->SetCullMode( CullMode::None );
	_rasterizerStateScissor->EnableScissor( true );
}

void OverlayRenderQueue::ValidateItem( OverlayRenderItem& item )
{
	OverlayRenderObject* obj = item.Object;

	// Validate program.
	item.Program = (obj->GetProgram() != nullptr) ? (Program*)obj->GetProgram() : (Program*)obj->GetData()->GetProgram();

	// Validate scissor rectangle.
	item.ScissorRect = (RectEx*)obj->GetScissorRect();

	// Validate states.
	item.BlendStates = (obj->GetBlendStates() != nullptr) ? (BlendStateSet*)obj->GetBlendStates() : _blendStates;
	item.RasterizerState = (item.ScissorRect != nullptr) ? _rasterizerStateScissor : _rasterizerState;

	// Validate vertex stage inputs.
	if ( obj->GetVertexParameters() != nullptr )
		item.VertexParams = (ParameterSet*)obj->GetVertexParameters();
	else if ( obj->GetProgram() != nullptr )
		item.VertexParams = (ParameterSet*)obj->GetProgram()->GetVertexStage()->GetParameters();
	else
		item.VertexParams = (ParameterSet*)obj->GetData()->GetProgram()->GetVertexStage()->GetParameters();

	// Validate fragment stage inputs.
	if ( obj->GetFragmentParameters() != nullptr )
		item.FragmentParams = (ParameterSet*)obj->GetFragmentParameters();
	else if ( obj->GetProgram() != nullptr )
		item.FragmentParams = (ParameterSet*)obj->GetProgram()->GetFragmentStage()->GetParameters();
	else
		item.FragmentParams = (ParameterSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetParameters();

	if ( item.FragmentSamplers == nullptr )
	{
		if ( obj->GetProgram() != nullptr )
			item.FragmentSamplers = (SamplerStateSet*)obj->GetProgram()->GetFragmentStage()->GetSamplers()->Clone( obj->ID() );
		else
			item.FragmentSamplers = (SamplerStateSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetSamplers()->Clone( obj->ID() );
	}

	if ( obj->GetFragmentResources() != nullptr )
		item.FragmentResources = (ResourceSet*)obj->GetFragmentResources();
	else if ( obj->GetProgram() != nullptr )
		item.FragmentResources = (ResourceSet*)obj->GetProgram()->GetFragmentStage()->GetResources();
	else
		item.FragmentResources = (ResourceSet*)obj->GetData()->GetProgram()->GetFragmentStage()->GetResources();

	for ( UInt i = 0; i < item.FragmentSamplers->GetSize(); ++i )
	{
		item.FragmentSamplers->Get( i )->SetFilter( obj->IsSmoothingEnabled() ? TextureFilter::Linear : TextureFilter::Point );
	}

	// Validate other stuff.
	item.ElementCount = obj->GetElementCount();
}


} // gfx


} // synkro
