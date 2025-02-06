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
// Purpose: Defines color filter property names.
//==============================================================================
#include "config.h"
#include "ColorFilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( ColorFilterProperty, Color,	0 )


struct TypeDesc
{
	ColorFilterProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ ColorFilterProperty::Color,	L"Color" },
};
static UInt _count = SizeOf( _desc );

lang::String ColorFilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
