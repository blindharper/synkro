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
// Purpose: Defines sound codec types.
//==============================================================================
#include "config.h"
#include <sound/SoundCodec.h>
#include <internal/Enum.h>


namespace synkro
{


namespace sound
{


SYNKRO_DEFINE_CONST( SoundCodec, Unknown,	0 )
SYNKRO_DEFINE_CONST( SoundCodec, Custom,	1 )
SYNKRO_DEFINE_CONST( SoundCodec, Wav,		2 )
SYNKRO_DEFINE_CONST( SoundCodec, Mp3,		3 )


struct TypeDesc
{
	SoundCodec	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ SoundCodec::Unknown,		L"" },
	{ SoundCodec::Custom,		L"snd" },
	{ SoundCodec::Wav,			L"wav" },
	{ SoundCodec::Mp3,			L"mp3" },
};
static UInt _count = SizeOf( _desc );

SoundCodec::SoundCodec( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String SoundCodec::ToString() const
{
	ENUM_TO_STRING()
}

Bool SoundCodec::IsValid( const lang::String& name )
{
	IS_VALID_ENUM( name )
}


} // sound


} // synkro
