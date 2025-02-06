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
// Purpose: Defines font styles.
//==============================================================================
#include "config.h"
#include <over/FontStyle.h>
#include <internal/Enum.h>


namespace synkro
{


namespace over
{


SYNKRO_DEFINE_CONST( FontStyle, Normal,			0x00 )
SYNKRO_DEFINE_CONST( FontStyle, Bold,			0x01 )
SYNKRO_DEFINE_CONST( FontStyle, Italic,			0x02 )
SYNKRO_DEFINE_CONST( FontStyle, Underline,		0x04 )
SYNKRO_DEFINE_CONST( FontStyle, Strikeout,		0x08 )
SYNKRO_DEFINE_CONST( FontStyle, Subscript,		0x10 )
SYNKRO_DEFINE_CONST( FontStyle, Superscript,	0x20 )


struct TypeDesc
{
	FontStyle	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Bold,			L"Bold" },
	{ FontStyle::Italic,		L"Italic" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Underline,		L"Underline" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Strikeout,		L"Strikeout" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Subscript,		L"Subscript" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Normal,		L"" },
	{ FontStyle::Superscript,	L"Superscript" },
};
static UInt _count = SizeOf( _desc );

FontStyle::FontStyle( const lang::String& style ) :
	Flag( 0 )
{
	SET_FLAG_VALUE( style )
}

lang::String FontStyle::ToString() const
{
	static FontStyle flags[] =
	{
		FontStyle::Bold,
		FontStyle::Italic,
		FontStyle::Underline,
		FontStyle::Strikeout,
		FontStyle::Subscript,
		FontStyle::Superscript,
	};
	FLAG_TO_STRING( FontStyle )
}


} // over


} // synkro
