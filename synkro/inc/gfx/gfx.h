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
// Purpose: 'gfx' namespace includes.
//==============================================================================
#ifndef _SYNKRO_GFX_
#define _SYNKRO_GFX_


#include <gfx/ITypedBuffer.h>
#include <gfx/IStructuredBuffer.h>
#include <gfx/ILinearTexture.h>
#include <gfx/IPlainTexture.h>
#include <gfx/ICubeTexture.h>
#include <gfx/IVolumeTexture.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/IDataFormatEx.h>
#include <gfx/IProgram.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IVirtualRenderWindow.h>
#include <gfx/IRect.h>
#include <gfx/IRenderView.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/ISceneRenderQueue.h>
#include <gfx/ISceneRenderObject.h>
#include <gfx/ISkyRenderObject.h>
#include <gfx/ILineRenderQueue.h>
#include <gfx/GraphicsSystem.h>
#include <gfx/GraphicsException.h>


#define PtrFrameRenderWindowEx P(synkro::gfx::IFrameRenderWindowEx)
#define PtrPlainRenderTexture P(synkro::gfx::IPlainRenderTexture)


namespace synkro
{


/**
 * The 'gfx' namespace contains interfaces
 * for creating graphics stuff in 2D and 3D.
 */
namespace gfx
{
} // gfx


} // synkro


#endif // _SYNKRO_GFX_
