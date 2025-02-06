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
// Purpose: Cone light node implementation.
//==============================================================================
SYNKRO_INLINE void ConeLight::Enable( Bool enable )
{
	// Call base implementation.
	LightImpl<IConeLight>::Enable( enable );

	_cone.SetColor( _enabled ? _diffuseColor*_intensity : img::Color::DimGray );
}

SYNKRO_INLINE void ConeLight::SetDiffuseColor( const img::Color& color )
{
	// Call base implementation.
	LightImpl<IConeLight>::SetDiffuseColor( color );

	_cone.SetColor( _diffuseColor*_intensity );
}

SYNKRO_INLINE void ConeLight::SetIntensity( Float intensity )
{
	// Call base implementation.
	LightImpl<IConeLight>::SetIntensity( intensity );

	_cone.SetColor( _diffuseColor * _intensity );
}

SYNKRO_INLINE IConeLight* ConeLight::AsCone() const
{
	return (IConeLight*)this;
}

SYNKRO_INLINE void ConeLight::SetRange( Float range )
{
	_range = range;
}

SYNKRO_INLINE void ConeLight::SetAttenuation( const Attenuation& attenuation )
{
	_attenuation = attenuation;
}

SYNKRO_INLINE void ConeLight::SetInnerAngle( Float angle )
{
	assert( angle >= 0.0f );

	if ( angle < 0.0f )
		throw lang::InvalidOperationException( L"Inner angle should be greater or equal to 0.");

	_innerAngle = Clamp( angle, 0.0f, _outerAngle );
	UpdateAngles();
}

SYNKRO_INLINE void ConeLight::SetOuterAngle( Float angle )
{
	assert( angle <= math::Math::Pi );

	if ( angle > math::Math::Pi )
		throw lang::InvalidOperationException( L"Outer angle should be less or equal to Pi." );

	_outerAngle = Clamp( angle, _innerAngle, math::Math::Pi );
	UpdateAngles();
}

SYNKRO_INLINE void ConeLight::SetFalloff( Float falloff )
{
	_falloff = falloff;
}

SYNKRO_INLINE Float ConeLight::GetRange() const
{
	return _range;
}

SYNKRO_INLINE void ConeLight::GetAttenuation( Attenuation& attenuation ) const
{
	attenuation = _attenuation;
}

SYNKRO_INLINE Float ConeLight::GetInnerAngle() const
{
	return _innerAngle;
}

SYNKRO_INLINE Float ConeLight::GetOuterAngle() const
{
	return _outerAngle;
}

SYNKRO_INLINE Float ConeLight::GetFalloff() const
{
	return _falloff;
}
