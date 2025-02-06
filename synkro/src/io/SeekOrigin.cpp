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
// Purpose: Defines stream seek origin.
//==============================================================================
#include "config.h"
#include <io/SeekOrigin.h>
#include <internal/Enum.h>
#include "SeekOriginConst.h"


namespace synkro
{


namespace io
{


SYNKRO_DEFINE_CONST( SeekOrigin, Start,		SEEK_ORIGIN_START )
SYNKRO_DEFINE_CONST( SeekOrigin, Current,	SEEK_ORIGIN_CURRENT )
SYNKRO_DEFINE_CONST( SeekOrigin, End,		SEEK_ORIGIN_END )


} // io


} // synkro
