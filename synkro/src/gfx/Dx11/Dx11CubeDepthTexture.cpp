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
// Purpose: DX11 cube depth texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11CubeDepthTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11CubeDepthTexture::Dx11CubeDepthTexture( Dx11Context* context, UInt length, const DepthFormat& format, Bool stencil, UInt sampleCount, UInt sampleQuality ) :
	CubeDepthTextureImpl<ICubeDepthTexture>( length, format, stencil ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr )
{
	HRESULT hr = S_OK;

	Bool resource = (sampleCount == 1) && (_format == DepthFormat::D32F);

	// Create texture.
	DXGI_FORMAT fmt = resource ? DXGI_FORMAT_R32_TYPELESS : DxGi::Convert( _format, _stencil );
	D3D11_TEXTURE2D_DESC desc;
	desc.Width				= _length;
	desc.Height				= _length;
	desc.MipLevels			= 1;
	desc.ArraySize			= 1;
	desc.Format				= fmt;
	desc.SampleDesc.Count	= sampleCount;
	desc.SampleDesc.Quality	= sampleQuality;
	desc.Usage				= D3D11_USAGE_DEFAULT;
	desc.BindFlags			= resource ? (D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE) : D3D11_BIND_DEPTH_STENCIL;
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= D3D11_RESOURCE_MISC_TEXTURECUBE;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create depth-stencil texture.", String::Format(L"Edge length = {0}, Format = {1}", length, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create depth-stencil view.
	D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc;
	dsvDesc.Format							= DxGi::Convert( _format, _stencil );
	dsvDesc.ViewDimension					= D3D11_DSV_DIMENSION_TEXTURE2DARRAY;
	dsvDesc.Texture2DArray.FirstArraySlice	= 0;
	dsvDesc.Texture2DArray.ArraySize		= 6;
	dsvDesc.Texture2DArray.MipSlice			= 0;
	if ( FAILED(hr = _context.Device()->CreateDepthStencilView(_texture, &dsvDesc, &_dsv)) )
		throw GraphicsException( "Failed to create depth-stencil texture.", Dx11::ToString(hr) );

	// Create resource view.
	if ( resource )
	{
		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
		Zero( &srvDesc );
		srvDesc.Format						= DXGI_FORMAT_R32_FLOAT;
		srvDesc.ViewDimension				= D3D11_SRV_DIMENSION_TEXTURECUBE;
		srvDesc.TextureCube.MipLevels		= 1;
		srvDesc.TextureCube.MostDetailedMip	= 0;
		if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, &srvDesc, &_srv)) )
			throw GraphicsException( "Failed to create rendering texture.", Dx11::ToString(hr) );
	}

	// Prepare flags for the Clear() call.
	_flags = _stencil ? (D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL) : D3D11_CLEAR_DEPTH;
}

Dx11CubeDepthTexture::~Dx11CubeDepthTexture()
{
	SafeRelease( _texture );
}


} // gfx


} // synkro
