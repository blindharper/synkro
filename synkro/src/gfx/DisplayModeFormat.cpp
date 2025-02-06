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
// Purpose: Defines display mode formats.
//==============================================================================
#include "config.h"
#include <gfx/DisplayModeFormat.h>
#include <internal/Enum.h>
#include "DisplayModeFormatConst.h"


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( DisplayModeFormat, Short,		DISPLAY_MODE_FORMAT_SHORT )
SYNKRO_DEFINE_CONST( DisplayModeFormat, Long,		DISPLAY_MODE_FORMAT_LONG )
SYNKRO_DEFINE_CONST( DisplayModeFormat, Aspect,		DISPLAY_MODE_FORMAT_ASPECT )
SYNKRO_DEFINE_CONST( DisplayModeFormat, Complete,	DISPLAY_MODE_FORMAT_COMPLETE )


} // gfx


} // synkro
