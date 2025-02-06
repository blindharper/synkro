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
// Purpose: Generic image codec implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ImageCodecImpl<T>::ImageCodecImpl( Float quality ) :
	_quality( quality )
{
}

template <class T>
SYNKRO_INLINE ImageCodecImpl<T>::~ImageCodecImpl()
{
}

template <class T>
SYNKRO_INLINE ImageCodecContext* ImageCodecImpl<T>::CreateContext()
{
	return new ImageCodecContextEx();
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::DestroyContext( ImageCodecContext* context )
{
	if ( context != nullptr )
	{
		delete context;
	}
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::Load( ImageCodecContext* context )
{
	assert( context != nullptr );
	assert( (context->Stream != nullptr) || (context->Streams != nullptr) );

	if ( context == nullptr )
		throw lang::BadArgumentException( L"Failed to load image. Bad context.", L"context" );

	if ( (context->Stream == nullptr) && (context->Streams == nullptr) )
		throw lang::BadArgumentException( L"Failed to load image. Bad stream.", L"stream" );

	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
	if ( context->Stream != nullptr )
	{
		ctx->CurrentWidth = 0;
		ctx->CurrentHeight = 0;
		ctx->BytesRead = 0;
		BeginLoad( context->Stream, context );
		LoadSurface( context->Stream, context );
	}
	else if ( context->Streams != nullptr )
	{
		if ( context->Streams->GetSize() == 0 )
			throw lang::BadArgumentException( L"Failed to load image. Stream set is empty.", L"streams" );

		ctx->CurrentWidth = 0;
		ctx->CurrentHeight = 0;
		ctx->BytesRead = 0;
		BeginLoad( context->Streams->Get(0), context );
		for ( UInt i = 0; i < context->Streams->GetSize(); ++i )
		{
			LoadSurface( context->Streams->Get(i), context );
		}
	}
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::Save( ImageCodecContext* context )
{
	assert(context!=nullptr);
	assert( (context->Stream != nullptr) || (context->Streams != nullptr) );
	assert( context->Image != nullptr );
	assert( context->Image->GetWidth() > 0 );
	assert( context->Image->GetHeight() > 0 );
	assert( context->Image->GetFormat() != PixelFormat::Unknown );
	assert( context->Image->GetElement() != nullptr );

	if ( context == nullptr )
		throw lang::BadArgumentException( L"Failed to save image. Bad context.", L"context" );

	if ( (context->Stream == nullptr) && (context->Streams == nullptr) )
		throw lang::BadArgumentException( L"Failed to save image. Bad stream.", L"stream" );

	if ( context->Image->GetWidth() == 0 )
		throw lang::BadArgumentException( L"Failed to save image. Image width is zero.", L"image" );

	if ( context->Image->GetHeight() == 0 )
		throw lang::BadArgumentException( L"Failed to save image. Image height is zero.", L"image" );

	if ( context->Image->GetFormat() == PixelFormat::Unknown )
		throw lang::BadArgumentException( L"Failed to save image. Bad pixel format.", L"image" );

	if ( context->Image->GetElement() == nullptr )
		throw lang::BadArgumentException( L"Failed to save image. Missing image data.", L"image" );

	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
	if ( context->Stream != nullptr )
	{
		ctx->CurrentElement = 0;
		ctx->CurrentLevel = 0;
		BeginSave(context->Stream, context->Format);
		SaveSurface( context->Stream, GetNextSurface(context), context );
	}
	else if ( context->Streams != nullptr )
	{
		if ( context->Streams->GetSize() == 0 )
			throw lang::BadArgumentException( L"Failed to save image. Stream set is empty.", L"streams" );

		ctx->CurrentElement = 0;
		ctx->CurrentLevel = 0;
		const Byte* data = nullptr;
		for ( UInt i = 0; (data = GetNextSurface(context)) != nullptr; ++i )
		{
			UInt idxStream = SupportsMipmaps() ? 0 : i;
			if ( idxStream >= context->Streams->GetSize() )
				return;
		
			if ( i == 0 )
			{
				BeginSave( context->Streams->Get(0), context->Format );
			}
			SaveSurface( context->Streams->Get(idxStream), data, context );
		}
	}
}

template <class T>
SYNKRO_INLINE Bool ImageCodecImpl<T>::SupportsMipmaps() const
{
	return false;
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::BeginLoad( io::IStream* stream, ImageCodecContext* context )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::BeginSave( io::IStream* stream, const PixelFormat& format )
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE UInt ImageCodecImpl<T>::Read( ImageCodecContext* context, io::IStream* stream, void* data, UInt size )
{
	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
	UInt bytes = stream->Read( data, size );
	ctx->BytesRead += bytes;
	UpdateProgress( context );
	return bytes;
}

template <class T>
SYNKRO_INLINE Int ImageCodecImpl<T>::Seek( ImageCodecContext* context, io::IStream* stream, Int bytes, const io::SeekOrigin& origin )
{
	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
	bytes = stream->Seek( bytes, origin );
	switch ( origin )
	{
		case io::SEEK_ORIGIN_START:
			ctx->BytesRead = bytes;
			break;

		case io::SEEK_ORIGIN_CURRENT:
			ctx->BytesRead += bytes;
			break;

		case io::SEEK_ORIGIN_END:
			ctx->BytesRead -= bytes;
			break;
	}
	UpdateProgress( context );
	return bytes;
}

template <class T>
SYNKRO_INLINE Byte* ImageCodecImpl<T>::CreateSurface( ImageCodecContext* context, UInt width, UInt height, UInt stride, const Byte* data, UInt size )
{
	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
	UInt currentSquare = ctx->CurrentWidth * ctx->CurrentHeight;
	UInt square = width * height;
	ctx->CurrentWidth = width;
	ctx->CurrentHeight = height;
	if ( square >= currentSquare )
	{
		return context->Image->AddElement( width, height, stride, data, size );
	}
	else
	{
		return context->Image->AddLevel( width, height, stride, data, size );
	}
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::SetImageFormat( ImageCodecContext* context, const PixelFormat& format )
{
	context->Image->SetFormat( format );
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::SetImageType( ImageCodecContext* context, const ImageType& type )
{
	context->Image->SetType( type );
}

template <class T>
SYNKRO_INLINE img::PixelFormat ImageCodecImpl<T>::GetImageFormat( ImageCodecContext* context ) const
{
	return context->Image->GetFormat();
}

template <class T>
SYNKRO_INLINE UInt ImageCodecImpl<T>::GetImageWidth( ImageCodecContext* context ) const
{
	return context->Image->GetWidth();
}

template <class T>
SYNKRO_INLINE UInt ImageCodecImpl<T>::GetImageHeight( ImageCodecContext* context ) const
{
	return context->Image->GetHeight();
}

template <class T>
SYNKRO_INLINE UInt ImageCodecImpl<T>::GetImageStride( ImageCodecContext* context ) const
{
	return context->Image->GetStride();
}

template <class T>
SYNKRO_INLINE Byte* ImageCodecImpl<T>::GetNextSurface( ImageCodecContext* context ) const
{
	Byte* data = nullptr;
	ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;

	if ( ctx->CurrentLevel >= context->Image->GetLevelCount() )
	{
		ctx->CurrentElement += 1;
		ctx->CurrentLevel = 0;
	}

	if ( ctx->CurrentElement < context->Image->GetElementCount() )
	{
		data = context->Image->GetLevel( ctx->CurrentElement, ctx->CurrentLevel );
		ctx->CurrentLevel += 1;
	}
	
	return data;
}

template <class T>
SYNKRO_INLINE void ImageCodecImpl<T>::UpdateProgress( ImageCodecContext* context ) const
{
	if ( context->Listener != nullptr )
	{
		ImageCodecContextEx* ctx = (ImageCodecContextEx*)context;
		context->Listener->OnProgressUpdate( context->Image, ctx->BytesRead );
	}
}
