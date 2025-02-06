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
#ifndef _SYNKRO_GFX_CUBERENDERMAP_
#define _SYNKRO_GFX_CUBERENDERMAP_


#include "config.h"
#include "RenderMapImpl.h"
#include <gfx/ICubeRenderMap.h>
#include <gfx/ICubeRenderTexture.h>
#include <gfx/ICubeDepthTexture.h>
#include "BaseRenderMap.h"
#include "Classes.h"


namespace synkro
{


namespace gfx
{


// Cube rendering map implementation.
class CubeRenderMap :
	public RenderMapImpl<ICubeRenderMap>,
	public BaseRenderMap
{
public:
	// Constructor.
	CubeRenderMap( ISceneRenderQueue* queue, ICubeRenderTexture* colorTarget, ICubeDepthTexture* depthTarget, Bool singlePass );

	// ICubeRenderMap methods.
	ICubeRenderTexture*										GetColorTarget() const;
	ICubeDepthTexture*										GetDepthTarget() const;

	// BaseRenderMap methods.
	UInt													Draw();

private:
	SceneRenderQueue*										_sceneQueue;
	P(ICubeRenderTexture)									_colorTarget;
	P(ICubeDepthTexture)									_depthTarget;
	Bool													_singlePass;
};


#include "CubeRenderMap.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBERENDERMAP_
