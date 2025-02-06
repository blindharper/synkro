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
// Purpose: Defines fog effect types.
//==============================================================================
#include "config.h"
#include <scene/FogType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( FogType, None,					0 )
SYNKRO_DEFINE_CONST( FogType, Linear,				1 )
SYNKRO_DEFINE_CONST( FogType, Exponential,			2 )
SYNKRO_DEFINE_CONST( FogType, ExponentialSquared,	3 )


struct TypeDesc
{
	FogType		type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ FogType::None,				L"None" },
	{ FogType::Linear,				L"Linear" },
	{ FogType::Exponential,			L"Exponential" },
	{ FogType::ExponentialSquared,	L"ExponentialSquared" },
};
static UInt _count = SizeOf( _desc );

FogType::FogType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String FogType::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
