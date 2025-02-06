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
// Purpose: Implements cube rendering image.
//==============================================================================
#include "config.h"
#include "CubeRenderImage.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


CubeRenderImage::CubeRenderImage( BaseImageManager* imageManager, ICubeRenderTexture* texture ) :
	ImageImpl<IImage>( imageManager, texture->GetFormat(), true ),
	_cubeTexture( texture )
{
	assert( _cubeTexture != nullptr );

	UInt length = 0; UInt stride = 0; PixelFormat format; Byte* data = nullptr; UInt size = 0;
	for ( UInt i = 0; i < 6; ++i )
	{
		const CubeFace face = (CubeFace)i;
		_cubeTexture->GetData( face, &length, &stride, &format, &data, &size );
		AddElement( length, length, stride, data, size );
	}
}

IResource* CubeRenderImage::AsResource() const
{
	return _cubeTexture;
}

ICubeRenderTexture* CubeRenderImage::AsCubeRenderTexture() const
{
	return _cubeTexture;
}


} // img


} // synkro
