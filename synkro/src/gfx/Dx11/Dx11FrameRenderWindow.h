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
// Purpose: DX11 frame rendering window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11FRAMERENDERWINDOW_
#define _SYNKRO_GFX_DX11FRAMERENDERWINDOW_


#include "config.h"
#include "Dx11Classes.h"
#include <gfx/FrameRenderWindowImpl.h>
#include <gfx/IFrameRenderWindow.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 frame rendering window implementation.
class Dx11FrameRenderWindow :
	public FrameRenderWindowImpl<IFrameRenderWindow>
{
public:
	// Constructor & destructor.
	Dx11FrameRenderWindow( IDXGIFactory1* factory, Dx11GraphicsDevice* device, win::IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality );
	~Dx11FrameRenderWindow();

	// IRenderWindow methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();

	// IFrameRenderWindow methods.
	Bool													SetDisplayMode( const DisplayMode& displayMode );

private:
	IDXGIFactory1*											_factory;
	Dx11Context												_context;
	IDXGISwapChain*											_swapChain;
	ID3D11RenderTargetView*									_rtv;
	D3D11_VIEWPORT											_viewport;
	DXGI_SWAP_CHAIN_DESC									_sd;
    UINT													_sampleCount;
    UINT													_sampleQuality;
	UINT													_syncInterval;
};


#include "Dx11FrameRenderWindow.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11FRAMERENDERWINDOW_
