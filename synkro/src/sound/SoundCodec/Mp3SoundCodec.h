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
// Purpose: Mp3 sound codec.
//==============================================================================
#ifndef _SYNKRO_SOUND_MP3SOUNDCODEC_
#define _SYNKRO_SOUND_MP3SOUNDCODEC_


#include "config.h"
#include "SoundCodecImpl.h"
#include <sound/ISoundCodec.h>
#include <libmad/mad.h>


namespace synkro
{


namespace sound
{


// Mp3 sound codec.
class Mp3SoundCodec :
	public SoundCodecImpl<ISoundCodec>
{
public:
	// ISoundCodec methods.
	Double													Load( SoundCodecContext* context, SoundFormat& format );
	void													Save( SoundCodecContext* context, const SoundFormat& format );
	UInt													Decode( SoundCodecContext* context, Byte** data, UInt size );
	UInt													Encode( SoundCodecContext* context, const Byte* data, UInt size );

private:
	enum
	{
		BUFFER_SIZE = 4096,
	};

	struct Mp3Context
	{
		Mp3Context() :
			ChannelCount( 0 ),
			DataStart( 0 ),
			BufferLength( 0 ),
			TempLength( 0 ),
			Temp( nullptr )
		{
			Zero( Buffer, sizeof(Buffer) );
		}

		~Mp3Context()
		{
			if ( Temp != nullptr )
			{
				delete Temp;
			}
		}

		mad_synth	Synth;
		mad_stream	Stream;
		mad_frame	Frame;
		UInt		ChannelCount;
		UInt		DataStart;
		UInt		BufferLength;
		Byte		Buffer[BUFFER_SIZE];
		UInt		TempLength;
		Byte*		Temp;
	};

	UInt													Scale( mad_fixed_t sample );
	UInt													Read( SoundCodecContext* context, Byte* buffer, UInt size );
	Bool													ReadFrame( SoundCodecContext* context, UInt* size, UInt* sampleCount );
	Bool													ReadFrame( SoundCodecContext* context );
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_MP3SOUNDCODEC_
