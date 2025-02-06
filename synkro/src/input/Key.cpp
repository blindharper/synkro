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
#include "config.h"
#include <input/Key.h>
#include <internal/Enum.h>
#include "KeyConst.h"


namespace synkro
{


namespace input
{


SYNKRO_DEFINE_CONST( Key, Unknown,		KEY_UNKNOWN )
SYNKRO_DEFINE_CONST( Key, Escape,		KEY_ESCAPE )
SYNKRO_DEFINE_CONST( Key, D1,			KEY_D1 )
SYNKRO_DEFINE_CONST( Key, D2,			KEY_D2 )
SYNKRO_DEFINE_CONST( Key, D3,			KEY_D3 )
SYNKRO_DEFINE_CONST( Key, D4,			KEY_D4 )
SYNKRO_DEFINE_CONST( Key, D5,			KEY_D5 )
SYNKRO_DEFINE_CONST( Key, D6,			KEY_D6 )
SYNKRO_DEFINE_CONST( Key, D7,			KEY_D7 )
SYNKRO_DEFINE_CONST( Key, D8,			KEY_D8 )
SYNKRO_DEFINE_CONST( Key, D9,			KEY_D9 )
SYNKRO_DEFINE_CONST( Key, D0,			KEY_D0 )
SYNKRO_DEFINE_CONST( Key, Minus,		KEY_MINUS )
SYNKRO_DEFINE_CONST( Key, Equals,		KEY_EQUALS )
SYNKRO_DEFINE_CONST( Key, Back,			KEY_BACK )
SYNKRO_DEFINE_CONST( Key, Tab,			KEY_TAB )
SYNKRO_DEFINE_CONST( Key, Q,			KEY_Q )
SYNKRO_DEFINE_CONST( Key, W,			KEY_W )
SYNKRO_DEFINE_CONST( Key, E,			KEY_E )
SYNKRO_DEFINE_CONST( Key, R,			KEY_R )
SYNKRO_DEFINE_CONST( Key, T,			KEY_T )
SYNKRO_DEFINE_CONST( Key, Y,			KEY_Y )
SYNKRO_DEFINE_CONST( Key, U,			KEY_U )
SYNKRO_DEFINE_CONST( Key, I,			KEY_I )
SYNKRO_DEFINE_CONST( Key, O,			KEY_O )
SYNKRO_DEFINE_CONST( Key, P,			KEY_P )
SYNKRO_DEFINE_CONST( Key, LeftBracket,	KEY_LEFT_BRACKET )
SYNKRO_DEFINE_CONST( Key, RightBracket,	KEY_RIGHT_BRACKET )
SYNKRO_DEFINE_CONST( Key, Return,		KEY_RETURN )
SYNKRO_DEFINE_CONST( Key, LeftControl,	KEY_LEFT_CONTROL )
SYNKRO_DEFINE_CONST( Key, A,			KEY_A )
SYNKRO_DEFINE_CONST( Key, S,			KEY_S )
SYNKRO_DEFINE_CONST( Key, D,			KEY_D )
SYNKRO_DEFINE_CONST( Key, F,			KEY_F )
SYNKRO_DEFINE_CONST( Key, G,			KEY_G )
SYNKRO_DEFINE_CONST( Key, H,			KEY_H )
SYNKRO_DEFINE_CONST( Key, J,			KEY_J )
SYNKRO_DEFINE_CONST( Key, K,			KEY_K )
SYNKRO_DEFINE_CONST( Key, L,			KEY_L )
SYNKRO_DEFINE_CONST( Key, Semicolon,	KEY_SEMICOLON )
SYNKRO_DEFINE_CONST( Key, Apostrophe,	KEY_APOSTROPHE )
SYNKRO_DEFINE_CONST( Key, Grave,		KEY_GRAVE )
SYNKRO_DEFINE_CONST( Key, LeftShift,	KEY_LEFT_SHIFT )
SYNKRO_DEFINE_CONST( Key, BackSlash,	KEY_BACK_SLASH )
SYNKRO_DEFINE_CONST( Key, Z,			KEY_Z )
SYNKRO_DEFINE_CONST( Key, X,			KEY_X )
SYNKRO_DEFINE_CONST( Key, C,			KEY_C )
SYNKRO_DEFINE_CONST( Key, V,			KEY_V )
SYNKRO_DEFINE_CONST( Key, B,			KEY_B )
SYNKRO_DEFINE_CONST( Key, N,			KEY_N )
SYNKRO_DEFINE_CONST( Key, M,			KEY_M )
SYNKRO_DEFINE_CONST( Key, Comma,		KEY_COMMA )
SYNKRO_DEFINE_CONST( Key, Period,		KEY_PERIOD )
SYNKRO_DEFINE_CONST( Key, Slash,		KEY_SLASH )
SYNKRO_DEFINE_CONST( Key, RightShift,	KEY_RIGHT_SHIFT )
SYNKRO_DEFINE_CONST( Key, Multiply,		KEY_MULTIPLY )
SYNKRO_DEFINE_CONST( Key, LeftAlt,		KEY_LEFT_ALT )
SYNKRO_DEFINE_CONST( Key, Space,		KEY_SPACE )
SYNKRO_DEFINE_CONST( Key, Capital,		KEY_CAPITAL )
SYNKRO_DEFINE_CONST( Key, F1,			KEY_F1 )
SYNKRO_DEFINE_CONST( Key, F2,			KEY_F2 )
SYNKRO_DEFINE_CONST( Key, F3,			KEY_F3 )
SYNKRO_DEFINE_CONST( Key, F4,			KEY_F4 )
SYNKRO_DEFINE_CONST( Key, F5,			KEY_F5 )
SYNKRO_DEFINE_CONST( Key, F6,			KEY_F6 )
SYNKRO_DEFINE_CONST( Key, F7,			KEY_F7 )
SYNKRO_DEFINE_CONST( Key, F8,			KEY_F8 )
SYNKRO_DEFINE_CONST( Key, F9,			KEY_F9 )
SYNKRO_DEFINE_CONST( Key, F10,			KEY_F10 )
SYNKRO_DEFINE_CONST( Key, NumLock,		KEY_NUM_LOCK )
SYNKRO_DEFINE_CONST( Key, Scroll,		KEY_SCROLL )
SYNKRO_DEFINE_CONST( Key, Numpad7,		KEY_NUMPAD7 )
SYNKRO_DEFINE_CONST( Key, Numpad8,		KEY_NUMPAD8 )
SYNKRO_DEFINE_CONST( Key, Numpad9,		KEY_NUMPAD9 )
SYNKRO_DEFINE_CONST( Key, Subtract,		KEY_SUBTRACT )
SYNKRO_DEFINE_CONST( Key, Numpad4,		KEY_NUMPAD4 )
SYNKRO_DEFINE_CONST( Key, Numpad5,		KEY_NUMPAD5 )
SYNKRO_DEFINE_CONST( Key, Numpad6,		KEY_NUMPAD6 )
SYNKRO_DEFINE_CONST( Key, Add,			KEY_ADD )
SYNKRO_DEFINE_CONST( Key, Numpad1,		KEY_NUMPAD1 )
SYNKRO_DEFINE_CONST( Key, Numpad2,		KEY_NUMPAD2 )
SYNKRO_DEFINE_CONST( Key, Numpad3,		KEY_NUMPAD3 )
SYNKRO_DEFINE_CONST( Key, Numpad0,		KEY_NUMPAD0 )
SYNKRO_DEFINE_CONST( Key, Decimal,		KEY_DECIMAL )
SYNKRO_DEFINE_CONST( Key, Oem102,		KEY_OEM102 )
SYNKRO_DEFINE_CONST( Key, F11,			KEY_F11 )
SYNKRO_DEFINE_CONST( Key, F12,			KEY_F12 )
SYNKRO_DEFINE_CONST( Key, Shift,		KEY_SHIFT )
SYNKRO_DEFINE_CONST( Key, F13,			KEY_F13 )
SYNKRO_DEFINE_CONST( Key, F14,			KEY_F14 )
SYNKRO_DEFINE_CONST( Key, F15,			KEY_F15 )
SYNKRO_DEFINE_CONST( Key, Kana,			KEY_KANA )
SYNKRO_DEFINE_CONST( Key, AbntC1,		KEY_ABNT_C1 )
SYNKRO_DEFINE_CONST( Key, ImeConvert,	KEY_IME_CONVERT )
SYNKRO_DEFINE_CONST( Key, ImeNoConvert,	KEY_IME_NO_CONVERT )
SYNKRO_DEFINE_CONST( Key, Yen,			KEY_YEN )
SYNKRO_DEFINE_CONST( Key, AbntC2,		KEY_ABNT_C2 )
SYNKRO_DEFINE_CONST( Key, NumpadEquals,	KEY_NUMPAD_EQUALS )
SYNKRO_DEFINE_CONST( Key, PrevTrack,	KEY_PREV_TRACK )
SYNKRO_DEFINE_CONST( Key, At,			KEY_AT )
SYNKRO_DEFINE_CONST( Key, Colon,		KEY_COLON )
SYNKRO_DEFINE_CONST( Key, Underline,	KEY_UNDERLINE )
SYNKRO_DEFINE_CONST( Key, Kanji,		KEY_KANJI )
SYNKRO_DEFINE_CONST( Key, Stop,			KEY_STOP )
SYNKRO_DEFINE_CONST( Key, Ax,			KEY_AX )
SYNKRO_DEFINE_CONST( Key, Unlabeled,	KEY_UNLABELED )
SYNKRO_DEFINE_CONST( Key, NextTrack,	KEY_NEXT_TRACK )
SYNKRO_DEFINE_CONST( Key, NumpadEnter,	KEY_NUMPAD_ENTER )
SYNKRO_DEFINE_CONST( Key, RightControl,	KEY_RIGHT_CONTROL )
SYNKRO_DEFINE_CONST( Key, Mute,			KEY_MUTE )
SYNKRO_DEFINE_CONST( Key, Calculator,	KEY_CALCULATOR )
SYNKRO_DEFINE_CONST( Key, PlayPause,	KEY_PLAY_PAUSE )
SYNKRO_DEFINE_CONST( Key, MediaStop,	KEY_MEDIA_STOP )
SYNKRO_DEFINE_CONST( Key, VolumeDown,	KEY_VOLUME_DOWN )
SYNKRO_DEFINE_CONST( Key, VolumeUp,		KEY_VOLUME_UP )
SYNKRO_DEFINE_CONST( Key, WebHome,		KEY_WEB_HOME )
SYNKRO_DEFINE_CONST( Key, NumpadComma,	KEY_NUMPAD_COMMA )
SYNKRO_DEFINE_CONST( Key, Divide,		KEY_DIVIDE )
SYNKRO_DEFINE_CONST( Key, PrintScreen,	KEY_PRINT_SCREEN )
SYNKRO_DEFINE_CONST( Key, RightAlt,		KEY_RIGHT_ALT )
SYNKRO_DEFINE_CONST( Key, Control,		KEY_CONTROL )
SYNKRO_DEFINE_CONST( Key, Pause,		KEY_PAUSE )
SYNKRO_DEFINE_CONST( Key, Home,			KEY_HOME )
SYNKRO_DEFINE_CONST( Key, Up,			KEY_UP )
SYNKRO_DEFINE_CONST( Key, Prior,		KEY_PRIOR )
SYNKRO_DEFINE_CONST( Key, Left,			KEY_LEFT )
SYNKRO_DEFINE_CONST( Key, Right,		KEY_RIGHT )
SYNKRO_DEFINE_CONST( Key, End,			KEY_END )
SYNKRO_DEFINE_CONST( Key, Down,			KEY_DOWN )
SYNKRO_DEFINE_CONST( Key, Next,			KEY_NEXT )
SYNKRO_DEFINE_CONST( Key, Insert,		KEY_INSERT )
SYNKRO_DEFINE_CONST( Key, Delete,		KEY_DELETE )
SYNKRO_DEFINE_CONST( Key, LeftWin,		KEY_LEFT_WIN )
SYNKRO_DEFINE_CONST( Key, RightWin,		KEY_RIGHT_WIN )
SYNKRO_DEFINE_CONST( Key, Apps,			KEY_APPS )
SYNKRO_DEFINE_CONST( Key, Power,		KEY_POWER )
SYNKRO_DEFINE_CONST( Key, Sleep,		KEY_SLEEP )
SYNKRO_DEFINE_CONST( Key, Wake,			KEY_WAKE )
SYNKRO_DEFINE_CONST( Key, WebSearch,	KEY_WEB_SEARCH )
SYNKRO_DEFINE_CONST( Key, WebFavorites,	KEY_WEB_FAVORITES )
SYNKRO_DEFINE_CONST( Key, WebRefresh,	KEY_WEB_REFRESH )
SYNKRO_DEFINE_CONST( Key, WebStop,		KEY_WEB_STOP )
SYNKRO_DEFINE_CONST( Key, WebForward,	KEY_WEB_FORWARD )
SYNKRO_DEFINE_CONST( Key, WebBack,		KEY_WEB_BACK )
SYNKRO_DEFINE_CONST( Key, MyComputer,	KEY_MY_COMPUTER )
SYNKRO_DEFINE_CONST( Key, Mail,			KEY_MAIL )
SYNKRO_DEFINE_CONST( Key, MediaSelect,	KEY_MEDIA_SELECT )
SYNKRO_DEFINE_CONST( Key, Alt,			KEY_ALT )


struct TypeDesc
{
	Key			type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ Key::Unknown,			L"" },			// 0x00
	{ Key::Escape,			L"Escape" },
	{ Key::D1,				L"D1" },
	{ Key::D2,				L"D2" },
	{ Key::D3,				L"D3" },
	{ Key::D4,				L"D4" },
	{ Key::D5,				L"D5" },
	{ Key::D6,				L"D6" },
	{ Key::D7,				L"D7" },
	{ Key::D8,				L"D8" },
	{ Key::D9,				L"D9" },
	{ Key::D0,				L"D0" },
	{ Key::Minus,			L"Minus" },
	{ Key::Equals,			L"Equals" },
	{ Key::Back,			L"Back" },
	{ Key::Tab,				L"Tab" },
	{ Key::Q,				L"Q" },			// 0x10
	{ Key::W,				L"W" },
	{ Key::E,				L"E" },
	{ Key::R,				L"R" },
	{ Key::T,				L"T" },
	{ Key::Y,				L"Y" },
	{ Key::U,				L"U" },
	{ Key::I,				L"I" },
	{ Key::O,				L"O" },
	{ Key::P,				L"P" },
	{ Key::LeftBracket,		L"LeftBracket" },
	{ Key::RightBracket,	L"RightBracket" },
	{ Key::Return,			L"Return" },
	{ Key::LeftControl,		L"LeftControl" },
	{ Key::A,				L"A" },
	{ Key::S,				L"S" },
	{ Key::D,				L"D" },			// 0x20
	{ Key::F,				L"F" },
	{ Key::G,				L"G" },
	{ Key::H,				L"H" },
	{ Key::J,				L"J" },
	{ Key::K,				L"K" },
	{ Key::L,				L"L" },
	{ Key::Semicolon,		L"Semicolon" },
	{ Key::Apostrophe,		L"Apostrophe" },
	{ Key::Grave,			L"Grave" },
	{ Key::LeftShift,		L"LeftShift" },
	{ Key::BackSlash,		L"Backslash" },
	{ Key::Z,				L"Z" },
	{ Key::X,				L"X" },
	{ Key::C,				L"C" },
	{ Key::V,				L"V" },
	{ Key::B,				L"B" },			// 0x30
	{ Key::N,				L"N" },
	{ Key::M,				L"M" },
	{ Key::Comma,			L"Comma" },
	{ Key::Period,			L"Period" },
	{ Key::Slash,			L"Slash" },
	{ Key::RightShift,		L"RightShift" },
	{ Key::Multiply,		L"Multiply" },
	{ Key::LeftAlt,			L"LeftAlt" },
	{ Key::Space,			L"Space" },
	{ Key::Capital,			L"Capital" },
	{ Key::F1,				L"F1" },
	{ Key::F2,				L"F2" },
	{ Key::F3,				L"F3" },
	{ Key::F4,				L"F4" },
	{ Key::F5,				L"F5" },
	{ Key::F6,				L"F6" },		// 0x40
	{ Key::F7,				L"F7" },
	{ Key::F8,				L"F8" },
	{ Key::F9,				L"F9" },
	{ Key::F10,				L"F10" },
	{ Key::NumLock,			L"NumLock" },
	{ Key::Scroll,			L"Scroll" },
	{ Key::Numpad7,			L"Numpad7" },
	{ Key::Numpad8,			L"Numpad8" },
	{ Key::Numpad9,			L"Numpad9" },
	{ Key::Subtract,		L"Subtract" },
	{ Key::Numpad4,			L"Numpad4" },
	{ Key::Numpad5,			L"Numpad5" },
	{ Key::Numpad6,			L"Numpad6" },
	{ Key::Add,				L"Add" },
	{ Key::Numpad1,			L"Numpad1" },
	{ Key::Numpad2,			L"Numpad2" },	// 0x50
	{ Key::Numpad3,			L"Numpad3" },
	{ Key::Numpad0,			L"Numpad0" },
	{ Key::Decimal,			L"Decimal" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Oem102,			L"Oem102" },
	{ Key::F11,				L"F11" },
	{ Key::F12,				L"F12" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Shift,			L"Shift" },		// 0x60
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::F13,				L"F13" },
	{ Key::F14,				L"F14" },
	{ Key::F15,				L"F15" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Kana,			L"Kana" },		// 0x70
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::AbntC1,			L"AbntC1" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::ImeConvert,		L"ImeConvert" },
	{ Key::Unknown,			L"" },
	{ Key::ImeNoConvert,	L"ImeNoConvert" },
	{ Key::Unknown,			L"" },
	{ Key::Yen,				L"Yen" },
	{ Key::AbntC2,			L"AbntC2" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },			// 0x80
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::NumpadEquals,	L"NumpadEQuals" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::PrevTrack,		L"PrevTrack" },	// 0x90
	{ Key::At,				L"At" },
	{ Key::Colon,			L"Colon" },
	{ Key::Underline,		L"Underline" },
	{ Key::Kanji,			L"Kanji" },
	{ Key::Stop,			L"Stop" },
	{ Key::Ax,				L"Ax" },
	{ Key::Unlabeled,		L"Unlabeled" },
	{ Key::Unknown,			L"" },
	{ Key::NextTrack,		L"NextTrack" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::NumpadEnter,		L"NumpadEnter" },
	{ Key::RightControl,	L"RightControl" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Mute,			L"Mute" },		// 0xA0
	{ Key::Calculator,		L"Calculator" },
	{ Key::PlayPause,		L"PlayPause" },
	{ Key::Unknown,			L"" },
	{ Key::MediaStop,		L"MediaStop" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::VolumeDown,		L"VolumeDown" },
	{ Key::Unknown,			L"" },
	{ Key::VolumeUp,		L"VolumEUp" },	// 0xB0
	{ Key::Unknown,			L"" },
	{ Key::WebHome,			L"WebHome" },
	{ Key::NumpadComma,		L"NumpadComma" },
	{ Key::Unknown,			L"" },
	{ Key::Divide,			L"Divide" },
	{ Key::Unknown,			L"" },
	{ Key::PrintScreen,		L"PrintScreen" },
	{ Key::RightAlt,		L"RightAlt" },
	{ Key::Unknown,			L"" },
	{ Key::Control,			L"Control" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },			// 0xC0
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Pause,			L"Pause" },
	{ Key::Unknown,			L"" },
	{ Key::Home,			L"Home" },
	{ Key::Up,				L"Up" },
	{ Key::Prior,			L"Prior" },
	{ Key::Unknown,			L"" },
	{ Key::Left,			L"Left" },
	{ Key::Unknown,			L"" },
	{ Key::Right,			L"Right" },
	{ Key::Unknown,			L"" },
	{ Key::End,				L"End" },
	{ Key::Down,			L"Down" },		// 0xD0
	{ Key::Next,			L"Next" },
	{ Key::Insert,			L"Insert" },
	{ Key::Delete,			L"Delete" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::LeftWin,			L"LeftWin" },
	{ Key::RightWin,		L"RightWin" },
	{ Key::Apps,			L"Apps" },
	{ Key::Power,			L"Power" },
	{ Key::Sleep,			L"Sleep" },
	{ Key::Unknown,			L"" },			// 0xE0
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Wake,			L"Wake" },
	{ Key::Unknown,			L"" },
	{ Key::WebSearch,		L"WebSearch" },
	{ Key::WebFavorites,	L"WebFavorites" },
	{ Key::WebRefresh,		L"WebRefresh" },
	{ Key::WebStop,			L"WebStop" },
	{ Key::WebForward,		L"WebForward" },
	{ Key::WebBack,			L"WebBack" },
	{ Key::MyComputer,		L"MyComputer" },
	{ Key::Mail,			L"Mail" },
	{ Key::MediaSelect,		L"MediaSelect" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Alt,				L"Alt" },		// 0xF0
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },
	{ Key::Unknown,			L"" },			// 0xFF
};
static UInt _count = SizeOf( _desc );

Key::Key( const lang::String& key ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( key )
}

lang::String Key::ToString() const
{
	ENUM_TO_STRING()
}


} // input


} // synkro
