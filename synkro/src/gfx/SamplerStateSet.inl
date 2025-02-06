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
// Purpose: Logical sampler state set.
//==============================================================================
SYNKRO_INLINE void SamplerStateSet::Bind()
{
	SynkroProfile( "SamplerStateSet.Bind" );

	_set->Bind();
}

SYNKRO_INLINE void SamplerStateSet::SetFilter( const TextureFilter& filter )
{
	_set->SetFilter( filter );
}

SYNKRO_INLINE void SamplerStateSet::SetMinFilter( const TextureFilter& filter )
{
	_set->SetMinFilter( filter );
}

SYNKRO_INLINE void SamplerStateSet::SetMagFilter( const TextureFilter& filter )
{
	_set->SetMagFilter( filter );
}

SYNKRO_INLINE void SamplerStateSet::SetMipFilter( const TextureFilter& filter )
{
	_set->SetMipFilter( filter );
}

SYNKRO_INLINE void SamplerStateSet::SetMaxAnisotropy( UInt anisotropy )
{
	_set->SetMaxAnisotropy( anisotropy );
}

SYNKRO_INLINE void SamplerStateSet::SetAddress( const TextureAddress& address )
{
	_set->SetAddress( address );
}

SYNKRO_INLINE void SamplerStateSet::SetAddressU( const TextureAddress& address )
{
	_set->SetAddressU( address );
}

SYNKRO_INLINE void SamplerStateSet::SetAddressV( const TextureAddress& address )
{
	_set->SetAddressV( address );
}

SYNKRO_INLINE void SamplerStateSet::SetAddressW( const TextureAddress& address )
{
	_set->SetAddressW( address );
}

SYNKRO_INLINE void SamplerStateSet::SetBorderColor( const math::Vector4& color )
{
	_set->SetBorderColor( color );
}

SYNKRO_INLINE ISamplerStateSet* SamplerStateSet::Clone( UInt ownerID ) const
{
	return new SamplerStateSet( *this, ownerID );
}
