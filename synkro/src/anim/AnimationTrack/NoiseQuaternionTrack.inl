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
// Purpose: Implements quaternion noise animation track.
//==============================================================================
SYNKRO_INLINE void NoiseQuaternionTrack::GetValue( Double time, math::Quaternion& value ) const
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

	const Float yaw = _magnitude*Lerp( v0, v1, s );
	const Float pitch = _magnitude*Lerp( v2, v3, s );
	const Float roll = _magnitude*Lerp( v4, v5, s );
	value = math::Quaternion( yaw, pitch, roll );
}

SYNKRO_INLINE IKeyframedQuaternionTrack* NoiseQuaternionTrack::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralQuaternionTrack* NoiseQuaternionTrack::AsProcedural() const
{
	return (IProceduralQuaternionTrack*)this;
}

SYNKRO_INLINE IExpressionQuaternionTrack* NoiseQuaternionTrack::AsExpression() const
{
	return nullptr;
}

SYNKRO_INLINE void NoiseQuaternionTrack::SetMagnitude( Float magnitude )
{
	assert( magnitude >= 0.0f );

	_magnitude = magnitude;
}

SYNKRO_INLINE Float NoiseQuaternionTrack::GetMagnitude() const
{
	return _magnitude;
}
