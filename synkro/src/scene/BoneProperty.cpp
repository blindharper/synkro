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
// Purpose: Defines skeleton bone property names.
//==============================================================================
#include "config.h"
#include "BoneProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( BoneProperty, Transform,	0 )
SYNKRO_DEFINE_CONST( BoneProperty, Position,	1 )
SYNKRO_DEFINE_CONST( BoneProperty, Orientation,	2 )
SYNKRO_DEFINE_CONST( BoneProperty, Scale,		3 )


struct TypeDesc
{
	BoneProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ BoneProperty::Transform,			L"Transform" },
	{ BoneProperty::Position,			L"Position" },
	{ BoneProperty::Orientation,		L"Orientation" },
	{ BoneProperty::Scale,				L"Scale" },
};
static UInt _count = SizeOf( _desc );

lang::String BoneProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
