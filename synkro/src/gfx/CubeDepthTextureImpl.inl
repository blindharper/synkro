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
// Purpose: Generic cube depth texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE CubeDepthTextureImpl<T>::CubeDepthTextureImpl( UInt length, const DepthFormat& format, Bool stencil ) :
	DepthTextureImpl<ICubeDepthTexture>( format, stencil ),
	_length( length )
{
}

template <class T>
SYNKRO_INLINE CubeDepthTextureImpl<T>::~CubeDepthTextureImpl()
{
}

template <class T>
SYNKRO_INLINE ICubeDepthTexture* CubeDepthTextureImpl<T>::AsCube() const
{
	return (ICubeDepthTexture*)this;
}

template <class T>
SYNKRO_INLINE Bool CubeDepthTextureImpl<T>::BindFace( const CubeFace& face )
{
	// Do nothing.
	return false;
}

template <class T>
SYNKRO_INLINE UInt CubeDepthTextureImpl<T>::GetLength() const
{
	return _length;
}
