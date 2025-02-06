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
// Purpose: Defines base text.
//==============================================================================
#ifndef _SYNKRO_OVER_BASETEXT_
#define _SYNKRO_OVER_BASETEXT_


#include "config.h"


namespace synkro
{


namespace over
{


// Base text.
class BaseText
{
public:
	virtual void											Update() = 0;
};


// Casts object to BaseText.
#define AsBaseText( OBJ ) dynamic_cast<BaseText*>( OBJ )


} // over


} // synkro


#endif // _SYNKRO_OVER_BASETEXT_
