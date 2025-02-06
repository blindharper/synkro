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
#ifndef _SYNKRO_AUDIO_AL_
#define _SYNKRO_AUDIO_AL_


#define AL_NO_PROTOTYPES


#include "config.h"
#include <al/al.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


// OpenAL API.
class Al
{
public:
	static void												FlushErrors();
	static ALenum											Convert( const sound::SoundFormat& format );
	static const Char*										ToString( ALenum res );

	static UInt												VersionMajor;
	static UInt												VersionMinor;

	static LPALENABLE										Enable;
	static LPALDISABLE										Disable;
	static LPALISENABLED									IsEnabled;
	static LPALGETSTRING									GetString;
	static LPALGETBOOLEANV									GetBooleanv;
	static LPALGETINTEGERV									GetIntegerv;
	static LPALGETFLOATV									GetFloatv;
	static LPALGETDOUBLEV									GetDoublev;
	static LPALGETBOOLEAN									GetBoolean;
	static LPALGETINTEGER									GetInteger;
	static LPALGETFLOAT										GetFloat;
	static LPALGETDOUBLE									GetDouble;
	static LPALGETERROR										GetError;
	static LPALISEXTENSIONPRESENT							IsExtensionPresent;
	static LPALGETPROCADDRESS								GetProcAddress;
	static LPALGETENUMVALUE									GetEnumValue;
	static LPALLISTENERF									Listenerf;
	static LPALLISTENER3F									Listener3f;
	static LPALLISTENERFV									Listenerfv;
	static LPALLISTENERI									Listeneri;
	static LPALLISTENER3I									Listener3i;
	static LPALLISTENERIV									Listeneriv;
	static LPALGETLISTENERF									GetListenerf;
	static LPALGETLISTENER3F								GetListener3f;
	static LPALGETLISTENERFV								GetListenerfv;
	static LPALGETLISTENERI									GetListeneri;
	static LPALGETLISTENER3I								GetListener3i;
	static LPALGETLISTENERIV								GetListeneriv;
	static LPALGENSOURCES									GenSources;
	static LPALDELETESOURCES								DeleteSources;
	static LPALISSOURCE										IsSource;
	static LPALSOURCEF										Sourcef;
	static LPALSOURCE3F										Source3f;
	static LPALSOURCEFV										Sourcefv;
	static LPALSOURCEI										Sourcei;
	static LPALSOURCE3I										Source3i;
	static LPALSOURCEIV										Sourceiv;
	static LPALGETSOURCEF									GetSourcef;
	static LPALGETSOURCE3F									GetSource3f;
	static LPALGETSOURCEFV									GetSourcefv;
	static LPALGETSOURCEI									GetSourcei;
	static LPALGETSOURCE3I									GetSource3i;
	static LPALGETSOURCEIV									GetSourceiv;
	static LPALSOURCEPLAYV									SourcePlayv;
	static LPALSOURCESTOPV									SourceStopv;
	static LPALSOURCEREWINDV								SourceRewindv;
	static LPALSOURCEPAUSEV									SourcePausev;
	static LPALSOURCEPLAY									SourcePlay;
	static LPALSOURCESTOP									SourceStop;
	static LPALSOURCEREWIND									SourceRewind;
	static LPALSOURCEPAUSE									SourcePause;
	static LPALSOURCEQUEUEBUFFERS							SourceQueueBuffers;
	static LPALSOURCEUNQUEUEBUFFERS							SourceUnqueueBuffers;
	static LPALGENBUFFERS									GenBuffers;
	static LPALDELETEBUFFERS								DeleteBuffers;
	static LPALISBUFFER										IsBuffer;
	static LPALBUFFERDATA									BufferData;
	static LPALBUFFERF										Bufferf;
	static LPALBUFFER3F										Buffer3f;
	static LPALBUFFERFV										Bufferfv;
	static LPALBUFFERI										Bufferi;
	static LPALBUFFER3I										Buffer3i;
	static LPALBUFFERIV										Bufferiv;
	static LPALGETBUFFERF									GetBufferf;
	static LPALGETBUFFER3F									GetBuffer3f;
	static LPALGETBUFFERFV									GetBufferfv;
	static LPALGETBUFFERI									GetBufferi;
	static LPALGETBUFFER3I									GetBuffer3i;
	static LPALGETBUFFERIV									GetBufferiv;
	static LPALDOPPLERFACTOR								DopplerFactor;
	static LPALDOPPLERVELOCITY								DopplerVelocity;
	static LPALSPEEDOFSOUND									SpeedOfSound;
	static LPALDISTANCEMODEL								DistanceModel;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AL_
