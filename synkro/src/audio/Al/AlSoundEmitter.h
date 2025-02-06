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
// Purpose: OpenAL sound emitter.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALSOUNDEMITTER_
#define _SYNKRO_AUDIO_ALSOUNDEMITTER_


#include "config.h"
#include <audio/SoundEmitterImpl.h>
#include <audio/ISoundEmitter.h>
#include "AlAudioChunk.h"
#include "Alc.h"


namespace synkro
{


namespace audio
{


// OpenAL sound emitter.
class AlSoundEmitter :
	public SoundEmitterImpl<ISoundEmitter, AlAudioChunk>
{
public:
	// Constructor & destructor.
	AlSoundEmitter( ALCdevice* device, const sound::SoundFormat& format, Double length );
	~AlSoundEmitter();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );

	// ISoundEmitter methods.
	void													Bind();

private:
	ALuint													_emitter;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALSOUNDEMITTER_
