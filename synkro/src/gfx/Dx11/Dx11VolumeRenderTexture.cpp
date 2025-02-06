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
// Purpose: DX11 volume rendering texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11VolumeRenderTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11VolumeRenderTexture::Dx11VolumeRenderTexture( Dx11Context* context, UInt width, UInt height, UInt depth, const PixelFormat& format ) :
	VolumeRenderTextureImpl<IVolumeRenderTexture>( width, height, depth, format ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr ),
	_textureDst( nullptr )
{
	HRESULT hr = S_OK;
	DXGI_FORMAT fmt = DxGi::Convert( _format );

	// Create texture.
	D3D11_TEXTURE3D_DESC desc;
	desc.Width				= _width;
	desc.Height				= _height;
	desc.Depth				= _depth;
	desc.MipLevels			= 1;
	desc.Format				= fmt;
	desc.Usage				= D3D11_USAGE_DEFAULT;
	desc.BindFlags			= D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= 0;
	if ( FAILED(hr = _context.Device()->CreateTexture3D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create volume rendering texture.", String::Format(L"Width = {0}, Height = {1}, Depth = {2}, Pixel format = {3}", width, height, depth, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create resource views.
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	Zero( &srvDesc );
	srvDesc.Format						= fmt;
	srvDesc.ViewDimension				= D3D11_SRV_DIMENSION_TEXTURE3D;
	srvDesc.TextureCube.MipLevels		= 1;
	srvDesc.TextureCube.MostDetailedMip	= 0;
	if ( FAILED(hr = _context.Device()->CreateRenderTargetView(_texture, nullptr, &_rtv)) )
		throw GraphicsException( "Failed to create volume rendering texture.", Dx11::ToString(hr) );

	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, nullptr, &_srv)) )
		throw GraphicsException( "Failed to create volume rendering texture.", Dx11::ToString(hr) );

	// Copy off-screen texture.
	D3D11_TEXTURE3D_DESC desc2;
	desc2.Width				= _width;
	desc2.Height			= _height;
	desc2.Depth				= _depth;
	desc2.MipLevels			= 1;
	desc2.Format			= fmt;
	desc2.Usage				= D3D11_USAGE_STAGING;
	desc2.BindFlags			= 0;
	desc2.CPUAccessFlags	= D3D11_CPU_ACCESS_READ;
	desc2.MiscFlags			= 0;
	if ( FAILED(hr = _context.Device()->CreateTexture3D(&desc2, nullptr, &_textureDst)) )
		throw GraphicsException( "Failed to create volume rendering texture.", Dx11::ToString(hr) );
}

Dx11VolumeRenderTexture::~Dx11VolumeRenderTexture()
{
	SafeRelease( _textureDst );
	SafeRelease( _texture );
}

Bool Dx11VolumeRenderTexture::GetData( UInt element, UInt* width, UInt* height, UInt* depth, UInt* stride, UInt* sliceStride, PixelFormat* format, Byte** data, UInt* size )
{
	*width = 0; *height = 0; *depth = 0; *stride = 0; *sliceStride = 0; *format = PixelFormat::Unknown; *data = 0; *size = 0;

	// Copy texture data to system memory.
	Dx11Lock( _context );
	_context->CopyResource( _textureDst, _texture );

	// Get access to texture data.
	D3D11_MAPPED_SUBRESOURCE tex;
	tex.pData = nullptr; tex.RowPitch = 0; tex.DepthPitch = 0;
	if ( FAILED(_context->Map(_textureDst, 0, D3D11_MAP_READ, 0, &tex)) && (tex.pData != nullptr) )
		return false;

	D3D11_TEXTURE3D_DESC desc;
	_textureDst->GetDesc( &desc );

	*width = _width;
	*height = _height;
	*stride = tex.RowPitch;
	*sliceStride = tex.DepthPitch;
	*format = DxGi::Convert( desc.Format );
	*data = (Byte*)tex.pData;
	*size = tex.RowPitch * _height;

	_context->Unmap( _textureDst, 0 );
	return true;
}


} // gfx


} // synkro
