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
// Purpose: Generic linear rendering texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE LinearRenderTextureImpl<T>::LinearRenderTextureImpl( UInt length, const img::PixelFormat& format ) :
	RenderTextureImpl<ILinearRenderTexture>( format ),
	_length( length )
{
}

template <class T>
SYNKRO_INLINE LinearRenderTextureImpl<T>::~LinearRenderTextureImpl()
{
}

template <class T>
SYNKRO_INLINE UInt LinearRenderTextureImpl<T>::GetLength() const
{
	return _length;
}
