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
// Purpose: Defines player description.
//==============================================================================
#ifndef _SYNKRO_AUDIO_PLAYERDESC_
#define _SYNKRO_AUDIO_PLAYERDESC_


#include "config.h"
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Player device description.
 */
class SYNKRO_API PlayerDesc
{
public:
	/** Creates player description with the specified properties. */
	PlayerDesc( const lang::String& name, const sound::SoundFormat& format, UInt memorySize );

	/** Creates default player description. */
	PlayerDesc();

	/** User-friendly device name. */
	lang::String											Name;

	/** Device's native output format. */
	sound::SoundFormat										Format;

	/** The amount of memory on the sound card, in bytes. */
	UInt													MemorySize;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_PLAYERDESC_
