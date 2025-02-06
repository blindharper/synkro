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
// Purpose: Implements generic image.
//==============================================================================
template <class T>
SYNKRO_INLINE ImageImpl<T>::ImageImpl( BaseImageManager* imageManager, const PixelFormat& format, Bool loaded ) :
	_imageManager( imageManager ),
	_elements( A(Element) ),
	_data( A(Byte) ),
	_format( format ),
	_type( ImageType::Unknown ),
	_loaded( loaded )
{
}

template <class T>
SYNKRO_INLINE ImageImpl<T>::~ImageImpl()
{
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::Prepare( const PixelFormat& format, UInt levelCount )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::Save( io::IStream* stream, const PixelFormat& format, const ImageCodec& type )
{
	_imageManager->SaveImage( this, stream, format, type );
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::Save( io::IStream* stream, const PixelFormat& format )
{
	_imageManager->SaveImage( this, stream, format );
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SaveAsync( io::IStream* stream, const PixelFormat& format, const ImageCodec& type )
{
	_imageManager->SaveImageAsync( this, stream, format, type );
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SaveAsync( io::IStream* stream, const PixelFormat& format )
{
	_imageManager->SaveImageAsync( this, stream, format );
}

template <class T>
SYNKRO_INLINE Byte* ImageImpl<T>::AddElement( UInt width, UInt height, UInt stride, const Byte* data, UInt size )
{
	// Validate data.
	if ( _elements.Size() > 0 )
	{
		const Level& lvl = _elements[0].Levels[0];
		if ( (width != lvl.Width) || (height != lvl.Height) || (stride != lvl.Stride) || (size != lvl.Size) )
			throw lang::BadArgumentException( L"Image dimensions do not match those of the previously added element.", L"size" );
	}

	// Update element array.
	UInt offset = _data.Size();
	_elements.Add( Element(width, height, stride, offset, size) );
	if ( data != nullptr )
	{
		_data.Add( data, size );
	}
	else
	{
		_data.SetSize( _data.Size()+size, 0 );
	}

	// Guess image type.
	_type = GuessType();

	return _data.Begin() + offset;
}

template <class T>
SYNKRO_INLINE Byte* ImageImpl<T>::AddLevel( UInt width, UInt height, UInt stride, const Byte* data, UInt size )
{
	assert( !_elements.IsEmpty() );

	// Add primary element, if needed.
	if ( _elements.IsEmpty() )
	{
		return AddElement( width, height, stride, data, size );
	}

	// Make sure each next level's dimensions are two times smaller than those of the previous one.
	if ( _elements.Size() > 1 )
	{
		const Level* lvl = _elements.Last()->Levels.Last();
		const UInt correctWidth = ((lvl->Width >> 1) > 1) ? lvl->Width >> 1 : 1;
		const UInt correctHeight = ((lvl->Height >> 1) > 1) ? lvl->Height >> 1 : 1;
		if ( (width != correctWidth) || (height != correctHeight) )
			throw lang::BadArgumentException( L"Level dimensions are not two times smaller than those of the previously added level.", L"size" );
	}

	// Update mip level array.
	UInt offset = _data.Size();
	_elements.Last()->Levels.Add( Level(width, height, stride, offset, size) );
	if ( data != nullptr )
	{
		_data.Add( data, size );
	}
	else
	{
		_data.SetSize( _data.Size()+size, 0 );
	}

	// Guess image type.
	_type = GuessType();

	return _data.Begin() + offset;
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SetTransparentColor( const Color& color )
{
	if ( _format.IsCompressed() )
		throw lang::InvalidOperationException( L"Cannot set transparent color for compressed image." );

	if ( !_format.HasAlpha() )
		throw lang::InvalidOperationException( L"Cannot set transparent color for the image without alpha channel." );

	if ( _elements.Size() > 0 )
	{
		Level& lvl = _elements[0].Levels[0];
		PixelFormatEx::SetAlpha( _data.Begin()+lvl.Offset, _format, lvl.Width, lvl.Height, lvl.Stride, color, 0 );
	}
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SetTransparentColor()
{
	if ( _elements.Size() > 0 )
	{
		const Level& lvl = _elements[0].Levels[0];
		if ( (lvl.Width > 0) && (lvl.Height > 0) )
		{
			Color color = PixelFormatEx::GetPixel( _data.Begin()+lvl.Offset, _format, lvl.Width, lvl.Height, lvl.Stride, 0, 0 );
			SetTransparentColor( color );
		}
	}
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SetAlpha( IImage* alpha )
{
	assert( alpha != nullptr );

	if ( alpha == nullptr )
		throw lang::BadArgumentException( L"Alpha channel is not specified.", L"alpha" );

	if ( alpha->GetFormat().BitsPerPixel() != 8 )
		throw lang::BadArgumentException( lang::String(L"Bad alpha channel format: ").Append( alpha->GetFormat().ToString() ), L"alpha" );

	if ( (alpha->GetWidth() != this->GetWidth()) || (alpha->GetHeight() != this->GetHeight()) )
		throw lang::BadArgumentException( L"Alpha channel dimensions do not match those of the image.", L"alpha" );

	if ( _elements.Size() > 0 )
	{
		Level& lvl = _elements[0].Levels[0];
		PixelFormatEx::SetAlpha( _data.Begin()+lvl.Offset, _format, lvl.Width, lvl.Height, lvl.Stride, alpha->GetElement(), alpha->GetStride() );
	}
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SetFormat( const PixelFormat& format )
{
	if ( format == PixelFormat::Unknown )
		throw lang::BadArgumentException( L"Pixel format is unknown.", L"format" );

	_format = format;
}

template <class T>
SYNKRO_INLINE void ImageImpl<T>::SetType( const ImageType& type )
{
	if ( type != _type )
	{
		switch ( type )
		{
			case IMAGE_TYPE_CUBE:
				if ( _elements.Size() != 6 )
					throw lang::BadArgumentException( L"Cube image should have exactly six elements.", L"type" );
				break;

			case IMAGE_TYPE_VOLUME:
				if ( _elements.Size() == 1 )
					throw lang::BadArgumentException( L"Volume image should have more than one element.", L"type" );
				break;
		}

		for ( UInt i = 0; i < this->GetLevelCount(); ++i )
		{
			switch ( type )
			{
				case IMAGE_TYPE_LINEAR:
					if ( (_elements[0].Levels[i].Width != 1) && (_elements[0].Levels[i].Height != 1) )
						throw lang::BadArgumentException( L"Linear image should have at least one dimension equal to one.", L"type" );
					break;

				case IMAGE_TYPE_PLAIN:
					if ( (_elements[0].Levels[i].Width == 1) || (_elements[0].Levels[i].Height == 1) )
						throw lang::BadArgumentException( L"Plain image should have all dimensions not equal to one.", L"type" );
					break;

				case IMAGE_TYPE_CUBE:
					if ( _elements[0].Levels[i].Width != _elements[0].Levels[i].Height )
						throw lang::BadArgumentException( L"Cube image dimensions should match.", L"type" );
					break;
			}
		}

		_texture = nullptr;
		_type = type;
	}
}

template <class T>
SYNKRO_INLINE Bool ImageImpl<T>::IsLoaded() const
{
	return _loaded;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetElementCount() const
{
	return _elements.Size();
}

template <class T>
SYNKRO_INLINE Byte* ImageImpl<T>::GetElement( UInt element ) const
{
	return GetLevel( element, 0 );
}

template <class T>
SYNKRO_INLINE Byte* ImageImpl<T>::GetElement() const
{
	return GetElement( 0 );
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetLevelCount() const
{
	return (_elements.Size() > 0) ? _elements[0].Levels.Size() : 0;
}

template <class T>
SYNKRO_INLINE Byte* ImageImpl<T>::GetLevel( UInt element, UInt level ) const
{
	return (element < _elements.Size()) ? _data.Begin()+_elements[element].Levels[level].Offset : nullptr;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetWidth( UInt level ) const
{
	return (_elements.Size() > 0) && (level < _elements[0].Levels.Size()) ? _elements[0].Levels[level].Width : 0;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetWidth() const
{
	return GetWidth( 0 );
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetHeight( UInt level ) const
{
	return (_elements.Size() > 0) && (level < _elements[0].Levels.Size()) ? _elements[0].Levels[level].Height : 0;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetHeight() const
{
	return GetHeight( 0 );
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetStride( UInt level ) const
{
	return (_elements.Size() > 0) && (level < _elements[0].Levels.Size()) ? _elements[0].Levels[level].Stride : 0;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetStride() const
{
	return GetStride( 0 );
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetSliceStride( UInt level ) const
{
	if ( (_elements.Size() > 0) && (level < _elements[0].Levels.Size()) )
	{
		const Level& lvl = _elements[0].Levels[level];
		return lvl.Height * lvl.Stride;
	}
	return 0;
}

template <class T>
SYNKRO_INLINE UInt ImageImpl<T>::GetSliceStride() const
{
	return GetSliceStride( 0 );
}

template <class T>
SYNKRO_INLINE PixelFormat ImageImpl<T>::GetFormat() const
{
	return _format;
}

template <class T>
SYNKRO_INLINE ImageType ImageImpl<T>::GetType() const
{
	return _type;
}

template <class T>
SYNKRO_INLINE gfx::IResource* ImageImpl<T>::AsResource() const
{
	return _texture;
}

template <class T>
SYNKRO_INLINE gfx::IPlainRenderTexture* ImageImpl<T>::AsPlainRenderTexture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE gfx::ICubeRenderTexture* ImageImpl<T>::AsCubeRenderTexture() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IImage* ImageImpl<T>::Clone( const PixelFormat& format ) const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IImage* ImageImpl<T>::Clone() const
{
	if ( _elements.Size() > 0 )
	{
		return Clone( _format );
	}
	return nullptr;
}

template <class T>
SYNKRO_INLINE ImageType ImageImpl<T>::GuessType()
{
	if ( _elements.Size() == 6 )
	{
		for ( UInt i = 0; i < this->GetLevelCount(); ++i )
		{
			if ( (_elements[0].Levels[i].Width == 1) || (_elements[0].Levels[i].Height == 1) )
				return ImageType::Linear;

			if ( _elements[0].Levels[i].Width != _elements[0].Levels[i].Height )
				return ImageType::Plain;
		}
		return ImageType::Cube;
	}
	else
	{
		for ( UInt i = 0; i < this->GetLevelCount(); ++i )
		{
			if ( (_elements[0].Levels[i].Width == 1) || (_elements[0].Levels[i].Height == 1) )
				return ImageType::Linear;
		}
		return ImageType::Plain;
	}

	return ImageType::Unknown;
}
