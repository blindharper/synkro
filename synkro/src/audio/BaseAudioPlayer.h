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
// Purpose: Base audio player.
//==============================================================================
#ifndef _SYNKRO_AUDIO_BASEAUDIOPLAYER_
#define _SYNKRO_AUDIO_BASEAUDIOPLAYER_


#include "config.h"


namespace synkro
{


namespace audio
{


// Base audio player.
class BaseAudioPlayer
{
public:
	virtual void											RemoveBuffer( ISoundBuffer* buffer ) = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_BASEAUDIOPLAYER_
