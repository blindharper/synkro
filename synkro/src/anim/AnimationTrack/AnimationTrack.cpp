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
// Purpose: Defines animation track types.
//==============================================================================
#include "config.h"
#include <anim/AnimationTrack.h>
#include <internal/Enum.h>


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( AnimationTrack, Custom,		0 )
SYNKRO_DEFINE_CONST( AnimationTrack, FloatNoise,	1 )
SYNKRO_DEFINE_CONST( AnimationTrack, FloatWave,		2 )


struct TypeDesc
{
	AnimationTrack	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ AnimationTrack::Custom,		L"Custom" },
	{ AnimationTrack::FloatNoise,	L"FloatNoise" },
	{ AnimationTrack::FloatWave,	L"FloatWave" },
};
static UInt _count = SizeOf( _desc );

lang::String AnimationTrack::ToString() const
{
	ENUM_TO_STRING()
}


} // anim


} // synkro
