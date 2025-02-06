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
// Purpose: Cube rendering map implementation.
//==============================================================================
#include "config.h"
#include "CubeRenderMap.h"
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


CubeRenderMap::CubeRenderMap( ISceneRenderQueue* queue, ICubeRenderTexture* colorTarget, ICubeDepthTexture* depthTarget, Bool singlePass ) :
	RenderMapImpl<ICubeRenderMap>( queue ),
	_sceneQueue( (SceneRenderQueue*)queue ),
	_colorTarget( colorTarget ),
	_depthTarget( depthTarget ),
	_singlePass( singlePass )
{
}

UInt CubeRenderMap::Draw()
{
	GraphicsStats stats;

	// NB: Pass viewProj transforms for each face.

	if ( _singlePass )
	{
		IDepthTexture* depthTarget = _depthTarget;
		IRenderTexture* colorTarget = _colorTarget;
		if ( colorTarget->Bind() )
		{
			depthTarget->Clear();
			colorTarget->Clear();
			_sceneQueue->Process( nullptr, false, FillMode::Solid, PixelChannel::All, _vertexParams, stats );
			colorTarget->Present();
		}
	}
	else
	{
		for ( UInt f = 0; f < 6; ++f )
		{
			CubeFace face = CubeFace(f);
			if ( _depthTarget->BindFace(face) && _colorTarget->BindFace(face) )
			{
				_depthTarget->Clear();
				_colorTarget->Clear();
				_sceneQueue->Process( nullptr, false, FillMode::Solid, PixelChannel::All, _vertexParams, stats );
				_colorTarget->Present();
			}
		}
	}

	return 0;
}


} // gfx


} // synkro
