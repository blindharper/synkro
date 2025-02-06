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
// Purpose: Defines music property names.
//==============================================================================
#include "config.h"
#include "MusicProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace sound
{


SYNKRO_DEFINE_CONST( MusicProperty, Volume,	0 )
SYNKRO_DEFINE_CONST( MusicProperty, Pan,	1 )


struct TypeDesc
{
	MusicProperty	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ MusicProperty::Volume,	L"Volume" },
	{ MusicProperty::Pan,		L"Pan" },
};
static UInt _count = SizeOf( _desc );

lang::String MusicProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // sound


} // synkro
