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
// Purpose: Defines mesh batch property names.
//==============================================================================
#include "config.h"
#include "MeshBatchProperty.h"
#include <internal/Enum.h>


namespace synkro
{


namespace scene
{


SYNKRO_DEFINE_CONST( MeshBatchProperty, Range,	0 )


struct TypeDesc
{
	MeshBatchProperty	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ MeshBatchProperty::Range,	L"Range" },
};
static UInt _count = SizeOf( _desc );

lang::String MeshBatchProperty::ToString() const
{
	ENUM_TO_STRING()
}


} // scene


} // synkro
