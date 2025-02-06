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
// Purpose: Defines blending mode.
//==============================================================================
#include "config.h"
#include <gfx/BlendMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( BlendMode, Unknown,		0 )
SYNKRO_DEFINE_CONST( BlendMode, Zero,			1 )
SYNKRO_DEFINE_CONST( BlendMode, One,			2 )
SYNKRO_DEFINE_CONST( BlendMode, SrcColor,		3 )
SYNKRO_DEFINE_CONST( BlendMode, InvSrcColor,	4 )
SYNKRO_DEFINE_CONST( BlendMode, SrcAlpha,		5 )
SYNKRO_DEFINE_CONST( BlendMode, InvSrcAlpha,	6 )
SYNKRO_DEFINE_CONST( BlendMode, DstAlpha,		7 )
SYNKRO_DEFINE_CONST( BlendMode, InvDstAlpha,	8 )
SYNKRO_DEFINE_CONST( BlendMode, DstColor,		9 )
SYNKRO_DEFINE_CONST( BlendMode, InvDstColor,	10 )
SYNKRO_DEFINE_CONST( BlendMode, SrcAlphaSat,	11 )


struct TypeDesc
{
	BlendMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ BlendMode::Unknown,		L"" },
	{ BlendMode::Zero,			L"Zero" },
	{ BlendMode::One,			L"One" },
	{ BlendMode::SrcColor,		L"SrcColor" },
	{ BlendMode::InvSrcColor,	L"InvSrcColor" },
	{ BlendMode::SrcAlpha,		L"SrcAlpha" },
	{ BlendMode::InvSrcAlpha,	L"InvSrcAlpha" },
	{ BlendMode::DstAlpha,		L"DstAlpha" },
	{ BlendMode::InvDstAlpha,	L"InvDstAlpha" },
	{ BlendMode::DstColor,		L"DstColor" },
	{ BlendMode::InvDstColor,	L"InvDstColor" },
	{ BlendMode::SrcAlphaSat,	L"SrcAlphaSat" },
};
static UInt _count = SizeOf( _desc );

BlendMode::BlendMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}

lang::String BlendMode::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
