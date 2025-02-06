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
// Purpose: Defines sound codec types.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUNDCODEC_
#define _SYNKRO_SOUND_SOUNDCODEC_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace sound
{


/**
 * Sound codec types.
 */
SYNKRO_ENUM_BEGIN( SoundCodec )
	/** Unknown sound codec. */
	SYNKRO_ENUM_CONST( SoundCodec, Unknown )

	/** Custom sound codec. */
	SYNKRO_ENUM_CONST( SoundCodec, Custom )

	/** Wave sound codec. */
	SYNKRO_ENUM_CONST( SoundCodec, Wav )

	/** Mp3 sound codec. */
	SYNKRO_ENUM_CONST( SoundCodec, Mp3 )

	/** Creates sound codec type from string. */
	SoundCodec( const lang::String& type );

	/** Converts sound codec type to string. */
	lang::String											ToString() const;

	/** Tests whether the given name has an extension corresponding to one of the sound codecs. */
	static Bool												IsValid( const lang::String& name );
SYNKRO_ENUM_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDCODEC_
