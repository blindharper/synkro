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
// Purpose: OpenAL sound listener implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALSOUNDLISTENER_
#define _SYNKRO_AUDIO_ALSOUNDLISTENER_


#include "config.h"
#include <audio/SoundListenerImpl.h>
#include <audio/ISoundListener.h>
#include "Al.h"


namespace synkro
{


namespace audio
{


// OpenAL sound listener.
class AlSoundListener :
	public SoundListenerImpl<ISoundListener>
{
public:
	// Constructors.
	AlSoundListener();
	AlSoundListener( const AlSoundListener& other );

	// ISoundListener methods.
	void													Bind();
	ISoundListener*											Clone() const;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALSOUNDLISTENER_
