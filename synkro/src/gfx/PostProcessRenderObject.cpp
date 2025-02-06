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
// Purpose: Post-processing rendering object implementation.
//==============================================================================
#include "config.h"
#include "PostProcessRenderObject.h"
#include "PostProcessRenderQueue.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PostProcessRenderObject::PostProcessRenderObject( PostProcessRenderQueue* queue, IProgram* program, UInt order ) :
	RenderObjectImpl<IPostProcessRenderObject>( program ),
	_queue( queue ),
	_passCount( 1 ),
	_order( order )
{
	assert( _queue != nullptr );
}

void PostProcessRenderObject::SetTarget( IPlainRenderTexture* target )
{
	if ( target != _target )
	{
		if ( _queue->TargetExists(target) )
			throw InvalidOperationException( L"This target is already used with another object." );

		_target = target;
		_dirty = true;
	}
}

void PostProcessRenderObject::SetOrder( UInt order )
{
	if ( order != _order )
	{
		_order = order;
		_dirty = true;
		_queue->SetDirty();
	}
}


} // gfx


} // synkro
