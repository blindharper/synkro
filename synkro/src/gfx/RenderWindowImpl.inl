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
// Purpose: Generic rendering window implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE RenderWindowImpl<T>::RenderWindowImpl( IGraphicsDevice* device, win::IWindow* window, const img::PixelFormat& format, UInt sampleCount ) :
	_device( device ),
	_baseWindow( window ),
	_defaultColor( math::Vector4(0.0f, 0.0f, 0.0f, 1.0f) ),
	_clientFormat( img::PixelFormat::Unknown ),
	_format( format ),
	_sampleCount( sampleCount )
{
}

template <class T>
SYNKRO_INLINE RenderWindowImpl<T>::~RenderWindowImpl()
{
}

template <class T>
SYNKRO_INLINE void RenderWindowImpl<T>::SetDefaultColor( const math::Vector4& color )
{
	_defaultColor = color;
}

template <class T>
SYNKRO_INLINE void RenderWindowImpl<T>::GetDefaultColor( math::Vector4& color ) const
{
	color = _defaultColor;
}

template <class T>
SYNKRO_INLINE img::PixelFormat RenderWindowImpl<T>::GetClientPixelFormat() const
{
	return _clientFormat;
}

template <class T>
SYNKRO_INLINE img::PixelFormat RenderWindowImpl<T>::GetPixelFormat() const
{
	return _format;
}

template <class T>
SYNKRO_INLINE UInt RenderWindowImpl<T>::GetWidth() const
{
	return _baseWindow->GetWidth();
}

template <class T>
SYNKRO_INLINE UInt RenderWindowImpl<T>::GetHeight() const
{
	return _baseWindow->GetHeight();
}

template <class T>
SYNKRO_INLINE UInt RenderWindowImpl<T>::GetSampleCount() const
{
	return _sampleCount;
}

template <class T>
SYNKRO_INLINE IGraphicsDevice* RenderWindowImpl<T>::GetDevice() const
{
	return _device;
}
