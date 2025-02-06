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
// Purpose: Defines base rendering map.
//==============================================================================
#ifndef _SYNKRO_GFX_BASERENDERMAP_
#define _SYNKRO_GFX_BASERENDERMAP_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Base rendering map.
class BaseRenderMap
{
public:
	virtual UInt											Draw() = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASERENDERMAP_
