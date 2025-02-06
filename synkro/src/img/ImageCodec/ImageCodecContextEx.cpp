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
// Purpose: Implements extended image codec context.
//==============================================================================
#include "config.h"
#include "ImageCodecContextEx.h"


namespace synkro
{


namespace img
{


ImageCodecContextEx::ImageCodecContextEx() :
	CurrentWidth( 0 ),
	CurrentHeight( 0 ),
	CurrentElement( 0 ),
	CurrentLevel( 0 ),
	BytesRead( 0 )
{
}

ImageCodecContextEx::~ImageCodecContextEx()
{
}


} // img


} // synkro
