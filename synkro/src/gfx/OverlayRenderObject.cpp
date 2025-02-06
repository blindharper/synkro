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
// Purpose: Overlay rendering object implementation.
//==============================================================================
#include "config.h"
#include "OverlayRenderObject.h"
#include "OverlayRenderQueue.h"
#include "Primitive.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


OverlayRenderObject::OverlayRenderObject( OverlayRenderQueue* queue, IPrimitive* data, Ndc* ndc ) :
	RenderObjectImpl<IOverlayRenderObject>( data->GetProgram() ),
	_queue( queue ),
	_smoothingEnabled( true ),
	_elementCount( (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount() ),
	_order( 24 ) // 7*Order::Normal + Order::Normal
{
	((Primitive*)data)->Prepare( ndc );
	_data = (IPrimitiveEx*)data;
}

OverlayRenderObject::~OverlayRenderObject()
{
	_queue->RemoveObject( this );
}

void OverlayRenderObject::SetElementCount( UInt count )
{
	if ( count != _elementCount )
	{
		assert( count <= ((_data->GetIndexCount() > 0) ? _data->GetIndexCount() : _data->GetVertexCount()) );

		if ( count > ((_data->GetIndexCount() > 0) ? _data->GetIndexCount() : _data->GetVertexCount()) )
			throw BadArgumentException( Str::InvalidArgument, L"count" );

		_elementCount = count;
		_dirty = true;
	}
}

void OverlayRenderObject::SetOrder( UInt order )
{
	if ( order != _order )
	{
		_order = order;
		_dirty = true;
		if ( _queue != nullptr )
		{
			_queue->SetDirty();
		}
	}
}


} // gfx


} // synkro
