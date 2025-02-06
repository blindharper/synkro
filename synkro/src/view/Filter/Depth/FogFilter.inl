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
// Purpose: Fog viewport filter implementation.
//==============================================================================
SYNKRO_INLINE IFogFilter* FogFilter::AsFog() const
{
	return (IFogFilter*)this;
}

SYNKRO_INLINE void FogFilter::SetColor( const img::Color& color )
{
	_params->Set( _paramColor, ToVector(color) );
}

SYNKRO_INLINE void FogFilter::SetDensity( Float density )
{
	density = math::Math::Clamp( density, 0.0f, 1.0f );
	_params->Set( _paramDensity, density );
}

SYNKRO_INLINE void FogFilter::SetStart( Float start )
{
	_params->Set( _paramStart, start );
}

SYNKRO_INLINE void FogFilter::SetEnd( Float end )
{
	_params->Set( _paramEnd, end );
}

SYNKRO_INLINE void FogFilter::SetType( const scene::FogType& type )
{
	_type = type;
	_params->Set( _paramType, (Int)_type );
}

SYNKRO_INLINE void FogFilter::GetColor( img::Color& color ) const
{
	math::Vector4 vec;
	_params->Get( _paramColor, &vec );
	color = ToColor( vec );
}

SYNKRO_INLINE Float FogFilter::GetDensity() const
{
	Float value;
	_params->Get( _paramDensity, &value );
	return value;
}

SYNKRO_INLINE Float FogFilter::GetStart() const
{
	Float value;
	_params->Get( _paramStart, &value );
	return value;
}

SYNKRO_INLINE Float FogFilter::GetEnd() const
{
	Float value;
	_params->Get( _paramEnd, &value );
	return value;
}

SYNKRO_INLINE scene::FogType FogFilter::GetType() const
{
	return _type;
}
