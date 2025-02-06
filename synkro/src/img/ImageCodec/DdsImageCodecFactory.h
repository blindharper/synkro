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
// Purpose: DDS image codec factory.
//==============================================================================
#ifndef _SYNKRO_IMG_DDSIMAGECODECFACTORY_
#define _SYNKRO_IMG_DDSIMAGECODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <img/IImageCodecFactory.h>
#include <img/ImageCodec.h>
#include "DdsImageCodec.h"


namespace synkro
{


namespace img
{


// Dds image codec factory.
SYNKRO_FACTORY_BEGIN( DdsImageCodecFactory, IImageCodecFactory, ImageCodec, ImageCodec::Dds )
	IImageCodec*		Create( Float quality ) { return new DdsImageCodec(quality); }
SYNKRO_FACTORY_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_DDSIMAGECODECFACTORY_
