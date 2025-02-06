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
// Purpose: Defines viewport filter property names.
//==============================================================================
#include "config.h"
#include "ViewportFilterProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace view
{


SYNKRO_DEFINE_CONST( ViewportFilterProperty, Rect,	0 )


struct TypeDesc
{
	ViewportFilterProperty	type;
	const Char*				name;
};

static TypeDesc _desc[] = 
{
	{ ViewportFilterProperty::Rect,	L"Rect" },
};
static UInt _count = SizeOf( _desc );

lang::String ViewportFilterProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // view


} // synkro
