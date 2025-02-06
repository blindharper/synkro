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
// Purpose: 2D sound implementation.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUND2D_
#define _SYNKRO_SOUND_SOUND2D_


#include "config.h"
#include <core/ObjectImpl.h>
#include <sound/ISound2D.h>
#include <audio/IAudioSystemEx.h>
#include <audio/ISoundBuffer.h>
#include <audio/IAudioChunk.h>
#include <audio/IAudioPlayer.h>


namespace synkro
{


namespace sound
{


// 2D sound implementation.
class Sound2D :
	public core::ObjectImpl<ISound2D>
{
public:
	// Constructor.
	Sound2D( audio::IAudioSystemEx* audioSystem, ISoundCodec* codec, io::IStream* stream );

	// ISound methods.
	void													Play( Bool play );
	void													SetVolume( Int volume );
	Bool													IsPlaying() const;
	Int														GetVolume() const;
	Double													GetLength() const;

private:
	audio::IAudioPlayer*									_player;
	P(audio::ISoundBuffer)									_buffer;
	Double													_length;
};


#include "Sound2D.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUND2D_
