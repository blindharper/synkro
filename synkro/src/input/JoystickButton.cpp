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
// Purpose: Defines joystick buttons.
//=============================================================================
#include "config.h"
#include <input/JoystickButton.h>
#include <internal/Enum.h>


namespace synkro
{


namespace input
{


SYNKRO_DEFINE_CONST( JoystickButton, Unknown,	0 )
SYNKRO_DEFINE_CONST( JoystickButton, Button1,	1 )
SYNKRO_DEFINE_CONST( JoystickButton, Button2,	2 )
SYNKRO_DEFINE_CONST( JoystickButton, Button3,	3 )
SYNKRO_DEFINE_CONST( JoystickButton, Button4,	4 )
SYNKRO_DEFINE_CONST( JoystickButton, Button5,	5 )
SYNKRO_DEFINE_CONST( JoystickButton, Button6,	6 )
SYNKRO_DEFINE_CONST( JoystickButton, Button7,	7 )
SYNKRO_DEFINE_CONST( JoystickButton, Button8,	8 )
SYNKRO_DEFINE_CONST( JoystickButton, Button9,	9 )
SYNKRO_DEFINE_CONST( JoystickButton, Button10,	10 )
SYNKRO_DEFINE_CONST( JoystickButton, Button11,	11 )
SYNKRO_DEFINE_CONST( JoystickButton, Button12,	12 )
SYNKRO_DEFINE_CONST( JoystickButton, Button13,	13 )
SYNKRO_DEFINE_CONST( JoystickButton, Button14,	14 )
SYNKRO_DEFINE_CONST( JoystickButton, Button15,	15 )
SYNKRO_DEFINE_CONST( JoystickButton, Button16,	16 )
SYNKRO_DEFINE_CONST( JoystickButton, Button17,	17 )
SYNKRO_DEFINE_CONST( JoystickButton, Button18,	18 )
SYNKRO_DEFINE_CONST( JoystickButton, Button19,	19 )
SYNKRO_DEFINE_CONST( JoystickButton, Button20,	20 )
SYNKRO_DEFINE_CONST( JoystickButton, Button21,	21 )
SYNKRO_DEFINE_CONST( JoystickButton, Button22,	22 )
SYNKRO_DEFINE_CONST( JoystickButton, Button23,	23 )
SYNKRO_DEFINE_CONST( JoystickButton, Button24,	24 )
SYNKRO_DEFINE_CONST( JoystickButton, Button25,	25 )
SYNKRO_DEFINE_CONST( JoystickButton, Button26,	26 )
SYNKRO_DEFINE_CONST( JoystickButton, Button27,	27 )
SYNKRO_DEFINE_CONST( JoystickButton, Button28,	28 )
SYNKRO_DEFINE_CONST( JoystickButton, Button29,	29 )
SYNKRO_DEFINE_CONST( JoystickButton, Button30,	30 )
SYNKRO_DEFINE_CONST( JoystickButton, Button31,	31 )
SYNKRO_DEFINE_CONST( JoystickButton, Button32,	32 )


struct TypeDesc
{
	JoystickButton	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ JoystickButton::Unknown,		L"" },
	{ JoystickButton::Button1,		L"JoyBtn1" },
	{ JoystickButton::Button2,		L"JoyBtn2" },
	{ JoystickButton::Button3,		L"JoyBtn3" },
	{ JoystickButton::Button4,		L"JoyBtn4" },
	{ JoystickButton::Button5,		L"JoyBtn5" },
	{ JoystickButton::Button6,		L"JoyBtn6" },
	{ JoystickButton::Button7,		L"JoyBtn7" },
	{ JoystickButton::Button8,		L"JoyBtn8" },
	{ JoystickButton::Button9,		L"JoyBtn9" },
	{ JoystickButton::Button10,		L"JoyBtn10" },
	{ JoystickButton::Button11,		L"JoyBtn11" },
	{ JoystickButton::Button12,		L"JoyBtn12" },
	{ JoystickButton::Button13,		L"JoyBtn13" },
	{ JoystickButton::Button14,		L"JoyBtn14" },
	{ JoystickButton::Button15,		L"JoyBtn15" },
	{ JoystickButton::Button16,		L"JoyBtn16" },
	{ JoystickButton::Button17,		L"JoyBtn17" },
	{ JoystickButton::Button18,		L"JoyBtn18" },
	{ JoystickButton::Button19,		L"JoyBtn19" },
	{ JoystickButton::Button20,		L"JoyBtn20" },
	{ JoystickButton::Button21,		L"JoyBtn21" },
	{ JoystickButton::Button22,		L"JoyBtn22" },
	{ JoystickButton::Button23,		L"JoyBtn23" },
	{ JoystickButton::Button24,		L"JoyBtn24" },
	{ JoystickButton::Button25,		L"JoyBtn25" },
	{ JoystickButton::Button26,		L"JoyBtn26" },
	{ JoystickButton::Button27,		L"JoyBtn27" },
	{ JoystickButton::Button28,		L"JoyBtn28" },
	{ JoystickButton::Button29,		L"JoyBtn29" },
	{ JoystickButton::Button30,		L"JoyBtn30" },
	{ JoystickButton::Button31,		L"JoyBtn31" },
	{ JoystickButton::Button32,		L"JoyBtn32" },
};
static UInt _count = SizeOf( _desc );

JoystickButton::JoystickButton( const lang::String& button ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( button )
}

lang::String JoystickButton::ToString() const
{
	ENUM_TO_STRING()
}


} // input


} // synkro
