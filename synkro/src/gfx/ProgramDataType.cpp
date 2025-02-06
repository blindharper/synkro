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
// Purpose: Defines program parameter types.
//==============================================================================
#include "config.h"
#include <gfx/ProgramDataType.h>
#include <internal/Enum.h>
#include "ProgramDataTypeConst.h"


namespace synkro
{


namespace gfx
{


SYNKRO_DEFINE_CONST( ProgramDataType, Unknown,				PROGRAM_DATA_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( ProgramDataType, Bool,					PROGRAM_DATA_TYPE_BOOL )
SYNKRO_DEFINE_CONST( ProgramDataType, Int,					PROGRAM_DATA_TYPE_INT )
SYNKRO_DEFINE_CONST( ProgramDataType, Float,				PROGRAM_DATA_TYPE_FLOAT )
SYNKRO_DEFINE_CONST( ProgramDataType, Vector2,				PROGRAM_DATA_TYPE_VECTOR2 )
SYNKRO_DEFINE_CONST( ProgramDataType, Vector3,				PROGRAM_DATA_TYPE_VECTOR3 )
SYNKRO_DEFINE_CONST( ProgramDataType, Vector4,				PROGRAM_DATA_TYPE_VECTOR4 )
SYNKRO_DEFINE_CONST( ProgramDataType, Matrix3x3,			PROGRAM_DATA_TYPE_MATRIX3X3 )
SYNKRO_DEFINE_CONST( ProgramDataType, Matrix4x4,			PROGRAM_DATA_TYPE_MATRIX4X4 )
SYNKRO_DEFINE_CONST( ProgramDataType, Matrix4x4Transposed,	PROGRAM_DATA_TYPE_MATRIX4X4_TRANSPOSED )
SYNKRO_DEFINE_CONST( ProgramDataType, Structure,			PROGRAM_DATA_TYPE_STRUCTURE )


struct TypeDesc
{
	ProgramDataType	type;
	const Char*		name;
	UInt			size;
};

static TypeDesc _desc[] = 
{
	{ ProgramDataType::Unknown,				L"",					0 },
	{ ProgramDataType::Bool,				L"Bool",				1*sizeof(Bool) },
	{ ProgramDataType::Int,					L"Int",					1*sizeof(Int) },
	{ ProgramDataType::Float,				L"Float",				1*sizeof(Float) },
	{ ProgramDataType::Vector2,				L"Vector2",				2*sizeof(Float) },
	{ ProgramDataType::Vector3,				L"Vector3",				3*sizeof(Float) },
	{ ProgramDataType::Vector4,				L"Vector4",				4*sizeof(Float) },
	{ ProgramDataType::Matrix3x3,			L"Matrix3x3",			9*sizeof(Float) },
	{ ProgramDataType::Matrix4x4,			L"Matrix4x4",			16*sizeof(Float) },
	{ ProgramDataType::Matrix4x4Transposed,	L"Matrix4x4Transposed",	16*sizeof(Float) },
	{ ProgramDataType::Structure,			L"Structure",			0 },
};
static UInt _count = SizeOf( _desc );

UInt ProgramDataType::Size() const
{
	return ( _value < _count ) ? _desc[_value].size : 0;
}

lang::String ProgramDataType::ToString() const
{
	ENUM_TO_STRING()
}


} // gfx


} // synkro
