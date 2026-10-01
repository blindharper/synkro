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
// Purpose: Extended Scene rendering object implementation.
//==============================================================================
#include "config.h"
#include "SceneRenderObjectEx.h"
#include "Primitive.h"


namespace synkro
{


namespace gfx
{


SceneRenderObjectEx::SceneRenderObjectEx( SceneRenderQueue* queue ) :
	SceneRenderObjectImpl<ISceneRenderObjectEx>( queue, nullptr ),
	_primitives( A(P(IPrimitiveEx)) )
{
}

SceneRenderObjectEx::~SceneRenderObjectEx()
{
	_queue->RemoveObject( this );
}

ISceneRenderObjectEx* SceneRenderObjectEx::AsEx() const
{
	return (ISceneRenderObjectEx*)this;
}

IPrimitiveEx* SceneRenderObjectEx::CreateLevel( IPrimitive* data )
{
	_program = data->GetProgram();
	_elementCount = (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount();
	((Primitive*)data)->Prepare( nullptr );
	_primitives.Add( _data = (IPrimitiveEx*)data );
	return _primitives.LastValue();
}

void SceneRenderObjectEx::SetLevel( IRenderView* view, UInt level )
{
	assert( level < _primitives.Size() );

	if ( !_views.ContainsKey(view->ID()) )
	{
		_views[view->ID()] = ViewData( true );
	}
	_views[view->ID()].Data = _primitives[level];
	_dirty = true;
}


} // gfx


} // synkro
