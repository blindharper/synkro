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
// Purpose: Omni light node implementation.
//==============================================================================
SYNKRO_INLINE void OmniLight::Enable( Bool enable )
{
	// Call base implementation.
	LightImpl<IOmniLight>::Enable( enable );

	_omni.SetColor( _enabled ? _diffuseColor*_intensity : img::Color::DimGray );
}

SYNKRO_INLINE void OmniLight::SetDiffuseColor( const img::Color& color )
{
	// Call base implementation.
	LightImpl<IOmniLight>::SetDiffuseColor( color );

	_omni.SetColor( _diffuseColor*_intensity );
}

SYNKRO_INLINE void OmniLight::SetIntensity( Float intensity )
{
	// Call base implementation.
	LightImpl<IOmniLight>::SetIntensity( intensity );

	_omni.SetColor( _diffuseColor*_intensity );
}

SYNKRO_INLINE IOmniLight* OmniLight::AsOmni() const
{
	return (IOmniLight*)this;
}

SYNKRO_INLINE void OmniLight::SetRange( Float range )
{
	_range = range;
}

SYNKRO_INLINE void OmniLight::SetAttenuation( const Attenuation& attenuation )
{
	_attenuation = attenuation;
}

SYNKRO_INLINE Float OmniLight::GetRange() const
{
	return _range;
}

SYNKRO_INLINE void OmniLight::GetAttenuation( Attenuation& attenuation ) const
{
	attenuation = _attenuation;
}
