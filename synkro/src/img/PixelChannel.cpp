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
// Purpose: Defines pixel channel.
//==============================================================================
#include "config.h"
#include <img/PixelChannel.h>
#include <internal/Enum.h>


namespace synkro
{


namespace img
{


SYNKRO_DEFINE_CONST( PixelChannel, Red,		0x01 )
SYNKRO_DEFINE_CONST( PixelChannel, Green,	0x02 )
SYNKRO_DEFINE_CONST( PixelChannel, Blue,	0x04 )
SYNKRO_DEFINE_CONST( PixelChannel, Alpha,	0x08 )
SYNKRO_DEFINE_CONST( PixelChannel, All,		0x0F )

struct TypeDesc
{
	PixelChannel	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ PixelChannel::All,		L"" },
	{ PixelChannel::Red,		L"Red" },
	{ PixelChannel::Green,		L"Green" },
	{ PixelChannel::All,		L"" },
	{ PixelChannel::Blue,		L"Blue" },
	{ PixelChannel::All,		L"" },
	{ PixelChannel::All,		L"" },
	{ PixelChannel::All,		L"" },
	{ PixelChannel::Alpha,		L"Alpha" },
};
static UInt _count = SizeOf( _desc );

PixelChannel::PixelChannel( const lang::String& channel ) :
	Flag( 0 )
{
	SET_FLAG_VALUE( channel )
	if ( _value == 0 )
	{
		_value = PixelChannel::All;
	}
}

lang::String PixelChannel::ToString() const
{
	static PixelChannel flags[] =
	{
		PixelChannel::Red,
		PixelChannel::Green,
		PixelChannel::Blue,
	};
	FLAG_TO_STRING( PixelChannel )
}


} // img


} // synkro
