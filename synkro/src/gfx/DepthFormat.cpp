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
// Purpose: Defines depth buffer format.
//==============================================================================
#include "config.h"
#include <gfx/DepthFormat.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( DepthFormat, Unknown,	0 )
SYNKRO_DEFINE_CONST( DepthFormat, D32F,		1 )
SYNKRO_DEFINE_CONST( DepthFormat, D24,		2 )
SYNKRO_DEFINE_CONST( DepthFormat, D16,		3 )


struct TypeDesc
{
	DepthFormat	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ DepthFormat::Unknown,	L"Unknown" },
	{ DepthFormat::D32F,	L"D32F" },
	{ DepthFormat::D24,		L"D24" },
	{ DepthFormat::D16,		L"D16" },
};
static UInt _count = SizeOf( _desc );

DepthFormat::DepthFormat( const lang::String& format ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( format )
}

lang::String DepthFormat::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
