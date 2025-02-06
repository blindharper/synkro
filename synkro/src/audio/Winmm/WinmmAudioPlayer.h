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
// Purpose: WinMM audio player.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMAUDIOPLAYER_
#define _SYNKRO_AUDIO_WINMMAUDIOPLAYER_


#include "config.h"
#include <audio/AudioPlayerImpl.h>
#include <audio/IAudioPlayer.h>
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM audio player device.
class WinmmAudioPlayer :
	public AudioPlayerImpl<IAudioPlayer>
{
public:
	// Constructor & destructor.
	WinmmAudioPlayer( UINT_PTR id, const sound::SoundFormat& format, const PlayerDesc& desc );
	~WinmmAudioPlayer();

	// IAudioPlayer methods.
	ISoundBuffer*											CreateSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	ISoundEmitter*											CreateSoundEmitter( const sound::SoundFormat& format, Double length );

private:
	HWAVEOUT												_device;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMAUDIOPLAYER_
