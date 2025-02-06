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
// Purpose: Defines widget anchors.
//==============================================================================
#include "config.h"
#include <ui/Anchor.h>
#include <internal/Enum.h>


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( Anchor, None,			0x00 )
SYNKRO_DEFINE_CONST( Anchor, Left,			0x01 )
SYNKRO_DEFINE_CONST( Anchor, Right,			0x02 )
SYNKRO_DEFINE_CONST( Anchor, Top,			0x04 )
SYNKRO_DEFINE_CONST( Anchor, Bottom,		0x08 )
SYNKRO_DEFINE_CONST( Anchor, TopLeft,		0x05 )
SYNKRO_DEFINE_CONST( Anchor, TopRight,		0x06 )
SYNKRO_DEFINE_CONST( Anchor, BottomLeft,	0x09 )
SYNKRO_DEFINE_CONST( Anchor, BottomRight,	0x0a )
SYNKRO_DEFINE_CONST( Anchor, All,			0x0f )


struct TypeDesc
{
	Anchor	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ Anchor::None,			L"" },
	{ Anchor::Left,			L"Left" },
	{ Anchor::Right,		L"Right" },
	{ Anchor::None,			L"" },
	{ Anchor::Top,			L"Top" },
	{ Anchor::TopLeft,		L"TopLeft" },
	{ Anchor::TopRight,		L"TopRight" },
	{ Anchor::None,			L"" },
	{ Anchor::Bottom,		L"Bottom" },
	{ Anchor::BottomLeft,	L"BottomLeft" },
	{ Anchor::BottomRight,	L"BottomRight" },
	{ Anchor::None,			L"" },
	{ Anchor::None,			L"" },
	{ Anchor::None,			L"" },
	{ Anchor::None,			L"" },
	{ Anchor::All,			L"All" },
};
static UInt _count = SizeOf( _desc );


Anchor::Anchor( const lang::String& anchor ) :
	Flag( 0 )
{
	SET_FLAG_VALUE( anchor )
}

lang::String Anchor::ToString() const
{
	static Anchor flags[] =
	{
		Anchor::Left,
		Anchor::Right,
		Anchor::Top,
		Anchor::Bottom,
		Anchor::TopLeft,
		Anchor::TopRight,
		Anchor::BottomLeft,
		Anchor::BottomRight,
		Anchor::All,
	};
	FLAG_TO_STRING( Anchor )
}


} // ui


} // synkro
