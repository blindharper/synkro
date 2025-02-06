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
// Purpose: Win32 joystick.
//==============================================================================
#include "config.h"
#include "Win32Joystick.h"
#include "Win32.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


#define SET_BUTTON( i )	if ( info.dwButtons & JOY_BUTTON##i ) {_state.Buttons[i-1] = 0x80;}


namespace synkro
{


namespace input
{


Win32Joystick::Win32Joystick( const JoystickDesc& desc ) :
	JoystickImpl<IJoystick>( desc )
{
}

Bool Win32Joystick::Update( Double delta )
{
	JOYINFOEX info;
	info.dwSize		= sizeof(JOYINFOEX);
	info.dwFlags	= JOY_RETURNALL;
	if ( Win32::JoyGetPosEx(0, &info) != JOYERR_NOERROR )
		return false;

	SET_BUTTON( 1 ); SET_BUTTON( 2 ); SET_BUTTON( 3 ); SET_BUTTON( 4 );
	SET_BUTTON( 5 ); SET_BUTTON( 6 ); SET_BUTTON( 7 ); SET_BUTTON( 8 );
	SET_BUTTON( 9 ); SET_BUTTON( 10); SET_BUTTON( 11); SET_BUTTON( 12);
	SET_BUTTON( 13); SET_BUTTON( 14); SET_BUTTON( 15); SET_BUTTON( 16);
	SET_BUTTON( 17); SET_BUTTON( 18); SET_BUTTON( 19); SET_BUTTON( 20);
	SET_BUTTON( 21); SET_BUTTON( 22); SET_BUTTON( 23); SET_BUTTON( 24);
	SET_BUTTON( 25); SET_BUTTON( 26); SET_BUTTON( 27); SET_BUTTON( 28);
	SET_BUTTON( 29); SET_BUTTON( 30); SET_BUTTON( 31); SET_BUTTON( 32);

	_state.Axes[0]	= CastInt( info.dwXpos );
	_state.Axes[1]	= CastInt( info.dwYpos );
	_state.Axes[2]	= CastInt( info.dwZpos );

	return true;
}


} // input


} // synkro
