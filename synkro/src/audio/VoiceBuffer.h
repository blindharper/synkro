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
// Purpose: Logical voice buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_VOICEBUFFER_
#define _SYNKRO_AUDIO_VOICEBUFFER_


#include "config.h"
#include "AudioBufferImpl.h"
#include <audio/IVoiceBuffer.h>
#include "AudioChunk.h"
#include "BaseAudioRecorder.h"


namespace synkro
{


namespace audio
{


// Logical voice buffer.
class VoiceBuffer :
	public AudioBufferImpl<IVoiceBuffer, AudioChunk>
{
public:
	// Constructor & destructor.
	VoiceBuffer( BaseAudioRecorder* recorder, IVoiceBuffer* buffer );
	~VoiceBuffer();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );
	void													GetFormat( sound::SoundFormat& format ) const;

	// IVoiceBuffer methods.
	void													SuppressEcho( Bool suppress );
	void													SuppressNoise( Bool suppress );
	Bool													IsEchoSuppressed() const;
	Bool													IsNoiseSuppressed() const;

private:
	BaseAudioRecorder*										_recorder;
	P(IVoiceBuffer)											_buffer;
};


#include "VoiceBuffer.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_VOICEBUFFER_
