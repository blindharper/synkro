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
// Purpose: Defines animation value types.
//==============================================================================
#include "config.h"
#include <anim/AnimationDataType.h>
#include <internal/Enum.h>
#include "AnimationDataTypeConst.h"


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( AnimationDataType, Unknown,		TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( AnimationDataType, Bool,			TYPE_BOOL )
SYNKRO_DEFINE_CONST( AnimationDataType, Color,			TYPE_COLOR )
SYNKRO_DEFINE_CONST( AnimationDataType, ColorGradient,	TYPE_COLOR_GRADIENT )
SYNKRO_DEFINE_CONST( AnimationDataType, Float,			TYPE_FLOAT )
SYNKRO_DEFINE_CONST( AnimationDataType, FloatRect,		TYPE_FLOAT_RECT )
SYNKRO_DEFINE_CONST( AnimationDataType, Int,			TYPE_INT )
SYNKRO_DEFINE_CONST( AnimationDataType, Matrix4x4,		TYPE_MATRIX4X4 )
SYNKRO_DEFINE_CONST( AnimationDataType, Point,			TYPE_POINT )
SYNKRO_DEFINE_CONST( AnimationDataType, Quaternion,		TYPE_QUATERNION )
SYNKRO_DEFINE_CONST( AnimationDataType, Range,			TYPE_RANGE )
SYNKRO_DEFINE_CONST( AnimationDataType, Rect,			TYPE_RECT )
SYNKRO_DEFINE_CONST( AnimationDataType, Size,			TYPE_SIZE )
SYNKRO_DEFINE_CONST( AnimationDataType, Vector3,		TYPE_VECTOR3 )


struct TypeDesc
{
	AnimationDataType	type;
	const Char*			name;
};

static TypeDesc _desc[] = 
{
	{ AnimationDataType::Unknown,		L"" },
	{ AnimationDataType::Bool,			L"Bool" },
	{ AnimationDataType::Color,			L"Color" },
	{ AnimationDataType::ColorGradient,	L"ColorGradient" },	
	{ AnimationDataType::Float,			L"Float" },
	{ AnimationDataType::FloatRect,		L"FloatRect" },
	{ AnimationDataType::Int,			L"Int" },
	{ AnimationDataType::Matrix4x4,		L"Matrix4x4" },
	{ AnimationDataType::Point,			L"Point" },
	{ AnimationDataType::Quaternion,	L"Quaternion" },
	{ AnimationDataType::Range,			L"Range" },
	{ AnimationDataType::Rect,			L"Rect" },
	{ AnimationDataType::Size,			L"Size" },
	{ AnimationDataType::Vector3,		L"Vector3" },
};
static UInt _count = SizeOf( _desc );

AnimationDataType::AnimationDataType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String AnimationDataType::ToString() const
{
	ENUM_TO_STRING()
}


} // anim


} // synkro
