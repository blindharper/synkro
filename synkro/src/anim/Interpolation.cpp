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
// Purpose: Defines animation key interpolation.
//==============================================================================
#include "config.h"
#include <anim/Interpolation.h>
#include <internal/Enum.h>
#include "InterpolationConst.h"


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( Interpolation, Stepped,	INTERPOLATION_STEPPED )
SYNKRO_DEFINE_CONST( Interpolation, Linear,		INTERPOLATION_LINEAR )
SYNKRO_DEFINE_CONST( Interpolation, Ease,		INTERPOLATION_EASE )
SYNKRO_DEFINE_CONST( Interpolation, EaseIn,		INTERPOLATION_EASE_IN )
SYNKRO_DEFINE_CONST( Interpolation, EaseOut,	INTERPOLATION_EASE_OUT )
SYNKRO_DEFINE_CONST( Interpolation, EaseInOut,	INTERPOLATION_EASE_IN_OUT )


} // anim


} // synkro
