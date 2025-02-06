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
// Purpose: Defines viewport property names.
//==============================================================================
#include "config.h"
#include "ViewportProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( ViewportProperty, Location,	0 )
SYNKRO_DEFINE_CONST( ViewportProperty, Size,		1 )
SYNKRO_DEFINE_CONST( ViewportProperty, Rect,		2 )
SYNKRO_DEFINE_CONST( ViewportProperty, Color,		3 )
SYNKRO_DEFINE_CONST( ViewportProperty, Opacity,		4 )


struct TypeDesc
{
	ViewportProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ ViewportProperty::Location,	L"Location" },
	{ ViewportProperty::Size,		L"Size" },
	{ ViewportProperty::Rect,		L"Rect" },
	{ ViewportProperty::Color,		L"Color" },
	{ ViewportProperty::Opacity,	L"Opacity" },
};
static UInt _count = SizeOf( _desc );

lang::String ViewportProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
