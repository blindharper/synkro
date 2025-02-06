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
#include "config.h"
#include "SimpleMaterialProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace mat
{


SYNKRO_DEFINE_CONST( SimpleMaterialProperty, DiffuseColor,	0 )
SYNKRO_DEFINE_CONST( SimpleMaterialProperty, AmbientColor,	1 )
SYNKRO_DEFINE_CONST( SimpleMaterialProperty, EmissiveColor,	2 )
SYNKRO_DEFINE_CONST( SimpleMaterialProperty, SpecularColor,	3 )
SYNKRO_DEFINE_CONST( SimpleMaterialProperty, SpecularPower,	4 )


struct TypeDesc
{
	SimpleMaterialProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ SimpleMaterialProperty::DiffuseColor,		L"Color.Diffuse" },
	{ SimpleMaterialProperty::AmbientColor,		L"Color.Ambient" },
	{ SimpleMaterialProperty::EmissiveColor,	L"Color.Emissive" },
	{ SimpleMaterialProperty::SpecularColor,	L"Color.Specular" },
	{ SimpleMaterialProperty::SpecularPower,	L"Color.Specular.Power" },
};
static UInt _count = SizeOf( _desc );

lang::String SimpleMaterialProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // mat


} // synkro
