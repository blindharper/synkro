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
// Purpose: Defines geometric primitive property names.
//==============================================================================
#include "config.h"
#include "PrimitiveProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( PrimitiveProperty, Transform,			0 )
SYNKRO_DEFINE_CONST( PrimitiveProperty, Orientation,		1 )
SYNKRO_DEFINE_CONST( PrimitiveProperty, OrientationYaw,		2 )
SYNKRO_DEFINE_CONST( PrimitiveProperty, OrientationPitch,	3 )
SYNKRO_DEFINE_CONST( PrimitiveProperty, OrientationRoll,	4 )
SYNKRO_DEFINE_CONST( PrimitiveProperty, ElementRange,		5 )


struct TypeDesc
{
	PrimitiveProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ PrimitiveProperty::Transform,			L"Transform" },
	{ PrimitiveProperty::Orientation,		L"Orientation" },
	{ PrimitiveProperty::OrientationYaw,	L"OrientationYaw" },
	{ PrimitiveProperty::OrientationPitch,	L"OrientationPitch" },
	{ PrimitiveProperty::OrientationRoll,	L"OrientationRoll" },
	{ PrimitiveProperty::ElementRange,		L"ElementRange" },
};
static UInt _count = SizeOf( _desc );

lang::String PrimitiveProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
