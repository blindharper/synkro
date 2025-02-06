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
// Purpose: Defines data stream types.
//==============================================================================
#include "config.h"
#include <gfx/DataStream.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( DataStream, Unknown,		0 )
SYNKRO_DEFINE_CONST( DataStream, Position2D,	1 )
SYNKRO_DEFINE_CONST( DataStream, Position3D,	2 )
SYNKRO_DEFINE_CONST( DataStream, Position4D,	3 )
SYNKRO_DEFINE_CONST( DataStream, Normal,		4 )
SYNKRO_DEFINE_CONST( DataStream, Color,			5 )
SYNKRO_DEFINE_CONST( DataStream, Bones,			6 )
SYNKRO_DEFINE_CONST( DataStream, Weights,		7 )
SYNKRO_DEFINE_CONST( DataStream, TexCoord2D,	8 )
SYNKRO_DEFINE_CONST( DataStream, TexCoord3D,	9 )
SYNKRO_DEFINE_CONST( DataStream, Transform,		10 )
SYNKRO_DEFINE_CONST( DataStream, ID,			11 )


struct TypeDesc
{
	DataStream	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ DataStream::Unknown,		L"" },
	{ DataStream::Position2D,	L"POSITION2D" },
	{ DataStream::Position3D,	L"POSITION" },
	{ DataStream::Position4D,	L"POSITION4D" },
	{ DataStream::Normal,		L"NORMAL" },
	{ DataStream::Color,		L"COLOR" },
	{ DataStream::Bones,		L"BONES" },
	{ DataStream::Weights,		L"WEIGHTS" },
	{ DataStream::TexCoord2D,	L"TEXCOORD" },
	{ DataStream::TexCoord3D,	L"TEXCOORD3D" },
	{ DataStream::Transform,	L"TRANSFORM" },
	{ DataStream::ID,			L"ID" },
};
static UInt _count = SizeOf( _desc );

DataStream::DataStream( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String DataStream::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
