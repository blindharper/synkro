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
// Purpose: Defines index data type.
//==============================================================================
#include "config.h"
#include <gfx/IndexType.h>
#include <internal/Enum.h>


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( IndexType, None,	0 )
SYNKRO_DEFINE_CONST( IndexType, Short,	1 )
SYNKRO_DEFINE_CONST( IndexType, Long,	2 )

struct TypeDesc
{
	IndexType	type;
	const Char*	name;
	UInt		size;
};

static TypeDesc _desc[] = 
{
	{ IndexType::None,	L"",		0 },
	{ IndexType::Short,	L"Short",	sizeof(UShort) },
	{ IndexType::Long,	L"Long",	sizeof(UInt) },
};
static UInt _count = SizeOf( _desc );

IndexType::IndexType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

IndexType IndexType::Get( UInt vertexCount )
{
	if ( vertexCount >= (1<<16) )
		IndexType::Long;

	if ( vertexCount > 0 )
		return IndexType::Short;

	return IndexType::None;
}

UInt IndexType::Size() const
{
	return _desc[this->Value()].size;
}

lang::String IndexType::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
