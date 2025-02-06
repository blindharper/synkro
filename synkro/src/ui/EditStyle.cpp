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
// Purpose: Defines text edit styles.
//==============================================================================
#include "config.h"
#include <ui/EditStyle.h>
#include <internal/Enum.h>
#include "EditStyleConst.h"


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( EditStyle, Normal,			EDIT_STYLE_NORMAL )
SYNKRO_DEFINE_CONST( EditStyle, Upper,			EDIT_STYLE_UPPER )
SYNKRO_DEFINE_CONST( EditStyle, Lower,			EDIT_STYLE_LOWER )
SYNKRO_DEFINE_CONST( EditStyle, Integer,		EDIT_STYLE_INTEGER )
SYNKRO_DEFINE_CONST( EditStyle, Decimal,		EDIT_STYLE_DECIMAL )
SYNKRO_DEFINE_CONST( EditStyle, Hexadecimal,	EDIT_STYLE_HEXADECIMAL )


struct TypeDesc
{
	EditStyle	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ EditStyle::Normal,		L"" },
	{ EditStyle::Upper,			L"Upper" },
	{ EditStyle::Lower,			L"Lower" },
	{ EditStyle::Integer,		L"Integer" },
	{ EditStyle::Decimal,		L"Decimal" },
	{ EditStyle::Hexadecimal,	L"Hexadecimal" },
};
static UInt _count = SizeOf( _desc );


EditStyle::EditStyle( const lang::String& style ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( style )
}

lang::String EditStyle::ToString() const
{
	ENUM_TO_STRING()
}


} // ui


} // synkro
