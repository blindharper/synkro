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
// Purpose: DX11 volume texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11VolumeTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11VolumeTexture::Dx11VolumeTexture( Dx11Context* context, const DataUsage& usage, UInt width, UInt height, UInt depth, const PixelFormat& format, UInt levelCount ) :
	VolumeTextureImpl<IVolumeTexture>( width, height, depth, format, levelCount ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr )
{
	HRESULT hr = S_OK;

	// Create texture.
	DXGI_FORMAT fmt = DxGi::Convert( format );
	D3D11_TEXTURE3D_DESC desc;
	desc.Width				= width;
	desc.Height				= height;
	desc.Depth				= depth;
	desc.MipLevels			= levelCount;
	desc.Format				= fmt;
	desc.Usage				= Dx11::Convert( usage );
	desc.BindFlags			= (levelCount != 1) ? (D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE) : D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= (levelCount != 1) ? D3D11_RESOURCE_MISC_GENERATE_MIPS : 0;
	if ( FAILED(hr = _context.Device()->CreateTexture3D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create volume texture.", String::Format(L"Width = {0}, Height = {1}, Depth = {2}, Pixel format = {3}", width, height, depth, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create resource view.
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	Zero( &srvDesc );
	srvDesc.Format						= fmt;
	srvDesc.ViewDimension				= D3D11_SRV_DIMENSION_TEXTURE3D;
	srvDesc.TextureCube.MipLevels		= levelCount;
	srvDesc.TextureCube.MostDetailedMip	= 0;
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, &srvDesc, &_srv)) )
		throw GraphicsException( L"Failed to create volume texture.", Dx11::ToString(hr) );

	// Retrieve the number of generated levels.
	_texture->GetDesc( &desc );
	_levelCount = desc.MipLevels;
}

Dx11VolumeTexture::~Dx11VolumeTexture()
{
	SafeRelease( _texture );
}

void Dx11VolumeTexture::GenerateLevels()
{
	Dx11ResourceImpl<Dx11Resource>::GenerateMipmaps();
}

Bool Dx11VolumeTexture::SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, UInt sliceStride, const PixelFormat& format, const Byte* data )
{
	assert( level < _levelCount );

	Dx11Lock( _context );
	UINT subres = D3D11CalcSubresource( level, element, _levelCount );
	_context->UpdateSubresource( _texture, subres, nullptr, data, stride, sliceStride );
	return true;
}


} // gfx


} // synkro
