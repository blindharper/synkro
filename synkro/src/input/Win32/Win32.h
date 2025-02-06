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
// Purpose: Win32 API.
//==============================================================================
#ifndef _SYNKRO_INPUT_WIN32_
#define _SYNKRO_INPUT_WIN32_


#include "config.h"
#include <mmsystem.h>


typedef MMRESULT (WINAPI* LPJOYGETPOSEX)( UINT, LPJOYINFOEX );


namespace synkro
{


namespace input
{


// Win32 API.
class Win32
{
public:
	static LPJOYGETPOSEX									JoyGetPosEx;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_WIN32_
