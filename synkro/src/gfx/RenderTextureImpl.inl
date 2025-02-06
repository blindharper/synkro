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
// Purpose: Generic rendering texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderTextureImpl<T>::RenderTextureImpl( const img::PixelFormat& format ) :
	_defaultColor( math::Vector4(0.0f, 0.0f, 0.0f, 1.0f) ),
	_format( format )
{
}

template <class T>
SYNKRO_INLINE RenderTextureImpl<T>::~RenderTextureImpl()
{
}

template <class T>
SYNKRO_INLINE IRenderTexture* RenderTextureImpl<T>::AsRenderTexture() const
{
	return (IRenderTexture*)this;
}

template <class T>
SYNKRO_INLINE Bool RenderTextureImpl<T>::Present()
{
	// Do nothing.
	return true;
}

template <class T>
SYNKRO_INLINE void RenderTextureImpl<T>::SetDefaultColor( const math::Vector4& color )
{
	_defaultColor = color;
}

template <class T>
SYNKRO_INLINE void RenderTextureImpl<T>::GetDefaultColor( math::Vector4& color ) const
{
	color = _defaultColor;
}

template <class T>
SYNKRO_INLINE img::PixelFormat RenderTextureImpl<T>::GetFormat() const
{
	return _format;
}
