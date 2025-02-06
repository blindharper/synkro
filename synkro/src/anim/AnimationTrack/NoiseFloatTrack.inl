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
	UInt i = CastUInt(time);
	Double f = time - CastDouble(i);
	Double s = f*f*(3 - 2*f);
	Float v0 = GetNoise( i );
	Float v1 = GetNoise( i+1 );
	value = Lerp( v0, v1, s );
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

SYNKRO_INLINE INoiseFloatTrack* NoiseFloatTrack::AsNoise() const
{
	return (INoiseFloatTrack*)this;
}

SYNKRO_INLINE IWaveFloatTrack* NoiseFloatTrack::AsWave() const
{
	return nullptr;
}

SYNKRO_INLINE void NoiseFloatTrack::SetSeed( UInt seed )
{
	_seed = seed;
}

SYNKRO_INLINE UInt NoiseFloatTrack::GetSeed() const
{
	return _seed;
}

SYNKRO_INLINE Float NoiseFloatTrack::GetNoise( UInt x ) const
{
	x = (x << 13) ^ x;
	return (1.0f - ((x * (x*x*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}
