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
// Purpose: Defines input device axes.
//==============================================================================
#include "config.h"
#include <input/Axis.h>
#include <internal/Enum.h>


namespace synkro
{


namespace input
{


SYNKRO_DEFINE_CONST( Axis, Unknown,	0 )
SYNKRO_DEFINE_CONST( Axis, X,		1 )
SYNKRO_DEFINE_CONST( Axis, Y,		2 )
SYNKRO_DEFINE_CONST( Axis, Z,		3 )


struct TypeDesc
{
	Axis		type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ Axis::Unknown,	L"" },
	{ Axis::X,			L"X" },
	{ Axis::Y,			L"Y" },
	{ Axis::Z,			L"Z" },
};
static UInt _count = SizeOf( _desc );

Axis::Axis( const lang::String& axis ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( axis )
}

lang::String Axis::ToString() const
{
	ENUM_TO_STRING()
}


} // input


} // synkro
