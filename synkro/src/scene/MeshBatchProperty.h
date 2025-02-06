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
// Purpose: Defines mesh batch property names.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHBATCHPROPERTY_
#define _SYNKRO_SCENE_MESHBATCHPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


// Mesh batch property names.
SYNKRO_ENUM_BEGIN( MeshBatchProperty )
	// Batch instance range.
	SYNKRO_ENUM_CONST( MeshBatchProperty, Range )

	// Converts primitive property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHBATCHPROPERTY_
