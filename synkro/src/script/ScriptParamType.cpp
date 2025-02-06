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
// Purpose: Defines script parameter data types.
//==============================================================================
#include "config.h"
#include <script/ScriptParamType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace script
{


SYNKRO_DEFINE_CONST( ScriptParamType, Unknown,	0 )
SYNKRO_DEFINE_CONST( ScriptParamType, Boolean,	1 )
SYNKRO_DEFINE_CONST( ScriptParamType, Number,	2 )
SYNKRO_DEFINE_CONST( ScriptParamType, String,	3 )
SYNKRO_DEFINE_CONST( ScriptParamType, Object,	4 )


} // script


} // synkro
