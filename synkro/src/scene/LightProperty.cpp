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
// Purpose: Defines light source property names.
//==============================================================================
#include "config.h"
#include "LightProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( LightProperty, DiffuseColor,	0 )
SYNKRO_DEFINE_CONST( LightProperty, AmbientColor,	1 )
SYNKRO_DEFINE_CONST( LightProperty, SpecularColor,	2 )
SYNKRO_DEFINE_CONST( LightProperty, Intensity,		3 )
SYNKRO_DEFINE_CONST( LightProperty, Availability,	4 )


struct TypeDesc
{
	LightProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ LightProperty::DiffuseColor,		L"Color.Diffuse" },
	{ LightProperty::AmbientColor,		L"Color.Ambient" },
	{ LightProperty::SpecularColor,		L"Color.Specular" },
	{ LightProperty::Intensity,			L"Intensity" },
	{ LightProperty::Availability,		L"Availability" },
};
static UInt _count = SizeOf( _desc );

lang::String LightProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
