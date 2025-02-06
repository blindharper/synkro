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
// Purpose: WinMM sound buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMSOUNDBUFFER_
#define _SYNKRO_AUDIO_WINMMSOUNDBUFFER_


#include "config.h"
#include <audio/SoundBufferImpl.h>
#include <audio/ISoundBuffer.h>
#include "WinmmAudioChunk.h"
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM sound data buffer.
class WinmmSoundBuffer :
	public SoundBufferImpl<ISoundBuffer, WinmmAudioChunk>
{
public:
	// Constructor.
	WinmmSoundBuffer( HWAVEOUT device, const sound::SoundFormat& format, Double length, UInt chunkCount );

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );

private:
	HWAVEOUT												_device;
	UInt													_chunkIndex;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMSOUNDBUFFER_
