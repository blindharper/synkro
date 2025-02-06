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
#ifndef _SYNKRO_GFX_DX11OUTPUTBUFFER_
#define _SYNKRO_GFX_DX11OUTPUTBUFFER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IDataBuffer.h>
#undef new
#include <d3d11.h>
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 10 output buffer implementation.
class Dx11OutputBuffer :
	public core::ObjectImpl<IDataBuffer>
{
public:
	// Constructor & destructor.
	Dx11OutputBuffer( ID3D11Device* device, IDataFormat* format, UInt count );
	~Dx11OutputBuffer();

	// IDataBuffer methods.
	Bool													Map( const MapMode& mode );
	Bool													Unmap();
	void													Resize( UInt count );
	void													SetData( const Byte* data, UInt size, UInt offset, UInt start, UInt count );
	void													GetData( Byte* data, UInt size, UInt offset, UInt start, UInt count );
	UInt													GetStride() const;
	UInt													GetSize() const;

private:
	friend class Dx11OutputBufferSet;

	ID3D11Buffer*											_buffer;
	UInt													_stride;
	UInt													_size;
};


#include "Dx11OutputBuffer.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11OUTPUTBUFFER_
