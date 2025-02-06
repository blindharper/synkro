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
// Purpose: Defines gradient types.
//==============================================================================
#include "config.h"
#include <lang/GradientType.h>
#include <internal/Enum.h>
#include "GradientTypeConst.h"


namespace synkro
{


namespace lang
{


SYNKRO_DEFINE_CONST( GradientType, Horizontal,	GRADIENT_TYPE_HORIZONTAL )
SYNKRO_DEFINE_CONST( GradientType, Vertical,	GRADIENT_TYPE_VERTICAL )
SYNKRO_DEFINE_CONST( GradientType, BottomUp,	GRADIENT_TYPE_BOTTOM_UP )
SYNKRO_DEFINE_CONST( GradientType, TopDown,		GRADIENT_TYPE_TOP_DOWN )
SYNKRO_DEFINE_CONST( GradientType, Radial,		GRADIENT_TYPE_RADIAL )


} // lang


} // synkro
