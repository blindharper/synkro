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
// Purpose: Defines progress widget types.
//==============================================================================
#include "config.h"
#include <ui/ProgressType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( ProgressType, Bar,		0 )
SYNKRO_DEFINE_CONST( ProgressType, Circle,	1 )


struct TypeDesc
{
	ProgressType	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ ProgressType::Bar,	L"Bar" },
	{ ProgressType::Circle,	L"Circle" },
};
static UInt _count = SizeOf( _desc );

ProgressType::ProgressType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String ProgressType::ToString() const
{
	ENUM_TO_STRING()
}


} // ui


} // synkro
