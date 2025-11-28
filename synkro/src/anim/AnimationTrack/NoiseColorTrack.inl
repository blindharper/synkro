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
// Purpose: Implements color noise animation track.
//==============================================================================
SYNKRO_INLINE void NoiseColorTrack::GetValue( Double time, img::Color& value ) const
{
	const UInt i = CastUInt(time);
	const Double f = time - CastDouble(i);
	const Double s = f*f*(3 - 2*f);
	
	Float v0 = GetNoise( i );
	Float v1 = GetNoise( i+1 );
	Float v2 = GetNoise( i+2 );
	Float v3 = GetNoise( i+3 );
	Float v4 = GetNoise( i+4 );
	Float v5 = GetNoise( i+5 );

	v0 = Clamp( math::Math::Abs(v0), 0.0f, 1.0f );
	v1 = Clamp( math::Math::Abs(v1), 0.0f, 1.0f );

	v2 = Clamp( math::Math::Abs(v2), 0.0f, 1.0f );
	v3 = Clamp( math::Math::Abs(v3), 0.0f, 1.0f );

	v4 = Clamp( math::Math::Abs(v4), 0.0f, 1.0f );
	v5 = Clamp( math::Math::Abs(v5), 0.0f, 1.0f );

	const Float red = Lerp( v0, v1, s );
	const Float green = Lerp( v2, v3, s );
	const Float blue = Lerp( v4, v5, s );
	value = img::Color( red, green, blue );
}

SYNKRO_INLINE IKeyframedColorTrack* NoiseColorTrack::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralColorTrack* NoiseColorTrack::AsProcedural() const
{
	return (IProceduralColorTrack*)this;
}

SYNKRO_INLINE IExpressionColorTrack* NoiseColorTrack::AsExpression() const
{
	return nullptr;
}
