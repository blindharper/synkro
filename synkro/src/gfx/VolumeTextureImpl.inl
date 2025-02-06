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
// Purpose: Generic volume texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE VolumeTextureImpl<T>::VolumeTextureImpl( UInt width, UInt height, UInt depth, const img::PixelFormat& format, UInt levelCount ) :
	TextureImpl<T>( format, levelCount, 1 ),
	_width( width ),
	_height( height ),
	_depth( depth )
{
}

template <class T>
SYNKRO_INLINE VolumeTextureImpl<T>::~VolumeTextureImpl()
{
}

template <class T>
SYNKRO_INLINE IVolumeTexture* VolumeTextureImpl<T>::AsVolume() const
{
	return (IVolumeTexture*)this;
}

template <class T>
SYNKRO_INLINE UInt VolumeTextureImpl<T>::GetWidth() const
{
	return _width;
}

template <class T>
SYNKRO_INLINE UInt VolumeTextureImpl<T>::GetHeight() const
{
	return _height;
}

template <class T>
SYNKRO_INLINE UInt VolumeTextureImpl<T>::GetDepth() const
{
	return _depth;
}
