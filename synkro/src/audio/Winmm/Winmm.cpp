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
// Purpose: WinMM API.
//==============================================================================
#include "config.h"
#include "Winmm.h"


//------------------------------------------------------------------------------

using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


SoundFormat Winmm::Convert( WAVEOUTCAPS caps )
{
	UInt samplesPerSecond = 0; UInt bitsPerSample = 0; UInt channelCount = 0;

		 if ( caps.dwFormats & WAVE_FORMAT_96S16 ) { samplesPerSecond = 96000; bitsPerSample = 16; channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_96M16 ) { samplesPerSecond = 96000; bitsPerSample = 16; channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_96S08 ) { samplesPerSecond = 96000; bitsPerSample = 8;  channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_96M08 ) { samplesPerSecond = 96000; bitsPerSample = 8;  channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_48S16 ) { samplesPerSecond = 48000; bitsPerSample = 16; channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_48M16 ) { samplesPerSecond = 48000; bitsPerSample = 16; channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_48S08 ) { samplesPerSecond = 48000; bitsPerSample = 8;  channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_48M08 ) { samplesPerSecond = 48000; bitsPerSample = 8;  channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_44S16 ) { samplesPerSecond = 44100; bitsPerSample = 16; channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_44M16 ) { samplesPerSecond = 44100; bitsPerSample = 16; channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_44S08 ) { samplesPerSecond = 44100; bitsPerSample = 8;  channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_44M08 ) { samplesPerSecond = 44100; bitsPerSample = 8;  channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_2S16 )  { samplesPerSecond = 22050; bitsPerSample = 16; channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_2M16 )  { samplesPerSecond = 22050; bitsPerSample = 16; channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_2S08 )  { samplesPerSecond = 22050; bitsPerSample = 8;  channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_2M08 )  { samplesPerSecond = 22050; bitsPerSample = 8;  channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_1S16 )  { samplesPerSecond = 11025; bitsPerSample = 16; channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_1M16 )  { samplesPerSecond = 11025; bitsPerSample = 16; channelCount = 1; }
	else if ( caps.dwFormats & WAVE_FORMAT_1S08 )  { samplesPerSecond = 11025; bitsPerSample = 8;  channelCount = 2; }
	else if ( caps.dwFormats & WAVE_FORMAT_1M08 )  { samplesPerSecond = 11025; bitsPerSample = 8;  channelCount = 1; }

	return SoundFormat( samplesPerSecond, bitsPerSample, channelCount );
}

const Char* Winmm::ToString( MMRESULT res )
{
	switch ( res )
	{
		case MMSYSERR_NOERROR:		return L"MMSYSERR_NOERROR";
		case MMSYSERR_BADDEVICEID:	return L"MMSYSERR_BADDEVICEID";
		case MMSYSERR_NOTENABLED:	return L"MMSYSERR_NOTENABLED";
		case MMSYSERR_ALLOCATED:	return L"MMSYSERR_ALLOCATED";
		case MMSYSERR_INVALHANDLE:	return L"MMSYSERR_INVALHANDLE";
		case MMSYSERR_NODRIVER:		return L"MMSYSERR_NODRIVER";
		case MMSYSERR_NOMEM:		return L"MMSYSERR_NOMEM";
		case MMSYSERR_NOTSUPPORTED:	return L"MMSYSERR_NOTSUPPORTED";
		case MMSYSERR_BADERRNUM:	return L"MMSYSERR_BADERRNUM";
		case MMSYSERR_INVALFLAG:	return L"MMSYSERR_INVALFLAG";
		case MMSYSERR_INVALPARAM:	return L"MMSYSERR_INVALPARAM";
		case MMSYSERR_HANDLEBUSY:	return L"MMSYSERR_HANDLEBUSY";
		case MMSYSERR_INVALIDALIAS:	return L"MMSYSERR_INVALIDALIAS";
		case MMSYSERR_BADDB:		return L"MMSYSERR_BADDB";
		case MMSYSERR_KEYNOTFOUND:	return L"MMSYSERR_KEYNOTFOUND";
		case MMSYSERR_READERROR:	return L"MMSYSERR_READERROR";
		case MMSYSERR_WRITEERROR:	return L"MMSYSERR_WRITEERROR";
		case MMSYSERR_DELETEERROR:	return L"MMSYSERR_DELETEERROR";
		case MMSYSERR_VALNOTFOUND:	return L"MMSYSERR_VALNOTFOUND";
		case MMSYSERR_NODRIVERCB:	return L"MMSYSERR_NODRIVERCB";
		case MMSYSERR_MOREDATA:		return L"MMSYSERR_MOREDATA";
		default:					return L"MMSYSERR_UNKNOWN";
	}
}

LPWAVEOUTOPEN Winmm::WaveOutOpen = nullptr;
LPWAVEOUTCLOSE Winmm::WaveOutClose = nullptr;
LPWAVEOUTPREPAREHEADER Winmm::WaveOutPrepareHeader = nullptr;
LPWAVEOUTPREPAREHEADER Winmm::WaveOutUnprepareHeader = nullptr;
LPWAVEOUTPREPAREHEADER Winmm::WaveOutWrite = nullptr;
LPWAVEOUTPAUSE Winmm::WaveOutPause = nullptr;
LPWAVEOUTPAUSE Winmm::WaveOutRestart = nullptr;
LPWAVEOUTPAUSE Winmm::WaveOutReset = nullptr;
LPWAVEOUTPAUSE Winmm::WaveOutBreakLoop = nullptr;
LPWAVEOUTGETPOSITION Winmm::WaveOutGetPosition = nullptr;
LPWAVEOUTGETVOLUME Winmm::WaveOutGetVolume = nullptr;
LPWAVEOUTSETVOLUME Winmm::WaveOutSetVolume = nullptr;
LPWAVEOUTGETPITCH Winmm::WaveOutGetPitch = nullptr;
LPWAVEOUTSETPITCH Winmm::WaveOutSetPitch = nullptr;
LPWAVEOUTGETPITCH Winmm::WaveOutGetPlaybackRate = nullptr;
LPWAVEOUTSETPITCH Winmm::WaveOutSetPlaybackRate = nullptr;

LPWAVEINOPEN Winmm::WaveInOpen = nullptr;
LPWAVEINCLOSE Winmm::WaveInClose = nullptr;
LPWAVEINPREPAREHEADER Winmm::WaveInPrepareHeader = nullptr;
LPWAVEINPREPAREHEADER Winmm::WaveInUnprepareHeader = nullptr;
LPWAVEINADDBUFFER Winmm::WaveInAddBuffer = nullptr;
LPWAVEINSTART Winmm::WaveInStart = nullptr;
LPWAVEINSTART Winmm::WaveInStop = nullptr;
LPWAVEINSTART Winmm::WaveInReset = nullptr;
LPWAVEINGETPOSITION Winmm::WaveInGetPosition = nullptr;


} // audio


} // synkro
