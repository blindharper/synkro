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
// Purpose: Defines texture addressing modes.
//==============================================================================
#include "config.h"
#include <gfx/TextureAddress.h>
#include <internal/Enum.h>

namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( TextureAddress, Wrap,			1 )
SYNKRO_DEFINE_CONST( TextureAddress, Mirror,		2 )
SYNKRO_DEFINE_CONST( TextureAddress, Clamp,			3 )
SYNKRO_DEFINE_CONST( TextureAddress, Border,		4 )
SYNKRO_DEFINE_CONST( TextureAddress, MirrorOnce,	5 )


struct TypeDesc
{
	TextureAddress	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ TextureAddress::Wrap,			L"Wrap" },
	{ TextureAddress::Mirror,		L"Mirror" },
	{ TextureAddress::Clamp,		L"Clamp" },
	{ TextureAddress::Border,		L"Border" },
	{ TextureAddress::MirrorOnce,	L"MirrorOnce" },
};
static UInt _count = SizeOf( _desc );

TextureAddress::TextureAddress( const lang::String& address ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( address )
}

lang::String TextureAddress::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
