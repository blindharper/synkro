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
// Purpose: Defines content alignment.
//==============================================================================
#include "config.h"
#include <ui/Alignment.h>
#include <internal/Enum.h>
#include "AlignmentConst.h"


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( Alignment, None,			ALIGNMENT_NONE )
SYNKRO_DEFINE_CONST( Alignment, TopLeft,		ALIGNMENT_TOP_LEFT )
SYNKRO_DEFINE_CONST( Alignment, Top,			ALIGNMENT_TOP )
SYNKRO_DEFINE_CONST( Alignment, TopRight,		ALIGNMENT_TOP_RIGHT )
SYNKRO_DEFINE_CONST( Alignment, Left,			ALIGNMENT_LEFT )
SYNKRO_DEFINE_CONST( Alignment, Center,			ALIGNMENT_CENTER )
SYNKRO_DEFINE_CONST( Alignment, Right,			ALIGNMENT_RIGHT )
SYNKRO_DEFINE_CONST( Alignment, BottomLeft,		ALIGNMENT_BOTTOM_LEFT )
SYNKRO_DEFINE_CONST( Alignment, Bottom,			ALIGNMENT_BOTTOM )
SYNKRO_DEFINE_CONST( Alignment, BottomRight,	ALIGNMENT_BOTTOM_RIGHT )


struct TypeDesc
{
	Alignment	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ Alignment::None,			L"" },
	{ Alignment::TopLeft,		L"TopLeft" },
	{ Alignment::Top,			L"Top" },
	{ Alignment::TopRight,		L"TopRight" },
	{ Alignment::Left,			L"Left" },
	{ Alignment::Center,		L"Center" },
	{ Alignment::Right,			L"Right" },
	{ Alignment::BottomLeft,	L"BottomLeft" },
	{ Alignment::Bottom,		L"Bottom" },
	{ Alignment::BottomRight,	L"BottomRight" },
};
static UInt _count = SizeOf( _desc );


Alignment::Alignment( const lang::String& alignment ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( alignment )
}

lang::String Alignment::ToString() const
{
	ENUM_TO_STRING()
}


} // ui


} // synkro
