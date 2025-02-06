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
// Purpose: Bmp image codec factory.
//==============================================================================
#ifndef _SYNKRO_IMG_BMPIMAGECODECFACTORY_
#define _SYNKRO_IMG_BMPIMAGECODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <img/IImageCodecFactory.h>
#include <img/ImageCodec.h>
#include "BmpImageCodec.h"


namespace synkro
{


namespace img
{


// Bitmap image codec factory.
SYNKRO_FACTORY_BEGIN( BmpImageCodecFactory, IImageCodecFactory, ImageCodec, ImageCodec::Bmp )
	IImageCodec*		Create( Float quality ) { return new BmpImageCodec(quality); }
SYNKRO_FACTORY_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_BMPIMAGECODECFACTORY_
