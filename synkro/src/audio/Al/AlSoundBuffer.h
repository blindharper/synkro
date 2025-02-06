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
// Purpose: OpenAL sound buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALSOUNDBUFFER_
#define _SYNKRO_AUDIO_ALSOUNDBUFFER_


#include "config.h"
#include <audio/SoundBufferImpl.h>
#include <audio/ISoundBuffer.h>
#include "AlAudioChunk.h"
#include "Alc.h"
#include "Al.h"


namespace synkro
{


namespace audio
{


// OpenAL sound buffer.
class AlSoundBuffer :
	public SoundBufferImpl<ISoundBuffer, AlAudioChunk>
{
public:
	// Constructor & destructor.
	AlSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	~AlSoundBuffer();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );

private:
	ALuint													_buffer;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALSOUNDBUFFER_
