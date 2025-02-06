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
#ifndef _SYNKRO_GFX_OVERLAYRENDERMAP_
#define _SYNKRO_GFX_OVERLAYRENDERMAP_


#include "config.h"
#include "RenderMapImpl.h"
#include <gfx/IPlainRenderMap.h>
#include <gfx/IPlainRenderTexture.h>
#include "BaseRenderMap.h"
#include "Classes.h"


namespace synkro
{


namespace gfx
{


// Overlay rendering map implementation.
class OverlayRenderMap :
	public RenderMapImpl<IPlainRenderMap>,
	public BaseRenderMap
{
public:
	// Constructor.
	OverlayRenderMap( IOverlayRenderQueue* queue, IPlainRenderTexture* target );

	// IPlainRenderMap methods.
	IPlainRenderTexture*									GetColorTarget() const;
	IPlainDepthTexture*										GetDepthTarget() const;

	// BaseRenderMap methods.
	UInt													Draw();

private:
	OverlayRenderQueue*										_overlayQueue;
	P(IPlainRenderTexture)									_target;
};


#include "OverlayRenderMap.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_OVERLAYRENDERMAP_
