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
#include "config.h"
#include "SceneRenderObject.h"
#include "Primitive.h"


namespace synkro
{


namespace gfx
{


SceneRenderObject::SceneRenderObject( SceneRenderQueue* queue, IPrimitive* data ) :
	SceneRenderObjectImpl<ISceneRenderObject>( queue, data->GetProgram() )
{
	_elementCount = (data->GetIndexCount() > 0) ? data->GetIndexCount() : data->GetVertexCount();
	((Primitive*)data)->Prepare( nullptr );
	_data = (IPrimitiveEx*)data;
}

SceneRenderObject::~SceneRenderObject()
{
	_queue->RemoveObject( this );
}


} // gfx


} // synkro
