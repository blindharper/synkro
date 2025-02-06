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
// Purpose: Defines fog property names.
//==============================================================================
#include "config.h"
#include "FogProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( FogProperty, Color,	0 )
SYNKRO_DEFINE_CONST( FogProperty, Density,	1 )
SYNKRO_DEFINE_CONST( FogProperty, Start,	2 )
SYNKRO_DEFINE_CONST( FogProperty, End,		3 )


struct TypeDesc
{
	FogProperty	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ FogProperty::Color,		L"Color" },
	{ FogProperty::Density,		L"Density" },
	{ FogProperty::Start,		L"Start" },
	{ FogProperty::End,			L"End" },
};
static UInt _count = SizeOf( _desc );

lang::String FogProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
