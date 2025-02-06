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
// Purpose: Defines transparent material property names.
//==============================================================================
#include "config.h"
#include "TransparentMaterialProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace mat
{


SYNKRO_DEFINE_CONST( TransparentMaterialProperty, Opacity,	0 )


struct TypeDesc
{
	TransparentMaterialProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ TransparentMaterialProperty::Opacity,		L"Opacity" },
};
static UInt _count = SizeOf( _desc );

lang::String TransparentMaterialProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // mat


} // synkro
