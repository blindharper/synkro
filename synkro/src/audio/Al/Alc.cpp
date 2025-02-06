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
#include "config.h"
#include "Alc.h"


namespace synkro
{


namespace audio
{


void Alc::FlushErrors( ALCdevice *device )
{
	while ( Alc::GetError(device) != ALC_NO_ERROR )
	{
	}
}

const Char* Alc::ToString( ALCenum res )
{
	switch ( res )
	{
		case ALC_NO_ERROR:			return L"ALC_NO_ERROR";
		case ALC_INVALID_DEVICE:	return L"ALC_INVALID_DEVICE";
		case ALC_INVALID_CONTEXT:	return L"ALC_INVALID_CONTEXT";
		case ALC_INVALID_ENUM:		return L"ALC_INVALID_ENUM";
		case ALC_INVALID_VALUE:		return L"ALC_INVALID_VALUE";
		case ALC_OUT_OF_MEMORY:		return L"ALC_OUT_OF_MEMORY";
		default:					return L"ALC_UNKNOWN_ERROR";
	}
}

LPALCCREATECONTEXT Alc::CreateContext = nullptr;
LPALCMAKECONTEXTCURRENT Alc::MakeContextCurrent = nullptr;
LPALCPROCESSCONTEXT Alc::ProcessContext = nullptr;
LPALCSUSPENDCONTEXT Alc::SuspendContext = nullptr;
LPALCDESTROYCONTEXT Alc::DestroyContext = nullptr;
LPALCGETCURRENTCONTEXT Alc::GetCurrentContext = nullptr;
LPALCGETCONTEXTSDEVICE Alc::GetContextsDevice = nullptr;
LPALCOPENDEVICE Alc::OpenDevice = nullptr;
LPALCCLOSEDEVICE Alc::CloseDevice = nullptr;
LPALCGETERROR Alc::GetError = nullptr;
LPALCISEXTENSIONPRESENT Alc::IsExtensionPresent = nullptr;
LPALCGETPROCADDRESS Alc::GetProcAddress = nullptr;
LPALCGETENUMVALUE Alc::GetEnumValue = nullptr;
LPALCGETSTRING Alc::GetString = nullptr;
LPALCGETINTEGERV Alc::GetIntegerv = nullptr;
LPALCCAPTUREOPENDEVICE Alc::CaptureOpenDevice = nullptr;
LPALCCAPTURECLOSEDEVICE Alc::CaptureCloseDevice = nullptr;
LPALCCAPTURESTART Alc::CaptureStart = nullptr;
LPALCCAPTURESTOP Alc::CaptureStop = nullptr;
LPALCCAPTURESAMPLES Alc::CaptureSamples = nullptr;


} // audio


} // synkro
