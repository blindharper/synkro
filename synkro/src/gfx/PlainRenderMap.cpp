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
// Purpose: Plain rendering map implementation.
//==============================================================================
#include "config.h"
#include "PlainRenderMap.h"
#include "SceneRenderQueue.h"
#include <gfx/GraphicsStats.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


PlainRenderMap::PlainRenderMap( ISceneRenderQueue* queue, IPlainRenderTexture* colorTarget, IPlainDepthTexture* depthTarget ) :
	RenderMapImpl<IPlainRenderMap>( queue ),
	_sceneQueue( (SceneRenderQueue*)queue ),
	_colorTarget( colorTarget ),
	_depthTarget( depthTarget )
{
}

UInt PlainRenderMap::Draw()
{
	if ( _colorTarget->Bind() )
	{
		GraphicsStats stats;
		_depthTarget->Clear();
		_colorTarget->Clear();
		_sceneQueue->Process( nullptr, false, FillMode::Solid, PixelChannel::All, _vertexParams, stats );
		_colorTarget->Present();
	}

	return 0;
}


} // gfx


} // synkro
