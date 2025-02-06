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
// Purpose: Logical audio buffer chunk.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOCHUNK_
#define _SYNKRO_AUDIO_AUDIOCHUNK_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/IAudioChunk.h>


namespace synkro
{


namespace audio
{


// Audio buffer chunk.
class AudioChunk :
	public core::ObjectImpl<IAudioChunk>
{
public:
	// Constructor.
	AudioChunk( IAudioChunk* chunk, Bool readonly );

	// IAudioChunk methods.
	void													Write( const Byte* data, UInt size );
	void													Read( Byte* data, UInt size ) const;
	UInt													GetSize() const;
	Bool													IsProcessing() const;

private:
	P(IAudioChunk)											_chunk;
	Bool													_readonly;
};


#include "AudioChunk.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOCHUNK_
