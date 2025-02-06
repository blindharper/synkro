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
// Purpose: Fog effect implementation.
//==============================================================================
SYNKRO_INLINE void Fog::SetColor( const img::Color& color )
{
	_state.FogColor.x = color.R;
	_state.FogColor.y = color.G;
	_state.FogColor.z = color.B;
}

SYNKRO_INLINE void Fog::SetDensity( Float density )
{
	_state.Density = density;
}

SYNKRO_INLINE void Fog::SetStart( Float start )
{
	_state.Start = start;
}

SYNKRO_INLINE void Fog::SetEnd( Float end )
{
	_state.End = end;
}

SYNKRO_INLINE void Fog::SetType( const FogType& type )
{
	_type		= type;
	_state.Type	= CastInt(type);
}

SYNKRO_INLINE void Fog::GetColor( img::Color& color ) const
{
	color = img::Color( _state.FogColor.x, _state.FogColor.y, _state.FogColor.z );
}

SYNKRO_INLINE Float Fog::GetDensity() const
{
	return _state.Density;
}

SYNKRO_INLINE Float Fog::GetStart() const
{
	return _state.Start;
}

SYNKRO_INLINE Float Fog::GetEnd() const
{
	return _state.End;
}

SYNKRO_INLINE FogType Fog::GetType() const
{
	return _type;
}

SYNKRO_INLINE void Fog::GetState( FogState& state ) const
{
	state = _state;
}
