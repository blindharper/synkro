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
// Purpose: Generic sampler state implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SamplerStateImpl<T>::SamplerStateImpl() :
	_dirty( true ),
	_filterMin( TextureFilter::Point ),
	_filterMag( TextureFilter::Point ),
	_filterMip( TextureFilter::Point ),
	_anisotropy( 16 ),
	_addressU( TextureAddress::Wrap ),
	_addressV( TextureAddress::Wrap ),
	_addressW( TextureAddress::Wrap ),
	_borderColor( math::Vector4(0.0f, 0.0f, 0.0f, 1.0f) )
{
}

template <class T>
SYNKRO_INLINE SamplerStateImpl<T>::~SamplerStateImpl()
{
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetFilter( const TextureFilter& filter )
{
	SetMinFilter( filter );
	SetMagFilter( filter );
	SetMipFilter( filter );
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetMinFilter( const TextureFilter& filter )
{
	if ( filter != _filterMin )
	{
		_filterMin = filter;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetMagFilter( const TextureFilter& filter )
{
	if ( filter != _filterMag )
	{
		_filterMag = filter;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetMipFilter( const TextureFilter& filter )
{
	if ( filter != _filterMip )
	{
		_filterMip = filter;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetMaxAnisotropy( UInt anisotropy )
{
	if ( anisotropy > 16 )
		anisotropy = 16;

	if ( anisotropy != _anisotropy )
	{
		_anisotropy = anisotropy;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetAddress( const TextureAddress& address )
{
	SetAddressU( address );
	SetAddressV( address );
	SetAddressW( address );
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetAddressU( const TextureAddress& address )
{
	if ( address != _addressU )
	{
		_addressU = address;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetAddressV( const TextureAddress& address )
{
	if ( address != _addressV )
	{
		_addressV = address;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetAddressW( const TextureAddress& address )
{
	if ( address != _addressW )
	{
		_addressW = address;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::SetBorderColor( const math::Vector4& color )
{
	if ( color != _borderColor )
	{
		_borderColor = color;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE TextureFilter SamplerStateImpl<T>::GetMinFilter() const
{
	return _filterMin;
}

template <class T>
SYNKRO_INLINE TextureFilter SamplerStateImpl<T>::GetMagFilter() const
{
	return _filterMag;
}

template <class T>
SYNKRO_INLINE TextureFilter SamplerStateImpl<T>::GetMipFilter() const
{
	return _filterMip;
}

template <class T>
SYNKRO_INLINE UInt SamplerStateImpl<T>::GetMaxAnisotropy() const
{
	return _anisotropy;
}

template <class T>
SYNKRO_INLINE TextureAddress SamplerStateImpl<T>::GetAddressU() const
{
	return _addressU;
}

template <class T>
SYNKRO_INLINE TextureAddress SamplerStateImpl<T>::GetAddressV() const
{
	return _addressV;
}

template <class T>
SYNKRO_INLINE TextureAddress SamplerStateImpl<T>::GetAddressW() const
{
	return _addressW;
}

template <class T>
SYNKRO_INLINE void SamplerStateImpl<T>::GetBorderColor( math::Vector4& color ) const
{
	color = _borderColor;
}
