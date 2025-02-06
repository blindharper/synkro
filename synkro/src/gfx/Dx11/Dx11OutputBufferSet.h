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
// Purpose: DX11 based output buffer set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11OUTPUTBUFFERSET_
#define _SYNKRO_GFX_DX11OUTPUTBUFFERSET_


#include "config.h"
#include <gfx/DataBufferSetImpl.h>
#include <gfx/IDataBufferSet.h>
#undef new
#include "Dx11.h"
#include "Dx11OutputBuffer.h"


namespace synkro
{


namespace gfx
{


// DX11 based output buffer set.
class Dx11OutputBufferSet :
	public DataBufferSetImpl<IDataBufferSet, Dx11OutputBuffer>
{
public:
	// Constructor.
	Dx11OutputBufferSet( Dx11Context* context );

	// IDataBufferSet methods.
	void													Bind();

	// Other methods.
	void													AddBuffer( Dx11OutputBuffer* buffer );

private:
	lang::Vector<ID3D11Buffer*>								_items;
	lang::Vector<UINT>										_offsets;
	Dx11Context												_context;
};


#include "Dx11OutputBufferSet.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11OUTPUTBUFFERSET_
