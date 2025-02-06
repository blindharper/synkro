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
// Purpose: Defines audio system types.
//==============================================================================
#include "config.h"
#include <audio/AudioSystem.h>
#include <internal/Enum.h>


namespace synkro
{


namespace audio
{


SYNKRO_DEFINE_CONST( AudioSystem, Custom,		0 )
SYNKRO_DEFINE_CONST( AudioSystem, OpenAL,		1 )
SYNKRO_DEFINE_CONST( AudioSystem, DirectSound8,	2 )
SYNKRO_DEFINE_CONST( AudioSystem, WinMM,		3 )


} // audio


} // synkro
