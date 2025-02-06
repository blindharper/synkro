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
// Purpose: Defines simple material property names.
//==============================================================================
#ifndef _SYNKRO_MAT_SIMPLEMATERIALPROPERTY_
#define _SYNKRO_MAT_SIMPLEMATERIALPROPERTY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace mat
{


// Simple material property names.
SYNKRO_ENUM_BEGIN( SimpleMaterialProperty )
	// Diffuse color.
	SYNKRO_ENUM_CONST( SimpleMaterialProperty, DiffuseColor )

	// Ambient color.
	SYNKRO_ENUM_CONST( SimpleMaterialProperty, AmbientColor )

	// Emissive color.
	SYNKRO_ENUM_CONST( SimpleMaterialProperty, EmissiveColor )

	// Specular color.
	SYNKRO_ENUM_CONST( SimpleMaterialProperty, SpecularColor )

	// Specular highlights power.
	SYNKRO_ENUM_CONST( SimpleMaterialProperty, SpecularPower )

	// Converts material property to string.
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // mat


} // synkro


#endif // _SYNKRO_MAT_SIMPLEMATERIALPROPERTY_
