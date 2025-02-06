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
// Purpose: DX11 primitive implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11PRIMITIVE_
#define _SYNKRO_GFX_DX11PRIMITIVE_


#include "config.h"
#include <gfx/PrimitiveImpl.h>
#include <gfx/IPrimitive.h>
#undef new
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 primitive implementation.
class Dx11Primitive :
	public PrimitiveImpl<IPrimitive>
{
public:
	// Constructor & destructor.
	Dx11Primitive( Dx11Context* context, IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency );
	~Dx11Primitive();

	// IPrimitive methods.
	UInt													Draw( UInt startElement, UInt elementCount, UInt startInstance, UInt instanceCount );
	UInt													Draw();
	void													Resize( UInt vertexCount, UInt indexCount, UInt instanceCount );

private:
	Dx11Context												_context;
	ID3D11InputLayout*										_layout;
	D3D11_PRIMITIVE_TOPOLOGY								_primitiveType;
	Bool													_first;
};


#include "Dx11Primitive.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PRIMITIVE_
