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
// Purpose: Implements scalar wave animation track.
//==============================================================================
#include "config.h"
#include "WaveFloatTrack.h"
#include "WaveTypeConst.h"
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


WaveFloatTrack::WaveFloatTrack( const String& name ) :
	ProceduralTrackImpl<IWaveFloatTrack, TYPE_FLOAT>( name, ProcedureType::Wave ),
	_amplitude( 1.0f ),
	_offset( 0.0f ),
	_frequency( 1.0f ),
	_phase( 0.0f ),
	_waveType( WaveType::Sine )
{
}

void WaveFloatTrack::GetValue( Double time, Float& value ) const
{
	Float res = 0.0f; Float angle = 0.0f; UInt ratio = 0;
	const Float a = _frequency*CastFloat(time) + _phase;

	switch ( _waveType )
	{
		case WAVE_TYPE_SINE:
			res = Math::Sin( a );
			break;

		case WAVE_TYPE_STEP:
			res = -_frequency*Math::TwoPi*Math::Floor(CastFloat(time) );
			break;

		case WAVE_TYPE_SQUARE:
			res = Math::Sign( Math::Sin(a) );
			break;

		case WAVE_TYPE_TRIANGLE:
			angle = (_frequency*Math::TwoPi*CastFloat(time) + _phase);
			ratio = CastInt(angle / Math::TwoPi);
			angle -= CastFloat(ratio);
			if ( (angle >= 0.0f) && (angle < Math::HalfPi) )
				res = Lerp( 0.0f, 1.0f, angle/Math::HalfPi );
			else if ( (angle >= Math::HalfPi) && (angle < 1.5f*Math::Pi) )
				res = Lerp( 1.0f, -1.0f, (angle-Math::HalfPi)/Math::Pi );
			else
				res = Lerp( -1.0f, 0.0f, (angle-1.5f*Math::Pi)/Math::HalfPi );
			break;

		case WAVE_TYPE_SAWTOOTH_UP:
			res = a - Math::Floor( a );
			break;

		case WAVE_TYPE_SAWTOOTH_DOWN:
			res = Math::Ceil( a ) - a;
			break;
	}

	value = _offset + _amplitude*res;
}


} // anim


} // synkro
