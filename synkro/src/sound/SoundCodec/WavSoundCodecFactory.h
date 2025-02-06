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
// Purpose: Wav sound codec factory.
//==============================================================================
#ifndef _SYNKRO_SOUND_WAVSOUNDCODECFACTORY_
#define _SYNKRO_SOUND_WAVSOUNDCODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <sound/ISoundCodecFactory.h>
#include <sound/SoundCodec.h>
#include "WavSoundCodec.h"


namespace synkro
{


namespace sound
{


// Wav sound codec factory.
SYNKRO_FACTORY_BEGIN( WavSoundCodecFactory, ISoundCodecFactory, SoundCodec, SoundCodec::Wav )
	ISoundCodec*	Create() { return new WavSoundCodec(); }
SYNKRO_FACTORY_END()


} // sound


} // synkro


#endif // _SYNKRO_SOUND_WAVSOUNDCODECFACTORY_
