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
// Purpose: Defines text pool property names.
//==============================================================================
#ifndef _SYNKRO_OVER_TEXTPOOLPROPERTY_
#define _SYNKRO_OVER_TEXTPOOLPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace over
{


// Text pool property names.
SYNKRO_ENUM_BEGIN( TextPoolProperty )
	// Text pool offset.
	SYNKRO_ENUM_CONST( TextPoolProperty, Offset )
	
	// Converts text pool property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // over


} // synkro


#endif // _SYNKRO_OVER_TEXTPOOLPROPERTY_
