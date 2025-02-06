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
// Purpose: Defines data mode.
//==============================================================================
#include "config.h"
#include <core/DataMode.h>
#include <internal/Enum.h>


namespace synkro
{


namespace core
{


SYNKRO_DEFINE_CONST( DataMode, Unknown,	0 )
SYNKRO_DEFINE_CONST( DataMode, Text,	1 )
SYNKRO_DEFINE_CONST( DataMode, Binary,	2 )


struct TypeDesc
{
	DataMode	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ DataMode::Unknown,	L"" },
	{ DataMode::Text,		L"Text" },
	{ DataMode::Binary,		L"Binary" },
};
static UInt _count = SizeOf( _desc );

DataMode::DataMode( const lang::String& mode ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( mode )
}


} // core


} // synkro
