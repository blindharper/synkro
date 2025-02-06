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
// Purpose: Defines text property names.
//==============================================================================
#include "config.h"
#include "TextProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace over
{


SYNKRO_DEFINE_CONST( TextProperty, Location,		0 )
SYNKRO_DEFINE_CONST( TextProperty, LocationX,		1 )
SYNKRO_DEFINE_CONST( TextProperty, LocationY,		2 )
SYNKRO_DEFINE_CONST( TextProperty, Rect,			3 )
SYNKRO_DEFINE_CONST( TextProperty, Orientation,		4 )
SYNKRO_DEFINE_CONST( TextProperty, Scale,			5 )
SYNKRO_DEFINE_CONST( TextProperty, ColorGradient,	6 )
SYNKRO_DEFINE_CONST( TextProperty, Color,			7 )
SYNKRO_DEFINE_CONST( TextProperty, Opacity,			8 )
SYNKRO_DEFINE_CONST( TextProperty, Visibility,		9 )


struct TypeDesc
{
	TextProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ TextProperty::Location,		L"Location" },
	{ TextProperty::LocationX,		L"Location.X" },
	{ TextProperty::LocationY,		L"Location.Y" },
	{ TextProperty::Rect,			L"Rect" },
	{ TextProperty::Orientation,	L"Orientation" },
	{ TextProperty::Scale,			L"Scale" },
	{ TextProperty::ColorGradient,	L"ColorGradient" },
	{ TextProperty::Color,			L"Color" },
	{ TextProperty::Opacity,		L"Opacity" },
	{ TextProperty::Visibility,		L"Visibility" },
};
static UInt _count = SizeOf( _desc );

lang::String TextProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // over


} // synkro
