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
// Purpose: Implements Targa image codec.
//==============================================================================
#ifndef _SYNKRO_IMG_TGAIMAGECODEC_
#define _SYNKRO_IMG_TGAIMAGECODEC_


#include "config.h"
#include "ImageCodecImpl.h"


namespace synkro
{


namespace img
{


// Targa image codec implementation.
class TgaImageCodec :
	public ImageCodecImpl<IImageCodec>
{
public:
	// Constructor.
	TgaImageCodec( Float quality );

private:
	void													LoadSurface( io::IStream* stream, ImageCodecContext* context );
	void													SaveSurface( io::IStream* stream, const Byte* data, ImageCodecContext* context );
	void													WriteByte( io::IStream* stream, Byte b );
	void													WriteShort( io::IStream* stream, UShort s );
	Byte													ReadByte( ImageCodecContext* context, io::IStream* stream );
	UShort													ReadShort( ImageCodecContext* context, io::IStream* stream );
};


} // img


} // synkro


#endif // _SYNKRO_IMG_TGAIMAGECODEC_
