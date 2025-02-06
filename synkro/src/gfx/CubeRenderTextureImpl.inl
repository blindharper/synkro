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
// Purpose: Generic cube rendering texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE CubeRenderTextureImpl<T>::CubeRenderTextureImpl( UInt length, const img::PixelFormat& format ) :
	RenderTextureImpl<ICubeRenderTexture>( format ),
	_length( length )
{
}

template <class T>
SYNKRO_INLINE CubeRenderTextureImpl<T>::~CubeRenderTextureImpl()
{
}

template <class T>
SYNKRO_INLINE Bool CubeRenderTextureImpl<T>::BindFace( const CubeFace& face )
{
	// Do nothing.
	return false;
}

template <class T>
SYNKRO_INLINE UInt CubeRenderTextureImpl<T>::GetLength() const
{
	return _length;
}
