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
// Purpose: Defines fog filter property names.
//==============================================================================
#ifndef _SYNKRO_VIEW_FOGFILTERPROPERTY_
#define _SYNKRO_VIEW_FOGFILTERPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace view
{


// Fog filter property names.
SYNKRO_ENUM_BEGIN( FogFilterProperty )
	// Fog color.
	SYNKRO_ENUM_CONST( FogFilterProperty, Color )

	// Fog density.
	SYNKRO_ENUM_CONST( FogFilterProperty, Density )

	// Fog start distance.
	SYNKRO_ENUM_CONST( FogFilterProperty, Start )

	// Fog end distance.
	SYNKRO_ENUM_CONST( FogFilterProperty, End )
	
	// Converts fog filter property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_FOGFILTERPROPERTY_
