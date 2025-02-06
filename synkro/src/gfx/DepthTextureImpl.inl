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
// Purpose: Generic depth texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DepthTextureImpl<T>::DepthTextureImpl( const DepthFormat& format, Bool stencil ) :
	_defaultDepth( 1.0f ),
	_defaultStencil( 0 ),
	_format( format ),
	_stencil( stencil )
{
}

template <class T>
SYNKRO_INLINE DepthTextureImpl<T>::~DepthTextureImpl()
{
}

template <class T>
SYNKRO_INLINE IDepthTexture* DepthTextureImpl<T>::AsDepthTexture() const
{
	return (IDepthTexture*)this;
}

template <class T>
SYNKRO_INLINE void DepthTextureImpl<T>::SetDefaultDepth( Float depth )
{
	_defaultDepth = depth;
}

template <class T>
SYNKRO_INLINE void DepthTextureImpl<T>::SetDefaultStencil( Byte stencil )
{
	_defaultStencil = stencil;
}

template <class T>
SYNKRO_INLINE Float DepthTextureImpl<T>::GetDefaultDepth() const
{
	return _defaultDepth;
}

template <class T>
SYNKRO_INLINE Byte DepthTextureImpl<T>::GetDefaultStencil() const
{
	return _defaultStencil;
}

template <class T>
SYNKRO_INLINE DepthFormat DepthTextureImpl<T>::GetFormat() const
{
	return _format;
}

template <class T>
SYNKRO_INLINE Bool DepthTextureImpl<T>::HasStencil() const
{
	return _stencil;
}

template <class T>
SYNKRO_INLINE IPlainDepthTexture* DepthTextureImpl<T>::AsPlain() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ICubeDepthTexture* DepthTextureImpl<T>::AsCube() const
{
	return nullptr;
}
