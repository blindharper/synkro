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
// Purpose: Defines simple filter property names.
//==============================================================================
#include "config.h"
#include "SimpleFilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( SimpleFilterProperty, ParamValue,	0 )


struct TypeDesc
{
	SimpleFilterProperty	type;
	const Char*				name;
};

static TypeDesc _desc[] = 
{
	{ SimpleFilterProperty::ParamValue,	L"ParamValue" },
};
static UInt _count = SizeOf( _desc );

lang::String SimpleFilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
