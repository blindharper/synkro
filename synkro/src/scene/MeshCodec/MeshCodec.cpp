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
// Purpose: Defines mesh codec types.
//==============================================================================
#include "config.h"
#include <scene/MeshCodec.h>
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( MeshCodec, Unknown,	0 )
SYNKRO_DEFINE_CONST( MeshCodec, Custom,		1 )
SYNKRO_DEFINE_CONST( MeshCodec, Obj,		2 )
SYNKRO_DEFINE_CONST( MeshCodec, X,			3 )


struct TypeDesc
{
	MeshCodec	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ MeshCodec::Unknown,	L"" },
	{ MeshCodec::Custom,	L"mesh" },
	{ MeshCodec::Obj,		L"obj" },
	{ MeshCodec::X,			L"x" },
};
static UInt _count = SizeOf( _desc );

MeshCodec::MeshCodec( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String MeshCodec::ToString() const
{
	ENUM_TO_STRING()
}

Bool MeshCodec::IsValid( const lang::String& name )
{
	IS_VALID_ENUM( name )
}


} // scene


} // synkro
