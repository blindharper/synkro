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
// Purpose: DX11 output buffer implementation.
//==============================================================================
#include "config.h"
#include "Dx11OutputBuffer.h"
#include "Dx11.h"
#include <gfx/GraphicsException.h>
#include <gfx/IProgramStage.h>
#include <gfx/IDataFormat.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11OutputBuffer::Dx11OutputBuffer( ID3D11Device* device, IDataFormat* format, UInt count ) :
	_buffer( nullptr ),
	_stride( 0 ),
	_size( count )
{
	HRESULT hr = S_OK;

	// Calculate vertex size.
	UInt vertexSize = 0;
	for ( UInt i = 0; i < format->GetVertexStreamCount(); ++i )
	{
		vertexSize += format->GetVertexStreamDataType( i ).Size();
	}

	// Create buffer.
	D3D11_BUFFER_DESC desc;
	desc.ByteWidth		= _size*_stride;
	desc.Usage			= D3D11_USAGE_DEFAULT;
	desc.BindFlags		= D3D11_BIND_STREAM_OUTPUT | D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags	= 0;
	desc.MiscFlags		= 0;
	if ( FAILED(hr = device->CreateBuffer(&desc, nullptr, &_buffer)) )
		throw GraphicsException( L"Failed to create output buffer.", Dx11::ToString(hr) );
}

Dx11OutputBuffer::~Dx11OutputBuffer()
{
	SafeRelease( _buffer );
}


} // gfx


} // synkro
