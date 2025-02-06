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
SYNKRO_INLINE IKeyframedFloatTrack* WaveFloatTrack::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralFloatTrack* WaveFloatTrack::AsProcedural() const
{
	return (IProceduralFloatTrack*)this;
}

SYNKRO_INLINE IExpressionFloatTrack* WaveFloatTrack::AsExpression() const
{
	return nullptr;
}

SYNKRO_INLINE INoiseFloatTrack* WaveFloatTrack::AsNoise() const
{
	return nullptr;
}

SYNKRO_INLINE IWaveFloatTrack* WaveFloatTrack::AsWave() const
{
	return (IWaveFloatTrack*)this;
}

SYNKRO_INLINE void WaveFloatTrack::SetAmplitude( Float amplitude )
{
	assert( amplitude > 0.0f );

	_amplitude = amplitude;
}

SYNKRO_INLINE void WaveFloatTrack::SetOffset( Float offset )
{
	_offset = offset;
}

SYNKRO_INLINE void WaveFloatTrack::SetFrequency( Float frequency )
{
	assert( frequency > 0.0f );

	_frequency = frequency;
}

SYNKRO_INLINE void WaveFloatTrack::SetPhase( Float phase )
{
	_phase = phase;
}

SYNKRO_INLINE void WaveFloatTrack::SetType( const WaveType& type )
{
	_waveType = type;
}

SYNKRO_INLINE Float WaveFloatTrack::GetAmplitude() const
{
	return _amplitude;
}

SYNKRO_INLINE Float WaveFloatTrack::GetOffset() const
{
	return _offset;
}

SYNKRO_INLINE Float WaveFloatTrack::GetFrequency() const
{
	return _frequency;
}

SYNKRO_INLINE Float WaveFloatTrack::GetPhase() const
{
	return _phase;
}

SYNKRO_INLINE WaveType WaveFloatTrack::GetWaveType() const
{
	return _waveType;
}
