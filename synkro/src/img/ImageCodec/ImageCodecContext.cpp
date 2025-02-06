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
// Purpose: Implements image codec context.
//==============================================================================
#include "config.h"
#include <img/ImageCodecContext.h>


namespace synkro
{


namespace img
{


ImageCodecContext::ImageCodecContext() :
	Image( nullptr ),
	Stream( nullptr ),
	Streams( nullptr ),
	Listener( nullptr )
{
}

ImageCodecContext::~ImageCodecContext()
{
}


} // img


} // synkro
