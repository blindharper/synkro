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
// Purpose: Generic voice buffer implementation.
//==============================================================================
template <class T, class C>
SYNKRO_INLINE VoiceBufferImpl<T, C>::VoiceBufferImpl( const sound::SoundFormat& format, UInt chunkCount, Bool suppressEcho, Bool suppressNoise ) :
	AudioBufferImpl<T, C>( format, chunkCount ),
	_suppressEcho( suppressEcho ),
	_suppressNoise( suppressNoise )
{
}

template <class T, class C>
SYNKRO_INLINE VoiceBufferImpl<T, C>::~VoiceBufferImpl()
{
}

template <class T, class C>
SYNKRO_INLINE void VoiceBufferImpl<T, C>::SuppressEcho( Bool suppress )
{
	_suppressEcho = suppress;
}

template <class T, class C>
SYNKRO_INLINE void VoiceBufferImpl<T, C>::SuppressNoise( Bool suppress )
{
	_suppressNoise = suppress;
}

template <class T, class C>
SYNKRO_INLINE Bool VoiceBufferImpl<T, C>::IsEchoSuppressed() const
{
	return _suppressEcho;
}

template <class T, class C>
SYNKRO_INLINE Bool VoiceBufferImpl<T, C>::IsNoiseSuppressed() const
{
	return _suppressNoise;
}
