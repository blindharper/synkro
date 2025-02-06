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
// Purpose: Defines sound codec context.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUNDCODECCONTEXT_
#define _SYNKRO_SOUND_SOUNDCODECCONTEXT_


#include "config.h"


namespace synkro
{


namespace sound
{


/**
 * Sound codec context.
 */
class SYNKRO_API SoundCodecContext
{
public:
	/** Creates context with the given data stream and opens stream for reading or writing. */
	SoundCodecContext( io::IStream* stream, Bool write );

	/** Creates default context. */
	SoundCodecContext();

	/** Destroys context. */
	~SoundCodecContext();

	/** Data stream. */
	io::IStream*											Stream;

	/** Context-specific data. */
	Byte*													Data;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDCODECCONTEXT_
