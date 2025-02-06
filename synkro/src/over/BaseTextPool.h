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
// Purpose: Base text pool.
//==============================================================================
#ifndef _SYNKRO_OVER_BASETEXTPOOL_
#define _SYNKRO_OVER_BASETEXTPOOL_


#include "config.h"
#include "BaseText.h"


namespace synkro
{


namespace over
{


// Base text pool.
class BaseTextPool
{
public:
	virtual void											AddText( BaseText* text ) = 0;
	virtual void											RemoveText( BaseText* text ) = 0;
	virtual void											InvalidateTexts() = 0;
	virtual void											Update() = 0;
};


} // over


} // synkro


#endif // _SYNKRO_OVER_BASETEXTPOOL_
