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
#ifndef _SYNKRO_IMG_IMAGECODECIMPL_
#define _SYNKRO_IMG_IMAGECODECIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/ProgressListener.h>
#include <io/IStreamSet.h>
#include <io/IStream.h>
#include <img/IImage.h>
#include <img/IImageCodec.h>
#include <img/IImageManager.h>
#include <img/PixelFormatEx.h>
#include <img/ImageCodec/ImageCodecContextEx.h>
#include <lang/Vector.h>
#include <io/SeekOriginConst.h>


namespace synkro
{


namespace img
{


// RGBA quadruple.
struct RGBA
{
	Byte Red;
	Byte Green;
	Byte Blue;
	Byte Alpha;
};


// Generic image codec implementation.
template <class T>
class ImageCodecImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructors & destructors.
	ImageCodecImpl( Float quality );
	virtual ~ImageCodecImpl();

	// IImageCodec methods.	
	virtual ImageCodecContext*								CreateContext();
	virtual void											DestroyContext( ImageCodecContext* context );
	virtual void											Load( ImageCodecContext* context );
	virtual void											Save( ImageCodecContext* context );

	// Other methods.
	virtual Bool											SupportsMipmaps() const;
	virtual void											BeginLoad( io::IStream* stream, ImageCodecContext* context );
	virtual void											LoadSurface( io::IStream* stream, ImageCodecContext* context ) = 0;
	virtual void											BeginSave( io::IStream* stream, const PixelFormat& format );
	virtual void											SaveSurface( io::IStream* stream, const Byte* data, ImageCodecContext* context ) = 0;

protected:
	IImageManager*											_imageManager;
	Float													_quality;

	UInt													Read( ImageCodecContext* context, io::IStream* stream, void* data, UInt size );
	Int														Seek( ImageCodecContext* context, io::IStream* stream, Int bytes, const io::SeekOrigin& origin );
	Byte*													CreateSurface( ImageCodecContext* context, UInt width, UInt height, UInt stride, const Byte* data, UInt size );
	void													SetImageFormat( ImageCodecContext* context, const PixelFormat& format );
	void													SetImageType( ImageCodecContext* context, const ImageType& type );
	img::PixelFormat										GetImageFormat( ImageCodecContext* context ) const;
	UInt													GetImageWidth( ImageCodecContext* context ) const;
	UInt													GetImageHeight( ImageCodecContext* context ) const;
	UInt													GetImageStride( ImageCodecContext* context ) const;

private:
	Byte*													GetNextSurface( ImageCodecContext* context ) const;
	void													UpdateProgress( ImageCodecContext* context ) const;
};


#include "ImageCodecImpl.inl"


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGECODECIMPL_
