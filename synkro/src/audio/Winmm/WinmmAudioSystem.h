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
// Purpose: WinMM audio system.
//==============================================================================
#ifndef _SYNKRO_AUDIO_WINMMAUDIOSYSTEM_
#define _SYNKRO_AUDIO_WINMMAUDIOSYSTEM_


#include "config.h"
#include <audio/AudioSystemImpl.h>
#include <audio/IAudioSystem.h>
#include "Winmm.h"


namespace synkro
{


namespace audio
{


// WinMM audio system.
class WinmmAudioSystem :
	public AudioSystemImpl<IAudioSystem>
{
public:
	// Constructor & destuctor.
	WinmmAudioSystem( const sound::SoundFormat& format, diag::ILog* log );
	~WinmmAudioSystem();

	// IAudioSystem methods.
	IAudioPlayer*											CreatePlayer( UInt index );
	IAudioRecorder*											CreateRecorder( UInt index );

private:
	HMODULE													_dll;

	FARPROC													GetEntryPoint( const char* name );
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMMAUDIOSYSTEM_
