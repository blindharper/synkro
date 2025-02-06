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
// Purpose: Generic texture implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE TextureImpl<T>::TextureImpl( const img::PixelFormat& format, UInt levelCount, UInt elementCount ) :
	_format( format ),
	_levelCount( levelCount ),
	_elementCount( elementCount )
{
}

template <class T>
SYNKRO_INLINE TextureImpl<T>::~TextureImpl()
{
}

template <class T>
SYNKRO_INLINE ITexture* TextureImpl<T>::AsTexture() const
{
	return (ITexture*)this;
}

template <class T>
SYNKRO_INLINE void TextureImpl<T>::GenerateLevels()
{
	throw lang::NotSupportedException();
}

template <class T>
SYNKRO_INLINE UInt TextureImpl<T>::GetElementCount() const
{
	return _elementCount;
}

template <class T>
SYNKRO_INLINE UInt TextureImpl<T>::GetLevelCount() const
{
	return _levelCount;
}

template <class T>
SYNKRO_INLINE img::PixelFormat TextureImpl<T>::GetFormat() const
{
	return _format;
}

template <class T>
SYNKRO_INLINE ILinearTexture* TextureImpl<T>::AsLinear() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IPlainTexture* TextureImpl<T>::AsPlain() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ICubeTexture* TextureImpl<T>::AsCube() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IVolumeTexture* TextureImpl<T>::AsVolume() const
{
	return nullptr;
}
