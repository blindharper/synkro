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
// Purpose: WinMM audio recorder.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMAUDIORECORDER_
#define _SYNKRO_AUDIO_WINMMAUDIORECORDER_


#include "config.h"
#include <audio/AudioRecorderImpl.h>
#include <audio/IAudioRecorder.h>
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM audio recorder device.
class WinmmAudioRecorder :
	public AudioRecorderImpl<IAudioRecorder>
{
public:
	// Constructor & destructor.
	WinmmAudioRecorder( UINT_PTR id, const sound::SoundFormat& format, const RecorderDesc& desc );
	~WinmmAudioRecorder();

	// IAudioRecorder methods.
	IVoiceBuffer*											CreateVoiceBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );

private:
	HWAVEIN													_device;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMAUDIORECORDER_
