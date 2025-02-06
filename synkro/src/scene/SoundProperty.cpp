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
// Purpose: Defines sound source property names.
//==============================================================================
#include "config.h"
#include "SoundProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( SoundProperty, InnerVolume,	0 )
SYNKRO_DEFINE_CONST( SoundProperty, OuterVolume,	1 )
SYNKRO_DEFINE_CONST( SoundProperty, Availability,	2 )


struct TypeDesc
{
	SoundProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ SoundProperty::InnerVolume,		L"Inner.Volume" },
	{ SoundProperty::OuterVolume,		L"Outer.Volume" },
	{ SoundProperty::Availability,		L"Availability" },
};
static UInt _count = SizeOf( _desc );

lang::String SoundProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
