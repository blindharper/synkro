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
#ifndef _SYNKRO_ANIM_WAVEFLOATTRACK_
#define _SYNKRO_ANIM_WAVEFLOATTRACK_


#include "config.h"
#include "ProceduralTrackImpl.h"
#include <anim/IWaveFloatTrack.h>


namespace synkro
{


namespace anim
{


// Scalar wave animation track.
class WaveFloatTrack :
	public ProceduralTrackImpl<IWaveFloatTrack, TYPE_FLOAT>
{
public:
	// Constructor.
	WaveFloatTrack( const lang::String& name );

	// IFloatTrack methods.
	void													GetValue( Double time, Float& value ) const;

	// IAnimationFloatTrack methods.
	IKeyframedFloatTrack*									AsKeyframed() const;
	IProceduralFloatTrack*									AsProcedural() const;
	IExpressionFloatTrack*									AsExpression() const;

	// IProceduralFloatTrack methods.
	INoiseFloatTrack*										AsNoise() const;
	IWaveFloatTrack*										AsWave() const;

	// IWaveFloatTrack methods.
	void													SetAmplitude( Float amplitude );
	void													SetOffset( Float offset );
	void													SetFrequency( Float frequency );
	void													SetPhase( Float phase );
	void													SetType( const WaveType& type );
	Float													GetAmplitude() const;
	Float													GetOffset() const;
	Float													GetFrequency() const;
	Float													GetPhase() const;
	WaveType												GetWaveType() const;

private:
	Float													_amplitude;
	Float													_offset;
	Float													_frequency;
	Float													_phase;
	WaveType												_waveType;
};


#include "WaveFloatTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_WAVEFLOATTRACK_
