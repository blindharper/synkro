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
// Purpose: Defines stream directory types.
//==============================================================================
#include "config.h"
#include <io/StreamDirectory.h>
#include <internal/Enum.h>


namespace synkro
{


namespace io
{


SYNKRO_DEFINE_CONST( StreamDirectory, Custom,	0 )
SYNKRO_DEFINE_CONST( StreamDirectory, Zip,		1 )


struct TypeDesc
{
	StreamDirectory	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ StreamDirectory::Custom,	L"dir" },
	{ StreamDirectory::Zip,		L"zip" },
};
static UInt _count = SizeOf( _desc );

lang::String StreamDirectory::ToString() const
{
	ENUM_TO_STRING()
}


} // io


} // synkro
