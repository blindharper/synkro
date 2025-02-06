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
// Purpose: DirectSound 8 audio chunk.
//==============================================================================
SYNKRO_INLINE void Ds8AudioChunk::Write( const Byte* data, UInt size )
{
	assert( size <= _size );

	Byte* ptr;
	if ( _buffer->Map(_offset, size, &ptr) )
	{
		Copy( ptr, data, size );
		_buffer->Unmap( ptr, size );
	}
}

SYNKRO_INLINE void Ds8AudioChunk::Read( Byte* data, UInt size ) const
{
	assert( size <= _size );

	Byte* ptr;
	if ( _buffer->Map(_offset, size, &ptr) )
	{
		Copy( data, ptr, size );
		_buffer->Unmap( ptr, size );
	}
}
