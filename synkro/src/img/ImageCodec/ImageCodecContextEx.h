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
// Purpose: Defines extended image codec context.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGECODECCONTEXTEX_
#define _SYNKRO_IMG_IMAGECODECCONTEXTEX_


#include "config.h"
#include <img/ImageCodecContext.h>


namespace synkro
{


namespace img
{


// Extended image codec context.
class SYNKRO_API ImageCodecContextEx :
	public ImageCodecContext
{
public:
	// Creates context.
	ImageCodecContextEx();

	// Destroys context.
	virtual ~ImageCodecContextEx();

	UInt	CurrentWidth;
	UInt	CurrentHeight;
	UInt	CurrentElement;
	UInt	CurrentLevel;
	UInt	BytesRead;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGECODECCONTEXTEX_
