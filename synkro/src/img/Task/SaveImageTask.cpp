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
#include "config.h"
#include "SaveImageTask.h"
#include <img/IImage.h>
#include <img/IImageCodec.h>
#include <img/ImageCodecContext.h>
#include <io/IStream.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


SaveImageTask::SaveImageTask( const IImage* image, IImageCodec* codec, IStream* stream, const PixelFormat& format, ILog* log ) :
	Logger( log, LogFacility::ImageManager ),
	_image( image ),
	_codec( codec ),
	_stream( stream ),
	_format( format )
{
}

void SaveImageTask::Execute()
{
	if ( _stream != nullptr )
	{
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Saving image [{0}] to stream [{1}]. Name = {2,q}.", _image->ID(), _stream->ID(), _stream->GetName()) );

		_stream->Open( OpenMode::Write );
		ImageCodecContext* ctx = _codec->CreateContext();
		ctx->Image = const_cast<IImage*>( _image );
		ctx->Stream = _stream;
		ctx->Format = _format;
		_codec->Save( ctx );
		_codec->DestroyContext( ctx );
		_stream->Close();
		
		LogInfo( MessagePriority::Lowest, Formatter::Format(L"Image [{0}] saved to stream.", _image->ID()) );
	}
}

void SaveImageTask::Cancel()
{
	// Do nothing.
}


} // img


} // synkro
