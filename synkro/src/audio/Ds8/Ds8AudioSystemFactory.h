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
// Purpose: DirectSound 8 audio system factory.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8AUDIOSYSTEMFACTORY_
#define _SYNKRO_AUDIO_DS8AUDIOSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <audio/IAudioSystemFactory.h>
#include <audio/AudioSystem.h>
#include "Ds8AudioSystem.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 audio system factory.
SYNKRO_FACTORY_BEGIN( Ds8AudioSystemFactory, IAudioSystemFactory, AudioSystem, AudioSystem::DirectSound8 )
	IAudioSystem*	Create( const sound::SoundFormat& format, win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new Ds8AudioSystem(format, windowSystem, log); }
SYNKRO_FACTORY_END()


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8AUDIOSYSTEMFACTORY_
