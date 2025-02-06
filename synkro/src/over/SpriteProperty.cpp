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
// Purpose: Defines sprite property names.
//==============================================================================
#include "config.h"
#include "SpriteProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace over
{


SYNKRO_DEFINE_CONST( SpriteProperty, Location,		0 )
SYNKRO_DEFINE_CONST( SpriteProperty, LocationX,		1 )
SYNKRO_DEFINE_CONST( SpriteProperty, LocationY,		2 )
SYNKRO_DEFINE_CONST( SpriteProperty, Size,			3 )
SYNKRO_DEFINE_CONST( SpriteProperty, Orientation,	4 )
SYNKRO_DEFINE_CONST( SpriteProperty, Opacity,		5 )
SYNKRO_DEFINE_CONST( SpriteProperty, Frame,			6 )
SYNKRO_DEFINE_CONST( SpriteProperty, Visibility,	7 )


struct TypeDesc
{
	SpriteProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ SpriteProperty::Location,		L"Location" },
	{ SpriteProperty::LocationX,	L"Location.X" },
	{ SpriteProperty::LocationY,	L"Location.Y" },
	{ SpriteProperty::Size,			L"Size" },
	{ SpriteProperty::Orientation,	L"Orientation" },
	{ SpriteProperty::Opacity,		L"Opacity" },
	{ SpriteProperty::Frame,		L"Frame" },
	{ SpriteProperty::Visibility,	L"Visibility" },
};
static UInt _count = SizeOf( _desc );

lang::String SpriteProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // over


} // synkro
