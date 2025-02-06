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
// Purpose: Defines comparison functions.
//==============================================================================
#include "config.h"
#include <gfx/CompareFunction.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( CompareFunction, Never,			0 )
SYNKRO_DEFINE_CONST( CompareFunction, Less,				1 )
SYNKRO_DEFINE_CONST( CompareFunction, Equal,			2 )
SYNKRO_DEFINE_CONST( CompareFunction, LessOrEqual,		3 )
SYNKRO_DEFINE_CONST( CompareFunction, Greater,			4 )
SYNKRO_DEFINE_CONST( CompareFunction, NotEqual,			5 )
SYNKRO_DEFINE_CONST( CompareFunction, GreaterOrEqual,	6 )
SYNKRO_DEFINE_CONST( CompareFunction, Always,			7 )


struct TypeDesc
{
	CompareFunction	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ CompareFunction::Never,			L"Never" },
	{ CompareFunction::Less,			L"Less" },
	{ CompareFunction::Equal,			L"Equal" },
	{ CompareFunction::LessOrEqual,		L"LessOrEqual" },
	{ CompareFunction::Greater,			L"Greater" },
	{ CompareFunction::NotEqual,		L"NotEqual" },
	{ CompareFunction::GreaterOrEqual,	L"GreaterOrEqual" },
	{ CompareFunction::Always,			L"Always" },
};
static UInt _count = SizeOf( _desc );

CompareFunction::CompareFunction( const lang::String& function ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( function )
}

lang::String CompareFunction::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
