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
// Purpose: OpenAL player.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALAUDIOPLAYER_
#define _SYNKRO_AUDIO_ALAUDIOPLAYER_


#include "config.h"
#include <audio/AudioPlayerImpl.h>
#include <audio/IAudioPlayer.h>
#include "Al.h"
#include "Alc.h"


namespace synkro
{


namespace audio
{


// OpenAL player device.
class AlAudioPlayer :
	public AudioPlayerImpl<IAudioPlayer>
{
public:
	// Constructor & destructor.
	AlAudioPlayer( const sound::SoundFormat& format, const PlayerDesc& desc );
	~AlAudioPlayer();

	// IAudioPlayer methods.
	ISoundBuffer*											CreateSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	ISoundEmitter*											CreateSoundEmitter( const sound::SoundFormat& format, Double length );

private:
	ALCcontext*												_context;
	ALCdevice*												_device;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALAUDIOPLAYER_
