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
// Purpose: Defines DX12 index buffer.
//==============================================================================
#include "config.h"
#include "Dx12IndexBuffer.h"
#include <gfx/Dx/DxGi.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx12IndexBuffer::Dx12IndexBuffer( ID3D12Device* device, ID3D12GraphicsCommandList* commandList, const DataUsage& usage, const DataAccess& access, const IndexType& type, UInt count ) :
	DataBufferImpl<IIndexBuffer>( usage, access, type.Size(), count ),
	_device( device ),
	_commandList( commandList ),
	_buffer( nullptr ),
	_type( DxGi::Convert(type) )
{
	Resize( count );
}

Dx12IndexBuffer::~Dx12IndexBuffer()
{
	Destroy();
}

Bool Dx12IndexBuffer::Map( const MapMode& mode )
{
	if ( _data != nullptr )
		return true;

	D3D12_RANGE range = {};
	range.Begin	= 0;
	range.End	= 0;
	return SUCCEEDED( _buffer->Map(0, &range, reinterpret_cast<void**>(&_data)) );
}

Bool Dx12IndexBuffer::Unmap()
{
	if ( _data != nullptr )
	{
		_buffer->Unmap( 0, nullptr );
		_bufferView.BufferLocation	= _buffer->GetGPUVirtualAddress();
		_bufferView.Format			= _type;
		_bufferView.SizeInBytes		= _size*_stride;
		_data = nullptr;
		return true;
	}
	return false;
}

void Dx12IndexBuffer::Resize( UInt count )
{
	Destroy();
	_size = count;

	D3D12_HEAP_PROPERTIES props = {};
	props.Type					= D3D12_HEAP_TYPE_DEFAULT;
	props.CPUPageProperty		= D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	props.MemoryPoolPreference	= D3D12_MEMORY_POOL_UNKNOWN;
	props.CreationNodeMask		= 1;
	props.VisibleNodeMask		= 1;

	D3D12_RESOURCE_DESC desc = {};
	desc.Dimension			= D3D12_RESOURCE_DIMENSION_BUFFER;
	desc.Alignment			= 0;
	desc.Width				= _size;
	desc.Height				= 1;
	desc.DepthOrArraySize	= 1;
	desc.MipLevels			= 1;
	desc.Format				= DXGI_FORMAT_UNKNOWN;
	desc.SampleDesc.Count	= 1;
	desc.SampleDesc.Quality	= 0;
	desc.Layout				= D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	desc.Flags				= D3D12_RESOURCE_FLAG_NONE;

	HRESULT hr = S_OK;
	if ( FAILED(hr = _device->CreateCommittedResource(&props, D3D12_HEAP_FLAG_NONE, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&_buffer))) )
		throw GraphicsException( L"Failed to create index buffer.", String::Format(Str::CallFail, L"ID3D12Device::CreateCommittedResource()"), Dx12::ToString(hr) );
}

void Dx12IndexBuffer::Destroy()
{
	SafeRelease( _buffer );
}


} // gfx


} // synkro
