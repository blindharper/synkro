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
// Purpose: Defines base image.
//==============================================================================
#ifndef _SYNKRO_IMG_BASEIMAGE_
#define _SYNKRO_IMG_BASEIMAGE_


#include "config.h"


namespace synkro
{


namespace img
{


// Base image.
class BaseImage
{
public:
	virtual void											WaitLoad() = 0;
	virtual void											SignalLoad() = 0;
	virtual UInt											GetSize() const = 0;
};


// Casts object to BaseImage.
#define AsBaseImage( OBJ ) dynamic_cast<BaseImage*>( OBJ )


} // img


} // synkro


#endif // _SYNKRO_IMG_BASEIMAGE_
