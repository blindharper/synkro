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
// Purpose: Defines data stream writer.
//==============================================================================
SYNKRO_INLINE DataStreamWriter::DataStreamWriter( IDataStream* stream ) :
	_stream( stream )
{
	assert( _stream != nullptr );
}

SYNKRO_INLINE DataStreamWriter::~DataStreamWriter()
{
	_stream->Close();
}

SYNKRO_INLINE Bool DataStreamWriter::Open()
{
	return _stream->Open( io::OpenMode::Write );
}
