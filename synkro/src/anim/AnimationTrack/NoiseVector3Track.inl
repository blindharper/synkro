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
// Purpose: Implements 3-component vector noise animation track.
//==============================================================================
SYNKRO_INLINE void NoiseVector3Track::GetValue( Double time, math::Vector3& value ) const
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

	const Float x = Lerp( v0, v1, s );
	const Float y = Lerp( v2, v3, s );
	const Float z = Lerp( v4, v5, s );
	value = _shift + math::Vector3( x, y, z ) * _magnitude;
}

SYNKRO_INLINE IKeyframedVector3Track* NoiseVector3Track::AsKeyframed() const
{
	return nullptr;
}

SYNKRO_INLINE IProceduralVector3Track* NoiseVector3Track::AsProcedural() const
{
	return (IProceduralVector3Track*)this;
}

SYNKRO_INLINE IExpressionVector3Track* NoiseVector3Track::AsExpression() const
{
	return nullptr;
}

SYNKRO_INLINE void NoiseVector3Track::SetMagnitude( Float magnitude )
{
	assert( magnitude >= 0.0f );

	_magnitude = magnitude;
}

SYNKRO_INLINE void NoiseVector3Track::SetShift( const math::Vector3 shift )
{
	_shift = shift;
}

SYNKRO_INLINE Float NoiseVector3Track::GetMagnitude() const
{
	return _magnitude;
}

SYNKRO_INLINE void NoiseVector3Track::GetShift( math::Vector3& shift ) const
{
	shift = _shift;
}
