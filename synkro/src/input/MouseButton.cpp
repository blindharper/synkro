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
// Purpose: Defines mouse buttons.
//==============================================================================
#include "config.h"
#include <input/MouseButton.h>
#include <internal/Enum.h>


namespace synkro
{


namespace input
{


SYNKRO_DEFINE_CONST( MouseButton, None,		0x00 )
SYNKRO_DEFINE_CONST( MouseButton, Left,		0x01 )
SYNKRO_DEFINE_CONST( MouseButton, Right,	0x02 )
SYNKRO_DEFINE_CONST( MouseButton, Middle,	0x04 )
SYNKRO_DEFINE_CONST( MouseButton, XButton1,	0x08 )
SYNKRO_DEFINE_CONST( MouseButton, XButton2,	0x10 )


struct TypeDesc
{
	MouseButton	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ MouseButton::None,		L"" },
	{ MouseButton::Left,		L"Left" },
	{ MouseButton::Right,		L"Right" },
	{ MouseButton::None,		L"" },
	{ MouseButton::Middle,		L"Middle" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::XButton1,	L"XButton1" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::None,		L"" },
	{ MouseButton::XButton2,	L"XButton2" },
};
static UInt _count = SizeOf( _desc );

MouseButton::MouseButton( const lang::String& button ) :
	Flag( 0 )
{
	SET_FLAG_VALUE( button )
}

lang::String MouseButton::ToString() const
{
	static MouseButton flags[] =
	{
		MouseButton::Left,
		MouseButton::Right,
		MouseButton::Middle,
		MouseButton::XButton1,
		MouseButton::XButton2,
	};
	FLAG_TO_STRING( MouseButton )
}


} // input


} // synkro
