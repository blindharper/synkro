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
// Purpose: Defines face filling mode.
//==============================================================================
#include "config.h"
#include <gfx/FillMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( FillMode, Wireframe,	1 )
SYNKRO_DEFINE_CONST( FillMode, Solid,		2 )


struct TypeDesc
{
	FillMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ FillMode::Wireframe,	L"Wireframe" },
	{ FillMode::Solid,		L"Solid" },
};
static UInt _count = SizeOf( _desc );

FillMode::FillMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}

lang::String FillMode::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
