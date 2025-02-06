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
// Purpose: WinMM sound listener implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMSOUNDLISTENER_
#define _SYNKRO_AUDIO_WINMMSOUNDLISTENER_


#include "config.h"
#include <audio/SoundListenerImpl.h>
#include <audio/ISoundListener.h>
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM sound listener.
class WinmmSoundListener :
	public SoundListenerImpl<ISoundListener>
{
public:
	// Constructor & destructor.
	WinmmSoundListener();
	~WinmmSoundListener();

	// ISoundListener methods.
	void													Bind();
	ISoundListener*											Clone() const;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMSOUNDLISTENER_
