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
// Purpose: Defines image type constant values.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGETYPECONST_
#define _SYNKRO_IMG_IMAGETYPECONST_


#include "config.h"


namespace synkro
{


namespace img
{


// image type constant values.
enum ImageTypeConst
{
	IMAGE_TYPE_UNKNOWN	= 0,
	IMAGE_TYPE_LINEAR	= 1,
	IMAGE_TYPE_PLAIN	= 2,
	IMAGE_TYPE_CUBE		= 3,
	IMAGE_TYPE_VOLUME	= 4,
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGETYPECONST_
