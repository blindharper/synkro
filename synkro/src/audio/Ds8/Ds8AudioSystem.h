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
// Purpose: DirectSound 8 audio system.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8AUDIOSYSTEM_
#define _SYNKRO_AUDIO_DS8AUDIOSYSTEM_


#include "config.h"
#include <audio/AudioSystemImpl.h>
#include <audio/IAudioSystem.h>
#include <internal/ComInitializer.h>


namespace synkro
{


namespace audio
{


// DirectSound 8 audio system.
class Ds8AudioSystem :
	public AudioSystemImpl<IAudioSystem>
{
public:
	// Constructor & destructor.
	Ds8AudioSystem( const sound::SoundFormat& format, win::IWindowSystemEx* windowSystem, diag::ILog* log );
	~Ds8AudioSystem();

	// IAudioSystem methods.
	IAudioPlayer*											CreatePlayer( UInt index );
	IAudioRecorder*											CreateRecorder( UInt index );

	// Other methods.
	void													AddPlayer( LPGUID guid, const lang::String& name );
	void													AddRecorder( LPGUID guid, const lang::String& name );

private:
	enum DeviceType
	{
		DEVICE_PLAYER,
		DEVICE_RECORDER,
	};

	struct DeviceGuid
	{
		DeviceGuid( REFGUID guid, DeviceType type ) :
			Guid( guid ),
			Type( type )
		{
		}
		
		DeviceGuid() :
			Type( DEVICE_PLAYER )
		{
		}

		GUID		Guid;
		DeviceType	Type;
	};

	lang::Vector<DeviceGuid>								_guids;
	ComInitializer											_com; // To enable effect DMOs.
	HMODULE													_dll;
	HWND													_wnd;

	FARPROC													GetEntryPoint( const char* name );
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8AUDIOSYSTEM_
