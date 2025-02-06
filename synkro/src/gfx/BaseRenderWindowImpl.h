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
// Purpose: Generic base render window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BASERENDERWINDOWIMPL_
#define _SYNKRO_GFX_BASERENDERWINDOWIMPL_


#include "config.h"
#include <gfx/IProgram.h>
#include <gfx/IParameterSet.h>
#include <gfx/IResourceSet.h>
#include <gfx/ISamplerState.h>
#include <gfx/ISamplerStateSet.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector4Stream.h>
#include <gfx/GraphicsStats.h>
#include "Primitive.h"
#include "OverlayRenderQueue.h"


namespace synkro
{


namespace gfx
{


// Generic base render window implementation.
template <class T>
class BaseRenderWindowImpl :
	public T
{
public:
	// Constructor & destructor.
	BaseRenderWindowImpl( GraphicsDevice* device, IRenderWindow* renderWindow, UInt width, UInt height, IProgram* programScreen, IProgram* programView, UInt sampleCount );
	virtual ~BaseRenderWindowImpl();

	// BaseRenderWindow methods.
	virtual void											Resize();
	virtual void											Draw( Double delta, GraphicsStats& stats );
	virtual UInt											DrawLast();
	virtual UInt											DrawScreen( IPlainRenderTexture* texture );
	virtual IPlainRenderTexture*							GetIntermediateTarget() const;

protected:
	lang::Vector<P(RenderView)>								_views;
	GraphicsDevice*											_device;
	IProgram*												_programScreen;
	IProgram*												_programView;
	IRenderWindow*											_renderWindow;
	UInt													_sampleCount;
	Ndc														_ndc;
	UInt													_width;
	UInt													_height;
	P(OverlayRenderQueue)									_overlays;
	P(Primitive)											_screen;
	P(IPlainRenderTexture)									_screenTexture;
	P(IBlendStateSet)										_blendStateDisabled;
	P(IBlendStateSet)										_blendStateEnabled;
	P(IDepthStencilState)									_depthStencilState;
	P(IRasterizerState)										_rasterizerState;
	P(IRasterizerState)										_rasterizerStateScissor;
	P(IResourceSet)											_resources;
	P(ISamplerStateSet)										_samplers;

	void													CreateOverlay();
	void													FillScreen();
};


#include "BaseRenderWindowImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASERENDERWINDOWIMPL_
