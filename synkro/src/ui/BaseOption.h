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
// Purpose: Base option.
//==============================================================================
#ifndef _SYNKRO_UI_BASEOPTION_
#define _SYNKRO_UI_BASEOPTION_


#include "config.h"


namespace synkro
{


namespace ui
{


// Base option.
class BaseOption
{
public:
	virtual void											Unselect() = 0;
};


// Casts object to BaseOption.
#define AsBaseOption( OBJ ) dynamic_cast<BaseOption*>( OBJ )


} // ui


} // synkro


#endif // _SYNKRO_UI_BASEOPTION_
