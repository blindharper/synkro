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
// Purpose: Implements boolean noise animation track.
//==============================================================================
SYNKRO_INLINE void NoiseBoolTrack::GetValue( Double time, Bool& value ) const
{
	const UInt i = CastUInt(time);
	const Double f = time - CastDouble(i);
	const Double s = f*f*(3 - 2*f);
	
	Float v0 = GetNoise( i );
	Float v1 = GetNoise( i+1 );

	v0 = Clamp( math::Math::Abs(v0), 0.0f, 1.0f );
	v1 = Clamp( math::Math::Abs(v1), 0.0f, 1.0f );
	const Float v = Lerp( v0, v1, s );

	UInt n = math::Math::Round( v*10.0f );
	value = (n % 2) == 0;
}

SYNKRO_INLINE IKeyframedBoolTrack* NoiseBoolTrack::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralBoolTrack* NoiseBoolTrack::AsProcedural() const
{
	return (IProceduralBoolTrack*)this;
}

SYNKRO_INLINE IExpressionBoolTrack* NoiseBoolTrack::AsExpression() const
{
	return nullptr;
}
