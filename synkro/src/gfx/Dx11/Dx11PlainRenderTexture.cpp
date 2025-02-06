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
// Purpose: DX11 rendering plain texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11PlainRenderTexture.h"
#include "Dx11BaseDepthTexture.h"
#include <gfx/Dx/DxGi.h>
#include <gfx/IPlainDepthTexture.h>

//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11PlainRenderTexture::Dx11PlainRenderTexture( Dx11Context* context, UInt width, UInt height, const PixelFormat& format, UInt sampleCount, UInt sampleQuality ) :
	PlainRenderTextureImpl<IPlainRenderTexture>( width, height, format ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr ),
	_textureMS( nullptr ),
	_textureDst( nullptr ),
	_dsv( nullptr ),
	_depthTexture( nullptr )
{
	HRESULT hr = S_OK;
	DXGI_FORMAT fmt = DxGi::Convert( _format );
	
	// Create texture.
	D3D11_TEXTURE2D_DESC desc;
	desc.Width				= _width;
	desc.Height				= _height;
	desc.MipLevels			= 1;
	desc.ArraySize			= 1;
	desc.Format				= fmt;
	desc.SampleDesc.Count	= 1/*sampleCount*/;
	desc.SampleDesc.Quality	= 0/*sampleQuality*/;
	desc.Usage				= D3D11_USAGE_DEFAULT;
	desc.BindFlags			= D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= 0;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create rendering texture.", String::Format(L"Width = {0}, Height = {1}, Pixel format = {2}", width, height, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create multi-sampled texture, if needed.
	if ( sampleCount > 1 )
	{
		desc.Width				= _width;
		desc.Height				= _height;
		desc.MipLevels			= 1;
		desc.ArraySize			= 1;
		desc.Format				= fmt;
		desc.SampleDesc.Count	= sampleCount;
		desc.SampleDesc.Quality	= sampleQuality;
		desc.Usage				= D3D11_USAGE_DEFAULT;
		desc.BindFlags			= D3D11_BIND_RENDER_TARGET;
		desc.CPUAccessFlags		= 0;
		desc.MiscFlags			= 0;
		if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc, nullptr, &_textureMS)) )
			throw GraphicsException( L"Failed to create rendering texture.", String::Format(L"Width = {0}, Height = {1}, Pixel format = {2}", width, height, DxGi::ToString(fmt)), Dx11::ToString(hr) );

		D3D11_RENDER_TARGET_VIEW_DESC rtvDesc;
		rtvDesc.Format			= fmt;
		rtvDesc.ViewDimension	= D3D11_RTV_DIMENSION_TEXTURE2DMS;
		if ( FAILED(hr = _context.Device()->CreateRenderTargetView(_textureMS, &rtvDesc, &_rtv)) )
			throw GraphicsException( "Failed to create rendering texture.", Dx11::ToString(hr) );
	}
	else
	{
		D3D11_RENDER_TARGET_VIEW_DESC rtvDesc;
		rtvDesc.Format				= fmt;
		rtvDesc.ViewDimension		= D3D11_RTV_DIMENSION_TEXTURE2D;
		rtvDesc.Texture2D.MipSlice	= 0;
		if ( FAILED(hr = _context.Device()->CreateRenderTargetView(_texture, &rtvDesc, &_rtv)) )
			throw GraphicsException( "Failed to create rendering texture.", Dx11::ToString(hr) );
	}

	// Create resource view.
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, nullptr, &_srv)) )
		throw GraphicsException( "Failed to create rendering texture.", Dx11::ToString(hr) );

	// Create off-screen texture.
	D3D11_TEXTURE2D_DESC desc2;
	desc2.Width					= _width;
	desc2.Height				= _height;
	desc2.MipLevels				= 1;
	desc2.ArraySize				= 1;
	desc2.Format				= fmt;
	desc2.SampleDesc.Count		= 1;
	desc2.SampleDesc.Quality	= 0;
	desc2.Usage					= D3D11_USAGE_STAGING;
	desc2.BindFlags				= 0;
	desc2.CPUAccessFlags		= D3D11_CPU_ACCESS_READ;
	desc2.MiscFlags				= 0;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc2, nullptr, &_textureDst)) )
		throw GraphicsException( "Failed to create rendering texture.", Dx11::ToString(hr) );

	// Create viewport.
	_viewport.TopLeftX		= 0.0f;
	_viewport.TopLeftY		= 0.0f;
	_viewport.Width			= _width;
	_viewport.Height		= _height;
	_viewport.MinDepth		= 0.0f;
	_viewport.MaxDepth		= 1.0f;
}

Dx11PlainRenderTexture::~Dx11PlainRenderTexture()
{
	SafeRelease( _textureDst );
	SafeRelease( _textureMS );
	SafeRelease( _texture );
}

void Dx11PlainRenderTexture::SetDepthTexture( IPlainDepthTexture* texture )
{
	_depthTexture = texture;
	if ( _depthTexture == nullptr )
	{
		_dsv = NULL;
		return;
	}
	_dsv = AsDx11BaseDepthTexture( _depthTexture )->AsDx11DepthStencilView();
}

Bool Dx11PlainRenderTexture::GetData( UInt* width, UInt* height, UInt* stride, PixelFormat* format, Byte** data, UInt* size )
{
	*width = 0; *height = 0; *stride = 0; *format = PixelFormat::Unknown; *data = 0; *size = 0;

	// Copy texture data to system memory.
	Dx11Lock( _context );
	if ( _textureMS != nullptr )
		_context->ResolveSubresource( _textureDst, 0, _textureMS, 0, DxGi::Convert(_format) );
	else
		_context->CopyResource( _textureDst, _texture );

	// Get access to texture data.
	D3D11_MAPPED_SUBRESOURCE tex;
	tex.pData = nullptr; tex.RowPitch = 0;
	if ( FAILED(_context->Map(_textureDst, 0, D3D11_MAP_READ, 0, &tex)) && (tex.pData != nullptr) )
		return false;

	D3D11_TEXTURE2D_DESC desc;
	_textureDst->GetDesc( &desc );

	*format = DxGi::Convert( desc.Format );
	*stride = tex.RowPitch;
	*width = *stride / format->BytesPerPixel();
	*height = _height;
	*data = (Byte*)tex.pData;
	*size = tex.RowPitch * _height;

	_context->Unmap( _textureDst, 0 );
	return true;
}


} // gfx


} // synkro
