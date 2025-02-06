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
// Purpose: Generic plain rendering texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE PlainRenderTextureImpl<T>::PlainRenderTextureImpl( UInt width, UInt height, const img::PixelFormat& format ) :
	RenderTextureImpl<T>( format ),
	_width( width ),
	_height( height )
{
}

template <class T>
SYNKRO_INLINE PlainRenderTextureImpl<T>::~PlainRenderTextureImpl()
{
}

template <class T>
SYNKRO_INLINE UInt PlainRenderTextureImpl<T>::GetWidth() const
{
	return _width;
}

template <class T>
SYNKRO_INLINE UInt PlainRenderTextureImpl<T>::GetHeight() const
{
	return _height;
}
