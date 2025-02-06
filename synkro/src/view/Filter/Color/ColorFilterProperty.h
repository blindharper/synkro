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
// Purpose: Defines color filter property names.
//==============================================================================
#ifndef _SYNKRO_VIEW_COLORFILTERPROPERTY_
#define _SYNKRO_VIEW_COLORFILTERPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


// Color filter property names.
SYNKRO_ENUM_BEGIN( ColorFilterProperty )
	// Filter's color.
	SYNKRO_ENUM_CONST( ColorFilterProperty, Color )

	// Converts filter property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_COLORFILTERPROPERTY_
