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
SYNKRO_INLINE void TypedBuffer::Set( const Float* value, UInt count )
{
	_buffer->Set( value, count );
}

SYNKRO_INLINE void TypedBuffer::Set( const math::Vector2* value, UInt count )
{
	_buffer->Set( value, count );
}

SYNKRO_INLINE void TypedBuffer::Set( const math::Vector3* value, UInt count )
{
	_buffer->Set( value, count );
}

SYNKRO_INLINE void TypedBuffer::Set( const math::Vector4* value, UInt count )
{
	_buffer->Set( value, count );
}

SYNKRO_INLINE void TypedBuffer::Set( const math::Matrix4x4* value, UInt count )
{
	_buffer->Set( value, count );
}
