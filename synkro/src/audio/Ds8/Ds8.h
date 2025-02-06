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
// Purpose: DS8 API.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8_
#define _SYNKRO_AUDIO_DS8_


#define DIRECTSOUND_VERSION 0x0800


#include "config.h"
#include <math/Vector3.h>
#include <mmsystem.h>
#include <mmreg.h>
#include <dx/dsound.h>
#include <internal/SafeRelease.h>
#include <internal/Zero.h>


typedef HRESULT (WINAPI *LPDIRECTSOUNDCREATE8)( LPCGUID, LPDIRECTSOUND8*, LPUNKNOWN );
typedef HRESULT (WINAPI *LPDIRECTSOUNDCAPTURECREATE8)( LPCGUID, LPDIRECTSOUNDCAPTURE8*, LPUNKNOWN );


namespace synkro
{


namespace audio
{


// DS8 API.
class Ds8
{
public:
	static void 											Convert( const math::Vector3& s, D3DVECTOR& d );
	static const Char*										ToString( HRESULT hr );

	static LPDIRECTSOUNDCREATE8								DirectSoundCreate8;
	static LPDIRECTSOUNDCAPTURECREATE8						DirectSoundCaptureCreate8;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8_
