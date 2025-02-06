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
// Purpose: Generic player implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE AudioPlayerImpl<T>::AudioPlayerImpl( const sound::SoundFormat& format, const PlayerDesc& desc ) :
	_format( format ),
	_desc( desc )
{
}

template <class T>
SYNKRO_INLINE AudioPlayerImpl<T>::~AudioPlayerImpl()
{
}

template <class T>
SYNKRO_INLINE void AudioPlayerImpl<T>::GetFormat( sound::SoundFormat& format ) const
{
	format = _format;
}

template <class T>
SYNKRO_INLINE void AudioPlayerImpl<T>::GetDesc( PlayerDesc& desc ) const
{
	desc = _desc;
}

template <class T>
SYNKRO_INLINE ISoundListener* AudioPlayerImpl<T>::GetListener() const
{
	return _listener;
}
