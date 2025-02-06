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
// Purpose: DirectSound 8 voice buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8VOICEBUFFER_
#define _SYNKRO_AUDIO_DS8VOICEBUFFER_


#include "config.h"
#include <audio/VoiceBufferImpl.h>
#include <audio/IVoiceBuffer.h>
#include "Ds8BaseBuffer.h"
#include "Ds8AudioChunk.h"
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 voice buffer.
class Ds8VoiceBuffer :
	public VoiceBufferImpl<IVoiceBuffer, Ds8AudioChunk>,
	public Ds8BaseBuffer
{
public:
	// Constructor & destructor.
	Ds8VoiceBuffer( IDirectSoundCapture8* device, const sound::SoundFormat& format, Double length, UInt chunkCount );
	~Ds8VoiceBuffer();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// IVoiceBuffer methods.
	void													SuppressEcho( Bool suppress );
	void													SuppressNoise( Bool suppress );

	// Ds8BaseBuffer methods.
	Bool													Map( UInt offset, UInt size, Byte** data );
	Bool													Unmap( Byte* data, UInt size );
	void													GetPosition( UInt* read, UInt* write ) const;

private:
	IDirectSoundCaptureBuffer8*								_buffer;
	IDirectSoundCaptureFXAec8*								_effectEcho;
	IDirectSoundCaptureFXNoiseSuppress8*					_effectNoise;
	void*													_ptr1;
	DWORD													_bytes1;
	void*													_ptr2;
	DWORD													_bytes2;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8VOICEBUFFER_
