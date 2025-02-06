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
#ifndef _SYNKRO_GFX_PLAINRENDERMAP_
#define _SYNKRO_GFX_PLAINRENDERMAP_


#include "config.h"
#include "RenderMapImpl.h"
#include <gfx/IPlainRenderMap.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/IPlainDepthTexture.h>
#include "BaseRenderMap.h"
#include "Classes.h"


namespace synkro
{


namespace gfx
{


// Plain rendering map implementation.
class PlainRenderMap :
	public RenderMapImpl<IPlainRenderMap>,
	public BaseRenderMap
{
public:
	// Constructor.
	PlainRenderMap( ISceneRenderQueue* queue, IPlainRenderTexture* colorTarget, IPlainDepthTexture* depthTarget );

	// IPlainRenderMap methods.
	IPlainRenderTexture*									GetColorTarget() const;
	IPlainDepthTexture*										GetDepthTarget() const;

	// BaseRenderMap methods.
	UInt													Draw();

private:
	SceneRenderQueue*										_sceneQueue;
	P(IPlainRenderTexture)									_colorTarget;
	P(IPlainDepthTexture)									_depthTarget;
};


#include "PlainRenderMap.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINRENDERMAP_
