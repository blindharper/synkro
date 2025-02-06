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
#include "config.h"
#include "LoadImageTask.h"
#include <img/BaseImage.h>
#include <img/IImage.h>
#include <img/IImageCodec.h>
#include <img/ImageCodecContext.h>
#include <io/IStream.h>
#include <io/IStreamSet.h>
#include <core/ProgressListener.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::diag;
using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace img
{


LoadImageTask::LoadImageTask( IImage* image, IImageCodec* codec, IStream* stream, IStreamSet* streams, ILog* log, ProgressListener* listener ) :
	Logger( log, LogFacility::ImageManager ),
	_image( image ),
	_codec( codec ),
	_stream( stream ),
	_streams( streams ),
	_listener( listener )
{
}

void LoadImageTask::Execute()
{
	if ( _streams != nullptr )
	{
		LogInfo( MessagePriority::Low, Formatter::Format(L"Loading image [{0}] from streams = [{1}].", _image->ID(), _streams->ID()) );

		UInt total = 0;
		for ( UInt i = 0; i < _streams->GetSize(); ++i )
		{
			IStream* stream = _streams->Get( i );
			stream->Open( OpenMode::Read );
			total += stream->GetLength();
		}
		ImageCodecContext* ctx = _codec->CreateContext();
		ctx->Image = _image;
		ctx->Streams = _streams;
		ctx->Listener = _listener;
		if ( _listener != nullptr )
		{
			_listener->OnProgressBegin( _image, total );
		}
		_codec->Load( ctx );
		_codec->DestroyContext( ctx );
		AsBaseImage( _image )->SignalLoad();
		for ( UInt i = 0; i < _streams->GetSize(); ++i )
		{
			_streams->Get(i)->Close();
		}
		if ( _listener != nullptr )
		{
			_listener->OnProgressEnd( _image );
		}

		LogInfo( MessagePriority::Low, Formatter::Format(L"Image [{0}] loaded from stream.", _image->ID()) );
	}
	else if ( _stream != nullptr )
	{
		LogInfo( MessagePriority::Low, Formatter::Format(L"Loading image [{0}] from stream [{1}]. Name = {2,q}.", _image->ID(), _stream->ID(), _stream->GetName()) );

		_stream->Open( OpenMode::Read );
		ImageCodecContext* ctx = _codec->CreateContext();
		ctx->Image = _image;
		ctx->Stream = _stream;
		ctx->Listener = _listener;
		if ( _listener != nullptr )
		{
			_listener->OnProgressBegin( _image, _stream->GetLength() );
		}
		_codec->Load( ctx );
		_codec->DestroyContext( ctx );
		AsBaseImage( _image )->SignalLoad();
		_stream->Close();
		if ( _listener != nullptr )
		{
			_listener->OnProgressEnd( _image );
		}

		LogInfo( MessagePriority::Low, Formatter::Format(L"Image [{0}] loaded from stream.", _image->ID()) );
	}
}

void LoadImageTask::Cancel()
{
	// Do nothing.
}


} // img


} // synkro
