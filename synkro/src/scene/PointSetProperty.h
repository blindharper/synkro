//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines point set property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_POINTSETPROPERTY_
#define _SYNKRO_SCENE_POINTSETPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Point set property names.
SYNKRO_ENUM_BEGIN( PointSetProperty )
	// Point set transformation.
	SYNKRO_ENUM_CONST( PointSetProperty, Color )

	// Converts point set property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_POINTSETPROPERTY_
