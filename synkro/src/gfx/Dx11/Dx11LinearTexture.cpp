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
// Purpose: DX11 linear texture implementation.
//==============================================================================
#include "config.h"
#include "Dx11LinearTexture.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11LinearTexture::Dx11LinearTexture( Dx11Context* context, const DataUsage& usage, UInt length, const PixelFormat& format, UInt levelCount, UInt elementCount ) :
	LinearTextureImpl<ILinearTexture>( length, format, levelCount, elementCount ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_texture( nullptr )
{
	HRESULT hr = S_OK;
	DXGI_FORMAT fmt = DxGi::Convert( format );

	// Create texture.
	D3D11_TEXTURE1D_DESC desc;
	desc.Width			= length;
	desc.MipLevels		= levelCount;
	desc.ArraySize		= elementCount;
	desc.Format			= fmt;
	desc.Usage			= Dx11::Convert( usage );
	desc.BindFlags		= (levelCount != 1) ? (D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE) : D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags	= (usage == DataUsage::Dynamic) ? D3D11_CPU_ACCESS_WRITE : 0;
	desc.MiscFlags		= (levelCount != 1) ? D3D11_RESOURCE_MISC_GENERATE_MIPS : 0;
	if ( FAILED(hr = _context.Device()->CreateTexture1D(&desc, nullptr, &_texture)) )
		throw GraphicsException( L"Failed to create linear texture.", String::Format(L"Length = {0}, Pixel format = {1}", length, DxGi::ToString(fmt)), Dx11::ToString(hr) );

	// Create resource view.
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_texture, nullptr, &_srv)) )
		throw GraphicsException( L"Failed to create linear texture.", Dx11::ToString(hr) );
}

Dx11LinearTexture::~Dx11LinearTexture()
{
	SafeRelease( _texture );
}

void Dx11LinearTexture::GenerateLevels()
{
	Dx11ResourceImpl<Dx11Resource>::GenerateMipmaps();
}

Bool Dx11LinearTexture::SetData( UInt element, UInt level, UInt length, const PixelFormat& format, const Byte* data )
{
	assert( level < _levelCount );

	Dx11Lock( _context );
	UINT subres = D3D10CalcSubresource( level, element, _levelCount );
	_context->UpdateSubresource( _texture, subres, nullptr, data, 0, 0 );
	return true;
}

void Dx11LinearTexture::Write( const Byte* data, UInt size )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _texture, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Byte>( (Byte*)subRes.pData, data, size );
		_context->Unmap( _texture, 0 );
	}
}


} // gfx


} // synkro
