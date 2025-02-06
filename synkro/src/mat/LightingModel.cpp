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
// Purpose: Defines material lighting model.
//==============================================================================
#include "config.h"
#include <mat/LightingModel.h>
#include <internal/Enum.h>


namespace synkro
{


namespace mat
{


SYNKRO_DEFINE_CONST( LightingModel, Unknown,	0 )
SYNKRO_DEFINE_CONST( LightingModel, Flat,		1 )
SYNKRO_DEFINE_CONST( LightingModel, Gouraud,	2 )
SYNKRO_DEFINE_CONST( LightingModel, Phong,		3 )
SYNKRO_DEFINE_CONST( LightingModel, Blinn,		4 )


struct TypeDesc
{
	LightingModel	type;
	const Char*		name;
};

static TypeDesc _desc[] =
{
	{ LightingModel::Unknown,	L"" },
	{ LightingModel::Flat,		L"Flat" },
	{ LightingModel::Gouraud,	L"Gouraud" },
	{ LightingModel::Phong,		L"Phong" },
	{ LightingModel::Blinn,		L"Blinn" },
};
static UInt _count = SizeOf(_desc);

lang::String LightingModel::ToString() const
{
	ENUM_TO_STRING()
}


} // mat


} // synkro
