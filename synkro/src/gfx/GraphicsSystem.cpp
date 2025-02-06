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
// Purpose: Defines graphics system types.
//==============================================================================
#include "config.h"
#include <gfx/GraphicsSystem.h>
#include <internal/Enum.h>

namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( GraphicsSystem, Custom,	0 )
SYNKRO_DEFINE_CONST( GraphicsSystem, DirectX11,	1 )


struct TypeDesc
{
	GraphicsSystem	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ GraphicsSystem::Custom,		L"Custom" },
	{ GraphicsSystem::DirectX11,	L"DirectX11" },
};
static UInt _count = SizeOf( _desc );

lang::String GraphicsSystem::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
