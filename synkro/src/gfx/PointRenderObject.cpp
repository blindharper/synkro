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
// Purpose: Point rendering object implementation.
//==============================================================================
#include "config.h"
#include "PointRenderObject.h"
#include "Primitive.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PointRenderObject::PointRenderObject( PointRenderQueue* queue, IPrimitive* data ) :
	RenderObjectImpl<IPointRenderObject>( data->GetProgram() ),
	_queue( queue ),
	_startElement( 0 ),
	_elementCount( (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount() ),
	_startInstance( 0 ),
	_instanceCount( 0 )
{
	((Primitive*)data)->Prepare( nullptr );
	_data = (IPrimitiveEx*)data;
}

PointRenderObject::~PointRenderObject()
{
	_queue->RemoveObject( this );
}

void PointRenderObject::SetElementRange( UInt start, UInt count )
{
	if ( (start != _startElement) || (count != _elementCount) )
	{
		const UInt maxElementCount = (_data->GetIndexCount() > 0) ? _data->GetIndexCount() : _data->GetVertexCount();
		assert( start+count <= maxElementCount );

		if ( start+count > maxElementCount )
			throw BadArgumentException( Str::InvalidArgument, L"start+count" );

		_startElement = start;
		_elementCount = count;
		_dirty = true;
	}
}

void PointRenderObject::SetInstanceRange( UInt start, UInt count )
{
	if ( (start != _startInstance) || (count != _instanceCount) )
	{
		assert( start+count <= _data->GetInstanceCount() );

		if ( start+count >= _data->GetInstanceCount() )
			throw BadArgumentException( Str::InvalidArgument, L"start+count" );

		_startInstance = start;
		_instanceCount = count;
		_dirty = true;
	}
}


} // gfx


} // synkro
