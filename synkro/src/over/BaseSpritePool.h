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
// Purpose: Base sprite pool.
//==============================================================================
#ifndef _SYNKRO_OVER_BASESPRITEPOOL_
#define _SYNKRO_OVER_BASESPRITEPOOL_


#include "config.h"


namespace synkro
{


namespace over
{


class PoolSprite;


// Base sprite pool.
class BaseSpritePool
{
public:
	virtual void											AddSprite( PoolSprite* sprite ) = 0;
	virtual void											RemoveSprite( PoolSprite* sprite ) = 0;
	virtual void											InvalidateSprites() = 0;
	virtual void											Update() = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_BASESPRITEPOOL_
