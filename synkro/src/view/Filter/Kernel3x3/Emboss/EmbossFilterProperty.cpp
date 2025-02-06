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
// Purpose: Defines emboss filter property names.
//==============================================================================
#include "config.h"
#include "EmbossFilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( EmbossFilterProperty, Angle,	0 )
SYNKRO_DEFINE_CONST( EmbossFilterProperty, Depth,	1 )


struct TypeDesc
{
	EmbossFilterProperty	type;
	const Char*				name;
};

static TypeDesc _desc[] = 
{
	{ EmbossFilterProperty::Angle,	L"Angle" },
	{ EmbossFilterProperty::Depth,	L"Depth" },
};
static UInt _count = SizeOf( _desc );

lang::String EmbossFilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
