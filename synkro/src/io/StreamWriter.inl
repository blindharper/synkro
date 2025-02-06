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
// Purpose: Defines base stream writer.
//==============================================================================
SYNKRO_INLINE StreamWriter::StreamWriter( IStream* stream, Bool append, Bool autoFlush ) :
	_stream( stream ),
	_autoFlush( autoFlush )
{
	assert( _stream != nullptr );

	_stream->Open( append ? OpenMode::Append : OpenMode::Write );
}

SYNKRO_INLINE StreamWriter::StreamWriter( IStream* stream, Bool append ) :
	_stream( stream ),
	_autoFlush( false )
{
	assert( _stream != nullptr );

	_stream->Open( append ? OpenMode::Append : OpenMode::Write );
}

SYNKRO_INLINE StreamWriter::StreamWriter( IStream* stream ) :
	_stream( stream ),
	_autoFlush( false )
{
	assert( _stream != nullptr );

	_stream->Open( OpenMode::Write );
}

SYNKRO_INLINE StreamWriter::~StreamWriter()
{	
	Close();
}

SYNKRO_INLINE void StreamWriter::Write( const void* data, UInt size )
{
	assert( _stream != nullptr );

	_stream->Write( data, size );
	if ( _autoFlush )
	{
		_stream->Flush();
	}
}

SYNKRO_INLINE void StreamWriter::Close()
{
	assert( _stream != nullptr );

	_stream->Flush();
	_stream->Close();
}

SYNKRO_INLINE void StreamWriter::Flush()
{
	assert( _stream != nullptr );

	_stream->Flush();
}

SYNKRO_INLINE void StreamWriter::SetAutoFlush( Bool autoFlush )
{
	_autoFlush = autoFlush;
}

SYNKRO_INLINE Bool StreamWriter::GetAutoFlush() const
{
	return _autoFlush;
}

SYNKRO_INLINE IStream* StreamWriter::GetStream() const
{
	return _stream;
}
