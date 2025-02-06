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
// Purpose: DirectSound 8 recorder.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8AUDIORECORDER_
#define _SYNKRO_AUDIO_DS8AUDIORECORDER_


#include "config.h"
#include <audio/AudioRecorderImpl.h>
#include <audio/IAudioRecorder.h>
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 recorder device.
class Ds8AudioRecorder :
	public AudioRecorderImpl<IAudioRecorder>
{
public:
	// Constructor & destructor.
	Ds8AudioRecorder( LPGUID guid, const sound::SoundFormat& format, const RecorderDesc& desc );
	~Ds8AudioRecorder();

	// IAudioRecorder methods.
	IVoiceBuffer*											CreateVoiceBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );

private:
	IDirectSoundCapture8*									_device;
	IDirectSoundBuffer*										_primaryBuffer;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8AUDIORECORDER_
