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
// Purpose: Defines viewport visualization mode.
//==============================================================================
#include "config.h"
#include <view/ViewMode.h>
#include <internal/Enum.h>
#include "ViewModeConst.h"


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( ViewMode, Color,	VIEW_MODE_COLOR )
SYNKRO_DEFINE_CONST( ViewMode, Alpha,	VIEW_MODE_ALPHA )
SYNKRO_DEFINE_CONST( ViewMode, Depth,	VIEW_MODE_DEPTH )
SYNKRO_DEFINE_CONST( ViewMode, Stencil,	VIEW_MODE_STENCIL )


} // view


} // synkro
