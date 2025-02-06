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
// Purpose: Defines keyboard keys.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEY_
#define _SYNKRO_INPUT_KEY_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace input
{


/**
 * Keyboard keys.
 */
SYNKRO_ENUM_BEGIN( Key )
	/** Unknown key. */
	SYNKRO_ENUM_CONST( Key, Unknown )

	/** The Escape key. */
	SYNKRO_ENUM_CONST( Key, Escape )

	/** The 1 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D1 )

	/** The 2 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D2 )

	/** The 3 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D3 )

	/** The 4 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D4 )

	/** The 5 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D5 )

	/** The 6 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D6 )

	/** The 7 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D7 )

	/** The 8 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D8 )

	/** The 9 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D9 )

	/** The 0 key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, D0 )

	/** - key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, Minus )

	/** The = key. */
	SYNKRO_ENUM_CONST( Key, Equals )

	/** The Backspace key. */
	SYNKRO_ENUM_CONST( Key, Back )

	/** The Tab key. */
	SYNKRO_ENUM_CONST( Key, Tab )

	/** The Q key. */
	SYNKRO_ENUM_CONST( Key, Q )

	/** The W key. */
	SYNKRO_ENUM_CONST( Key, W )

	/** The E key. */
	SYNKRO_ENUM_CONST( Key, E )

	/** The R key. */
	SYNKRO_ENUM_CONST( Key, R )

	/** The T key. */
	SYNKRO_ENUM_CONST( Key, T )

	/** The Y key. */
	SYNKRO_ENUM_CONST( Key, Y )

	/** The U key. */
	SYNKRO_ENUM_CONST( Key, U )

	/** The I key. */
	SYNKRO_ENUM_CONST( Key, I )

	/** The O key. */
	SYNKRO_ENUM_CONST( Key, O )

	/** The P key. */
	SYNKRO_ENUM_CONST( Key, P )

	/** The [ key. */
	SYNKRO_ENUM_CONST( Key, LeftBracket )

	/** The ] key. */
	SYNKRO_ENUM_CONST( Key, RightBracket )

	/** The Enter key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, Return )

	/** The left Ctrl key. */
	SYNKRO_ENUM_CONST( Key, LeftControl )

	/** The A key. */
	SYNKRO_ENUM_CONST( Key, A )

	/** The S key. */
	SYNKRO_ENUM_CONST( Key, S )

	/** The D key. */
	SYNKRO_ENUM_CONST( Key, D )

	/** The F key. */
	SYNKRO_ENUM_CONST( Key, F )

	/** The G key. */
	SYNKRO_ENUM_CONST( Key, G )

	/** The H key. */
	SYNKRO_ENUM_CONST( Key, H )

	/** The J key. */
	SYNKRO_ENUM_CONST( Key, J )

	/** The K key. */
	SYNKRO_ENUM_CONST( Key, K )

	/** The L key. */
	SYNKRO_ENUM_CONST( Key, L )

	/** The ; key. */
	SYNKRO_ENUM_CONST( Key, Semicolon )

	/** The ' key. */
	SYNKRO_ENUM_CONST( Key, Apostrophe )

	/** The ` key. */
	SYNKRO_ENUM_CONST( Key, Grave )

	/** The left Shift key. */
	SYNKRO_ENUM_CONST( Key, LeftShift )

	/** The \ key. */
	SYNKRO_ENUM_CONST( Key, BackSlash )

	/** The Z key. */
	SYNKRO_ENUM_CONST( Key, Z )

	/** The X key. */
	SYNKRO_ENUM_CONST( Key, X )

	/** The C key. */
	SYNKRO_ENUM_CONST( Key, C )

	/** The V key. */
	SYNKRO_ENUM_CONST( Key, V )

	/** The B key. */
	SYNKRO_ENUM_CONST( Key, B )

	/** The N key. */
	SYNKRO_ENUM_CONST( Key, N )

	/** The M key. */
	SYNKRO_ENUM_CONST( Key, M )

	/** The , key. */
	SYNKRO_ENUM_CONST( Key, Comma )

	/** The . key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, Period )

	/** The / key on main keyboard. */
	SYNKRO_ENUM_CONST( Key, Slash )

	/** The right Shift key. */
	SYNKRO_ENUM_CONST( Key, RightShift )

	/** The * key on numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Multiply )

	/** The left Alt key. */
	SYNKRO_ENUM_CONST( Key, LeftAlt )

	/** The Spacebar key. */
	SYNKRO_ENUM_CONST( Key, Space )

	/** The Caps Lock key. */
	SYNKRO_ENUM_CONST( Key, Capital )

	/** The F1 key. */
	SYNKRO_ENUM_CONST( Key, F1 )

	/** The F2 key. */
	SYNKRO_ENUM_CONST( Key, F2 )

	/** The F3 key. */
	SYNKRO_ENUM_CONST( Key, F3 )

	/** The F4 key. */
	SYNKRO_ENUM_CONST( Key, F4 )

	/** The F5 key. */
	SYNKRO_ENUM_CONST( Key, F5 )

	/** The F6 key. */
	SYNKRO_ENUM_CONST( Key, F6 )

	/** The F7 key. */
	SYNKRO_ENUM_CONST( Key, F7 )

	/** The F8 key. */
	SYNKRO_ENUM_CONST( Key, F8 )

	/** The F9 key. */
	SYNKRO_ENUM_CONST( Key, F9 )

	/** The F10 key. */
	SYNKRO_ENUM_CONST( Key, F10 )

	/** The Num Lock key. */
	SYNKRO_ENUM_CONST( Key, NumLock )

	/** The Scroll Lock key. */
	SYNKRO_ENUM_CONST( Key, Scroll )

	/** The 7 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad7 )

	/** The 8 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad8 )

	/** The 9 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad9 )

	/** The - key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Subtract )

	/** The 4 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad4 )

	/** The 5 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad5 )

	/** The 6 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad6 )

	/** The + key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Add )

	/** The 1 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad1 )

	/** The 2 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad2 )

	/** The 3 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad3 )

	/** The 0 key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Numpad0 )

	/** The . key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Decimal )

	/** The <> or \| key on the RT 102-key keyboard. */
	SYNKRO_ENUM_CONST( Key, Oem102 )

	/** The F11 key. */
	SYNKRO_ENUM_CONST( Key, F11 )

	/** The F12 key. */
	SYNKRO_ENUM_CONST( Key, F12 )

	/** Any of the Shift keys. */
	SYNKRO_ENUM_CONST( Key, Shift )

	/** The F13 key. */
	SYNKRO_ENUM_CONST( Key, F13 )

	/** The F14 key. */
	SYNKRO_ENUM_CONST( Key, F14 )

	/** The F15 key. */
	SYNKRO_ENUM_CONST( Key, F15 )

	/** The IME Kana mode key. */
	SYNKRO_ENUM_CONST( Key, Kana )

	/** The /? key on Brazilian keyboard. */
	SYNKRO_ENUM_CONST( Key, AbntC1 )

	/** The IME convert key. */
	SYNKRO_ENUM_CONST( Key, ImeConvert )

	/** The IME noconvert key. */
	SYNKRO_ENUM_CONST( Key, ImeNoConvert )

	/** The Yen key. */
	SYNKRO_ENUM_CONST( Key, Yen )

	/** The . key on Brazilian keyboard numpad. */
	SYNKRO_ENUM_CONST( Key, AbntC2 )

	/** The = key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, NumpadEquals )

	/** The Previous Track key. */
	SYNKRO_ENUM_CONST( Key, PrevTrack )

	/** The At key. */
	SYNKRO_ENUM_CONST( Key, At )

	/** The : key. */
	SYNKRO_ENUM_CONST( Key, Colon )

	/** The _ key. */
	SYNKRO_ENUM_CONST( Key, Underline )

	/** The IME Kanji mode key. */
	SYNKRO_ENUM_CONST( Key, Kanji )

	/** The Stop key. */
	SYNKRO_ENUM_CONST( Key, Stop )

	/** The Ax key. */
	SYNKRO_ENUM_CONST( Key, Ax )

	/** Unlabeled key. */
	SYNKRO_ENUM_CONST( Key, Unlabeled )

	/** The Next Track key. */
	SYNKRO_ENUM_CONST( Key, NextTrack )

	/** The Enter key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, NumpadEnter )

	/** The right Ctrl key. */
	SYNKRO_ENUM_CONST( Key, RightControl )

	/** The Mute key. */
	SYNKRO_ENUM_CONST( Key, Mute )

	/** The Calculator key. */
	SYNKRO_ENUM_CONST( Key, Calculator )

	/** The Play/Pause key. */
	SYNKRO_ENUM_CONST( Key, PlayPause )

	/** Stop Media key. */
	SYNKRO_ENUM_CONST( Key, MediaStop )

	/** Volume - key. */
	SYNKRO_ENUM_CONST( Key, VolumeDown )

	/** Volume + key. */
	SYNKRO_ENUM_CONST( Key, VolumeUp )

	/** Web home key. */
	SYNKRO_ENUM_CONST( Key, WebHome )

	/** The , key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, NumpadComma )

	/** The / key on the numeric keypad. */
	SYNKRO_ENUM_CONST( Key, Divide )

	/** The Print Screen key. */
	SYNKRO_ENUM_CONST( Key, PrintScreen )

	/** The right Alt key. */
	SYNKRO_ENUM_CONST( Key, RightAlt )

	/** Any of the Ctrl keys. */
	SYNKRO_ENUM_CONST( Key, Control )

	/** Pause. */
	SYNKRO_ENUM_CONST( Key, Pause )

	/** The Home key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Home )

	/** The Up Arrow key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Up )

	/** The PgUp key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Prior )

	/** The Left Arrow key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Left )

	/** The Right Arrow key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Right )

	/** The End key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, End )

	/** The Down Arrow key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Down )

	/** The PgDn key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Next )

	/** The Insert key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Insert )

	/** The Delete key on the arrow keypad. */
	SYNKRO_ENUM_CONST( Key, Delete )

	/** The left Windows key. */
	SYNKRO_ENUM_CONST( Key, LeftWin )

	/** The right Windows key. */
	SYNKRO_ENUM_CONST( Key, RightWin )

	/** The Application Menu key. */
	SYNKRO_ENUM_CONST( Key, Apps )

	/** The System Power key. */
	SYNKRO_ENUM_CONST( Key, Power )

	/** The System Sleep key. */
	SYNKRO_ENUM_CONST( Key, Sleep )

	/** The System Wake key. */
	SYNKRO_ENUM_CONST( Key, Wake )

	/** The Web Search key. */
	SYNKRO_ENUM_CONST( Key, WebSearch )

	/** The Web Favorites key. */
	SYNKRO_ENUM_CONST( Key, WebFavorites )

	/** The Web Refresh key. */
	SYNKRO_ENUM_CONST( Key, WebRefresh )

	/** The Web Stop key. */
	SYNKRO_ENUM_CONST( Key, WebStop )

	/** The Web Forward key. */
	SYNKRO_ENUM_CONST( Key, WebForward )

	/** The Web Back key. */
	SYNKRO_ENUM_CONST( Key, WebBack )

	/** The My Computer key. */
	SYNKRO_ENUM_CONST( Key, MyComputer )

	/** The Mail key. */
	SYNKRO_ENUM_CONST( Key, Mail )

	/** The Select Media key. */
	SYNKRO_ENUM_CONST( Key, MediaSelect )

	/** Any of the Alt keys. */
	SYNKRO_ENUM_CONST( Key, Alt )

	/** Creates key from string. */
	Key( const lang::String& key );

	/** Converts key to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEY_
