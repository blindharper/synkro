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
// Purpose: Implements plain rendering image.
//==============================================================================
#include "config.h"
#include "PlainRenderImage.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


PlainRenderImage::PlainRenderImage( BaseImageManager* imageManager, IPlainRenderTexture* texture ) :
	ImageImpl<IImage>( imageManager, texture->GetFormat(), true ),
	_plainTexture( texture )
{
	assert( _plainTexture != nullptr );

	UInt width; UInt height; UInt stride; PixelFormat format; Byte* data; UInt size;
	_plainTexture->GetData( &width, &height, &stride, &format, &data, &size );
	SetFormat( format );
	AddElement( width, height, stride, data, size );
}

IResource* PlainRenderImage::AsResource() const
{
	return _plainTexture;
}

IPlainRenderTexture* PlainRenderImage::AsPlainRenderTexture() const
{
	return _plainTexture;
}


} // img


} // synkro
