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
#ifndef _SYNKRO_IMG_IMAGEMANAGER_
#define _SYNKRO_IMG_IMAGEMANAGER_


#include "config.h"
#include <lang/Map.h>
#include <core/ObjectImpl.h>
#include <core/ThreadPool.h>
#include <img/IImage.h>
#include <img/IImageManager.h>
#include <img/IImageCodec.h>
#include "BaseImageManager.h"


namespace synkro
{


namespace img
{


// Image manager implementation.
class ImageManager :
	public core::ObjectImpl<IImageManager>,
	public BaseImageManager,
	public Logger
{
public:
	// Constructor & destructor.
	ImageManager( Float quality, gfx::IGraphicsSystemEx* graphicsSystem, diag::ILog* log );
	~ImageManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// IImageManager methods.
	void													ClearCache();
	IImage*													CreateImage( const PixelFormat& format );
	IImage*													CreateImage( gfx::IPlainRenderTexture* texture );
	IImage*													CreateImage( gfx::ICubeRenderTexture* texture );
	IImage*													LoadImage( io::IStream* stream, PixelFormat& format );
	IImage*													LoadImageAsync( io::IStream* stream, PixelFormat& format, core::ProgressListener* listener );
	IImage*													LoadImage( io::IStreamSet* streams, PixelFormat& format);
	IImage*													LoadImageAsync( io::IStreamSet* streams, PixelFormat& format, core::ProgressListener* listener );
	void													GetStats( ImageStats& stats ) const;

	// BaseImageManager methods.
	IImage*													Create( const PixelFormat& format );
	gfx::ITexture*											PrepareImage( IImage* image, const PixelFormat& format, UInt levelCount );
	void													SaveImage( const IImage* image, io::IStream* stream, const PixelFormat& format, const ImageCodec& type );
	void													SaveImage( const IImage* image, io::IStream* stream, const PixelFormat& format );
	void													SaveImageAsync( const IImage* image, io::IStream* stream, const PixelFormat& format, const ImageCodec& type );
	void													SaveImageAsync( const IImage* image, io::IStream* stream, const PixelFormat& format );

	// Other methods.
	void													SetThreadPool( core::ThreadPool* threadPool );
	void													RegisterCodec( IImageCodecFactory* factory );

private:
	typedef lang::MapPair<UInt, P(IImageCodec)>			CodecEntry;
	typedef lang::MapPair<UInt, P(IImage)>					ImageEntry;

	lang::Map<UInt, P(IImageCodec)>						_codecs;
	lang::Map<UInt, P(IImage)>								_imageCache;
	gfx::IGraphicsSystemEx*									_graphicsSystem;
	core::ThreadPool*										_threadPool;
	Float													_quality;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGEMANAGER_
