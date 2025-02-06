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
// Purpose: DirectSound 8 audio chunk.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8AUDIOCHUNK_
#define _SYNKRO_AUDIO_DS8AUDIOCHUNK_


#include "config.h"
#include <audio/AudioChunkImpl.h>
#include <audio/IAudioChunk.h>
#include "Ds8BaseBuffer.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 audio chunk.
class Ds8AudioChunk :
	public AudioChunkImpl<IAudioChunk>
{
public:
	// Constructor.
	Ds8AudioChunk( Ds8BaseBuffer* buffer, UInt offset, UInt size );

	// IAudioChunk methods.
	void													Write( const Byte* data, UInt size );
	void													Read( Byte* data, UInt size ) const;
	Bool													IsProcessing() const;

private:
	Ds8BaseBuffer*											_buffer;
	UInt													_offset;
};


#include "Ds8AudioChunk.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8AUDIOCHUNK_
