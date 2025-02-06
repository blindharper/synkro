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
#ifndef _SYNKRO_AUDIO_VOICEBUFFERIMPL_
#define _SYNKRO_AUDIO_VOICEBUFFERIMPL_


#include "config.h"
#include "AudioBufferImpl.h"


namespace synkro
{


namespace audio
{


// Generic voice buffer implementation.
template <class T, class C>
class VoiceBufferImpl :
	public AudioBufferImpl<T, C>
{
public:
	// Constructor & destructor.
	VoiceBufferImpl( const sound::SoundFormat& format, UInt chunkCount, Bool suppressEcho, Bool suppressNoise );
	virtual ~VoiceBufferImpl();

	// IVoiceBuffer methods.
	virtual void											SuppressEcho( Bool suppress );
	virtual void											SuppressNoise( Bool suppress );
	virtual Bool											IsEchoSuppressed() const;
	virtual Bool											IsNoiseSuppressed() const;

protected:
	Bool													_suppressEcho;
	Bool													_suppressNoise;
};


#include "VoiceBufferImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_VOICEBUFFERIMPL_
