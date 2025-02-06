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
// Purpose: Logical sampler state.
//==============================================================================
SYNKRO_INLINE void SamplerState::SetFilter( const TextureFilter& filter )
{
	PreventModify();

	_state->SetFilter( filter );
}

SYNKRO_INLINE void SamplerState::SetMinFilter( const TextureFilter& filter )
{
	PreventModify();

	_state->SetMinFilter( filter );
}

SYNKRO_INLINE void SamplerState::SetMagFilter( const TextureFilter& filter )
{
	PreventModify();

	_state->SetMagFilter( filter );
}

SYNKRO_INLINE void SamplerState::SetMipFilter( const TextureFilter& filter )
{
	PreventModify();

	_state->SetMipFilter( filter );
}

SYNKRO_INLINE void SamplerState::SetMaxAnisotropy( UInt anisotropy )
{
	PreventModify();

	_state->SetMaxAnisotropy( anisotropy );
}

SYNKRO_INLINE void SamplerState::SetAddress( const TextureAddress& address )
{
	PreventModify();

	_state->SetAddress( address );
}

SYNKRO_INLINE void SamplerState::SetAddressU( const TextureAddress& address )
{
	PreventModify();

	_state->SetAddressU( address );
}

SYNKRO_INLINE void SamplerState::SetAddressV( const TextureAddress& address )
{
	PreventModify();

	_state->SetAddressV( address );
}

SYNKRO_INLINE void SamplerState::SetAddressW( const TextureAddress& address )
{
	PreventModify();

	_state->SetAddressW( address );
}

SYNKRO_INLINE void SamplerState::SetBorderColor( const math::Vector4& color )
{
	PreventModify();

	_state->SetBorderColor( color );
}

SYNKRO_INLINE TextureFilter SamplerState::GetMinFilter() const
{
	return _state->GetMinFilter();
}

SYNKRO_INLINE TextureFilter SamplerState::GetMagFilter() const
{
	return _state->GetMagFilter();
}

SYNKRO_INLINE TextureFilter SamplerState::GetMipFilter() const
{
	return _state->GetMipFilter();
}

SYNKRO_INLINE UInt SamplerState::GetMaxAnisotropy() const
{
	return _state->GetMaxAnisotropy();
}

SYNKRO_INLINE TextureAddress SamplerState::GetAddressU() const
{
	return _state->GetAddressU();
}

SYNKRO_INLINE TextureAddress SamplerState::GetAddressV() const
{
	return _state->GetAddressV();
}

SYNKRO_INLINE TextureAddress SamplerState::GetAddressW() const
{
	return _state->GetAddressW();
}

SYNKRO_INLINE void SamplerState::GetBorderColor( math::Vector4& color ) const
{
	_state->GetBorderColor( color );
}
