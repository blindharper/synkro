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
// Purpose: Generic sampler state set implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SamplerStateSetImpl<T>::SamplerStateSetImpl( const ProgramStageType& type ) :
	_states( A(P(ISamplerState)) ),
	_type( type )
{
}

template <class T>
SYNKRO_INLINE SamplerStateSetImpl<T>::~SamplerStateSetImpl()
{
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetFilter( const TextureFilter& filter )
{
	SetMinFilter( filter );
	SetMagFilter( filter );
	SetMipFilter( filter );
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetMinFilter( const TextureFilter& filter )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetMinFilter( filter );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetMagFilter( const TextureFilter& filter )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetMagFilter( filter );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetMipFilter( const TextureFilter& filter )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetMipFilter( filter );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetMaxAnisotropy( UInt anisotropy )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetMaxAnisotropy( anisotropy );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetAddress( const TextureAddress& address )
{
	SetAddressU( address );
	SetAddressV( address );
	SetAddressW( address );
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetAddressU( const TextureAddress& address )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAddressU( address );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetAddressV( const TextureAddress& address )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAddressV( address );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetAddressW( const TextureAddress& address )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetAddressW( address );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE void SamplerStateSetImpl<T>::SetBorderColor( const math::Vector4& color )
{
	for ( UInt i = 0; i < _states.Size(); ++i )
	{
		_states[i]->SetBorderColor( color );
	}
	_dirty = true;
}

template <class T>
SYNKRO_INLINE UInt SamplerStateSetImpl<T>::GetSize() const
{
	return _states.Size();
}

template <class T>
SYNKRO_INLINE ISamplerState* SamplerStateSetImpl<T>::Get( UInt index ) const
{
	assert( index < _states.Size() );

	if ( index >= _states.Size() )
		throw lang::OutOfRangeException( index, _states.Size() );

	return _states[index];
}
