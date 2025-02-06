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
// Purpose: Logical player.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOPLAYER_
#define _SYNKRO_AUDIO_AUDIOPLAYER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/IAudioPlayer.h>
#include <audio/ISoundListener.h>
#include <lang/Vector.h>
#include "BaseAudioPlayer.h"


namespace synkro
{


namespace audio
{


// Logical player.
class AudioPlayer :
	public core::ObjectImpl<IAudioPlayer>,
	public BaseAudioPlayer
{
public:
	// Constructor.
	AudioPlayer( IAudioPlayer* player, UInt index );

	// IAudioPlayer methods.
	ISoundBuffer*											CreateSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount );
	ISoundEmitter*											CreateSoundEmitter( const sound::SoundFormat& format, Double length );
	void													GetFormat( sound::SoundFormat& format ) const;
	void													GetDesc( PlayerDesc& desc ) const;
	ISoundListener*											GetListener() const;

	// BaseAudioPlayer methods.
	void													RemoveBuffer( ISoundBuffer* buffer );

	// Other methods.
	void													Update();
	UInt													GetIndex() const;

private:
	lang::Vector<ISoundBuffer*>								_buffers;
	P(IAudioPlayer)											_player;
	P(ISoundListener)										_listener;
	UInt													_index;
};


#include "AudioPlayer.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOPLAYER_
