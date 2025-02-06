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
// Purpose: DX11 cube rendering texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11CubeRenderTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11CubeRenderTexture::Dx11CubeRenderTexture( Dx11Context* context, UInt length, const PixelFormat& format, UInt sampleCount, UInt sampleQuality ) :
	CubeRenderTextureImpl<ICubeRenderTexture>( length, format ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr ),
	_textureDst( nullptr )
{
	HRESULT hr = S_OK;
	DXGI_FORMAT fmt = DxGi::Convert( _format );

	// Create texture.
	D3D11_TEXTURE2D_DESC desc;
	desc.Width				= _length;
	desc.Height				= _length;
	desc.MipLevels			= 1;
	desc.ArraySize			= 1;
	desc.Format				= fmt;
	desc.SampleDesc.Count	= sampleCount;
	desc.SampleDesc.Quality	= sampleQuality;
	desc.Usage				= D3D11_USAGE_DEFAULT;
	desc.BindFlags			= (sampleCount > 1) ? D3D11_BIND_RENDER_TARGET : (D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE);
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= D3D11_RESOURCE_MISC_TEXTURECUBE;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create cube rendering texture.", String::Format(L"Edge length = {0}, Pixel format = {1}", length, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create resource views.
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	Zero( &srvDesc );
	srvDesc.Format						= fmt;
	srvDesc.ViewDimension				= D3D11_SRV_DIMENSION_TEXTURECUBE;
	srvDesc.TextureCube.MipLevels		= 1;
	srvDesc.TextureCube.MostDetailedMip	= 0;
	if ( FAILED(hr = _context.Device()->CreateRenderTargetView(_texture, nullptr, &_rtv)) )
		throw GraphicsException( "Failed to create cube rendering texture.", Dx11::ToString(hr) );

	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, nullptr, &_srv)) )
		throw GraphicsException( "Failed to create cube rendering texture.", Dx11::ToString(hr) );

	D3D11_TEXTURE2D_DESC desc2;
	desc2.Width					= _length;
	desc2.Height				= _length;
	desc2.MipLevels				= 1;
	desc2.ArraySize				= 1;
	desc2.Format				= fmt;
	desc2.SampleDesc.Count		= 1;
	desc2.SampleDesc.Quality	= 0;
	desc2.Usage					= D3D11_USAGE_STAGING;
	desc2.BindFlags				= 0;
	desc2.CPUAccessFlags		= D3D11_CPU_ACCESS_READ;
	desc2.MiscFlags				= D3D11_RESOURCE_MISC_TEXTURECUBE;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc2, nullptr, &_textureDst)) )
		throw GraphicsException( "Failed to create cube rendering texture.", Dx11::ToString(hr) );
}

Dx11CubeRenderTexture::~Dx11CubeRenderTexture()
{
	SafeRelease( _textureDst );
	SafeRelease( _texture );
}

Bool Dx11CubeRenderTexture::GetData( const CubeFace& face, UInt* length, UInt* stride, PixelFormat* format, Byte** data, UInt* size )
{
	*length = 0; *stride = 0; *format = PixelFormat::Unknown; *data = 0; *size = 0;

	// Copy texture data to system memory.
	Dx11Lock( _context );
	_context->CopyResource( _textureDst, _texture );

	// Get access to texture data.
	D3D11_MAPPED_SUBRESOURCE tex;
	tex.pData = nullptr; tex.RowPitch	= 0;
	if ( FAILED(_context->Map(_textureDst, 0, D3D11_MAP_READ, 0, &tex)) && (tex.pData != nullptr) )
		return false;

	D3D11_TEXTURE2D_DESC desc;
	_textureDst->GetDesc( &desc );

	*length = _length;
	*stride = tex.RowPitch;
	*format = DxGi::Convert( desc.Format );
	*data = (Byte*)tex.pData;
	*size = tex.RowPitch * _length;

	_context->Unmap( _textureDst, 0 );
	return true;
}


} // gfx


} // synkro
