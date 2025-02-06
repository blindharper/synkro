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
// Purpose: Defines text pool property names.
//==============================================================================
#include "config.h"
#include "TextPoolProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace over
{


SYNKRO_DEFINE_CONST( TextPoolProperty, Offset, 0 )


struct TypeDesc
{
	TextPoolProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ TextPoolProperty::Offset,	L"Offset" },
};
static UInt _count = SizeOf( _desc );

lang::String TextPoolProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // over


} // synkro
