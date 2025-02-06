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
// Purpose: ALC API.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ALC_
#define _SYNKRO_AUDIO_ALC_


#include "config.h"
#include <al/alc.h>


namespace synkro
{


namespace audio
{


// ALC API.
class Alc
{
public:
	static void												FlushErrors( ALCdevice *device );
	static const Char*										ToString( ALCenum res );

	static LPALCCREATECONTEXT								CreateContext;
	static LPALCMAKECONTEXTCURRENT							MakeContextCurrent;
	static LPALCPROCESSCONTEXT								ProcessContext;
	static LPALCSUSPENDCONTEXT								SuspendContext;
	static LPALCDESTROYCONTEXT								DestroyContext;
	static LPALCGETCURRENTCONTEXT							GetCurrentContext;
	static LPALCGETCONTEXTSDEVICE							GetContextsDevice;
	static LPALCOPENDEVICE									OpenDevice;
	static LPALCCLOSEDEVICE									CloseDevice;
	static LPALCGETERROR									GetError;
	static LPALCISEXTENSIONPRESENT							IsExtensionPresent;
	static LPALCGETPROCADDRESS								GetProcAddress;
	static LPALCGETENUMVALUE								GetEnumValue;
	static LPALCGETSTRING									GetString;
	static LPALCGETINTEGERV									GetIntegerv;
	static LPALCCAPTUREOPENDEVICE							CaptureOpenDevice;
	static LPALCCAPTURECLOSEDEVICE							CaptureCloseDevice;
	static LPALCCAPTURESTART								CaptureStart;
	static LPALCCAPTURESTOP									CaptureStop;
	static LPALCCAPTURESAMPLES								CaptureSamples;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ALC_
