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
// Purpose: Generic linear texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE LinearTextureImpl<T>::LinearTextureImpl( UInt length, const img::PixelFormat& format, UInt levelCount, UInt elementCount ) :
	TextureImpl<T>( format, levelCount, elementCount ),
	_length( length )
{
}

template <class T>
SYNKRO_INLINE LinearTextureImpl<T>::~LinearTextureImpl()
{
}

template <class T>
SYNKRO_INLINE ILinearTexture* LinearTextureImpl<T>::AsLinear() const
{
	return (ILinearTexture*)this;
}

template <class T>
SYNKRO_INLINE UInt LinearTextureImpl<T>::GetLength() const
{
	return _length;
}
