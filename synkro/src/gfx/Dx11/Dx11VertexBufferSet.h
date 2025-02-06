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
// Purpose: DX11 based vertex buffer set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11VERTEXBUFFERSET_
#define _SYNKRO_GFX_DX11VERTEXBUFFERSET_


#include "config.h"
#include <gfx/DataBufferSetImpl.h>
#include <gfx/IDataBufferSet.h>
#undef new
#include "Dx11.h"
#include "Dx11VertexBuffer.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 based vertex buffer set.
class Dx11VertexBufferSet :
	public DataBufferSetImpl<IDataBufferSet, Dx11VertexBuffer>
{
public:
	// Constructor.
	Dx11VertexBufferSet( Dx11Context* context );

	// IDataBufferSet methods.
	void													Bind();

	// Other methods.
	void													AddBuffer( Dx11VertexBuffer* buffer );
	void													UpdateBuffer( Dx11VertexBuffer* buffer );

private:
	lang::Vector<ID3D11Buffer*>								_items;
	lang::Vector<UINT>										_strides;
	lang::Vector<UINT>										_offsets;
	Dx11Context												_context;
};


#include "Dx11VertexBufferSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11VERTEXBUFFERSET_
