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
#include "config.h"
#include "Dx11ViewRenderWindow.h"
#include "Dx11GraphicsDevice.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11ViewRenderWindow::Dx11ViewRenderWindow( IDXGIFactory* factory, Dx11GraphicsDevice* device, IViewWindow* window, const PixelFormat& format, Bool vsync, UInt sampleCount, UInt sampleQuality ) :
	ViewRenderWindowImpl<IViewRenderWindow>( device, window, format, sampleCount ),
	_context( device ),
	_swapChain( nullptr ),
	_rtv( nullptr ),
	_syncInterval( vsync ? 1 : 0 )
{
	HRESULT hr = S_OK;

	// Create swap chain.
	Zero( &_sd );
	_sd.BufferDesc.Width		= _window->GetWidth();
	_sd.BufferDesc.Height		= _window->GetHeight();
	_sd.BufferDesc.Format		= DxGi::Convert( _format );
	_sd.BufferDesc.RefreshRate.Numerator = 60;
	_sd.BufferDesc.RefreshRate.Denominator = 1;
	_sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	_sd.BufferDesc.Scaling		= DXGI_MODE_SCALING_UNSPECIFIED;
	_sd.SampleDesc.Count		= sampleCount;
	_sd.SampleDesc.Quality		= sampleQuality;
	_sd.BufferUsage				= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	_sd.BufferCount				= 1;
	_sd.OutputWindow			= (HWND)_window->GetHandle();
	_sd.Windowed				= TRUE;
	_sd.SwapEffect				= DXGI_SWAP_EFFECT_DISCARD;
	if ( FAILED(hr = factory->CreateSwapChain(_context.Device(), &_sd, &_swapChain)) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"IDXGIFactory::CreateSwapChain()"), Dx11::ToString(hr) );

	// Create back buffer texture.
	ID3D11Texture2D* buffer = nullptr;
	if ( FAILED(hr = _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer)) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"IDXGISwapChain::GetBuffer()"), Dx11::ToString(hr) );

	hr = _context.Device()->CreateRenderTargetView( buffer, nullptr, &_rtv );
	buffer->Release();
	if ( FAILED(hr) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"ID3D11Device::CreateRenderTargetView()"), Dx11::ToString(hr) );

	// Create viewport.
	_viewport.TopLeftX		= 0.0f;
	_viewport.TopLeftY		= 0.0f;
	_viewport.Width			= _window->GetWidth();
	_viewport.Height		= _window->GetHeight();
	_viewport.MinDepth		= 0.0f;
	_viewport.MaxDepth		= 1.0f;

	_clientFormat = (_format == PixelFormat::R8G8B8A8) ? PixelFormat::B8G8R8A8 : _format;
}

Dx11ViewRenderWindow::~Dx11ViewRenderWindow()
{
	SafeRelease( _rtv );
	SafeRelease( _swapChain );
}


} // gfx


} // synkro
