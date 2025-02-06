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
// Purpose: Defines system language.
//==============================================================================
#include "config.h"
#include <core/Language.h>
#include <internal/Enum.h>


namespace synkro
{


namespace core
{


SYNKRO_DEFINE_CONST( Language, Unknown,	0 )
SYNKRO_DEFINE_CONST( Language, English,	1 )
SYNKRO_DEFINE_CONST( Language, Russian,	2 )

struct TypeDesc
{
	Language		type;
	const Char*		name;
	const Char*		chars;
};

static TypeDesc _desc[] = 
{
	{ Language::Unknown,	L"",		L"" },
	{ Language::English,	L"English",	L"!'#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`°abcdefghijklmnopqrstuvwxyz{|}~▲▼◄►°" },
	{ Language::Russian,	L"Russian",	L"!'#$%&()*+,-./0123456789:;<=>?@АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ[\\]^_`°абвгдеёжзийклмнопрстуфхцчшщъыьэюя{|}~▲▼◄►°" },
};
static UInt _count = SizeOf( _desc );

Language::Language( const lang::String& language ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( language )
}

UInt Language::CharCount() const
{
	return CastUInt( wcslen(_desc[this->Value()].chars) );
}

Char Language::GetChar( UInt index ) const
{
	return _desc[this->Value()].chars[index];
}

lang::String Language::ToString() const
{
	ENUM_TO_STRING()
}


} // core


} // synkro
