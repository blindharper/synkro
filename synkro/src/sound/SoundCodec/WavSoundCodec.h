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
// Purpose: Wav sound codec.
//==============================================================================
#ifndef _SYNKRO_SOUND_WAVSOUNDCODEC_
#define _SYNKRO_SOUND_WAVSOUNDCODEC_


#include "config.h"
#include "SoundCodecImpl.h"
#include <sound/ISoundCodec.h>


namespace synkro
{


namespace sound
{


// Wav sound codec.
class WavSoundCodec :
	public SoundCodecImpl<ISoundCodec>
{
public:
	// ISoundCodec methods.
	Double													Load( SoundCodecContext* context, SoundFormat& format );
	void													Save( SoundCodecContext* context, const SoundFormat& format );
	UInt													Decode( SoundCodecContext* context, Byte** data, UInt size );
	UInt													Encode( SoundCodecContext* context, const Byte* data, UInt size );

private:
	struct WavContext
	{
		WavContext() :
			DataStart( 0 )
		{
		}

		UInt DataStart;
	};
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_WAVSOUNDCODEC_
