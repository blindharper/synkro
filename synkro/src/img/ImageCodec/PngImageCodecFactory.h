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
// Purpose: Png image codec factory.
//==============================================================================
#ifndef _SYNKRO_IMG_PNGIMAGECODECFACTORY_
#define _SYNKRO_IMG_PNGIMAGECODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <img/IImageCodecFactory.h>
#include <img/ImageCodec.h>
#include "PngImageCodec.h"


namespace synkro
{


namespace img
{


// Png image codec factory.
SYNKRO_FACTORY_BEGIN( PngImageCodecFactory, IImageCodecFactory, ImageCodec, ImageCodec::Png )
	IImageCodec*		Create( Float quality ) { return new PngImageCodec(quality); }
SYNKRO_FACTORY_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_PNGIMAGECODECFACTORY_
