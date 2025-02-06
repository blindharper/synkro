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
#ifndef _SYNKRO_INPUT_DI8_
#define _SYNKRO_INPUT_DI8_


#define DIRECTINPUT_VERSION 0x0800


#include "config.h"
#include <dinput.h>


namespace synkro
{


namespace input
{


// DirectInput 8 API.
class Di8
{
public:
	static const Char*										ToString( HRESULT hr );
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_DI8_
