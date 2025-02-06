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
// Purpose: OpenAL audio chunk.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALAUDIOCHUNK_
#define _SYNKRO_AUDIO_ALAUDIOCHUNK_


#include "config.h"
#include <audio/AudioChunkImpl.h>
#include <audio/IAudioChunk.h>
#include "Al.h"


namespace synkro
{


namespace audio
{


// OpenAL audio chunk.
class AlAudioChunk :
	public AudioChunkImpl<IAudioChunk>
{
public:
	// Constructors & destructor.
	AlAudioChunk( ALuint buffer, ALenum format, ALsizei frequency, Bool streaming, UInt size );
	AlAudioChunk( UInt size );
	~AlAudioChunk();

	// IAudioChunk methods.
	void													Write( const Byte* data, UInt size );
	void													Read( Byte* data, UInt size ) const;
	Bool													IsProcessing() const;

private:
	friend class AlSoundBuffer;
	friend class AlSoundEmitter;
	friend class AlVoiceBuffer;

	Byte*													_data;
	ALuint													_buffer;
	ALuint													_chunk;
	ALenum													_format;
	ALsizei													_frequency;
	Bool													_streaming;
	mutable Bool											_processing;
};


#include "AlAudioChunk.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALAUDIOCHUNK_
