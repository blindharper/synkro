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
// Purpose: Overlay rendering map implementation.
//==============================================================================
#include "config.h"
#include "OverlayRenderMap.h"
#include "OverlayRenderQueue.h"


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


OverlayRenderMap::OverlayRenderMap( IOverlayRenderQueue* queue, IPlainRenderTexture* target ) :
	RenderMapImpl<IPlainRenderMap>( queue ),
	_overlayQueue( (OverlayRenderQueue*)queue ),
	_target( target )
{
}

UInt OverlayRenderMap::Draw()
{
	UInt primitiveCount = 0;

	if ( _target->Bind() )
	{
		_target->Clear();
		primitiveCount = _overlayQueue->Process();
		_target->Present();
	}

	return primitiveCount;
}


} // gfx


} // synkro
