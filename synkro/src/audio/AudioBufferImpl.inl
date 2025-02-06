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
// Purpose: Generic audio buffer implementation.
//==============================================================================
template <class T, class C>
SYNKRO_INLINE AudioBufferImpl<T, C>::AudioBufferImpl( const sound::SoundFormat& format, UInt chunkCount ) :
	_chunks( A(P(C)), chunkCount ),
	_format( format ),
	_size( 0 )
{
}

template <class T, class C>
SYNKRO_INLINE AudioBufferImpl<T, C>::~AudioBufferImpl()
{
}

template <class T, class C>
SYNKRO_INLINE void AudioBufferImpl<T, C>::GetFormat( sound::SoundFormat& format ) const
{
	format = _format;
}

template <class T, class C>
SYNKRO_INLINE UInt AudioBufferImpl<T, C>::GetChunkCount() const
{
	return _chunks.Size();
}

template <class T, class C>
SYNKRO_INLINE IAudioChunk* AudioBufferImpl<T, C>::GetChunk( UInt index ) const
{
	assert( index < _chunks.Size() );

	if ( index >= _chunks.Size() )
		throw lang::OutOfRangeException( index, _chunks.Size() );

	return _chunks[index];
}

template <class T, class C>
SYNKRO_INLINE UInt AudioBufferImpl<T, C>::GetSize() const
{
	return _size;
}
