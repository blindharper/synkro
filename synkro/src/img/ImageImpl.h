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
#ifndef _SYNKRO_IMG_IMAGEIMPL_
#define _SYNKRO_IMG_IMAGEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <lang/Vector.h>
#include <img/Color.h>
#include "PixelFormatEx.h"
#include <img/ImageType.h>
#include <gfx/ITexture.h>
#include "ImageTypeConst.h"
#include "BaseImageManager.h"


namespace synkro
{


namespace img
{


// Generic image implementation.
template <class T>
class ImageImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	ImageImpl( BaseImageManager* imageManager, const PixelFormat& format, Bool loaded );
	virtual ~ImageImpl();

	// IImage methods.
	virtual void											Prepare( const PixelFormat& format, UInt levelCount );
	virtual void											Save( io::IStream* stream, const PixelFormat& format, const ImageCodec& type );
	virtual void											Save( io::IStream* stream, const PixelFormat& format );
	virtual void											SaveAsync( io::IStream* stream, const PixelFormat& format, const ImageCodec& type );
	virtual void											SaveAsync( io::IStream* stream, const PixelFormat& format );
	virtual Byte*											AddElement( UInt width, UInt height, UInt stride, const Byte* data, UInt size );
	virtual Byte*											AddLevel( UInt width, UInt height, UInt stride, const Byte* data, UInt size );
	virtual void											SetTransparentColor( const Color& color );
	virtual void											SetTransparentColor();
	virtual void											SetAlpha( IImage* alpha );
	virtual void											SetFormat( const PixelFormat& format );
	virtual void											SetType( const ImageType& type );
	virtual Bool											IsLoaded() const;
	virtual UInt											GetElementCount() const;
	virtual Byte*											GetElement( UInt element ) const;
	virtual Byte*											GetElement() const;
	virtual UInt											GetLevelCount() const;
	virtual Byte*											GetLevel( UInt element, UInt level ) const;
	virtual UInt											GetWidth( UInt level ) const;
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight( UInt level ) const;
	virtual UInt											GetHeight() const;
	virtual UInt											GetStride( UInt level ) const;
	virtual UInt											GetStride() const;
	virtual UInt											GetSliceStride( UInt level ) const;
	virtual UInt											GetSliceStride() const;
	virtual PixelFormat										GetFormat() const;
	virtual ImageType										GetType() const;
	virtual gfx::IResource*									AsResource() const;
	virtual gfx::IPlainRenderTexture*						AsPlainRenderTexture() const;
	virtual gfx::ICubeRenderTexture*						AsCubeRenderTexture() const;
	virtual IImage*											Clone( const PixelFormat& format ) const;
	virtual IImage*											Clone() const;

protected:
	// Image mip level.
	class Level
	{
	public:
		Level( UInt width, UInt height, UInt stride, UInt offset, UInt size ) :
			Width( width ), Height( height ), Stride( stride ), Offset( offset ), Size( size )
		{
		}

		Level() :
			Width( 0 ), Height( 0 ), Stride( 0 ), Offset( 0 ), Size( 0 )
		{
		}

		UInt Width;
		UInt Height;
		UInt Stride;
		UInt Offset;
		UInt Size;
	};

	// Image element.
	class Element
	{
	public:
		Element( UInt width, UInt height, UInt stride, UInt offset, UInt size ) :
			Levels( A(Level) )
		{
			Levels.Add( Level(width, height, stride, offset, size) );
		}

		Element() :
			Levels( A(Level) )
		{
		}

		lang::Vector<Level>	Levels;
	};

	BaseImageManager*										_imageManager;
	lang::Vector<Element>									_elements;
	lang::Vector<Byte>										_data;
	PixelFormat												_format;
	ImageType												_type;
	Bool													_loaded;
	P(gfx::ITexture)										_texture;

	ImageType												GuessType();
};


#include "ImageImpl.inl"


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGEIMPL_
