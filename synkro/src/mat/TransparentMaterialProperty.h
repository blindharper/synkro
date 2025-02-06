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
// Purpose: Defines transparent material property names.
//==============================================================================
#ifndef _SYNKRO_MAT_TRANSPARENTMATERIALPROPERTY_
#define _SYNKRO_MAT_TRANSPARENTMATERIALPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace mat
{


// Transparent material property names.
SYNKRO_ENUM_BEGIN( TransparentMaterialProperty )
	// Opacity.
	SYNKRO_ENUM_CONST( TransparentMaterialProperty, Opacity )

	// Converts material property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // mat


} // synkro


#endif // _SYNKRO_MAT_TRANSPARENTMATERIALPROPERTY_
