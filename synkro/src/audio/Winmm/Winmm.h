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
#ifndef _SYNKRO_AUDIO_WINMM_
#define _SYNKRO_AUDIO_WINMM_


#undef WINVER
#define WINVER 0x0500


#include "config.h"
#include <mmsystem.h>
#include <mmreg.h>
#include <sound/SoundFormat.h>


typedef MMRESULT (WINAPI* LPWAVEOUTOPEN)( LPHWAVEOUT, UINT, LPCWAVEFORMATEX, DWORD_PTR, DWORD_PTR, DWORD );
typedef MMRESULT (WINAPI* LPWAVEOUTCLOSE)( HWAVEOUT );
typedef MMRESULT (WINAPI* LPWAVEOUTPREPAREHEADER)( HWAVEOUT, LPWAVEHDR, UINT );
typedef MMRESULT (WINAPI* LPWAVEOUTPAUSE)( HWAVEOUT );
typedef MMRESULT (WINAPI* LPWAVEOUTGETPOSITION)( HWAVEOUT, LPMMTIME, UINT );
typedef MMRESULT (WINAPI* LPWAVEOUTGETVOLUME)( HWAVEOUT, LPDWORD );
typedef MMRESULT (WINAPI* LPWAVEOUTSETVOLUME)( HWAVEOUT, DWORD );
typedef MMRESULT (WINAPI* LPWAVEOUTGETPITCH)( HWAVEOUT, LPDWORD );
typedef MMRESULT (WINAPI* LPWAVEOUTSETPITCH)( HWAVEOUT, DWORD );

typedef MMRESULT (WINAPI* LPWAVEINOPEN)( LPHWAVEIN, UINT, LPCWAVEFORMATEX, DWORD_PTR, DWORD_PTR, DWORD );
typedef MMRESULT (WINAPI* LPWAVEINCLOSE)( HWAVEIN );
typedef MMRESULT (WINAPI* LPWAVEINPREPAREHEADER)( HWAVEIN, LPWAVEHDR, UINT );
typedef MMRESULT (WINAPI* LPWAVEINADDBUFFER)( HWAVEIN, LPWAVEHDR, UINT );
typedef MMRESULT (WINAPI* LPWAVEINSTART)( HWAVEIN );
typedef MMRESULT (WINAPI* LPWAVEINGETPOSITION)( HWAVEIN, LPMMTIME, UINT );


namespace synkro
{


namespace audio
{


// WinMM API.
class Winmm
{
public:
	static sound::SoundFormat								Convert( WAVEOUTCAPS caps );
	static const Char*										ToString( MMRESULT res );

	static LPWAVEOUTOPEN									WaveOutOpen;
	static LPWAVEOUTCLOSE									WaveOutClose;
	static LPWAVEOUTPREPAREHEADER							WaveOutPrepareHeader;
	static LPWAVEOUTPREPAREHEADER							WaveOutUnprepareHeader;
	static LPWAVEOUTPREPAREHEADER							WaveOutWrite;
	static LPWAVEOUTPAUSE									WaveOutPause;
	static LPWAVEOUTPAUSE									WaveOutRestart;
	static LPWAVEOUTPAUSE									WaveOutReset;
	static LPWAVEOUTPAUSE									WaveOutBreakLoop;
	static LPWAVEOUTGETPOSITION								WaveOutGetPosition;
	static LPWAVEOUTGETVOLUME								WaveOutGetVolume;
	static LPWAVEOUTSETVOLUME								WaveOutSetVolume;
	static LPWAVEOUTGETPITCH								WaveOutGetPitch;
	static LPWAVEOUTSETPITCH								WaveOutSetPitch;
	static LPWAVEOUTGETPITCH								WaveOutGetPlaybackRate;
	static LPWAVEOUTSETPITCH								WaveOutSetPlaybackRate;

	static LPWAVEINOPEN										WaveInOpen;
	static LPWAVEINCLOSE									WaveInClose;
	static LPWAVEINPREPAREHEADER							WaveInPrepareHeader;
	static LPWAVEINPREPAREHEADER							WaveInUnprepareHeader;
	static LPWAVEINADDBUFFER								WaveInAddBuffer;
	static LPWAVEINSTART									WaveInStart;
	static LPWAVEINSTART									WaveInStop;
	static LPWAVEINSTART									WaveInReset;
	static LPWAVEINGETPOSITION								WaveInGetPosition;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_WINMM_
