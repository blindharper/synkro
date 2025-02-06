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
// Purpose: OpenAL voice buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALVOICEBUFFER_
#define _SYNKRO_AUDIO_ALVOICEBUFFER_



#include "config.h"
#include <audio/VoiceBufferImpl.h>
#include <audio/IVoiceBuffer.h>
#include "AlAudioChunk.h"
#include "Alc.h"
#include <lang/Vector.h>


namespace synkro
{


namespace audio
{


// OpenAL voice buffer.
class AlVoiceBuffer :
	public VoiceBufferImpl<IVoiceBuffer, AlAudioChunk>
{
public:
	// Constructor.
	AlVoiceBuffer( ALCdevice* device, const sound::SoundFormat& format, Double length, UInt chunkCount );

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

private:
	lang::Vector<Byte>										_data;
	ALCdevice*												_device;
	ALCint													_sampleCapacity;
	UInt													_chunkIndex;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALVOICEBUFFER_
