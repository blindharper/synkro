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
// Purpose: DX11 typed structured implementation.
//==============================================================================
#include "config.h"
#include "Dx11StructuredBuffer.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11StructuredBuffer::Dx11StructuredBuffer( Dx11Context* context, const DataUsage& usage, UInt stride, UInt count ) :
	StructuredBufferImpl<IStructuredBuffer>( stride, count ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_buffer( nullptr )
{
	HRESULT hr = S_OK;

	// Create buffer.
	D3D11_BUFFER_DESC desc;
	desc.ByteWidth				= stride*count;
	desc.Usage					= Dx11::Convert( usage );
	desc.BindFlags				= D3D10_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags			= (usage == DataUsage::Dynamic) ? D3D11_CPU_ACCESS_WRITE : 0;
	desc.MiscFlags				= D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
	desc.StructureByteStride	= stride;
	if ( FAILED(hr = _context.Device()->CreateBuffer(&desc, nullptr, &_buffer)) )
		throw GraphicsException( L"Failed to create structured buffer resource.", String::Format(Str::CallFail, L"ID3D11Device::CreateBuffer()"), Dx11::ToString(hr) );

	// Create resource view.
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc = {};
	viewDesc.Format					= DXGI_FORMAT_UNKNOWN;
	viewDesc.ViewDimension			= D3D11_SRV_DIMENSION_BUFFER;
	viewDesc.Buffer.FirstElement	= 0;
	viewDesc.Buffer.NumElements		= count;
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_buffer, &viewDesc, &_srv)) )
		throw GraphicsException( L"Failed to create structured buffer resource.", Dx11::ToString(hr) );
}

Dx11StructuredBuffer::~Dx11StructuredBuffer()
{
	SafeRelease( _buffer );
}

void Dx11StructuredBuffer::Set( const Byte* value, UInt size )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Byte>( (Byte*)subRes.pData, value, size );
		_context->Unmap( _buffer, 0 );
	}
}


} // gfx


} // synkro
