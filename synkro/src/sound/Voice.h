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
// Purpose: Voice implementation.
//==============================================================================
#ifndef _SYNKRO_SOUND_VOICE_
#define _SYNKRO_SOUND_VOICE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <sound/IVoice.h>
#include <sound/ISoundCodec.h>
#include <audio/IVoiceBuffer.h>
#include <audio/IAudioChunk.h>
#include <audio/IAudioRecorder.h>
#include <audio/IAudioSystem.h>
#include <sound/SoundCodecContext.h>
#include <io/IStream.h>
#include <lang/Vector.h>
#include "BaseSoundManager.h"


namespace synkro
{


namespace sound
{


// Voice implementation.
class Voice :
	public core::ObjectImpl<IVoice>,
	public BaseVoice
{
public:
	// Constructor & destructor.
	Voice( BaseSoundManager* soundManager, audio::IAudioRecorder* recorder, ISoundCodec* codec, io::IStream* stream, const SoundFormat& format );
	~Voice();

	// IVoice methods.
	void													Record( Bool record );
	Bool													IsRecording() const;
	Double													GetLength() const;

	// BaseVoice methods.
	void													Update();

private:
	lang::Vector<Byte>										_data;
	BaseSoundManager*										_soundManager;
	SoundCodecContext*										_soundContext;
	P(audio::IAudioRecorder)								_recorder;
	P(audio::IVoiceBuffer)									_buffer;
	P(io::IStream)											_stream;
	ISoundCodec*											_codec;
	Double													_length;
	Bool													_recording;
	UInt													_chunkIndex;
	UInt													_bytesPerSecond;
};


#include "Voice.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_VOICE_
