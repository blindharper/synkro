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
// Purpose: Defines line set property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_LINESETPROPERTY_
#define _SYNKRO_SCENE_LINESETPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Line set property names.
SYNKRO_ENUM_BEGIN( LineSetProperty )
	// Line set transformation.
	SYNKRO_ENUM_CONST( LineSetProperty, Color )

	// Converts line set property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LINESETPROPERTY_
