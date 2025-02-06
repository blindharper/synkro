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
// Purpose: Defines scene node property names.
//==============================================================================
#include "config.h"
#include "NodeProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( NodeProperty, Transform,			 0 )
SYNKRO_DEFINE_CONST( NodeProperty, Position,			 1 )
SYNKRO_DEFINE_CONST( NodeProperty, PositionX,			 2 )
SYNKRO_DEFINE_CONST( NodeProperty, PositionY,			 3 )
SYNKRO_DEFINE_CONST( NodeProperty, PositionZ,			 4 )
SYNKRO_DEFINE_CONST( NodeProperty, Orientation,			 5 )
SYNKRO_DEFINE_CONST( NodeProperty, OrientationYaw,		 6 )
SYNKRO_DEFINE_CONST( NodeProperty, OrientationPitch,	 7 )
SYNKRO_DEFINE_CONST( NodeProperty, OrientationRoll,		 8 )
SYNKRO_DEFINE_CONST( NodeProperty, Scale,				 9 )
SYNKRO_DEFINE_CONST( NodeProperty, ScaleX,				10 )
SYNKRO_DEFINE_CONST( NodeProperty, ScaleY,				11 )
SYNKRO_DEFINE_CONST( NodeProperty, ScaleZ,				12 )
SYNKRO_DEFINE_CONST( NodeProperty, ScaleUniform,		13 )
SYNKRO_DEFINE_CONST( NodeProperty, PathPhase,			14 )


struct TypeDesc
{
	NodeProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ NodeProperty::Transform,			L"Transform" },
	{ NodeProperty::Position,			L"Position" },
	{ NodeProperty::PositionX,			L"Position.X" },
	{ NodeProperty::PositionY,			L"Position.Y" },
	{ NodeProperty::PositionZ,			L"Position.Z" },
	{ NodeProperty::Orientation,		L"Orientation" },
	{ NodeProperty::OrientationYaw,		L"Orientation.Yaw" },
	{ NodeProperty::OrientationPitch,	L"Orientation.Pitch" },
	{ NodeProperty::OrientationRoll,	L"Orientation.Roll" },
	{ NodeProperty::Scale,				L"Scale" },
	{ NodeProperty::ScaleX,				L"Scale.X" },
	{ NodeProperty::ScaleY,				L"Scale.Y" },
	{ NodeProperty::ScaleZ,				L"Scale.Z" },
	{ NodeProperty::ScaleUniform,		L"Scale.Uniform" },
	{ NodeProperty::PathPhase,			L"Path.Phase" },
};
static UInt _count = SizeOf( _desc );

lang::String NodeProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
