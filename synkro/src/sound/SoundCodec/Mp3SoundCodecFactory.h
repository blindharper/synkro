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
// Purpose: Mp3 sound codec factory.
//==============================================================================
#ifndef _SYNKRO_SOUND_MP3SOUNDCODECFACTORY_
#define _SYNKRO_SOUND_MP3SOUNDCODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <sound/ISoundCodecFactory.h>
#include <sound/SoundCodec.h>
#include "Mp3SoundCodec.h"


namespace synkro
{


namespace sound
{


// Mp3 sound codec factory.
SYNKRO_FACTORY_BEGIN( Mp3SoundCodecFactory, ISoundCodecFactory, SoundCodec, SoundCodec::Mp3 )
	ISoundCodec*	Create() { return new Mp3SoundCodec(); }
SYNKRO_FACTORY_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_MP3SOUNDCODECFACTORY_
