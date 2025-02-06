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
// Purpose: Defines scene property names.
//==============================================================================
#include "config.h"
#include "SceneProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( SceneProperty, AmbientLightColor,		0 )
SYNKRO_DEFINE_CONST( SceneProperty, AmbientLightIntensity,	1 )


struct TypeDesc
{
	SceneProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ SceneProperty::AmbientLightColor,		L"Ambient.Light.Color" },
	{ SceneProperty::AmbientLightIntensity,	L"Ambient.Light.Intensity" },
};
static UInt _count = SizeOf( _desc );

lang::String SceneProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
