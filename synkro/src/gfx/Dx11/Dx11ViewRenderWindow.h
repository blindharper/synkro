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
// Purpose: DX11 view rendering window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11VIEWRENDERWINDOW_
#define _SYNKRO_GFX_DX11VIEWRENDERWINDOW_


#include "config.h"
#include "Dx11Classes.h"
#include <gfx/ViewRenderWindowImpl.h>
#include <gfx/IViewRenderWindow.h>
#include "Dx11.h"


namespace synkro
{


namespace gfx
{


// DirectX 11 view rendering window implementation.
class Dx11ViewRenderWindow :
	public ViewRenderWindowImpl<IViewRenderWindow>
{
public:
	// Constructor & destructor.
	Dx11ViewRenderWindow( IDXGIFactory* factory, Dx11GraphicsDevice* device, win::IViewWindow* window, const img::PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality );
	~Dx11ViewRenderWindow();

	// IRenderWindow methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();

private:
	Dx11Context												_context;
	IDXGISwapChain*											_swapChain;
	ID3D11RenderTargetView*									_rtv;
	D3D11_VIEWPORT											_viewport;
	DXGI_SWAP_CHAIN_DESC									_sd;
	UINT													_syncInterval;
};


#include "Dx11ViewRenderWindow.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11VIEWRENDERWINDOW_
