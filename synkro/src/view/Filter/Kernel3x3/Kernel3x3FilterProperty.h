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
// Purpose: Defines kernel3x3 filter property names.
//==============================================================================
#ifndef _SYNKRO_VIEW_KERNEL3X3FILTERPROPERTY_
#define _SYNKRO_VIEW_KERNEL3X3FILTERPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


// Kernel3x3 filter property names.
SYNKRO_ENUM_BEGIN( Kernel3x3FilterProperty )
	// Filter's pass count.
	SYNKRO_ENUM_CONST( Kernel3x3FilterProperty, PassCount )
	
	// Converts filter property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_KERNEL3X3FILTERPROPERTY_
