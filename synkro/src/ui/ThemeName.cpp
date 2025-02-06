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
// Purpose: Defines standard user interface theme names.
//==============================================================================
#include "config.h"
#include <ui/ThemeName.h>
#include <internal/Enum.h>


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( ThemeName, Custom,	0 )
SYNKRO_DEFINE_CONST( ThemeName, Glass,	1 )
SYNKRO_DEFINE_CONST( ThemeName, Flat,	2 )


struct TypeDesc
{
	ThemeName	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ ThemeName::Custom,	L"Custom" },
	{ ThemeName::Glass,		L"Glass" },
	{ ThemeName::Flat,		L"Flat" },
};
static UInt _count = SizeOf( _desc );

ThemeName::ThemeName( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String ThemeName::ToString() const
{
	ENUM_TO_STRING()
}


} // ui


} // synkro
