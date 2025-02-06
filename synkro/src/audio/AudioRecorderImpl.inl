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
// Purpose: Generic recorder implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE AudioRecorderImpl<T>::AudioRecorderImpl( const sound::SoundFormat& format, const RecorderDesc& desc ) :
	_format( format ),
	_desc( desc )
{
}

template <class T>
SYNKRO_INLINE AudioRecorderImpl<T>::~AudioRecorderImpl()
{
}

template <class T>
SYNKRO_INLINE void AudioRecorderImpl<T>::GetDesc( RecorderDesc& desc ) const
{
	desc = _desc;
}
