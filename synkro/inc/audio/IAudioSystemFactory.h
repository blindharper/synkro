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
// Purpose: Defines audio system factory.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOSYSTEMFACTORY_
#define _SYNKRO_AUDIO_IAUDIOSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Audio system factory.
 */
iface IAudioSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates audio system.
	 * @param format Sound format.
	 * @param windowSystem Window system.
	 * @param log Log to write debug messages to.
	 * @return Created audio system.
	 */
	virtual IAudioSystem*									Create( const sound::SoundFormat& format, win::IWindowSystemEx* windowSystem, diag::ILog* log ) = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOSYSTEMFACTORY_
