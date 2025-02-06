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
// Purpose: DirectSound 8 sound buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8SOUNDBUFFER_
#define _SYNKRO_AUDIO_DS8SOUNDBUFFER_


#include "config.h"
#include <audio/SoundBufferImpl.h>
#include <audio/ISoundBuffer.h>
#include "Ds8BaseBuffer.h"
#include "Ds8AudioChunk.h"
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 sound buffer.
class Ds8SoundBuffer :
	public SoundBufferImpl<ISoundBuffer, Ds8AudioChunk>,
	public Ds8BaseBuffer
{
public:
	// Constructor & destructor.
	Ds8SoundBuffer( IDirectSound8* device, const sound::SoundFormat& format, Double length, UInt chunkCount );
	~Ds8SoundBuffer();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );

	// Ds8BaseBuffer methods.
	Bool													Map( UInt offset, UInt size, Byte** data );
	Bool													Unmap( Byte* data, UInt size );
	void													GetPosition( UInt* read, UInt* write ) const;

private:
	IDirectSoundBuffer8*									_buffer;
	void*													_ptr1;
	DWORD													_bytes1;
	void*													_ptr2;
	DWORD													_bytes2;
};


#include "Ds8SoundBuffer.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8SOUNDBUFFER_
