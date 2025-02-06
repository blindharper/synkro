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
// Purpose: DX11 typed buffer implementation.
//==============================================================================
#include "config.h"
#include "Dx11TypedBuffer.h"
#include <gfx/Dx/DxGi.h>
#include "../ProgramDataTypeConst.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11TypedBuffer::Dx11TypedBuffer( Dx11Context* context, const DataUsage& usage, const ProgramDataType& dataType, UInt count ) :
	TypedBufferImpl<ITypedBuffer>( dataType, count ),
	Dx11ResourceImpl<Dx11Resource>( context ),
	_buffer( nullptr )
{
	HRESULT hr = S_OK;

	// Create buffer.
	D3D11_BUFFER_DESC desc;
	desc.ByteWidth		= count*dataType.Size();
	desc.Usage			= Dx11::Convert( usage );
	desc.BindFlags		= D3D10_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags	= (usage == DataUsage::Dynamic) ? D3D11_CPU_ACCESS_WRITE : 0;
	desc.MiscFlags		= 0;
	if ( FAILED(hr = _context.Device()->CreateBuffer(&desc, nullptr, &_buffer)) )
		throw GraphicsException( L"Failed to create typed buffer resource.", String::Format(Str::CallFail, L"ID3D11Device::CreateBuffer()"), Dx11::ToString(hr) );

	// Create resource view.
	D3D11_SHADER_RESOURCE_VIEW_DESC viewDesc = {};
	viewDesc.Format					= GetFormat( dataType );
	viewDesc.ViewDimension			= D3D11_SRV_DIMENSION_BUFFER;
	viewDesc.Buffer.ElementOffset	= 0;
	viewDesc.Buffer.ElementWidth	= count*GetElementFactor( dataType );
	if ( FAILED(hr = _context.Device()->CreateShaderResourceView(_buffer, &viewDesc, &_srv)) )
		throw GraphicsException( L"Failed to create typed buffer resource.", Dx11::ToString(hr) );
}

Dx11TypedBuffer::~Dx11TypedBuffer()
{
	SafeRelease( _buffer );
}

void Dx11TypedBuffer::Set( const Float* value, UInt count )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Float>( (Float*)subRes.pData, value, count );
		_context->Unmap( _buffer, 0 );
	}
}

void Dx11TypedBuffer::Set( const Vector2* value, UInt count )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Vector2>( (Vector2*)subRes.pData, value, count );
		_context->Unmap( _buffer, 0 );
	}
}

void Dx11TypedBuffer::Set( const Vector3* value, UInt count )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Vector3>( (Vector3*)subRes.pData, value, count );
		_context->Unmap( _buffer, 0 );
	}
}

void Dx11TypedBuffer::Set( const Vector4* value, UInt count )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Vector4>( (Vector4*)subRes.pData, value, count );
		_context->Unmap( _buffer, 0 );
	}
}

void Dx11TypedBuffer::Set( const Matrix4x4* value, UInt count )
{
	Dx11Lock( _context );
	D3D11_MAPPED_SUBRESOURCE subRes;
	HRESULT hr = _context->Map( _buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes );
	if ( SUCCEEDED(hr) )
	{
		Copy<Matrix4x4>( (Matrix4x4*)subRes.pData, value, count );
		_context->Unmap( _buffer, 0 );
	}
}

DXGI_FORMAT Dx11TypedBuffer::GetFormat( const ProgramDataType& dataType )
{
	switch ( dataType )
	{
		case PROGRAM_DATA_TYPE_BOOL:					return DXGI_FORMAT_R8_UINT;
		case PROGRAM_DATA_TYPE_INT:						return DXGI_FORMAT_R8_UINT;
		case PROGRAM_DATA_TYPE_FLOAT:					return DXGI_FORMAT_R32_FLOAT;
		case PROGRAM_DATA_TYPE_VECTOR2:					return DXGI_FORMAT_R32G32_FLOAT;
		case PROGRAM_DATA_TYPE_VECTOR3:					return DXGI_FORMAT_R32G32B32_FLOAT;
		case PROGRAM_DATA_TYPE_VECTOR4:					return DXGI_FORMAT_R32G32B32A32_FLOAT;
		case PROGRAM_DATA_TYPE_MATRIX3X3:				return DXGI_FORMAT_R32G32B32_FLOAT;
		case PROGRAM_DATA_TYPE_MATRIX4X4:				return DXGI_FORMAT_R32G32B32A32_FLOAT;
		case PROGRAM_DATA_TYPE_MATRIX4X4_TRANSPOSED:	return DXGI_FORMAT_R32G32B32A32_FLOAT;
	}

	return DXGI_FORMAT_UNKNOWN;
}

UInt Dx11TypedBuffer::GetElementFactor( const ProgramDataType& dataType )
{
	switch ( dataType )
	{
		case PROGRAM_DATA_TYPE_MATRIX3X3:				return 3;
		case PROGRAM_DATA_TYPE_MATRIX4X4:				return 4;
		case PROGRAM_DATA_TYPE_MATRIX4X4_TRANSPOSED:	return 4;
	}

	return 1;
}

} // gfx


} // synkro
