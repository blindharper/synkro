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
// Purpose: Defines faces culling mode.
//==============================================================================
#include "config.h"
#include <gfx/CullMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( CullMode, None,	1 )
SYNKRO_DEFINE_CONST( CullMode, Front,	2 )
SYNKRO_DEFINE_CONST( CullMode, Back,	3 )


struct TypeDesc
{
	CullMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ CullMode::None,	L"None" },
	{ CullMode::Front,	L"Front" },
	{ CullMode::Back,	L"Back" },
};
static UInt _count = SizeOf( _desc );

CullMode::CullMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}

lang::String CullMode::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
