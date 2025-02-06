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
#ifndef _SYNKRO_GFX_DX11INDEXBUFFER_
#define _SYNKRO_GFX_DX11INDEXBUFFER_


#include "config.h"
#include <gfx/DataBufferImpl.h>
#include <gfx/IIndexBuffer.h>
#include <gfx/IndexType.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 index buffer.
class Dx11IndexBuffer :
	public DataBufferImpl<IIndexBuffer>
{
public:
	// Constructor & destructor.
	Dx11IndexBuffer( Dx11Context* context, const DataUsage& usage, const DataAccess& access, const IndexType& type, UInt count );
	~Dx11IndexBuffer();

	// IDataBuffer methods.
	Bool													Map( const MapMode& mode );
	Bool													Unmap();
	void													Resize( UInt count );

	// IIndexBuffer methods.
	void													Bind();

private:
	Dx11Context												_context;
	ID3D11Buffer*											_buffer;
	DXGI_FORMAT												_type;

	void													Destroy();
};


#include "Dx11IndexBuffer.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11INDEXBUFFER_
