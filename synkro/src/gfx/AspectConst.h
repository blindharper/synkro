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
// Purpose: Defines aspect ratio constant values.
//==============================================================================
#ifndef _SYNKRO_GFX_ASPECTCONST_
#define _SYNKRO_GFX_ASPECTCONST_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Aspect ratio constant values.
enum AspectConst
{
	ASPECT_UNKNOWN	= 0,
	ASPECT_2X1		= 1,
	ASPECT_3X2		= 2,
	ASPECT_4X3		= 3,
	ASPECT_5X4		= 4,
	ASPECT_8X5		= 5,
	ASPECT_16X9		= 6,
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ASPECTCONST_
