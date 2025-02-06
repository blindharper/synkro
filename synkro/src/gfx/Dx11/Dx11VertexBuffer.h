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
// Purpose: Defines DX11 vertex buffer.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11VERTEXBUFFER_
#define _SYNKRO_GFX_DX11VERTEXBUFFER_


#include "config.h"
#include <gfx/DataBufferImpl.h>
#include <gfx/IDataBuffer.h>
#undef new
#include "Dx11.h"
#include "Dx11Classes.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DX11 vertex buffer.
class Dx11VertexBuffer :
	public DataBufferImpl<IDataBuffer>
{
public:
	// Constructor & destructor.
	Dx11VertexBuffer( Dx11VertexBufferSet* set, Dx11Context* context, const DataUsage& usage, const DataAccess& access, UINT stride, UINT count );
	~Dx11VertexBuffer();

	// IDataBuffer methods.
	Bool													Map( const MapMode& mode );
	Bool													Unmap();
	void													Resize( UInt count );

private:
	friend class Dx11VertexBufferSet;

	Dx11VertexBufferSet*									_set;
	Dx11Context												_context;
	ID3D11Buffer*											_buffer;
	Bool													_update;

	void													Destroy();
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11VERTEXBUFFER_
