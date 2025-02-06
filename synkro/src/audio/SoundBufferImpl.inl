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
// Purpose: Generic sound buffer implementation.
//==============================================================================
template <class T, class C>
SYNKRO_INLINE SoundBufferImpl<T, C>::SoundBufferImpl( const sound::SoundFormat& format, UInt chunkCount ) :
	AudioBufferImpl<T, C>( format, chunkCount ),
	_dirty( true ),
	_pan( 0 ),
	_attenuation( 0 ),
	_frequency( 1 )
{
}

template <class T, class C>
SYNKRO_INLINE SoundBufferImpl<T, C>::~SoundBufferImpl()
{
}

template <class T, class C>
SYNKRO_INLINE void SoundBufferImpl<T, C>::SetPan( Int pan )
{
	if ( pan != _pan )
	{
		_pan = pan;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundBufferImpl<T, C>::SetAttenuation( Int attenuation )
{
	if ( attenuation != _attenuation )
	{
		_attenuation = attenuation;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundBufferImpl<T, C>::SetFrequency( UInt frequency )
{
	if ( frequency != _frequency )
	{
		_frequency = frequency;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE Int SoundBufferImpl<T, C>::GetPan() const
{
	return _pan;
}

template <class T, class C>
SYNKRO_INLINE Int SoundBufferImpl<T, C>::GetAttenuation() const
{
	return _attenuation;
}

template <class T, class C>
SYNKRO_INLINE UInt SoundBufferImpl<T, C>::GetFrequency() const
{
	return _frequency;
}
