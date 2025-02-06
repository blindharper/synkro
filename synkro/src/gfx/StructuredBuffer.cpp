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
#include "config.h"
#include "StructuredBuffer.h"


namespace synkro
{


namespace gfx
{


StructuredBuffer::StructuredBuffer( IStructuredBuffer* buffer ) :
	StructuredBufferImpl<IStructuredBuffer>( buffer->GetStride(), buffer->GetSize() ),
	_buffer( buffer )
{
	_resource = _buffer;
}


} // gfx


} // synkro
