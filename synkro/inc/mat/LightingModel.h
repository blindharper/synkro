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
// Purpose: Defines material lighting model.
//==============================================================================
#ifndef _SYNKRO_MAT_LIGHTINGMODEL_
#define _SYNKRO_MAT_LIGHTINGMODEL_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace mat
{


/**
 * Material lighting model.
 */
SYNKRO_ENUM_BEGIN( LightingModel )
	/** Unknown lighting model. */
	SYNKRO_ENUM_CONST( LightingModel, Unknown )

	/** Flat lighting model. */
	SYNKRO_ENUM_CONST( LightingModel, Flat )

	/** Gouraud lighting model. */
	SYNKRO_ENUM_CONST( LightingModel, Gouraud )

	/** Phong lighting model. */
	SYNKRO_ENUM_CONST( LightingModel, Phong )

	/** Blinn lighting model. */
	SYNKRO_ENUM_CONST( LightingModel, Blinn )

	/** Converts lighting model to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // mat


} // synkro


#endif // _SYNKRO_MAT_LIGHTINGMODEL_
