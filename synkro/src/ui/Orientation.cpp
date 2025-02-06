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
// Purpose: Defines widget orientation.
//==============================================================================
#include "config.h"
#include <ui/Orientation.h>
#include <internal/Enum.h>
#include "OrientationConst.h"


namespace synkro
{


namespace ui
{


SYNKRO_DEFINE_CONST( Orientation, Horizontal,	ORIENTATION_HORIZONTAL )
SYNKRO_DEFINE_CONST( Orientation, Vertical,		ORIENTATION_VERTICAL )


struct TypeDesc
{
	Orientation	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ Orientation::Horizontal,	L"Horizontal" },
	{ Orientation::Vertical,	L"Vertical" },
};
static UInt _count = SizeOf( _desc );

Orientation::Orientation( const lang::String& orientation ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( orientation )
}

lang::String Orientation::ToString() const
{
	ENUM_TO_STRING()
}


} // ui


} // synkro
