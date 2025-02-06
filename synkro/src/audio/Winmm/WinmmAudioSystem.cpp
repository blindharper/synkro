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
#include "config.h"
#include "WinmmAudioSystem.h"
#include "WinmmAudioPlayer.h"
#include "WinmmAudioRecorder.h"
#include <audio/AudioException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


// WinMM library name.
#define WINMM_DLL L"winmm.dll"


namespace synkro
{


namespace audio
{


WinmmAudioSystem::WinmmAudioSystem( const SoundFormat& format, ILog* log ) :
	AudioSystemImpl<IAudioSystem>( format, log ),
	_dll( nullptr )
{
	typedef UINT (WINAPI* LPWAVEGETNUMDEVS)();
	typedef MMRESULT (WINAPI* LPWAVEOUTGETDEVCAPSW)( UINT_PTR, LPWAVEOUTCAPSW, UINT );
	typedef MMRESULT (WINAPI* LPWAVEINGETDEVCAPSW)( UINT_PTR, LPWAVEINCAPSW, UINT );

	// Make sure WinMM is installed.
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Initializing, L"WinMM") );
	if ( (_dll = ::LoadLibrary(WINMM_DLL)) == nullptr )
		throw AudioException( String::Format(Str::InitializeFail, L"WinMM"), String::Format(Str::NotFound, WINMM_DLL) );

	// Get required entry points.
	LPWAVEGETNUMDEVS pWaveOutGetNumDevs = (LPWAVEGETNUMDEVS)GetEntryPoint( "waveOutGetNumDevs" );
	LPWAVEGETNUMDEVS pWaveInGetNumDevs = (LPWAVEGETNUMDEVS)GetEntryPoint( "waveInGetNumDevs" );
	LPWAVEOUTGETDEVCAPSW pWaveOutGetDevCaps = (LPWAVEOUTGETDEVCAPSW)GetEntryPoint( "waveOutGetDevCapsW" );
	LPWAVEINGETDEVCAPSW pWaveInGetDevCaps = (LPWAVEINGETDEVCAPSW)GetEntryPoint( "waveInGetDevCapsW" );

	Winmm::WaveOutOpen = (LPWAVEOUTOPEN)GetEntryPoint( "waveOutOpen" );
	Winmm::WaveOutClose = (LPWAVEOUTCLOSE)GetEntryPoint( "waveOutClose" );
	Winmm::WaveOutPrepareHeader = (LPWAVEOUTPREPAREHEADER)GetEntryPoint( "waveOutPrepareHeader" );
	Winmm::WaveOutUnprepareHeader = (LPWAVEOUTPREPAREHEADER)GetEntryPoint( "waveOutUnprepareHeader" );
	Winmm::WaveOutWrite = (LPWAVEOUTPREPAREHEADER)GetEntryPoint( "waveOutWrite" );
	Winmm::WaveOutPause = (LPWAVEOUTPAUSE)GetEntryPoint( "waveOutPause" );
	Winmm::WaveOutRestart = (LPWAVEOUTPAUSE)GetEntryPoint( "waveOutRestart" );
	Winmm::WaveOutReset = (LPWAVEOUTPAUSE)GetEntryPoint( "waveOutReset" );
	Winmm::WaveOutBreakLoop = (LPWAVEOUTPAUSE)GetEntryPoint( "waveOutBreakLoop" );
	Winmm::WaveOutGetPosition = (LPWAVEOUTGETPOSITION)GetEntryPoint( "waveOutGetPosition" );
	Winmm::WaveOutGetVolume = (LPWAVEOUTGETVOLUME)GetEntryPoint( "waveOutGetVolume" );
	Winmm::WaveOutSetVolume = (LPWAVEOUTSETVOLUME)GetEntryPoint( "waveOutSetVolume" );
	Winmm::WaveOutGetPitch = (LPWAVEOUTGETPITCH)GetEntryPoint( "waveOutGetPitch" );
	Winmm::WaveOutSetPitch = (LPWAVEOUTSETPITCH)GetEntryPoint( "waveOutSetPitch" );
	Winmm::WaveOutGetPlaybackRate = (LPWAVEOUTGETPITCH)GetEntryPoint( "waveOutGetPlaybackRate" );
	Winmm::WaveOutSetPlaybackRate = (LPWAVEOUTSETPITCH)GetEntryPoint( "waveOutSetPlaybackRate" );

	Winmm::WaveInOpen = (LPWAVEINOPEN)GetEntryPoint( "waveInOpen" );
	Winmm::WaveInClose = (LPWAVEINCLOSE)GetEntryPoint( "waveInClose" );
	Winmm::WaveInPrepareHeader = (LPWAVEINPREPAREHEADER)GetEntryPoint( "waveInPrepareHeader" );
	Winmm::WaveInUnprepareHeader = (LPWAVEINPREPAREHEADER)GetEntryPoint( "waveInUnprepareHeader" );
	Winmm::WaveInAddBuffer = (LPWAVEINADDBUFFER)GetEntryPoint( "waveInAddBuffer" );
	Winmm::WaveInStart = (LPWAVEINSTART)GetEntryPoint( "waveInStart" );
	Winmm::WaveInStop = (LPWAVEINSTART)GetEntryPoint( "waveInStop" );
	Winmm::WaveInReset = (LPWAVEINSTART)GetEntryPoint( "waveInReset" );
	Winmm::WaveInGetPosition = (LPWAVEINGETPOSITION)GetEntryPoint( "waveInGetPosition" );

	// Enumerate player devices.
	UINT playerCount = pWaveOutGetNumDevs();
	for ( UINT i = 0; i < playerCount; ++i )
	{
		WAVEOUTCAPS caps;
		if ( pWaveOutGetDevCaps(i, &caps, sizeof(caps)) == MMSYSERR_NOERROR )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::PlayerDetected, caps.szPname) );
			_players.Add( PlayerDesc(caps.szPname, Winmm::Convert(caps), 0) );
		}
	}

	// Enumerate recorder devices.
	UINT recorderCount = pWaveInGetNumDevs();
	for ( UINT i = 0; i < recorderCount; ++i )
	{
		WAVEINCAPS caps;
		if ( pWaveInGetDevCaps(i, &caps, sizeof(caps)) == MMSYSERR_NOERROR )
		{
			LogInfo( MessagePriority::Low, Formatter::Format(Str::RecorderDetected, caps.szPname) );
			_recorders.Add( RecorderDesc(caps.szPname, (UInt)caps.wChannels) );
		}
	}
}

WinmmAudioSystem::~WinmmAudioSystem()
{
	::FreeLibrary( _dll );
}

IAudioPlayer* WinmmAudioSystem::CreatePlayer( UInt index )
{
	assert( index < _players.Size() );

	if ( index >= _players.Size() )
		throw OutOfRangeException( index, _players.Size() );

	return new WinmmAudioPlayer( index, _format, _players[index] );
}

IAudioRecorder* WinmmAudioSystem::CreateRecorder( UInt index )
{
	assert( index < _recorders.Size() );

	if ( index >= _recorders.Size() )
		throw OutOfRangeException( index, _recorders.Size() );

	return new WinmmAudioRecorder( index, _format, _recorders[index] );
}

FARPROC WinmmAudioSystem::GetEntryPoint( const char* name )
{
	FARPROC proc = ::GetProcAddress( _dll, name );
	if ( proc == nullptr )
		throw AudioException( String::Format(Str::InitializeFail, L"WinMM"), String::Format(Str::NotFound, name), String::Empty );
	return proc;
}


} // audio


} // synkro
