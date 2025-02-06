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
// Purpose: OpenAL audio chunk.
//==============================================================================
SYNKRO_INLINE void AlAudioChunk::Write( const Byte* data, UInt size )
{
	assert( size <= _size );
	assert( !_processing );

	Al::BufferData( _chunk, _format, data, size, _frequency );
	_streaming ? Al::SourceQueueBuffers( _buffer, 1, &_chunk ) : Al::Sourcei( _buffer, AL_BUFFER, _chunk );
	_processing = true;
}

SYNKRO_INLINE void AlAudioChunk::Read( Byte* data, UInt size ) const
{
	assert( size <= _size );

	Copy( data, _data, size );
	_processing = false;
}

SYNKRO_INLINE Bool AlAudioChunk::IsProcessing() const
{
	return _processing;
}
