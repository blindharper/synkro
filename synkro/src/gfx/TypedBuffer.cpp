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
// Purpose: Logical typed buffer resource.
//==============================================================================
#include "config.h"
#include "TypedBuffer.h"


namespace synkro
{


namespace gfx
{


TypedBuffer::TypedBuffer( ITypedBuffer* buffer ) :
	TypedBufferImpl<ITypedBuffer>( buffer->GetDataType(), buffer->GetSize() ),
	_buffer( buffer )
{
	_resource = _buffer;
}


} // gfx


} // synkro
