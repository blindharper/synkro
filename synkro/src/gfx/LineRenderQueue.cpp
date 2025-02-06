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
// Purpose: Line rendering queue implementation.
//==============================================================================
#include "config.h"
#include "LineRenderQueue.h"
#include "LineRenderObject.h"
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


LineRenderItem::LineRenderItem( LineRenderObject* object ) :
	Object( object ),
	Data( (Primitive*)object->GetData() ),
	VertexParams( nullptr ),
	StartElement( object->GetStartElement() ),
	ElementCount( object->GetElementCount() ),
	StartInstance( object->GetStartInstance() ),
	InstanceCount( object->GetInstanceCount() )
{
}

LineRenderItem::LineRenderItem() :
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


LineRenderQueue::LineRenderQueue( IGraphicsSystemEx* graphicsSystem ) :
	_items( A(LineRenderItem) ),
	_items4D( A(LineRenderItem) ),
	_itemsColored( A(LineRenderItem) ),
	_items4DColored( A(LineRenderItem) ),
	_itemsInstanced( A(LineRenderItem) ),
	_itemsColoredInstanced( A(LineRenderItem) )
{
	_program = (Program*)graphicsSystem->GetProgram( L"line.monochrome" );
	_program4D = (Program*)graphicsSystem->GetProgram( L"line4d.monochrome" );
	_programColored = (Program*)graphicsSystem->GetProgram( L"line.colored" );
	_program4DColored = (Program*)graphicsSystem->GetProgram( L"line4d.colored" );
	_programInstanced = (Program*)graphicsSystem->GetProgram( L"line.instanced" );

	_blendStates = (BlendStateSet*)graphicsSystem->GetDevice()->GetBlendStates()->Clone();
	_depthStencilState = (DepthStencilState*)graphicsSystem->GetDevice()->GetDepthStencilState()->Clone();
	_rasterizerState = (RasterizerState*)graphicsSystem->GetDevice()->GetRasterizerState()->Clone();
	_rasterizerState->EnableAntialiasing( false );
}

ILineRenderObject* LineRenderQueue::CreateObject( IPrimitive* data )
{
	LineRenderObject* object = nullptr;

	IDataFormat* inputFormat = data->GetProgram()->GetInputFormat();
	if ( inputFormat == _program->GetInputFormat() )
	{
		object = new LineRenderObject( this, data );
		_items.Add( LineRenderItem(object) );
	}
	else if ( inputFormat == _program4D->GetInputFormat() )
	{
		object = new LineRenderObject( this, data );
		_items4D.Add( LineRenderItem(object) );
	}
	else if ( inputFormat == _programColored->GetInputFormat() )
	{
		object = new LineRenderObject( this, data );
		_itemsColored.Add( LineRenderItem(object) );
	}
	else if ( inputFormat == _program4DColored->GetInputFormat() )
	{
		object = new LineRenderObject( this, data );
		_items4DColored.Add( LineRenderItem(object) );
	}
	else if ( inputFormat == _programInstanced->GetInputFormat() )
	{
		object = new LineRenderObject( this, data );
		_itemsInstanced.Add( LineRenderItem(object) );
	}

	return object;
}

void LineRenderQueue::RemoveObject( LineRenderObject* object )
{
	RemoveObject(_items, object) || RemoveObject(_items4D, object) || RemoveObject(_itemsColored, object) ||
	RemoveObject(_items4DColored, object) || RemoveObject(_itemsInstanced, object) || RemoveObject(_itemsColoredInstanced, object);
}

void LineRenderQueue::Process( GraphicsStats& stats )
{
	SynkroProfile( "LineRenderQueue.Process" );

	// Skip processing if the queue is disabled.
	if ( !_enabled )
		return;

	// Bind states.
	_blendStates->Bind();
	_depthStencilState->Bind();
	_rasterizerState->Bind();

	// Draw items.
	ProcessItems( _program, _items, stats );
	ProcessItems( _program4D, _items4D, stats );
	ProcessItems( _programColored, _itemsColored, stats );
	ProcessItems( _program4DColored, _items4DColored, stats );
	ProcessItems( _programInstanced, _itemsInstanced, stats );
}

void LineRenderQueue::ProcessItems( IProgram* program, Vector<LineRenderItem>& items, GraphicsStats& stats )
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

Bool LineRenderQueue::RemoveObject( Vector<LineRenderItem>& items, LineRenderObject* object )
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

void LineRenderQueue::ValidateItem( LineRenderItem& item )
{
	LineRenderObject* obj = item.Object;

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
