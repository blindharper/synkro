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
// Purpose: Defines fog filter property names.
//==============================================================================
#include "config.h"
#include "FogFilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( FogFilterProperty, Color,		0 )
SYNKRO_DEFINE_CONST( FogFilterProperty, Density,	1 )
SYNKRO_DEFINE_CONST( FogFilterProperty, Start,		2 )
SYNKRO_DEFINE_CONST( FogFilterProperty, End,		3 )


struct TypeDesc
{
	FogFilterProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ FogFilterProperty::Color,		L"Color" },
	{ FogFilterProperty::Density,	L"Density" },
	{ FogFilterProperty::Start,		L"Start" },
	{ FogFilterProperty::End,		L"End" },
};
static UInt _count = SizeOf( _desc );

lang::String FogFilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
