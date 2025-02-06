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
// Purpose: Defines Synkro version.
//==============================================================================
#ifndef _SYNKRO_CFG_SYNKROVERSION_
#define _SYNKRO_CFG_SYNKROVERSION_


#include "ConfigSynkro.h"


constexpr synkro::Byte 		SYNKRO_VERSION_MAJOR = 1;
constexpr synkro::Byte 		SYNKRO_VERSION_MINOR = 0;
constexpr synkro::Byte 		SYNKRO_VERSION_PATCH = 0;
constexpr synkro::UInt		SYNKRO_VERSION = (SYNKRO_VERSION_MAJOR << 16) | (SYNKRO_VERSION_MINOR << 8) | SYNKRO_VERSION_PATCH;


#endif // _SYNKRO_CFG_SYNKROVERSION_
