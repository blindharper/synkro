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
// Purpose: Generic plain depth texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE PlainDepthTextureImpl<T>::PlainDepthTextureImpl( UInt width, UInt height, const DepthFormat& format, Bool stencil ) :
	DepthTextureImpl<T>( format, stencil ),
	_width( width ),
	_height( height )
{
}

template <class T>
SYNKRO_INLINE PlainDepthTextureImpl<T>::~PlainDepthTextureImpl()
{
}

template <class T>
SYNKRO_INLINE IPlainDepthTexture* PlainDepthTextureImpl<T>::AsPlain() const
{
	return (IPlainDepthTexture*)this;
}

template <class T>
SYNKRO_INLINE UInt PlainDepthTextureImpl<T>::GetWidth() const
{
	return _width;
}

template <class T>
SYNKRO_INLINE UInt PlainDepthTextureImpl<T>::GetHeight() const
{
	return _height;
}
