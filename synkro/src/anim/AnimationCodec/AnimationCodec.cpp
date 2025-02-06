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
// Purpose: Defines animation codec types.
//==============================================================================
#include "config.h"
#include <anim/AnimationCodec.h>
#include <internal/Enum.h>


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( AnimationCodec, Unknown,	0 )
SYNKRO_DEFINE_CONST( AnimationCodec, Custom,	1 )
SYNKRO_DEFINE_CONST( AnimationCodec, Bin,		2 )
SYNKRO_DEFINE_CONST( AnimationCodec, Sql,		3 )
SYNKRO_DEFINE_CONST( AnimationCodec, Xml,		4 )


struct TypeDesc
{
	AnimationCodec	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ AnimationCodec::Unknown,	L"" },
	{ AnimationCodec::Custom,	L"anim" },
	{ AnimationCodec::Bin,		L"bia" },
	{ AnimationCodec::Sql,		L"sqa" },
	{ AnimationCodec::Xml,		L"xma" },
};
static UInt _count = SizeOf( _desc );

AnimationCodec::AnimationCodec( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String AnimationCodec::ToString() const
{
	ENUM_TO_STRING()
}


} // anim


} // synkro
