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
// Purpose: "Load image" task.
//==============================================================================
#ifndef _SYNKRO_IMG_LOADIMAGETASK_
#define _SYNKRO_IMG_LOADIMAGETASK_


#include "config.h"
#include <core/Task.h>
#include <lang/Formatter.h>
#include <internal/Logger.h>


namespace synkro
{


namespace img
{


// Image loader.
class LoadImageTask :
	public core::Task,
	public Logger
{
public:
	// Constructor.
	LoadImageTask( IImage* image, IImageCodec* codec, io::IStream* stream, io::IStreamSet* streams, diag::ILog* log, core::ProgressListener* listener );

	// Task methods.
	void													Execute();
	void													Cancel();

private:
	IImage*													_image;
	IImageCodec*											_codec;
	io::IStream*											_stream;
	io::IStreamSet*											_streams;
	core::ProgressListener*									_listener;
};


} // img


} // synkro


#endif // _SYNKRO_IMG_LOADIMAGETASK_
