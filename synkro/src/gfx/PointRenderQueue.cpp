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
// Purpose: Point rendering queue implementation.
//==============================================================================
#include "config.h"
#include "PointRenderQueue.h"
#include "PointRenderObject.h"
#include "Primitive.h"
#include "Program.h"
#include "ParameterSet.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
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


PointRenderItem::PointRenderItem( PointRenderObject* object ) :
	Object( object ),
	Data( (Primitive*)object->GetData() ),
	VertexParams( nullptr ),
	StartElement( object->GetStartElement() ),
	ElementCount( object->GetElementCount() ),
	StartInstance( object->GetStartInstance() ),
	InstanceCount( object->GetInstanceCount() )
{
}

PointRenderItem::PointRenderItem() :
	Object( nullptr ),
	Data( nullptr ),
	VertexParams( nullptr ),
	StartElement( 0 ),
	ElementCount( 0 ),
	StartInstance( 0 ),
	InstanceCount( 0 )
{
}


//------------------------------------------------------------------------------


PointRenderQueue::PointRenderQueue( IGraphicsSystemEx* graphicsSystem ) :
	_items( A(PointRenderItem) )
{
	_program = (Program*)graphicsSystem->GetProgram( L"point.monochrome" );

	_blendStates = (BlendStateSet*)graphicsSystem->GetDevice()->GetBlendStates()->Clone();
	_depthStencilState = (DepthStencilState*)graphicsSystem->GetDevice()->GetDepthStencilState()->Clone();
	_rasterizerState = (RasterizerState*)graphicsSystem->GetDevice()->GetRasterizerState()->Clone();
	_rasterizerState->EnableAntialiasing( false );
}

IPointRenderObject* PointRenderQueue::CreateObject( IPrimitive* data )
{
	PointRenderObject* object = nullptr;

	IDataFormat* inputFormat = data->GetProgram()->GetInputFormat();
	if ( inputFormat == _program->GetInputFormat() )
	{
		object = new PointRenderObject( this, data );
		_items.Add( PointRenderItem(object) );
	}

	return object;
}

void PointRenderQueue::RemoveObject( PointRenderObject* object )
{
	RemoveObject (_items, object );
}

void PointRenderQueue::Process( GraphicsStats& stats )
{
	SynkroProfile( "PointRenderQueue.Process" );

	// Skip processing if the queue is disabled.
	if ( !_enabled )
		return;

	// Bind states.
	_blendStates->Bind();
	_depthStencilState->Bind();
	_rasterizerState->Bind();

	// Draw items.
	ProcessItems( _program, _items, stats );
}

void PointRenderQueue::ProcessItems( IProgram* program, Vector<PointRenderItem>& items, GraphicsStats& stats )
{
	program->Bind();
	for ( UInt i = 0; i < items.Size(); ++i )
	{
		// Skip disabled items.
		if ( !items[i].Object->IsEnabled() )
			continue;

		// Validate item if needed.
		if ( items[i].Object->IsDirty() )
		{
			ValidateItem( items[i] );
			items[i].Object->ResetDirty();
		}

		// Bind input buffers.
		items[i].Data->GetInputBuffers()->Bind();
		if ( items[i].Data->GetIndexBuffer() != nullptr )
			items[i].Data->GetIndexBuffer()->Bind();

		// Bind vertex stage stuff.
		items[i].VertexParams->Bind();

		// Perform drawing.
		stats.PrimitiveCount += items[i].Data->Draw( items[i].StartElement, items[i].ElementCount, items[i].StartInstance, items[i].InstanceCount );
		stats.ObjectCount += 1;
	}
}

Bool PointRenderQueue::RemoveObject( Vector<PointRenderItem>& items, PointRenderObject* object )
{
	for ( UInt i = 0; i < items.Size(); ++i )
	{
		if ( items[i].Object = object )
		{
			items.Remove( i );
			return true;
		}
	}
	return false;
}

void PointRenderQueue::ValidateItem( PointRenderItem& item )
{
	PointRenderObject* obj = item.Object;

	// Validate vertex stage parameters.
	if ( obj->GetVertexParameters() != nullptr )
		item.VertexParams = (ParameterSet*)obj->GetVertexParameters();
	else if ( obj->GetProgram() != nullptr )
		item.VertexParams = (ParameterSet*)obj->GetProgram()->GetVertexStage()->GetParameters();
	else
		item.VertexParams = (ParameterSet*)obj->GetData()->GetProgram()->GetVertexStage()->GetParameters();

	// Validate other stuff.
	item.StartElement = obj->GetStartElement();
	item.ElementCount = obj->GetElementCount();
	item.StartInstance = obj->GetStartInstance();
	item.InstanceCount = obj->GetInstanceCount();
}


} // gfx


} // synkro
