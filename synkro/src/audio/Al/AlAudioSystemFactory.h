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
// Purpose: OpenAL audio system factory.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALAUDIOSYSTEMFACTORY_
#define _SYNKRO_AUDIO_ALAUDIOSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <audio/IAudioSystemFactory.h>
#include <audio/AudioSystem.h>
#include "AlAudioSystem.h"


namespace synkro
{


namespace audio
{


// OpenAL audio system factory.
SYNKRO_FACTORY_BEGIN( AlAudioSystemFactory, IAudioSystemFactory, AudioSystem, AudioSystem::OpenAL )
	IAudioSystem*	Create( const sound::SoundFormat& format, win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new AlAudioSystem(format, log); }
SYNKRO_FACTORY_END()


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALAUDIOSYSTEMFACTORY_
