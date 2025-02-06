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
// Purpose: Defines graphics program stage type.
//==============================================================================
#include "config.h"
#include <gfx/ProgramStageType.h>
#include <internal/Enum.h>
#include "ProgramStageTypeConst.h"


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( ProgramStageType, Unknown,		PROGRAM_STAGE_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( ProgramStageType, Vertex,		PROGRAM_STAGE_TYPE_VERTEX )
SYNKRO_DEFINE_CONST( ProgramStageType, Hull,		PROGRAM_STAGE_TYPE_HULL )
SYNKRO_DEFINE_CONST( ProgramStageType, Domain,		PROGRAM_STAGE_TYPE_DOMAIN )
SYNKRO_DEFINE_CONST( ProgramStageType, Geometry,	PROGRAM_STAGE_TYPE_GEOMETRY )
SYNKRO_DEFINE_CONST( ProgramStageType, Fragment,	PROGRAM_STAGE_TYPE_FRAGMENT )


struct TypeDesc
{
	ProgramStageType	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ ProgramStageType::Unknown,	L"" },
	{ ProgramStageType::Vertex,		L"Vertex" },
	{ ProgramStageType::Hull,		L"Hull" },
	{ ProgramStageType::Domain,		L"Domain" },
	{ ProgramStageType::Geometry,	L"Geometry" },
	{ ProgramStageType::Fragment,	L"Fragment" },
};
static UInt _count = SizeOf( _desc );

ProgramStageType::ProgramStageType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String ProgramStageType::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
