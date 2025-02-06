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
// Purpose: DX11 typed buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11TYPEDBUFFER_
#define _SYNKRO_GFX_DX11TYPEDBUFFER_


#include "config.h"
#include <gfx/TypedBufferImpl.h>
#include <gfx/ITypedBuffer.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 typed buffer implementation.
class Dx11TypedBuffer :
	public TypedBufferImpl<ITypedBuffer>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11TypedBuffer( Dx11Context* context, const DataUsage& usage, const ProgramDataType& dataType, UInt count );
	~Dx11TypedBuffer();

	// ITypedBuffer methods.
	void													Set( const Float* value, UInt count );
	void													Set( const math::Vector2* value, UInt count );
	void													Set( const math::Vector3* value, UInt count );
	void													Set( const math::Vector4* value, UInt count );
	void													Set( const math::Matrix4x4* value, UInt count );

private:
	ID3D11Buffer*											_buffer;

	DXGI_FORMAT												GetFormat( const ProgramDataType& dataType );
	UInt													GetElementFactor( const ProgramDataType& dataType );
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11TYPEDBUFFER_
