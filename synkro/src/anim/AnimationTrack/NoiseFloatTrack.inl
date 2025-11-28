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
// Purpose: Implements scalar noise animation track.
//==============================================================================
SYNKRO_INLINE void NoiseFloatTrack::GetValue( Double time, Float& value ) const
{
	const UInt i = CastUInt(time);
	const Double f = time - CastDouble(i);
	const Double s = f*f*(3 - 2*f);
	const Float v0 = GetNoise( i );
	const Float v1 = GetNoise( i+1 );
	value = _shift + _magnitude*Lerp( v0, v1, s );
}

SYNKRO_INLINE IKeyframedFloatTrack* NoiseFloatTrack::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralFloatTrack* NoiseFloatTrack::AsProcedural() const
{
	return (IProceduralFloatTrack*)this;
}

SYNKRO_INLINE IExpressionFloatTrack* NoiseFloatTrack::AsExpression() const
{
	return nullptr;
}

SYNKRO_INLINE IWaveFloatTrack* NoiseFloatTrack::AsWave() const
{
	return nullptr;
}

SYNKRO_INLINE void NoiseFloatTrack::SetMagnitude( Float magnitude )
{
	assert( magnitude >= 0.0f );

	_magnitude = magnitude;
}

SYNKRO_INLINE void NoiseFloatTrack::SetShift( Float shift )
{
	_shift = shift;
}

SYNKRO_INLINE Float NoiseFloatTrack::GetMagnitude() const
{
	return _magnitude;
}

SYNKRO_INLINE Float NoiseFloatTrack::GetShift() const
{
	return _shift;
}
