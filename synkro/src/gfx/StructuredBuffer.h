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
// Purpose: Logical structured buffer resource.
//==============================================================================
#ifndef _SYNKRO_GFX_STRUCTUREDBUFFER_
#define _SYNKRO_GFX_STRUCTUREDBUFFER_


#include "config.h"
#include "BaseResourceImpl.h"
#include "BaseResource.h"
#include "StructuredBufferImpl.h"
#include <gfx/IStructuredBuffer.h>


namespace synkro
{


namespace gfx
{


// Logical structured buffer resource.
class StructuredBuffer :
	public StructuredBufferImpl<IStructuredBuffer>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	StructuredBuffer( IStructuredBuffer* buffer );

	// IStructuredBuffer methods.
	void													Set( const Byte* value, UInt size );

private:
	P(IStructuredBuffer)									_buffer;
};


#include "StructuredBuffer.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_STRUCTUREDBUFFER_
