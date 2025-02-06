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
// Purpose: DX11 structured buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11STRUCTUREDBUFFER_
#define _SYNKRO_GFX_DX11STRUCTUREDBUFFER_


#include "config.h"
#include <gfx/StructuredBufferImpl.h>
#include <gfx/IStructuredBuffer.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 structured buffer implementation.
class Dx11StructuredBuffer :
	public StructuredBufferImpl<IStructuredBuffer>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11StructuredBuffer( Dx11Context* context, const DataUsage& usage, UInt stride, UInt count );
	~Dx11StructuredBuffer();

	// IStructuredBuffer methods.
	void													Set( const Byte* value, UInt size );

private:
	ID3D11Buffer*											_buffer;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11STRUCTUREDBUFFER_
