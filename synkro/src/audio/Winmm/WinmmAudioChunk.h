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
// Purpose: WinMM audio chunk.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMAUDIOCHUNK_
#define _SYNKRO_AUDIO_WINMMAUDIOCHUNK_


#include "config.h"
#include <audio/AudioChunkImpl.h>
#include <audio/IAudioChunk.h>
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM audio chunk.
class WinmmAudioChunk :
	public AudioChunkImpl<IAudioChunk>
{
public:
	// Constructors & destructor.
	WinmmAudioChunk( HWAVEIN device, UInt offset, UInt size );
	WinmmAudioChunk( HWAVEOUT device, UInt offset, UInt size );
	~WinmmAudioChunk();

	// IAudioChunk methods.
	void													Write( const Byte* data, UInt size );
	void													Read( Byte* data, UInt size ) const;
	Bool													IsProcessing() const;

private:
	friend class WinmmSoundBuffer;
	friend class WinmmVoiceBuffer;

	HWAVEIN													_deviceIn;
	HWAVEOUT												_deviceOut;
	WAVEHDR													_chunk;
};


#include "WinmmAudioChunk.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMAUDIOCHUNK_
