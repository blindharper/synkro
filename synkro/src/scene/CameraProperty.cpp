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
// Purpose: Defines camera property names.
//==============================================================================
#include "config.h"
#include "CameraProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( CameraProperty, FieldOfView,	0 )


struct TypeDesc
{
	CameraProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ CameraProperty::FieldOfView,	L"FieldOfView" },
};
static UInt _count = SizeOf( _desc );

lang::String CameraProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
