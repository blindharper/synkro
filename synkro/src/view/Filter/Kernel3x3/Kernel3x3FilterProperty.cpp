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
// Purpose: Defines kernel3x3 filter property names.
//==============================================================================
#include "config.h"
#include "Kernel3x3FilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( Kernel3x3FilterProperty, PassCount,	0 )


struct TypeDesc
{
	Kernel3x3FilterProperty	type;
	const Char*				name;
};

static TypeDesc _desc[] = 
{
	{ Kernel3x3FilterProperty::PassCount,	L"PassCount" },
};
static UInt _count = SizeOf( _desc );

lang::String Kernel3x3FilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
