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
// Purpose: Logical sound buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDBUFFER_
#define _SYNKRO_AUDIO_SOUNDBUFFER_


#include "config.h"
#include "AudioBufferImpl.h"
#include <audio/ISoundBuffer.h>
#include "AudioChunk.h"
#include "BaseAudioPlayer.h"


namespace synkro
{


namespace audio
{


// Logical sound buffer.
class SoundBuffer :
	public AudioBufferImpl<ISoundBuffer, AudioChunk>
{
public:
	// Constructor & destructor.
	SoundBuffer( BaseAudioPlayer* player, ISoundBuffer* buffer );
	~SoundBuffer();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );
	void													GetFormat( sound::SoundFormat& format ) const;

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );
	void													SetReadPosition( UInt position );
	Int														GetPan() const;
	Int														GetAttenuation() const;
	UInt													GetFrequency() const;

private:
	BaseAudioPlayer*										_player;
	P(ISoundBuffer)											_buffer;
};


#include "SoundBuffer.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDBUFFER_
