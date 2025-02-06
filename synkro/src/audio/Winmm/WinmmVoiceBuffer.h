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
// Purpose: WinMM voice buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMVOICEBUFFER_
#define _SYNKRO_AUDIO_WINMMVOICEBUFFER_



#include "config.h"
#include <audio/VoiceBufferImpl.h>
#include <audio/IVoiceBuffer.h>
#include "WinmmAudioChunk.h"
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM voice buffer.
class WinmmVoiceBuffer :
	public VoiceBufferImpl<IVoiceBuffer, WinmmAudioChunk>
{
public:
	// Constructor.
	WinmmVoiceBuffer( HWAVEIN device, const sound::SoundFormat& format, Double length, UInt chunkCount );

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

private:
	HWAVEIN													_device;
	UInt													_chunkIndex;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMVOICEBUFFER_
