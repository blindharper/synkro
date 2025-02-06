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
#include "config.h"
#include "Ds8.h"


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


void Ds8::Convert( const Vector3& s, D3DVECTOR& d )
{
	d.x = s.x;
	d.y = s.y;
	d.z = s.z;
}

const Char* Ds8::ToString( HRESULT hr )
{
	switch ( hr )
	{
		case DS_OK:						return L"DS_OK";
		case DS_NO_VIRTUALIZATION:		return L"DS_NO_VIRTUALIZATION";
		case DSERR_ALLOCATED:			return L"DSERR_ALLOCATED";
		case DSERR_CONTROLUNAVAIL:		return L"DSERR_CONTROLUNAVAIL";
		case DSERR_INVALIDPARAM:		return L"DSERR_INVALIDPARAM";
		case DSERR_INVALIDCALL:			return L"DSERR_INVALIDCALL";
		case DSERR_GENERIC:				return L"DSERR_GENERIC";
		case DSERR_PRIOLEVELNEEDED:		return L"DSERR_PRIOLEVELNEEDED";
		case DSERR_OUTOFMEMORY:			return L"DSERR_OUTOFMEMORY";
		case DSERR_BADFORMAT:			return L"DSERR_BADFORMAT";
		case DSERR_UNSUPPORTED:			return L"DSERR_UNSUPPORTED";
		case DSERR_NODRIVER:			return L"DSERR_NODRIVER";
		case DSERR_ALREADYINITIALIZED:	return L"DSERR_ALREADYINITIALIZED";
		case DSERR_NOAGGREGATION:		return L"DSERR_NOAGGREGATION";
		case DSERR_BUFFERLOST:			return L"DSERR_BUFFERLOST";
		case DSERR_OTHERAPPHASPRIO:		return L"DSERR_OTHERAPPHASPRIO";
		case DSERR_UNINITIALIZED:		return L"DSERR_UNINITIALIZED";
		case DSERR_NOINTERFACE:			return L"DSERR_NOINTERFACE";
		case DSERR_ACCESSDENIED:		return L"DSERR_ACCESSDENIED";
		case DSERR_BUFFERTOOSMALL:		return L"DSERR_BUFFERTOOSMALL";
		case DSERR_DS8_REQUIRED:		return L"DSERR_DS8_REQUIRED";
		case DSERR_SENDLOOP:			return L"DSERR_SENDLOOP";
		case DSERR_BADSENDBUFFERGUID:	return L"DSERR_BADSENDBUFFERGUID";
		case DSERR_OBJECTNOTFOUND:		return L"DSERR_OBJECTNOTFOUND";
		case DSERR_FXUNAVAILABLE:		return L"DSERR_FXUNAVAILABLE";
		default:						return L"DSERR_UNKNOWN";
	}
}

LPDIRECTSOUNDCREATE8 Ds8::DirectSoundCreate8 = nullptr;
LPDIRECTSOUNDCAPTURECREATE8 Ds8::DirectSoundCaptureCreate8 = nullptr;


} // audio


} // synkro
