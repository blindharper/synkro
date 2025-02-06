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
// Purpose: DX11 cube texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11CubeTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11CubeTexture::Dx11CubeTexture( Dx11Context* context, const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount ) :
	CubeTextureImpl<ICubeTexture>( length, format, levelCount ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr )
{
	HRESULT hr = S_OK;

	// Create texture.
	DXGI_FORMAT fmt = DxGi::Convert( format );
	D3D11_TEXTURE2D_DESC desc;
	desc.Width				= length;
	desc.Height				= length;
	desc.MipLevels			= levelCount;
	desc.ArraySize			= 6;
	desc.Format				= fmt;
	desc.SampleDesc.Count	= 1;
	desc.SampleDesc.Quality	= 0;
	desc.Usage				= Dx11::Convert( usage );
	desc.BindFlags			= (levelCount != 1) ? (D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE) : D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags		= 0;
	desc.MiscFlags			= (levelCount != 1) ? D3D11_RESOURCE_MISC_GENERATE_MIPS : D3D11_RESOURCE_MISC_TEXTURECUBE;
	if ( FAILED(hr = _context.Device()->CreateTexture2D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create cube texture.", String::Format(L"Edge length = {0}, Pixel format = {1}", length, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create resource view.
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, nullptr, &_srv)) )
		throw GraphicsException( L"Failed to create cube texture.", Dx11::ToString(hr) );

	// Retrieve the number of generated levels.
	_texture->GetDesc( &desc );
	_levelCount = desc.MipLevels;
}

Dx11CubeTexture::~Dx11CubeTexture()
{
	SafeRelease( _texture );
}

void Dx11CubeTexture::GenerateLevels()
{
	Dx11ResourceImpl<Dx11Resource>::GenerateMipmaps();
}

Bool Dx11CubeTexture::SetData( const CubeFace& face, UInt level, UInt length, UInt stride, const PixelFormat& format, const Byte* data )
{
	assert( level < _levelCount );

	Dx11Lock( _context );
	UINT subres = D3D11CalcSubresource( level, face, _levelCount );
	_context->UpdateSubresource( _texture, subres, nullptr, data, stride, 0 );
	return true;
}


} // gfx


} // synkro
