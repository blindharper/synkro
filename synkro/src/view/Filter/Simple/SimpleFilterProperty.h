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
// Purpose: Defines simple filter property names.
//==============================================================================
#ifndef _SYNKRO_VIEW_SIMPLEFILTERPROPERTY_
#define _SYNKRO_VIEW_SIMPLEFILTERPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


// Simple filter property names.
SYNKRO_ENUM_BEGIN( SimpleFilterProperty )
	// Filter's parameter value.
	SYNKRO_ENUM_CONST( SimpleFilterProperty, ParamValue )
	
	// Converts filter property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_SIMPLEFILTERPROPERTY_
