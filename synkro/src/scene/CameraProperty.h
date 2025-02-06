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
// Purpose: Defines camera property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_CAMERAPROPERTY_
#define _SYNKRO_SCENE_CAMERAPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Camera property names.
SYNKRO_ENUM_BEGIN( CameraProperty )
	// Field of view.
	SYNKRO_ENUM_CONST( CameraProperty, FieldOfView )

	// Converts camera property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CAMERAPROPERTY_
