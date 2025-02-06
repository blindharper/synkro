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
// Purpose: Targa image codec factory.
//==============================================================================
#ifndef _SYNKRO_IMG_TGAIMAGECODECFACTORY_
#define _SYNKRO_IMG_TGAIMAGECODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <img/IImageCodecFactory.h>
#include <img/ImageCodec.h>
#include "TgaImageCodec.h"


namespace synkro
{


namespace img
{


// Targa image codec factory.
SYNKRO_FACTORY_BEGIN( TgaImageCodecFactory, IImageCodecFactory, ImageCodec, ImageCodec::Tga )
	IImageCodec*		Create( Float quality ) { return new TgaImageCodec(quality); }
SYNKRO_FACTORY_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_TGAIMAGECODECFACTORY_
