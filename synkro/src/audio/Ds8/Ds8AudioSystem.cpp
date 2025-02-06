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
#include "config.h"
#include "Ds8AudioSystem.h"
#include "Ds8AudioPlayer.h"
#include "Ds8AudioRecorder.h"
#include <win/IWindowSystemEx.h>
#include <win/IFrameWindowEx.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::sound;
using namespace synkro::win;

//------------------------------------------------------------------------------


// DirectSound8 library name.
#define DS8_DLL L"dsound.dll"


namespace synkro
{


namespace audio
{


static BOOL CALLBACK ListPlayerDevice( LPGUID lpUid, LPCWSTR lpcstrDescription, LPCWSTR lpcstrModule, LPVOID lpContext )
{
	if ( lpUid != nullptr )
	{
		Ds8AudioSystem* sys = reinterpret_cast<Ds8AudioSystem*>( lpContext );
		sys->AddPlayer( lpUid, lpcstrDescription );
	}
	return TRUE;
}

static BOOL CALLBACK ListRecorderDevice( LPGUID lpUid, LPCWSTR lpcstrDescription, LPCWSTR lpcstrModule, LPVOID lpContext )
{
	if ( lpUid != nullptr )
	{
		Ds8AudioSystem* sys = reinterpret_cast<Ds8AudioSystem*>( lpContext );
		sys->AddRecorder( lpUid, lpcstrDescription );
	}
	return TRUE;
}


//------------------------------------------------------------------------------


Ds8AudioSystem::Ds8AudioSystem( const SoundFormat& format, IWindowSystemEx* windowSystem, ILog* log ) :
	AudioSystemImpl<IAudioSystem>( format, log ),
	_guids( A(DeviceGuid) ),
	_dll( nullptr )
{
	typedef HRESULT (WINAPI *LPDIRECTSOUNDENUMERATE)( LPDSENUMCALLBACKW, LPVOID );
	typedef HRESULT (WINAPI *LPDIRECTSOUNDCAPTUREENUMERATE)( LPDSENUMCALLBACKW, LPVOID );

	// Make sure DirectSound 8 is installed.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"DirectSound 8") );
	if ( (_dll = ::LoadLibrary(DS8_DLL)) == nullptr )
		throw AudioException( String::Format(Str::InitializeFail, L"DirectSound 8"), String::Format(Str::NotFound, DS8_DLL) );

	// Get required entry points.
	LPDIRECTSOUNDENUMERATE pDirectSoundEnumerate = (LPDIRECTSOUNDENUMERATE)GetEntryPoint( "DirectSoundEnumerateW" );
	LPDIRECTSOUNDCAPTUREENUMERATE pDirectSoundCaptureEnumerate = (LPDIRECTSOUNDCAPTUREENUMERATE)GetEntryPoint( "DirectSoundCaptureEnumerateW" );
	Ds8::DirectSoundCreate8 = (LPDIRECTSOUNDCREATE8)GetEntryPoint( "DirectSoundCreate8" );
	Ds8::DirectSoundCaptureCreate8 = (LPDIRECTSOUNDCAPTURECREATE8)GetEntryPoint( "DirectSoundCaptureCreate8" );
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Done) );

	// Enumerate available devices.
	_wnd = (windowSystem->GetFrameWindowCount() > 0) ? (HWND)windowSystem->GetFrameWindow(0)->GetHandle() : nullptr;

	// Enumerate player devices.
	if ( FAILED(pDirectSoundEnumerate(ListPlayerDevice, this)) )
	{
		AddPlayer( (LPGUID)&DSDEVID_DefaultPlayback, L"Default" );
	}

	// Enumerate recorder devices.
	if ( FAILED(pDirectSoundCaptureEnumerate(ListRecorderDevice, this)) )
	{
		AddRecorder( (LPGUID)&DSDEVID_DefaultCapture, L"Default" );
	}
}

Ds8AudioSystem::~Ds8AudioSystem()
{
	::FreeLibrary( _dll );
}

IAudioPlayer* Ds8AudioSystem::CreatePlayer( UInt index )
{
	assert( index < _players.Size() );

	if ( index >= _players.Size() )
		throw OutOfRangeException( index, _players.Size() );

	UInt idx = 0;
	for ( UInt i = 0; i < _guids.Size(); ++i )
	{
		if ( _guids[i].Type == DEVICE_PLAYER )
		{
			if ( idx++ == index )
			{
				return new Ds8AudioPlayer( &_guids[index].Guid, _format, _wnd, _players[index] );
			}
		}
	}

	return nullptr;
}

IAudioRecorder* Ds8AudioSystem::CreateRecorder( UInt index )
{
	assert( index < _recorders.Size() );

	if ( index >= _recorders.Size() )
		throw OutOfRangeException( index, _recorders.Size() );

	UInt idx = 0;
	for ( UInt i = 0; i < _guids.Size(); ++i )
	{
		if ( _guids[i].Type == DEVICE_RECORDER )
		{
			if ( idx++ == index )
			{
				return new Ds8AudioRecorder( &_guids[index].Guid, _format, _recorders[index] );
			}
		}
	}

	return nullptr;
}

void Ds8AudioSystem::AddPlayer( LPGUID guid, const String& name )
{
	IDirectSound8* device = nullptr;
	if ( SUCCEEDED(Ds8::DirectSoundCreate8(guid, &device, nullptr)) )
	{
		// Get device capabilities.
		DSCAPS caps;
		caps.dwSize = sizeof( caps );
		device->GetCaps( &caps );

		// Retrieve primary buffer's native format.
		DSBUFFERDESC bd;
		Zero( &bd );
		bd.dwSize	= sizeof(DSBUFFERDESC);
		bd.dwFlags	= DSBCAPS_PRIMARYBUFFER;
		IDirectSoundBuffer* primaryBuffer = nullptr;
		SoundFormat fmt = SoundFormat::Unknown;
		if ( SUCCEEDED(device->CreateSoundBuffer(&bd, &primaryBuffer, nullptr)) )
		{
			DWORD dwSize;
			if ( SUCCEEDED(primaryBuffer->GetFormat(nullptr, 0, &dwSize)) )
			{
				WAVEFORMATEXTENSIBLE format;
				if ( SUCCEEDED(primaryBuffer->GetFormat((LPWAVEFORMATEX)&format, dwSize, nullptr)) )
				{
					const UInt samplesPerSecond = format.Format.nSamplesPerSec;
					const UInt bitsPerSample = format.Format.wBitsPerSample;
					const UInt channelCount = format.Format.nChannels;
					SoundChannel channels( (dwSize == sizeof(WAVEFORMATEXTENSIBLE) ? format.dwChannelMask : 0) );
					fmt = SoundFormat( samplesPerSecond, bitsPerSample, channels, channelCount );
				}
			}
			primaryBuffer->Release();
		}

		// Register player device.
		LogInfo( MessagePriority::Low, Formatter::Format(Str::PlayerDetected, name) );
		_guids.Add( DeviceGuid(*guid, DEVICE_PLAYER) );
		_players.Add( PlayerDesc(name, fmt, CastUInt(caps.dwTotalHwMemBytes)) );
		device->Release();
	}
}

void Ds8AudioSystem::AddRecorder( LPGUID guid, const String& name )
{
	IDirectSoundCapture8* device = nullptr;
	if ( SUCCEEDED(Ds8::DirectSoundCaptureCreate8(guid, &device, nullptr)) )
	{
		DSCCAPS caps;
		caps.dwSize = sizeof( caps );
		if ( SUCCEEDED(device->GetCaps(&caps)) )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::RecorderDetected, name) );
			_guids.Add( DeviceGuid(*guid, DEVICE_RECORDER) );
			_recorders.Add( RecorderDesc(name, CastUInt(caps.dwChannels)) );
			device->Release();
		}
	}
}

FARPROC Ds8AudioSystem::GetEntryPoint( const char* name )
{
	FARPROC proc = ::GetProcAddress( _dll, name );
	if ( proc == nullptr )
		throw AudioException( String::Format(Str::InitializeFail, L"DirectSound 8"), String::Format(Str::NotFound, name), String::Empty );
	return proc;
}


} // audio


} // synkro
