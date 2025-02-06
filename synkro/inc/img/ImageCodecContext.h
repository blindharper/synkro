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
// Purpose: Defines image codec context.
//==============================================================================
#ifndef _SYNKRO_IMG_IMAGECODECCONTEXT_
#define _SYNKRO_IMG_IMAGECODECCONTEXT_


#include "config.h"
#include <img/PixelFormat.h>


namespace synkro
{


namespace img
{


/**
 * Image codec context.
 */
class SYNKRO_API ImageCodecContext
{
public:
	/** Creates context. */
	ImageCodecContext();

	/** Destroys context. */
	virtual ~ImageCodecContext();

	/* Image to load/save. */
	IImage*													Image;

	/** Input/output stream. */
	io::IStream*											Stream;

	/** Input/output streams. */
	io::IStreamSet*											Streams;

	/** Optional load progress listener. */
	core::ProgressListener*									Listener;

	/** Destination pixel format. */
	PixelFormat												Format;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_IMAGECODECCONTEXT_
