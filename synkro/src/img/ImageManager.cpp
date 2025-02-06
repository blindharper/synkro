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
// Purpose: Implements image manager.
//==============================================================================
#include "config.h"
#include "ImageManager.h"
#include "Image.h"
#include "ImageTypeConst.h"
#include "RenderImage/CubeRenderImage.h"
#include "RenderImage/PlainRenderImage.h"
#include "Task/LoadImageTask.h"
#include "Task/SaveImageTask.h"
#include "Task/PrepareImageTask.h"
#include <core/ISynkro.h>
#include <core/ProgressListener.h>
#include <img/ImageCodecContext.h>
#include <img/ImageCodec.h>
#include <img/IImageCodecFactory.h>
#include <io/Path.h>
#include <io/IStream.h>
#include <io/IStreamSet.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/ILinearTexture.h>
#include <gfx/IPlainTexture.h>
#include <gfx/ICubeTexture.h>
#include <gfx/IVolumeTexture.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


ImageManager::ImageManager( Float quality, IGraphicsSystemEx* graphicsSystem, ILog* log ) :
	_codecs( A(CodecEntry) ),
	_imageCache( A(ImageEntry) ),
	_graphicsSystem( graphicsSystem ),
	_quality( quality ),
	Logger( log, LogFacility::ImageManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating image manager...") );
}

ImageManager::~ImageManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying image manager...") );
}

Bool ImageManager::Update( Double delta )
{
	return true;
}

void ImageManager::ClearCache()
{
	_imageCache.Clear();
}

IImage* ImageManager::CreateImage( const PixelFormat& format )
{
	return new Image( this, format, true, _log );
}

IImage* ImageManager::CreateImage( IPlainRenderTexture* texture )
{
	assert( texture != nullptr );

	return new PlainRenderImage( this, texture );
}

IImage* ImageManager::CreateImage( ICubeRenderTexture* texture )
{
	assert( texture != nullptr );

	return new CubeRenderImage( this, texture );
}

IImage* ImageManager::LoadImage( IStream* stream, PixelFormat& format )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to load image. Bad stream.", L"stream", L"nullptr" );

	// Return cached image, if one exists.
	const UInt key = stream->ID();
	if ( _imageCache.ContainsKey(key) )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Loading image {0,q}. Stream = [{1}]. Loaded from cache.", stream->GetName(), key) );
		return _imageCache[key];
	}

	// Determine image codec to use.
	const ImageCodec type( Path(stream->GetName()).GetExtensionWoDot() );
	if ( type == ImageCodec::Unknown )
		throw BadArgumentException( L"Failed to load image. Unknown image type.", L"stream" );

	IImageCodec* codec = _codecs[type];
	IImage* image = new Image( this, format, true, _log );
	_imageCache[key] = image;

	// Load image.
	LogInfo( MessagePriority::Low, Formatter::Format(L"Loading image [{0}] from stream [{1}]. Name = {2,q}.", image->ID(), stream->ID(), stream->GetName()) );
	stream->Open( OpenMode::Read );
	ImageCodecContext* ctx = codec->CreateContext();
	ctx->Image = image;
	ctx->Stream = stream;
	codec->Load( ctx );
	codec->DestroyContext( ctx );
	stream->Close();
	format = image->GetFormat();
	LogInfo( MessagePriority::Low, Formatter::Format(L"Image [{0}] loaded from stream.", image->ID()) );

	return image;
}

IImage* ImageManager::LoadImageAsync( IStream* stream, PixelFormat& format, ProgressListener* listener )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to load image. Bad stream.", L"stream", L"nullptr" );

	// Return cached image, if one exists.
	const UInt key = stream->ID();
	if ( _imageCache.ContainsKey(key) )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Loading image {0,q}. Stream = [{1}]. Loaded from cache.", stream->GetName(), key) );
		return _imageCache[key];
	}

	// Determine image codec to use.
	const ImageCodec type( Path(stream->GetName()).GetExtensionWoDot() );
	if ( type == ImageCodec::Unknown )
		throw BadArgumentException( L"Failed to load image. Unknown image type.", L"stream" );

	// Create image load task.
	IImageCodec* codec = _codecs[type];
	IImage* image = new Image( this, format, false, _log );
	_imageCache[key] = image;
	_threadPool->AddTask( new LoadImageTask(image, codec, stream, nullptr, _log, listener) );
	return image;
}

IImage* ImageManager::LoadImage( IStreamSet* streams, PixelFormat& format )
{
	assert( streams != nullptr );
	assert( streams->GetSize() != 0 );

	if ( streams == nullptr )
		throw BadArgumentException( L"Failed to load image. Bad stream set.", L"streams", L"nullptr" );

	if ( streams->GetSize() == 0 )
		throw BadArgumentException( L"Failed to load image. Empty stream set.", L"streams" );

	// Return cached image, if one exists.
	const UInt key = streams->ID();
	if ( _imageCache.ContainsKey(key) )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Loading image. Stream = {{0}]. Loaded from cache.", key) );
		return _imageCache[key];
	}

	// Determine image codec to use.
	const ImageCodec type( Path(streams->Get(0)->GetName()).GetExtensionWoDot() );
	if ( type == ImageCodec::Unknown )
		throw BadArgumentException( L"Failed to load image. Unknown image type.", L"stream" );

	// Load image.
	IImageCodec* codec = _codecs[type];
	IImage* image = new Image( this, format, true, _log );
	_imageCache[key] = image;
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Loading image [{0}] from streams = [{1}].", image->ID(), streams->ID()) );

	for ( UInt i = 0; i < streams->GetSize(); ++i )
	{
		streams->Get(i)->Open( OpenMode::Read );
	}
	ImageCodecContext* ctx = codec->CreateContext();
	ctx->Image = image;
	ctx->Streams = streams;
	codec->Load( ctx );
	codec->DestroyContext( ctx );
	for ( UInt i = 0; i < streams->GetSize(); ++i )
	{
		streams->Get(i)->Close();
	}
	format = image->GetFormat();

	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Image [{0}] loaded from stream.", image->ID()) );
	return image;
}

IImage* ImageManager::LoadImageAsync( IStreamSet* streams, PixelFormat& format, ProgressListener* listener )
{
	assert( streams != nullptr );
	assert( streams->GetSize() != 0 );

	if ( streams == nullptr )
		throw BadArgumentException( L"Failed to load image. Bad stream set.", L"streams", L"nullptr" );

	if ( streams->GetSize() == 0 )
		throw BadArgumentException( L"Failed to load image. Empty stream set.", L"streams" );

	// Return cached image, if one exists.
	const UInt key = streams->ID();
	if ( _imageCache.ContainsKey(key) )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Loading image. Stream = {{0}]. Loaded from cache.", key) );
		return _imageCache[key];
	}

	// Determine image codec to use.
	const ImageCodec type( Path(streams->Get(0)->GetName()).GetExtensionWoDot() );
	if ( type == ImageCodec::Unknown )
		throw BadArgumentException( L"Failed to load image. Unknown image type.", L"stream" );

	// Create image load task.
	IImageCodec* codec = _codecs[type];
	IImage* image = new Image( this, format, false, _log );
	_imageCache[key] = image;
	_threadPool->AddTask( new LoadImageTask(image, codec, nullptr, streams, _log, listener) );
	return image;
}

void ImageManager::GetStats( ImageStats& stats ) const
{
	stats.CacheSize = 0;
	MapIterator<UInt, P(IImage)> it = _imageCache.Begin();
	for ( ; it != _imageCache.End() ; ++it )
	{
		stats.CacheSize += AsBaseImage( it.Value().AsPtr() )->GetSize();
	}
}

IImage* ImageManager::Create( const PixelFormat& format )
{
	return CreateImage( format );
}

ITexture* ImageManager::PrepareImage( IImage* image, const PixelFormat& format, UInt levelCount )
{
	ITexture* texture = nullptr;

	switch ( image->GetType() )
	{
		case IMAGE_TYPE_LINEAR:
			texture = _graphicsSystem->GetDevice()->CreateTexture( DataUsage::Default, image->GetWidth(), format, levelCount, image->GetElementCount() );
			break;

		case IMAGE_TYPE_PLAIN:
			texture = _graphicsSystem->GetDevice()->CreateTexture( DataUsage::Default, image->GetWidth(), image->GetHeight(), format, levelCount, image->GetElementCount() );
			break;

		case IMAGE_TYPE_CUBE:
			texture = _graphicsSystem->GetDevice()->CreateTexture( DataUsage::Default, image->GetWidth(), format, levelCount );
			break;

		case IMAGE_TYPE_VOLUME:
			texture = _graphicsSystem->GetDevice()->CreateTexture( DataUsage::Default, image->GetWidth(), image->GetHeight(), image->GetElementCount(), format, levelCount );
			break;
	}

	_threadPool->AddTask( new PrepareImageTask(image, texture, _log) );

	return texture;
}

void ImageManager::SaveImage( const IImage* image, IStream* stream, const PixelFormat& format, const ImageCodec& type )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save image. Bad stream.", L"stream" );

	IImageCodec* codec = _codecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save image. Unknown image type '{0}'.", type.ToString()), L"type", type.ToString() );

	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Saving image [{0}] to stream [{1}]. Name = {2,q}.", image->ID(), stream->ID(), stream->GetName()) );

	stream->Open( OpenMode::Write );
	ImageCodecContext ctx;
	ctx.Image = const_cast<IImage*>( image );
	ctx.Stream = stream;
	ctx.Format = format;
	codec->Save( &ctx );
	stream->Close();

	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Image [{0}] saved to stream.", image->ID()) );
}

void ImageManager::SaveImage( const IImage* image, IStream* stream, const PixelFormat& format )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		SaveImage( image, stream, format, ImageCodec(type) );
	}
}

void ImageManager::SaveImageAsync( const IImage* image, IStream* stream, const PixelFormat& format, const ImageCodec& type )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save image. Bad stream.", L"stream" );

	IImageCodec* codec = _codecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save image. Unknown image type '{0}'.", type.ToString()), L"type", type.ToString() );

	_threadPool->AddTask( new SaveImageTask(image, codec, stream, format, _log) );
}

void ImageManager::SaveImageAsync( const IImage* image, IStream* stream, const PixelFormat& format )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		SaveImageAsync( image, stream, format, ImageCodec(type) );
	}
}

void ImageManager::SetThreadPool( ThreadPool* threadPool )
{
	_threadPool = threadPool;
}

void ImageManager::RegisterCodec( IImageCodecFactory* factory )
{
	assert( factory != nullptr );

	const ImageCodec type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering image codec {0,q}...", type.ToString()) );
	if ( !_codecs.ContainsKey(type) )
	{
		try
		{
			IImageCodec* codec = factory->Create( _quality );
			_codecs[type] = codec;
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Codec already registered.") );
	}
}


} // img


} // synkro
