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
// Purpose: DirectInput 8 API.
//==============================================================================
#include "config.h"
#include "Di8.h"


namespace synkro
{


namespace input
{


const Char* Di8::ToString( HRESULT hr )
{
	switch ( hr )
	{
		case DI_OK:							return L"DI_OK";
		case DI_BUFFEROVERFLOW:				return L"DI_BUFFEROVERFLOW";
		case DI_DOWNLOADSKIPPED:			return L"DI_DOWNLOADSKIPPED";
		case DI_EFFECTRESTARTED:			return L"DI_EFFECTRESTARTED";
		case DI_POLLEDDEVICE:				return L"DI_POLLEDDEVICE";
		case DI_SETTINGSNOTSAVED:			return L"DI_SETTINGSNOTSAVED";
		case DI_TRUNCATED:					return L"DI_TRUNCATED";
		case DI_TRUNCATEDANDRESTARTED:		return L"DI_TRUNCATEDANDRESTARTED";
		case DI_WRITEPROTECT:				return L"DI_WRITEPROTECT";
		case DIERR_ACQUIRED:				return L"DIERR_ACQUIRED";
		case DIERR_ALREADYINITIALIZED:		return L"DIERR_ALREADYINITIALIZED";
		case DIERR_BADDRIVERVER:			return L"DIERR_BADDRIVERVER";
		case DIERR_BETADIRECTINPUTVERSION:	return L"DIERR_BETADIRECTINPUTVERSION";
		case DIERR_DEVICEFULL:				return L"DIERR_DEVICEFULL";
		case DIERR_DEVICENOTREG:			return L"DIERR_DEVICENOTREG";
		case DIERR_EFFECTPLAYING:			return L"DIERR_EFFECTPLAYING";
		case DIERR_HANDLEEXISTS:			return L"DIERR_HANDLEEXISTS";
		case DIERR_HASEFFECTS:				return L"DIERR_HASEFFECTS";
		case DIERR_INCOMPLETEEFFECT:		return L"DIERR_INCOMPLETEEFFECT";
		case DIERR_INPUTLOST:				return L"DIERR_INPUTLOST";
		case DIERR_INVALIDPARAM:			return L"DIERR_INVALIDPARAM";
		case DIERR_MAPFILEFAIL:				return L"DIERR_MAPFILEFAIL";
		case DIERR_MOREDATA:				return L"DIERR_MOREDATA";
		case DIERR_NOAGGREGATION:			return L"DIERR_NOAGGREGATION";
		case DIERR_NOINTERFACE:				return L"DIERR_NOINTERFACE";
		case DIERR_NOTACQUIRED:				return L"DIERR_NOTACQUIRED";
		case DIERR_NOTBUFFERED:				return L"DIERR_NOTBUFFERED";
		case DIERR_NOTDOWNLOADED:			return L"DIERR_NOTDOWNLOADED";
		case DIERR_NOTEXCLUSIVEACQUIRED:	return L"DIERR_NOTEXCLUSIVEACQUIRED";
		case DIERR_NOTFOUND:				return L"DIERR_NOTFOUND";
		case DIERR_NOTINITIALIZED:			return L"DIERR_NOTINITIALIZED";
		case DIERR_OLDDIRECTINPUTVERSION:	return L"DIERR_OLDDIRECTINPUTVERSION";
		case DIERR_OUTOFMEMORY:				return L"DIERR_OUTOFMEMORY";
		case DIERR_REPORTFULL:				return L"DIERR_REPORTFULL";
		case DIERR_UNPLUGGED:				return L"DIERR_UNPLUGGED";
		case DIERR_UNSUPPORTED:				return L"DIERR_UNSUPPORTED";
		case E_HANDLE:						return L"E_HANDLE";
		case E_PENDING:						return L"E_PENDING";
		case E_POINTER:						return L"E_POINTER";
		default:							return L"DIERR_GENERIC";
	}
}


} // input


} // synkro
