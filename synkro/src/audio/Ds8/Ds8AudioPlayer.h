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
// Purpose: DirectSound 8 player.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8AUDIOPLAYER_
#define _SYNKRO_AUDIO_DS8AUDIOPLAYER_


#include "config.h"
#include <audio/AudioPlayerImpl.h>
#include <audio/IAudioPlayer.h>
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 player device.
class Ds8AudioPlayer :
	public AudioPlayerImpl<IAudioPlayer>
{
public:
	// Constructor & destructor.
	Ds8AudioPlayer( LPGUID guid, const sound::SoundFormat& format, HWND window, const PlayerDesc& desc );
	~Ds8AudioPlayer();

	// IAudioPlayer methods.
	ISoundBuffer*											CreateSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	ISoundEmitter*											CreateSoundEmitter( const sound::SoundFormat& format, Double length );

private:
	IDirectSound8*											_device;
	IDirectSoundBuffer*										_primaryBuffer;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8AUDIOPLAYER_
