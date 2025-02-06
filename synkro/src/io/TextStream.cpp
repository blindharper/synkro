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
// Purpose: Implements text stream.
//==============================================================================
#include "config.h"
#include "TextStream.h"
#include "SeekOriginConst.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


TextStream::TextStream( const String& buffer, const char* encoding ) :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Char) ),
	_encoding( Encoding::Get(encoding) ),
	_position( 0L )
{
	// Copy characters from the original string.
	for ( UInt i = 0; i < buffer.Length(); ++i )
	{
		_buffer.Add( buffer[i] );
	}
}

TextStream::TextStream( const String& buffer ) :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Char) ),
	_encoding( Encoding::Get("ASCII-7") ),
	_position( 0L )
{
	// Copy characters from the original string.
	for ( UInt i = 0; i < buffer.Length(); ++i )
	{
		_buffer.Add( buffer[i] );
	}
}

TextStream::TextStream( const char* encoding ) :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Char) ),
	_encoding( Encoding::Get(encoding) ),
	_position( 0L )
{
}

TextStream::TextStream() :
	StreamImpl<IStream>( nullptr, String::Empty ),
	_buffer( A(Char) ),
	_encoding( Encoding::Get("ASCII-7") ),
	_position( 0L )
{
}

void TextStream::Open( const OpenMode& mode )
{
	// Skip if reopening in the same mode.
	if ( mode == _mode )
		return;

	// Call base implementation.
	StreamImpl<IStream>::Open( mode );

	// Set initial position.
	if ( _mode.IsSet(OpenMode::Append) )
	{
		_position = CastUInt( _buffer.Size() );
	}
	else if ( _mode.IsSet(OpenMode::Write) )
	{
		_buffer.Clear();
		_position = 0L;
	}
	else
	{
		_position = 0L;
	}
}

void TextStream::Flush()
{
	_buffer.Add( 0 );
	_buffer.SetSize( _buffer.Size()-1 );
}

UInt TextStream::Read( void* data, UInt size )
{
	assert( _mode.IsSet(OpenMode::Read) );

	// Sanity check.
	if ( _mode.IsNotSet(OpenMode::Read) )
		throw IoException( L"Stream is not open for reading." );

	// Read elements.
	UInt srcLenUsed = 0; UInt dstLenUsed = 0;
	if ( _encoding->Encode(_buffer.Begin()+_position, _buffer.Size()-_position, &srcLenUsed, (Byte*)data, size, &dstLenUsed) )
	{
		_position += srcLenUsed;
	}

	return dstLenUsed;
}

UInt TextStream::Write( const void* data, UInt size )
{
	assert( _mode.IsSet(OpenMode::Write) || _mode.IsSet(OpenMode::Append) );

	// Sanity check.
	if ( _mode.IsNotSet(OpenMode::Write) && _mode.IsNotSet(OpenMode::Append) )
		throw IoException( L"Stream is not open for writing." );

	// Write elements.
	Char dst[64] = {};
	UInt srcLenUsed = 0; UInt dstLenUsed = 0;
	if ( _encoding->Decode((const Byte*)data, size, &srcLenUsed, dst, 64, &dstLenUsed) )
	{
		_buffer.Add( &dst[0], dstLenUsed );
		_position += dstLenUsed;
	}

	return size;
}

Int TextStream::Seek( Int bytes, const SeekOrigin& origin )
{
	const UInt posOld = _position;
	Int pos = 0L;
	switch ( origin )
	{
		case SEEK_ORIGIN_START:
			pos = bytes;
			break;

		case SEEK_ORIGIN_CURRENT:
			pos = _position + bytes;
			break;

		case SEEK_ORIGIN_END:
			pos = _buffer.Size() - bytes;
			break;
	}
	_position = max( 0, min(CastUInt(pos), _buffer.Size()-1) );
	return CastInt(_position-posOld);
}

Bool TextStream::Reset()
{
	_position = 0L;
	return true;
}

void TextStream::SetLength( UInt length )
{
	_buffer.SetSize( length );
	_position = max( 0, min(_position, _buffer.Size()-1) );
}

UInt TextStream::GetLength() const
{
	return _buffer.Size();
}

UInt TextStream::GetPosition() const
{
	return _position;
}


} // io


} // synkro
