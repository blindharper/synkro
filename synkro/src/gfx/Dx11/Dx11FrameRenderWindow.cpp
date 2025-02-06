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
#include "config.h"
#include "Dx11FrameRenderWindow.h"
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


Dx11FrameRenderWindow::Dx11FrameRenderWindow( IDXGIFactory1* factory, Dx11GraphicsDevice* device, IFrameWindow* window, const DisplayMode& displayMode, Bool vsync, UInt sampleCount, UInt sampleQuality ) :
	FrameRenderWindowImpl<IFrameRenderWindow>( device, window, sampleCount ),
	_factory( factory ),
	_context( device ),
	_swapChain( nullptr ),
	_rtv( nullptr ),
	_sampleCount( sampleCount ),
	_sampleQuality( sampleQuality ),
	_syncInterval( vsync ? 1 : 0 )
{
	Zero( &_sd );
	SetDisplayMode( displayMode );
}

Dx11FrameRenderWindow::~Dx11FrameRenderWindow()
{
	SafeRelease( _rtv );

	if ( _swapChain != nullptr )
	{
		// Put swap chain to windowed mode before releasing it.
		_swapChain->SetFullscreenState( FALSE, nullptr );
		_swapChain->Release();
		_swapChain = nullptr;
	}
}

Bool Dx11FrameRenderWindow::SetDisplayMode( const DisplayMode& displayMode )
{
	// Release references to device resources.
	SafeRelease( _rtv );

	if ( _swapChain != nullptr )
	{
		// Put swap chain to windowed mode before releasing it.
		_swapChain->SetFullscreenState( FALSE, nullptr );
		_swapChain->Release();
		_swapChain = nullptr;
	}

	// Prepare presentation parameters.
	DXGI_SWAP_CHAIN_DESC sd;
	PixelFormat format		= (displayMode.Depth == 32) ? PixelFormat::R8G8B8A8 : PixelFormat::R5G6B5;
	sd.BufferDesc.Width		= displayMode.Width;
	sd.BufferDesc.Height	= displayMode.Height;
	sd.BufferDesc.Format	= DxGi::Convert( format );
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferDesc.Scaling	= DXGI_MODE_SCALING_UNSPECIFIED;
	sd.SampleDesc.Count		= _sampleCount;
	sd.SampleDesc.Quality	= _sampleQuality;
	sd.BufferUsage			= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount			= 1;
	sd.OutputWindow			= (HWND)_window->GetHandle();
	sd.Windowed				= !displayMode.Fullscreen;
	sd.SwapEffect			= DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags				= DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	HRESULT hr = S_OK;
	if ( FAILED(hr = _factory->CreateSwapChain(_context.Device(), &sd, &_swapChain)) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"IDXGIFactory1::CreateSwapChain()"), Dx11::ToString(hr) );

	// Create back buffer texture.
	ID3D11Texture2D* buffer = nullptr;
	if ( FAILED(hr = _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer)) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"IDXGISwapChain::GetBuffer()"), Dx11::ToString(hr) );

	hr = _context.Device()->CreateRenderTargetView( buffer, nullptr, &_rtv );
	buffer->Release();
	if ( FAILED(hr) )
		throw GraphicsException( Str::RenderWindowFail, String::Format(Str::CallFail, L"ID3D11Device::CreateRenderTargetView()"), Dx11::ToString(hr) );

	if ( displayMode.Fullscreen != _displayMode.Fullscreen )
	{
		if ( FAILED(hr = _swapChain->SetFullscreenState((BOOL)displayMode.Fullscreen, nullptr)) )
			return false;
	}

	// Adjust window size to get the desired client area size.
	if ( !displayMode.Fullscreen )
	{
		if ( FAILED(hr = _swapChain->ResizeTarget(&sd.BufferDesc)) )
			return false;
	}

	// Create viewport.
	_viewport.TopLeftX		= 0.0f;
	_viewport.TopLeftY		= 0.0f;
	_viewport.Width			= displayMode.Width;
	_viewport.Height		= displayMode.Height;
	_viewport.MinDepth		= 0.0f;
	_viewport.MaxDepth		= 1.0f;

	// Remember presentation parameters.
	_displayMode = displayMode;
	_clientFormat = (displayMode.Depth == 32) ? PixelFormat::B8G8R8A8 : PixelFormat::R5G6B5;
	_format = format;
	_sd = sd;

	// Signal success.
	return true;
}


} // gfx


} // synkro
