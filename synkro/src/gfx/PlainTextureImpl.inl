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
// Purpose: Generic plain texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE PlainTextureImpl<T>::PlainTextureImpl( UInt width, UInt height, const img::PixelFormat& format, UInt levelCount, UInt elementCount ) :
	TextureImpl<T>( format, levelCount, elementCount ),
	_width( width ),
	_height( height )
{
}

template <class T>
SYNKRO_INLINE PlainTextureImpl<T>::~PlainTextureImpl()
{
}

template <class T>
SYNKRO_INLINE IPlainTexture* PlainTextureImpl<T>::AsPlain() const
{
	return (IPlainTexture*)this;
}

template <class T>
SYNKRO_INLINE UInt PlainTextureImpl<T>::GetWidth() const
{
	return _width;
}

template <class T>
SYNKRO_INLINE UInt PlainTextureImpl<T>::GetHeight() const
{
	return _height;
}
