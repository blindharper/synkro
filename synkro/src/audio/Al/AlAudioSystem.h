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
// Purpose: OpenAL audio system.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALAUDIOSYSTEM_
#define _SYNKRO_AUDIO_ALAUDIOSYSTEM_


#include "config.h"
#include <audio/AudioSystemImpl.h>
#include <audio/IAudioSystem.h>
#include "Al.h"
#include "Alc.h"


namespace synkro
{


namespace audio
{


// OpenAL audio system.
class AlAudioSystem :
	public AudioSystemImpl<IAudioSystem>
{
public:
	// Constructor & destructor.
	AlAudioSystem( const sound::SoundFormat& format, diag::ILog* log );
	~AlAudioSystem();

	// IAudioSystem methods.
	IAudioPlayer*											CreatePlayer( UInt index );
	IAudioRecorder*											CreateRecorder( UInt index );

private:
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	HMODULE													_dll;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	void													InitGlue();
	void													InitCore();
	void*													GetFunction( const char* name );
	void*													GetExtension( const char* name );
	void													AddPlayer( const sound::SoundFormat& format, const ALchar* name );
	void													AddRecorder( const sound::SoundFormat& format, const ALchar* name );
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALAUDIOSYSTEM_
