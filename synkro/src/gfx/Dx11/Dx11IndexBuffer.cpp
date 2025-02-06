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
// Purpose: Defines DX11 index buffer.
//==============================================================================
#include "config.h"
#include "Dx11IndexBuffer.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11IndexBuffer::Dx11IndexBuffer( Dx11Context* context, const DataUsage& usage, const DataAccess& access, const IndexType& type, UInt count ) :
	DataBufferImpl<IIndexBuffer>( usage, access, type.Size(), count ),
	_context( context ),
	_buffer( nullptr ),
	_type( DxGi::Convert(type) )
{
	Resize( count );
}

Dx11IndexBuffer::~Dx11IndexBuffer()
{
	Destroy();
}

Bool Dx11IndexBuffer::Map( const MapMode& mode )
{
	D3D11_MAPPED_SUBRESOURCE subRes;

	if ( _data != nullptr )
		return true;

	Dx11Lock( _context );
	return SUCCEEDED(_context->Map(_buffer, 0, Dx11::Convert(mode, true), 0, &subRes)) && (_data = (Byte*)subRes.pData);
}

Bool Dx11IndexBuffer::Unmap()
{
	if ( _data != nullptr )
	{
		Dx11Lock( _context );
		_context->Unmap( _buffer, 0 );
		_data = nullptr;
		return true;
	}
	return false;
}

void Dx11IndexBuffer::Resize( UInt count )
{
	Destroy();
	_size = count;

	D3D11_BUFFER_DESC desc;
	desc.ByteWidth		= _size*_stride;
	desc.Usage			= Dx11::Convert( _usage );
	desc.BindFlags		= D3D11_BIND_INDEX_BUFFER;
	desc.CPUAccessFlags	= Dx11::Convert( _access );
	desc.MiscFlags		= 0;

	HRESULT hr = S_OK;
	if ( FAILED(hr = _context.Device()->CreateBuffer(&desc, nullptr, &_buffer)) )
		throw GraphicsException( L"Failed to create index buffer.", String::Format(Str::CallFail, L"ID3D11Device::CreateBuffer()"), Dx11::ToString(hr) );
}

void Dx11IndexBuffer::Destroy()
{
	SafeRelease( _buffer );
}


} // gfx


} // synkro
