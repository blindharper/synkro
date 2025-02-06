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
// Purpose: DirectSound 8 sound listener implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8SOUNDLISTENER_
#define _SYNKRO_AUDIO_DS8SOUNDLISTENER_


#include "config.h"
#include <audio/SoundListenerImpl.h>
#include <audio/ISoundListener.h>
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 sound listener.
class Ds8SoundListener :
	public SoundListenerImpl<ISoundListener>
{
public:
	// Constructors.
	Ds8SoundListener( IDirectSoundBuffer* buffer );
	Ds8SoundListener( const Ds8SoundListener& other );

	// ISoundListener methods.
	void													Bind();
	ISoundListener*											Clone() const;

private:
	IDirectSound3DListener8*								_listener;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8SOUNDLISTENER_
