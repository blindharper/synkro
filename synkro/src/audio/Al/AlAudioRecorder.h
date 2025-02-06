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
// Purpose: OpenAL recorder.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALAUDIORECORDER_
#define _SYNKRO_AUDIO_ALAUDIORECORDER_


#include "config.h"
#include <audio/AudioRecorderImpl.h>
#include <audio/IAudioRecorder.h>
#include "Al.h"
#include "Alc.h"


namespace synkro
{


namespace audio
{


// OpenAL recorder device.
class AlAudioRecorder :
	public AudioRecorderImpl<IAudioRecorder>
{
public:
	// Constructor & destructor.
	AlAudioRecorder( const sound::SoundFormat& format, const RecorderDesc& desc );
	~AlAudioRecorder();

	// IAudioRecorder methods.
	IVoiceBuffer*											CreateVoiceBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );

private:
	ALCdevice*												_device;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALAUDIORECORDER_
