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
// Purpose: Defines widget states.
//==============================================================================
#include "config.h"
#include <ui/WidgetState.h>
#include <internal/Enum.h>


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( WidgetState, Normal,	0 )
SYNKRO_DEFINE_CONST( WidgetState, Active,	1 )
SYNKRO_DEFINE_CONST( WidgetState, Hovered,	2 )
SYNKRO_DEFINE_CONST( WidgetState, Disabled,	3 )


} // ui


} // synkro
