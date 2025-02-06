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
// Purpose: Implements image.
//==============================================================================
#include "config.h"
#include "Image.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


Image::Image( BaseImageManager* imageManager, const PixelFormat& format, Bool loaded, ILog* log ) :
	ImageImpl<IImage>( imageManager, format, loaded ),
	_lock( loaded ),
	Logger( log, LogFacility::ImageManager )
{
}

void Image::Prepare( const PixelFormat& format, UInt levelCount )
{
	if ( _texture == nullptr )
	{
		WaitLoad();
		_texture = _imageManager->PrepareImage( this, format, levelCount );
	}
}

IImage* Image::Clone( const PixelFormat& format ) const
{
	if ( _texture == nullptr )
	{
		_lock.Wait();
	}

	if ( (_elements.Size() > 0) && (_elements[0].Levels.Size() > 0) )
	{
		const UInt stride = _elements[0].Levels[0].Width * format.BytesPerPixel();
		const UInt size = _elements[0].Levels[0].Height * stride;
		if ( size == 0 )
			return nullptr;

		Vector<Byte> buffer( A(Byte) );
		buffer.SetSize( size );
		const UInt width = _elements[0].Levels[0].Width;
		const UInt height = _elements[0].Levels[0].Height;
		PixelFormatEx::CopyPixels( buffer.Begin(), format, _data.Begin()+_elements[0].Levels[0].Offset, _format, width*height);

		IImage* image = _imageManager->Create( format );
		image->AddElement( width, height, stride, buffer.Begin(), size );
		return image;
	}

	return nullptr;
}

void Image::WaitLoad()
{
	if ( _texture == nullptr )
	{
		LogInfo( MessagePriority::Low, Formatter::Format(L"Waiting for image [{0}] loading...", this->ID()) );
		_lock.Wait();
	}
}


} // img


} // synkro
