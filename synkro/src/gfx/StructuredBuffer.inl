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
SYNKRO_INLINE void StructuredBuffer::Set( const Byte* value, UInt size )
{
	_buffer->Set( value, size );
}
