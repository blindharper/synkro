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
// Purpose: Defines force mode.
//==============================================================================
#include "config.h"
#include <phys/ForceMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace phys
{


SYNKRO_DEFINE_CONST( ForceMode, Unknown,			0 )
SYNKRO_DEFINE_CONST( ForceMode, Force,				1 )
SYNKRO_DEFINE_CONST( ForceMode, Impulse,			2 )
SYNKRO_DEFINE_CONST( ForceMode, Velocity,			3 )
SYNKRO_DEFINE_CONST( ForceMode, Acceleration,		4 )


struct TypeDesc
{
	ForceMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ ForceMode::Unknown,		L"" },
	{ ForceMode::Force,			L"Force" },
	{ ForceMode::Impulse,		L"Impulse" },
	{ ForceMode::Velocity,		L"Velocity" },
	{ ForceMode::Acceleration,	L"Acceleration" },
};
static ULong _count = SizeOf( _desc );

ForceMode::ForceMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}

lang::String ForceMode::ToString() const
{
	ENUM_TO_STRING()
}


} // phys


} // synkro
