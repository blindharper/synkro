//==============================================================================
// This file stream a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Implements generic image reader interface.
//==============================================================================
#include "config.h"
#include "imageread.h"
#include <io/IStream.h>
#include <img/IImage.h>
#include <img/ImageCodec/ImageCodecContextEx.h>
#include <core/ProgressListener.h>

using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro;

unsigned int imageread( void* buffer, unsigned int size, unsigned int count, void* stream, void* ctx )
{
	IStream* s = (IStream*)stream;
	UInt bytes = s->Read( buffer, CastUInt(size*count) );
	ImageCodecContextEx* context = (ImageCodecContextEx*)(ImageCodecContext*)ctx;
	context->BytesRead += bytes;
	if ( context->Listener != nullptr )
	{
		context->Listener->OnProgressUpdate( context->Image, context->BytesRead );
	}
	return (unsigned int)(bytes/size);
}
