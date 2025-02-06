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
// Purpose: "Save image" task.
//==============================================================================
#ifndef _SYNKRO_IMG_SAVEIMAGETASK_
#define _SYNKRO_IMG_SAVEIMAGETASK_


#include "config.h"
#include <core/Task.h>
#include <img/PixelFormat.h>
#include <lang/Formatter.h>
#include <internal/Logger.h>


namespace synkro
{


namespace img
{


// Image loader.
class SaveImageTask :
	public core::Task,
	public Logger
{
public:
	// Constructor.
	SaveImageTask( const IImage* image, IImageCodec* codec, io::IStream* stream, const PixelFormat& format, diag::ILog* log );

	// Task methods.
	void													Execute();
	void													Cancel();

private:
	const IImage*											_image;
	IImageCodec*											_codec;
	io::IStream*											_stream;
	PixelFormat												_format;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_SAVEIMAGETASK_
