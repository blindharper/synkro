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
// Purpose: Defines image codec factory.
//==============================================================================
#ifndef _SYNKRO_IMG_IIMAGECODECFACTORY_
#define _SYNKRO_IMG_IIMAGECODECFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace img
{


/**
 * Image codec factory.
 */
iface IImageCodecFactory :
	public core::IFactory
{
public:
	/**
	 * Creates image codec.
	 * @param quality Quality of the image produced by the codec. Valid range is [0.0-1.0]. Default 1.0.
	 */
	virtual IImageCodec*									Create( Float quality ) = 0;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IIMAGECODECFACTORY_
