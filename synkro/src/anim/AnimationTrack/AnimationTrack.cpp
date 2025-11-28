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


SYNKRO_DEFINE_CONST( AnimationTrack, Custom,				0 )
SYNKRO_DEFINE_CONST( AnimationTrack, FloatWave,				1 )
SYNKRO_DEFINE_CONST( AnimationTrack, BoolNoise,				2 )
SYNKRO_DEFINE_CONST( AnimationTrack, ColorNoise,			3 )
SYNKRO_DEFINE_CONST( AnimationTrack, ColorGradientNoise,	4 )
SYNKRO_DEFINE_CONST( AnimationTrack, FloatNoise,			5 )
SYNKRO_DEFINE_CONST( AnimationTrack, QuaternionNoise,		6 )
SYNKRO_DEFINE_CONST( AnimationTrack, Vector3Noise,			7 )


struct TypeDesc
{
	AnimationTrack	type;
	const Char*		name;
};

static TypeDesc _desc[] = 
{
	{ AnimationTrack::Custom,				L"Custom" },
	{ AnimationTrack::FloatWave,			L"FloatWave" },
	{ AnimationTrack::BoolNoise,			L"BoolNoise" },
	{ AnimationTrack::ColorNoise,			L"ColorNoise" },
	{ AnimationTrack::ColorGradientNoise,	L"ColorGradientNoise" },
	{ AnimationTrack::FloatNoise,			L"FloatNoise" },
	{ AnimationTrack::QuaternionNoise,		L"QuaternionNoise" },
	{ AnimationTrack::Vector3Noise,			L"Vector3Noise" },
	
};
static UInt _count = SizeOf( _desc );

lang::String AnimationTrack::ToString() const
{
	ENUM_TO_STRING()
}


} // anim


} // synkro
