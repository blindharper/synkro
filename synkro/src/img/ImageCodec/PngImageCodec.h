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
// Purpose: Implements Png image codec.
//==============================================================================
#ifndef _SYNKRO_IMG_PNGIMAGECODEC_
#define _SYNKRO_IMG_PNGIMAGECODEC_


#include "config.h"
#include "ImageCodecImpl.h"


namespace synkro
{


namespace img
{


// Png image codec implementation.
class PngImageCodec :
	public ImageCodecImpl<IImageCodec>
{
public:
	// Constructor.
	PngImageCodec( Float quality );

private:
	void													LoadSurface( io::IStream* stream, ImageCodecContext* context );
	void													SaveSurface( io::IStream* stream, const Byte* data, ImageCodecContext* context );
};


} // img


} // synkro


#endif // _SYNKRO_IMG_PNGIMAGECODEC_
