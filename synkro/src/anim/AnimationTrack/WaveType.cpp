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
// Purpose: Defines waveform type.
//==============================================================================
#include "config.h"
#include <anim/WaveType.h>
#include <internal/Enum.h>
#include "WaveTypeConst.h"


namespace synkro
{


namespace anim
{


SYNKRO_DEFINE_CONST( WaveType, Unknown,			WAVE_TYPE_UNKNOWN )
SYNKRO_DEFINE_CONST( WaveType, Sine,			WAVE_TYPE_SINE )
SYNKRO_DEFINE_CONST( WaveType, Step,			WAVE_TYPE_STEP )
SYNKRO_DEFINE_CONST( WaveType, Square,			WAVE_TYPE_SQUARE )
SYNKRO_DEFINE_CONST( WaveType, Triangle,		WAVE_TYPE_TRIANGLE )
SYNKRO_DEFINE_CONST( WaveType, SawtoothUp,		WAVE_TYPE_SAWTOOTH_UP )
SYNKRO_DEFINE_CONST( WaveType, SawtoothDown,	WAVE_TYPE_SAWTOOTH_DOWN )


struct TypeDesc
{
	WaveType	type;
	const Char*	name;
};

static TypeDesc _desc[] = 
{
	{ WaveType::Unknown,		L"" },
	{ WaveType::Sine,			L"Sine" },
	{ WaveType::Step,			L"Step" },
	{ WaveType::Square,			L"Square" },
	{ WaveType::Triangle,		L"Triangle" },
	{ WaveType::SawtoothUp,		L"SawtoothUp" },
	{ WaveType::SawtoothDown,	L"SawtoothDown" },
};
static UInt _count = SizeOf( _desc );

WaveType::WaveType( const lang::String& type ) :
	Enum( 0 )
{
	SET_ENUM_VALUE( type )
}

lang::String WaveType::ToString() const
{
	ENUM_TO_STRING()
}


} // anim


} // synkro
