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
#ifndef _SYNKRO_GFX_DX12INDEXBUFFER_
#define _SYNKRO_GFX_DX12INDEXBUFFER_


#include "config.h"
#include <gfx/DataBufferImpl.h>
#include <gfx/IIndexBuffer.h>
#include <gfx/IndexType.h>
#undef new
#include "Dx12.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX12 index buffer.
class Dx12IndexBuffer :
	public DataBufferImpl<IIndexBuffer>
{
public:
	// Constructor & destructor.
	Dx12IndexBuffer( ID3D12Device* device, ID3D12GraphicsCommandList* commandList, const DataUsage& usage, const DataAccess& access, const IndexType& type, UInt count );
	~Dx12IndexBuffer();

	// IDataBuffer methods.
	Bool													Map( const MapMode& mode );
	Bool													Unmap();
	void													Resize( UInt count );

	// IIndexBuffer methods.
	void													Bind();

private:
	ID3D12Device*											_device;
	ID3D12GraphicsCommandList*								_commandList;
	ID3D12Resource*											_buffer;
	D3D12_INDEX_BUFFER_VIEW									_bufferView;
	DXGI_FORMAT												_type;

	void													Destroy();
};


#include "Dx12IndexBuffer.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX12INDEXBUFFER_
