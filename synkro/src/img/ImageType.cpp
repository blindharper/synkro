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
// Purpose: Defines image type.
//==============================================================================
#include "config.h"
#include <img/ImageType.h>
#include <internal/Enum.h>
#include "ImageTypeConst.h"


namespace synkro
{


namespace img
{


SYNKRO_DEFINE_CONST( ImageType, Unknown,	IMAGE_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( ImageType, Linear,		IMAGE_TYPE_LINEAR )
SYNKRO_DEFINE_CONST( ImageType, Plain,		IMAGE_TYPE_PLAIN )
SYNKRO_DEFINE_CONST( ImageType, Cube,		IMAGE_TYPE_CUBE )
SYNKRO_DEFINE_CONST( ImageType, Volume,		IMAGE_TYPE_VOLUME )


} // img


} // synkro
