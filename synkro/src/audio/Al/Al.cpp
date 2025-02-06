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
// Purpose: OpenAL API.
//==============================================================================
#include "config.h"
#include "Al.h"


//------------------------------------------------------------------------------

using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


void Al::FlushErrors()
{
	while ( Al::GetError() != AL_NO_ERROR )
	{
	}
}

ALenum Al::Convert( const SoundFormat& format )
{
	ALchar name[] = "AL_FORMAT_\0\0\0\0\0\0\0\0";

	// Determine channel count.
	switch ( format.ChannelCount )
	{
		case 1:
			strcat( name, "MONO" );
			break;

		case 2:
			strcat( name, (format.Channels == SoundChannel::Rear) ? "REAR" : "STEREO" );
			break;

		case 4:
			if ( format.Channels == SoundChannel::Quad )
			{
				strcat( name, "QUAD" );
			}
			break;
	
		case 6:
			if ( (format.Channels == SoundChannel::FivePointOne) || (format.Channels == SoundChannel::FivePointOneSurround) )
			{
				strcat( name, "51CHN" );
			}
			break;

		case 7:
			if ( (format.Channels == SoundChannel::SixPointOne) || (format.Channels == SoundChannel::SixPointOneSurround) )
			{
				strcat( name, "61CHN" );
			}
			break;
	
		case 8:
			if ( (format.Channels == SoundChannel::SevenPointOne) || (format.Channels == SoundChannel::SevenPointOneSurround) )
			{
				strcat( name, "71CHN" );
			}
			break;
	}

	// Determine bitrate.
	char buf[4];
	sprintf( buf, "%d", format.BitsPerSample );
	strcat( name, buf );

	// Convert string to enumeration.
	return Al::GetEnumValue( name );
}

const Char* Al::ToString( ALenum res )
{
	switch ( res )
	{
		case AL_NO_ERROR:			return L"AL_NO_ERROR";
		case AL_INVALID_NAME:		return L"AL_INVALID_NAME";
		case AL_INVALID_ENUM:		return L"AL_INVALID_ENUM";
		case AL_INVALID_VALUE:		return L"AL_INVALID_VALUE";
		case AL_INVALID_OPERATION:	return L"AL_INVALID_OPERATION";
		case AL_OUT_OF_MEMORY:		return L"AL_OUT_OF_MEMORY";
		default:					return L"AL_UNKNOWN_ERROR";
	}
}

UInt Al::VersionMajor = 1;
UInt Al::VersionMinor = 0;

LPALENABLE Al::Enable = nullptr;
LPALDISABLE Al::Disable = nullptr;
LPALISENABLED Al::IsEnabled = nullptr;
LPALGETSTRING Al::GetString = nullptr;
LPALGETBOOLEANV Al::GetBooleanv = nullptr;
LPALGETINTEGERV Al::GetIntegerv = nullptr;
LPALGETFLOATV Al::GetFloatv = nullptr;
LPALGETDOUBLEV Al::GetDoublev = nullptr;
LPALGETBOOLEAN Al::GetBoolean = nullptr;
LPALGETINTEGER Al::GetInteger = nullptr;
LPALGETFLOAT Al::GetFloat = nullptr;
LPALGETDOUBLE Al::GetDouble = nullptr;
LPALGETERROR Al::GetError = nullptr;
LPALISEXTENSIONPRESENT Al::IsExtensionPresent = nullptr;
LPALGETPROCADDRESS Al::GetProcAddress = nullptr;
LPALGETENUMVALUE Al::GetEnumValue = nullptr;
LPALLISTENERF Al::Listenerf = nullptr;
LPALLISTENER3F Al::Listener3f = nullptr;
LPALLISTENERFV Al::Listenerfv = nullptr;
LPALLISTENERI Al::Listeneri = nullptr;
LPALLISTENER3I Al::Listener3i = nullptr;
LPALLISTENERIV Al::Listeneriv = nullptr;
LPALGETLISTENERF Al::GetListenerf = nullptr;
LPALGETLISTENER3F Al::GetListener3f = nullptr;
LPALGETLISTENERFV Al::GetListenerfv = nullptr;
LPALGETLISTENERI Al::GetListeneri = nullptr;
LPALGETLISTENER3I Al::GetListener3i = nullptr;
LPALGETLISTENERIV Al::GetListeneriv = nullptr;
LPALGENSOURCES Al::GenSources = nullptr;
LPALDELETESOURCES Al::DeleteSources = nullptr;
LPALISSOURCE Al::IsSource = nullptr;
LPALSOURCEF Al::Sourcef = nullptr;
LPALSOURCE3F Al::Source3f = nullptr;
LPALSOURCEFV Al::Sourcefv = nullptr;
LPALSOURCEI Al::Sourcei = nullptr;
LPALSOURCE3I Al::Source3i = nullptr;
LPALSOURCEIV Al::Sourceiv = nullptr;
LPALGETSOURCEF Al::GetSourcef = nullptr;
LPALGETSOURCE3F Al::GetSource3f = nullptr;
LPALGETSOURCEFV Al::GetSourcefv = nullptr;
LPALGETSOURCEI Al::GetSourcei = nullptr;
LPALGETSOURCE3I Al::GetSource3i = nullptr;
LPALGETSOURCEIV Al::GetSourceiv = nullptr;
LPALSOURCEPLAYV Al::SourcePlayv = nullptr;
LPALSOURCESTOPV Al::SourceStopv = nullptr;
LPALSOURCEREWINDV Al::SourceRewindv = nullptr;
LPALSOURCEPAUSEV Al::SourcePausev = nullptr;
LPALSOURCEPLAY Al::SourcePlay = nullptr;
LPALSOURCESTOP Al::SourceStop = nullptr;
LPALSOURCEREWIND Al::SourceRewind = nullptr;
LPALSOURCEPAUSE Al::SourcePause = nullptr;
LPALSOURCEQUEUEBUFFERS Al::SourceQueueBuffers = nullptr;
LPALSOURCEUNQUEUEBUFFERS Al::SourceUnqueueBuffers = nullptr;
LPALGENBUFFERS Al::GenBuffers = nullptr;
LPALDELETEBUFFERS Al::DeleteBuffers = nullptr;
LPALISBUFFER Al::IsBuffer = nullptr;
LPALBUFFERDATA Al::BufferData = nullptr;
LPALBUFFERF Al::Bufferf = nullptr;
LPALBUFFER3F Al::Buffer3f = nullptr;
LPALBUFFERFV Al::Bufferfv = nullptr;
LPALBUFFERI Al::Bufferi = nullptr;
LPALBUFFER3I Al::Buffer3i = nullptr;
LPALBUFFERIV Al::Bufferiv = nullptr;
LPALGETBUFFERF Al::GetBufferf = nullptr;
LPALGETBUFFER3F Al::GetBuffer3f = nullptr;
LPALGETBUFFERFV Al::GetBufferfv = nullptr;
LPALGETBUFFERI Al::GetBufferi = nullptr;
LPALGETBUFFER3I Al::GetBuffer3i = nullptr;
LPALGETBUFFERIV Al::GetBufferiv = nullptr;
LPALDOPPLERFACTOR Al::DopplerFactor = nullptr;
LPALDOPPLERVELOCITY Al::DopplerVelocity = nullptr;
LPALSPEEDOFSOUND Al::SpeedOfSound = nullptr;
LPALDISTANCEMODEL Al::DistanceModel = nullptr;


} // audio


} // synkro
