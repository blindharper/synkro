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
// Purpose: Defines recorder description.
//==============================================================================
#ifndef _SYNKRO_AUDIO_RECORDERDESC_
#define _SYNKRO_AUDIO_RECORDERDESC_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace audio
{


/**
 * Recorder device description.
 */
class SYNKRO_API RecorderDesc
{
public:
	/** Creates recorder description with the specified properties. */
	RecorderDesc( const lang::String& name, UInt channelCount );

	/** Creates default recorder description. */
	RecorderDesc();

	/** User-friendly device name. */
	lang::String											Name;

	/** Total number of channels in the recorder. */
	UInt													ChannelCount;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_RECORDERDESC_
