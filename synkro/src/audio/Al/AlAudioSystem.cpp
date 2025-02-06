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
#include "AlAudioSystem.h"
#include "AlAudioPlayer.h"
#include "AlAudioRecorder.h"
#include <lang/Convert.h>
#include <lang/Formatter.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::sound;
using namespace synkro::win;

//------------------------------------------------------------------------------


// Uncomment to override actual OpenAL version.
//#define SYNKRO_AL_VERSION "1.1"

// OpenGL gateway library name.
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#define OPENAL32_DLL L"openal32.dll"
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

// Initializes ALC core function.
#define SYNKRO_ALC_FUNC( FUNC, PTR ) \
	Alc::##FUNC = (PTR)GetFunction( "alc"## #FUNC )

// Initializes OpenAL core function.
#define SYNKRO_AL_FUNC( FUNC, PTR ) \
	Al::##FUNC = (PTR)GetFunction( "al"## #FUNC )


namespace synkro
{


namespace audio
{


AlAudioSystem::AlAudioSystem( const SoundFormat& format, ILog* log ) :
	AudioSystemImpl<IAudioSystem>( format, log )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

	// Make sure OpenAL is installed.
	if ( (_dll = ::LoadLibrary(OPENAL32_DLL)) == NULL )
	{
		throw AudioException( String::Format(Str::InitializeFail, L"OpenAL"), String::Format(Str::NotFound, OPENAL32_DLL) );
	}

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	// Find required entry points.
	InitGlue();
	InitCore();
	LogInfo( MessagePriority::Lowest, Formatter::Format(Str::Done, L"") );

	// Initialize playback devices.
	const ALchar* pDevices = NULL;
	if ( Alc::IsExtensionPresent(NULL, "ALC_ENUMERATE_ALL_EXT") == AL_TRUE )
	{
		pDevices = Alc::GetString( NULL, ALC_ALL_DEVICES_SPECIFIER );
	}
	else if ( Alc::IsExtensionPresent(NULL, "ALC_ENUMERATION_EXT") == AL_TRUE )
	{
		pDevices = Alc::GetString( NULL, ALC_DEVICE_SPECIFIER );
	}
	if ( pDevices != NULL )
	{
		// Enumerate playback devices.
		while ( *pDevices != null )
		{
			AddPlayer( format, pDevices );
			pDevices += strlen( pDevices ) + 1;
		}
	}
	else
	{
		// Create default device.
		const ALchar* playbackDevice = Alc::GetString( NULL, ALC_DEFAULT_DEVICE_SPECIFIER );
		if ( playbackDevice != NULL )
		{
			AddPlayer( format, playbackDevice );
		}
	}

	// Initialize capture devices.
	const ALchar* pCaptureDevices = NULL;
	if ( Alc::IsExtensionPresent(NULL, "ALC_EXT_CAPTURE") == AL_TRUE )
	{
		pCaptureDevices = Alc::GetString( NULL, ALC_CAPTURE_DEVICE_SPECIFIER );
	}
	if ( pCaptureDevices != NULL )
	{
		// Enumerate capture devices.
		while ( *pCaptureDevices != null )
		{
			AddRecorder( format, pCaptureDevices );
			pCaptureDevices += strlen( pCaptureDevices ) + 1;
		}
	}
	else
	{
		// Create default device.
		const ALchar* captureDevice = Alc::GetString( NULL, ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER );
		if ( captureDevice != NULL )
		{
			AddRecorder( format, captureDevice );
		}
	}
}

AlAudioSystem::~AlAudioSystem()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

	::FreeLibrary( _dll );

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

IAudioPlayer* AlAudioSystem::CreatePlayer( UInt index )
{
	assert( index < _players.Size() );

	if ( index >= _players.Size() )
		throw OutOfRangeException( index, _players.Size() );

	return new AlAudioPlayer( _format, _players[index] );
}

IAudioRecorder* AlAudioSystem::CreateRecorder( UInt index )
{
	assert( index < _recorders.Size() );

	if ( index >= _recorders.Size() )
		throw OutOfRangeException( index, _recorders.Size() );

	return new AlAudioRecorder( _format, _recorders[index] );
}

void AlAudioSystem::InitGlue()
{
	//-------------------------------------	-----------------------------------------------
	//	Function							Prototype
	//-------------------------------------	-----------------------------------------------
	SYNKRO_ALC_FUNC( CreateContext,			LPALCCREATECONTEXT );
	SYNKRO_ALC_FUNC( MakeContextCurrent,	LPALCMAKECONTEXTCURRENT );
	SYNKRO_ALC_FUNC( ProcessContext,		LPALCPROCESSCONTEXT );
	SYNKRO_ALC_FUNC( SuspendContext,		LPALCSUSPENDCONTEXT );
	SYNKRO_ALC_FUNC( DestroyContext,		LPALCDESTROYCONTEXT );
	SYNKRO_ALC_FUNC( GetCurrentContext,		LPALCGETCURRENTCONTEXT );
	SYNKRO_ALC_FUNC( GetContextsDevice,		LPALCGETCONTEXTSDEVICE );
	SYNKRO_ALC_FUNC( OpenDevice,			LPALCOPENDEVICE );
	SYNKRO_ALC_FUNC( CloseDevice,			LPALCCLOSEDEVICE );
	SYNKRO_ALC_FUNC( GetError,				LPALCGETERROR );
	SYNKRO_ALC_FUNC( IsExtensionPresent,	LPALCISEXTENSIONPRESENT );
	SYNKRO_ALC_FUNC( GetProcAddress,		LPALCGETPROCADDRESS );
	SYNKRO_ALC_FUNC( GetEnumValue,			LPALCGETENUMVALUE );
	SYNKRO_ALC_FUNC( GetString,				LPALCGETSTRING );
	SYNKRO_ALC_FUNC( GetIntegerv,			LPALCGETINTEGERV );
	SYNKRO_ALC_FUNC( CaptureOpenDevice,		LPALCCAPTUREOPENDEVICE );
	SYNKRO_ALC_FUNC( CaptureCloseDevice,	LPALCCAPTURECLOSEDEVICE );
	SYNKRO_ALC_FUNC( CaptureStart,			LPALCCAPTURESTART );
	SYNKRO_ALC_FUNC( CaptureStop,			LPALCCAPTURESTOP );
	SYNKRO_ALC_FUNC( CaptureSamples,		LPALCCAPTURESAMPLES );
}

void AlAudioSystem::InitCore()
{
	//-------------------------------------	-----------------------------------------------
	//	Function							Prototype
	//-------------------------------------	-----------------------------------------------
	SYNKRO_AL_FUNC( Enable,					LPALENABLE );
	SYNKRO_AL_FUNC( Disable,				LPALDISABLE );
	SYNKRO_AL_FUNC( IsEnabled,				LPALISENABLED );
	SYNKRO_AL_FUNC( GetString,				LPALGETSTRING );
	SYNKRO_AL_FUNC( GetBooleanv,			LPALGETBOOLEANV );
	SYNKRO_AL_FUNC( GetIntegerv,			LPALGETINTEGERV );
	SYNKRO_AL_FUNC( GetFloatv,				LPALGETFLOATV );
	SYNKRO_AL_FUNC( GetDoublev,				LPALGETDOUBLEV );
	SYNKRO_AL_FUNC( GetBoolean,				LPALGETBOOLEAN );
	SYNKRO_AL_FUNC( GetInteger,				LPALGETINTEGER );
	SYNKRO_AL_FUNC( GetFloat,				LPALGETFLOAT );
	SYNKRO_AL_FUNC( GetDouble,				LPALGETDOUBLE );
	SYNKRO_AL_FUNC( GetError,				LPALGETERROR );
	SYNKRO_AL_FUNC( IsExtensionPresent,		LPALISEXTENSIONPRESENT );
	SYNKRO_AL_FUNC( GetProcAddress,			LPALGETPROCADDRESS );
	SYNKRO_AL_FUNC( GetEnumValue,			LPALGETENUMVALUE );
	SYNKRO_AL_FUNC( Listenerf,				LPALLISTENERF );
	SYNKRO_AL_FUNC( Listener3f,				LPALLISTENER3F );
	SYNKRO_AL_FUNC( Listenerfv,				LPALLISTENERFV );
	SYNKRO_AL_FUNC( Listeneri,				LPALLISTENERI );
	SYNKRO_AL_FUNC( Listener3i,				LPALLISTENER3I );
	SYNKRO_AL_FUNC( Listeneriv,				LPALLISTENERIV );
	SYNKRO_AL_FUNC( GetListenerf,			LPALGETLISTENERF );
	SYNKRO_AL_FUNC( GetListener3f,			LPALGETLISTENER3F );
	SYNKRO_AL_FUNC( GetListenerfv,			LPALGETLISTENERFV );
	SYNKRO_AL_FUNC( GetListeneri,			LPALGETLISTENERI );
	SYNKRO_AL_FUNC( GetListener3i,			LPALGETLISTENER3I );
	SYNKRO_AL_FUNC( GetListeneriv,			LPALGETLISTENERIV );
	SYNKRO_AL_FUNC( GenSources,				LPALGENSOURCES );
	SYNKRO_AL_FUNC( DeleteSources,			LPALDELETESOURCES );
	SYNKRO_AL_FUNC( IsSource,				LPALISSOURCE );
	SYNKRO_AL_FUNC( Sourcef,				LPALSOURCEF );
	SYNKRO_AL_FUNC( Source3f,				LPALSOURCE3F );
	SYNKRO_AL_FUNC( Sourcefv,				LPALSOURCEFV );
	SYNKRO_AL_FUNC( Sourcei,				LPALSOURCEI );
	SYNKRO_AL_FUNC( Source3i,				LPALSOURCE3I );
	SYNKRO_AL_FUNC( Sourceiv,				LPALSOURCEIV );
	SYNKRO_AL_FUNC( GetSourcef,				LPALGETSOURCEF );
	SYNKRO_AL_FUNC( GetSource3f,			LPALGETSOURCE3F );
	SYNKRO_AL_FUNC( GetSourcefv,			LPALGETSOURCEFV );
	SYNKRO_AL_FUNC( GetSourcei,				LPALGETSOURCEI );
	SYNKRO_AL_FUNC( GetSource3i,			LPALGETSOURCE3I );
	SYNKRO_AL_FUNC( GetSourceiv,			LPALGETSOURCEIV );
	SYNKRO_AL_FUNC( SourcePlayv,			LPALSOURCEPLAYV );
	SYNKRO_AL_FUNC( SourceStopv,			LPALSOURCESTOPV );
	SYNKRO_AL_FUNC( SourceRewindv,			LPALSOURCEREWINDV );
	SYNKRO_AL_FUNC( SourcePausev,			LPALSOURCEPAUSEV );
	SYNKRO_AL_FUNC( SourcePlay,				LPALSOURCEPLAY );
	SYNKRO_AL_FUNC( SourceStop,				LPALSOURCESTOP );
	SYNKRO_AL_FUNC( SourceRewind,			LPALSOURCEREWIND );
	SYNKRO_AL_FUNC( SourcePause,			LPALSOURCEPAUSE );
	SYNKRO_AL_FUNC( SourceQueueBuffers,		LPALSOURCEQUEUEBUFFERS );
	SYNKRO_AL_FUNC( SourceUnqueueBuffers,	LPALSOURCEUNQUEUEBUFFERS );
	SYNKRO_AL_FUNC( GenBuffers,				LPALGENBUFFERS );
	SYNKRO_AL_FUNC( DeleteBuffers,			LPALDELETEBUFFERS );
	SYNKRO_AL_FUNC( IsBuffer,				LPALISBUFFER );
	SYNKRO_AL_FUNC( BufferData,				LPALBUFFERDATA );
	SYNKRO_AL_FUNC( Bufferf,				LPALBUFFERF );
	SYNKRO_AL_FUNC( Buffer3f,				LPALBUFFER3F );
	SYNKRO_AL_FUNC( Bufferfv,				LPALBUFFERFV );
	SYNKRO_AL_FUNC( Bufferi,				LPALBUFFERI );
	SYNKRO_AL_FUNC( Buffer3i,				LPALBUFFER3I );
	SYNKRO_AL_FUNC( Bufferiv,				LPALBUFFERIV );
	SYNKRO_AL_FUNC( GetBufferf,				LPALGETBUFFERF );
	SYNKRO_AL_FUNC( GetBuffer3f,			LPALGETBUFFER3F );
	SYNKRO_AL_FUNC( GetBufferfv,			LPALGETBUFFERFV );
	SYNKRO_AL_FUNC( GetBufferi,				LPALGETBUFFERI );
	SYNKRO_AL_FUNC( GetBuffer3i,			LPALGETBUFFER3I );
	SYNKRO_AL_FUNC( GetBufferiv,			LPALGETBUFFERIV );
	SYNKRO_AL_FUNC( DopplerFactor,			LPALDOPPLERFACTOR );
	SYNKRO_AL_FUNC( DopplerVelocity,		LPALDOPPLERVELOCITY );
	SYNKRO_AL_FUNC( SpeedOfSound,			LPALSPEEDOFSOUND );
	SYNKRO_AL_FUNC( DistanceModel,			LPALDISTANCEMODEL );

	// Create temporary context.
	ALCdevice* device = Alc::OpenDevice( NULL );
	ALCcontext* context = Alc::CreateContext( device, NULL );
	Alc::MakeContextCurrent( context );

	// Check AL version.
#if defined( SYNKRO_AL_VERSION )
	const char* version = SYNKRO_AL_VERSION;
#else
	const char* version = (const char*)Al::GetString( AL_VERSION );
	const char* renderer = (const char*)Al::GetString( AL_RENDERER );
	const char* vendor = (const char*)Al::GetString( AL_VENDOR );
	const char* exts = (const char*)Al::GetString( AL_EXTENSIONS );
#endif // defined( SYNKRO_AL_VERSION )

	String ver( version );
	Al::VersionMajor = Convert::ToUInt( ver.Substring(0, 1) );
	Al::VersionMinor = Convert::ToUInt( ver.Substring(2, 1) );
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"OpenAL version: {0}", ver) );

	// Destroy temporary context.
	Alc::MakeContextCurrent( NULL );
	Alc::DestroyContext( context );
	Alc::CloseDevice( device );
}

void* AlAudioSystem::GetFunction( const char* name )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )

	void* p = (void*)::GetProcAddress( _dll, name );
	return p;

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void* AlAudioSystem::GetExtension( const char* name )
{
	void* p = (void*)Al::GetProcAddress( name );
	return p;
}

void AlAudioSystem::AddPlayer( const SoundFormat& format, const ALchar* name )
{
	LogInfo( MessagePriority::Low, Formatter::Format(Str::PlayerDetected, name) );
	_players.Add( PlayerDesc(String((const char*)name), SoundFormat::Mono22kHz8bit, 0) );
}

void AlAudioSystem::AddRecorder( const SoundFormat& format, const ALchar* name )
{
	LogInfo( MessagePriority::Low, Formatter::Format(Str::RecorderDetected, name) );
	_recorders.Add( RecorderDesc(String((const char*)name), 2) );
}


} // audio


} // synkro
