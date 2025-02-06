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
// Purpose: Generic cube texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE CubeTextureImpl<T>::CubeTextureImpl( UInt length, const img::PixelFormat& format, UInt levelCount ) :
	TextureImpl<T>( format, levelCount, 6 ),
	_length( length )
{
}

template <class T>
SYNKRO_INLINE CubeTextureImpl<T>::~CubeTextureImpl()
{
}

template <class T>
SYNKRO_INLINE ICubeTexture* CubeTextureImpl<T>::AsCube() const
{
	return (ICubeTexture*)this;
}

template <class T>
SYNKRO_INLINE UInt CubeTextureImpl<T>::GetLength() const
{
	return _length;
}
