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
// Purpose: Defines cone light source property names.
//==============================================================================
#include "config.h"
#include "ConeLightProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( ConeLightProperty, Range,		0 )
SYNKRO_DEFINE_CONST( ConeLightProperty, InnerAngle,	1 )
SYNKRO_DEFINE_CONST( ConeLightProperty, OuterAngle,	2 )
SYNKRO_DEFINE_CONST( ConeLightProperty, Falloff,	3 )


struct TypeDesc
{
	ConeLightProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ ConeLightProperty::Range,			L"Range" },
	{ ConeLightProperty::InnerAngle,	L"Inner.Angle" },
	{ ConeLightProperty::OuterAngle,	L"Outer.Angle" },
	{ ConeLightProperty::Falloff,		L"Falloff" },
};
static UInt _count = SizeOf( _desc );

lang::String ConeLightProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
