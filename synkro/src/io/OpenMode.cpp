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
// Purpose: Defines stream open mode.
//==============================================================================
#include "config.h"
#include <io/OpenMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace io
{


SYNKRO_DEFINE_CONST( OpenMode, None,		0x00 )
SYNKRO_DEFINE_CONST( OpenMode, Read,		0x01 )
SYNKRO_DEFINE_CONST( OpenMode, Write,		0x02 )
SYNKRO_DEFINE_CONST( OpenMode, ReadWrite,	0x03 )
SYNKRO_DEFINE_CONST( OpenMode, Append,		0x04 )


} // io


} // synkro
