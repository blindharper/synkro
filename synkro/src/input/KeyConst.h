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
// Purpose: Defines keyboard keys constant values.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEYCONST_
#define _SYNKRO_INPUT_KEYCONST_


#include "config.h"


namespace synkro
{


namespace input
{


// Keyboard keys constant values.
enum KeyConst
{
	KEY_UNKNOWN				= 0x00,
	KEY_ESCAPE				= 0x01,
	KEY_D1					= 0x02,
	KEY_D2					= 0x03,
	KEY_D3					= 0x04,
	KEY_D4					= 0x05,
	KEY_D5					= 0x06,
	KEY_D6					= 0x07,
	KEY_D7					= 0x08,
	KEY_D8					= 0x09,
	KEY_D9					= 0x0A,
	KEY_D0					= 0x0B,
	KEY_MINUS				= 0x0C,
	KEY_EQUALS				= 0x0D,
	KEY_BACK				= 0x0E,
	KEY_TAB					= 0x0F,
	KEY_Q					= 0x10,
	KEY_W					= 0x11,
	KEY_E					= 0x12,
	KEY_R					= 0x13,
	KEY_T					= 0x14,
	KEY_Y					= 0x15,
	KEY_U					= 0x16,
	KEY_I					= 0x17,
	KEY_O					= 0x18,
	KEY_P					= 0x19,
	KEY_LEFT_BRACKET		= 0x1A,
	KEY_RIGHT_BRACKET		= 0x1B,
	KEY_RETURN				= 0x1C,
	KEY_LEFT_CONTROL		= 0x1D,
	KEY_A					= 0x1E,
	KEY_S					= 0x1F,
	KEY_D					= 0x20,
	KEY_F					= 0x21,
	KEY_G					= 0x22,
	KEY_H					= 0x23,
	KEY_J					= 0x24,
	KEY_K					= 0x25,
	KEY_L					= 0x26,
	KEY_SEMICOLON			= 0x27,
	KEY_APOSTROPHE			= 0x28,
	KEY_GRAVE				= 0x29,
	KEY_LEFT_SHIFT			= 0x2A,
	KEY_BACK_SLASH			= 0x2B,
	KEY_Z					= 0x2C,
	KEY_X					= 0x2D,
	KEY_C					= 0x2E,
	KEY_V					= 0x2F,
	KEY_B					= 0x30,
	KEY_N					= 0x31,
	KEY_M					= 0x32,
	KEY_COMMA				= 0x33,
	KEY_PERIOD				= 0x34,
	KEY_SLASH				= 0x35,
	KEY_RIGHT_SHIFT			= 0x36,
	KEY_MULTIPLY			= 0x37,
	KEY_LEFT_ALT			= 0x38,
	KEY_SPACE				= 0x39,
	KEY_CAPITAL				= 0x3A,
	KEY_F1					= 0x3B,
	KEY_F2					= 0x3C,
	KEY_F3					= 0x3D,
	KEY_F4					= 0x3E,
	KEY_F5					= 0x3F,
	KEY_F6					= 0x40,
	KEY_F7					= 0x41,
	KEY_F8					= 0x42,
	KEY_F9					= 0x43,
	KEY_F10					= 0x44,
	KEY_NUM_LOCK			= 0x45,
	KEY_SCROLL				= 0x46,
	KEY_NUMPAD7				= 0x47,
	KEY_NUMPAD8				= 0x48,
	KEY_NUMPAD9				= 0x49,
	KEY_SUBTRACT			= 0x4A,
	KEY_NUMPAD4				= 0x4B,
	KEY_NUMPAD5				= 0x4C,
	KEY_NUMPAD6				= 0x4D,
	KEY_ADD					= 0x4E,
	KEY_NUMPAD1				= 0x4F,
	KEY_NUMPAD2				= 0x50,
	KEY_NUMPAD3				= 0x51,
	KEY_NUMPAD0				= 0x52,
	KEY_DECIMAL				= 0x53,
	KEY_OEM102				= 0x56,
	KEY_F11					= 0x57,
	KEY_F12					= 0x58,
	KEY_SHIFT				= 0x60,
	KEY_F13					= 0x64,
	KEY_F14					= 0x65,
	KEY_F15					= 0x66,
	KEY_KANA				= 0x70,
	KEY_ABNT_C1				= 0x73,
	KEY_IME_CONVERT			= 0x79,
	KEY_IME_NO_CONVERT		= 0x7B,
	KEY_YEN					= 0x7D,
	KEY_ABNT_C2				= 0x7E,
	KEY_NUMPAD_EQUALS		= 0x8D,
	KEY_PREV_TRACK			= 0x90,
	KEY_AT					= 0x91,
	KEY_COLON				= 0x92,
	KEY_UNDERLINE			= 0x93,
	KEY_KANJI				= 0x94,
	KEY_STOP				= 0x95,
	KEY_AX					= 0x96,
	KEY_UNLABELED			= 0x97,
	KEY_NEXT_TRACK			= 0x99,
	KEY_NUMPAD_ENTER		= 0x9C,
	KEY_RIGHT_CONTROL		= 0x9D,
	KEY_MUTE				= 0xA0,
	KEY_CALCULATOR			= 0xA1,
	KEY_PLAY_PAUSE			= 0xA2,
	KEY_MEDIA_STOP			= 0xA4,
	KEY_VOLUME_DOWN			= 0xAE,
	KEY_VOLUME_UP			= 0xB0,
	KEY_WEB_HOME			= 0xB2,
	KEY_NUMPAD_COMMA		= 0xB3,
	KEY_DIVIDE				= 0xB5,
	KEY_PRINT_SCREEN		= 0xB7,
	KEY_RIGHT_ALT			= 0xB8,
	KEY_CONTROL				= 0xBA,
	KEY_PAUSE				= 0xC5,
	KEY_HOME				= 0xC7,
	KEY_UP					= 0xC8,
	KEY_PRIOR				= 0xC9,
	KEY_LEFT				= 0xCB,
	KEY_RIGHT				= 0xCD,
	KEY_END					= 0xCF,
	KEY_DOWN				= 0xD0,
	KEY_NEXT				= 0xD1,
	KEY_INSERT				= 0xD2,
	KEY_DELETE				= 0xD3,
	KEY_LEFT_WIN			= 0xDB,
	KEY_RIGHT_WIN			= 0xDC,
	KEY_APPS				= 0xDD,
	KEY_POWER				= 0xDE,
	KEY_SLEEP				= 0xDF,
	KEY_WAKE				= 0xE3,
	KEY_WEB_SEARCH			= 0xE5,
	KEY_WEB_FAVORITES		= 0xE6,
	KEY_WEB_REFRESH			= 0xE7,
	KEY_WEB_STOP			= 0xE8,
	KEY_WEB_FORWARD			= 0xE9,
	KEY_WEB_BACK			= 0xEA,
	KEY_MY_COMPUTER			= 0xEB,
	KEY_MAIL				= 0xEC,
	KEY_MEDIA_SELECT		= 0xED,
	KEY_ALT					= 0xF0,
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYCONST_
