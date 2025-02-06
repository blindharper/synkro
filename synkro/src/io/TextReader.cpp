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
// Purpose: Defines text reader.
//==============================================================================
#include "config.h"
#include "TextReader.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{


TextReader::TextReader( IStream* stream, const char* encoding ) :
	StreamReader( stream ),
	_buffer( A(Char), BUFFER_SIZE ),
	_buffer2( A(Char), BUFFER_SIZE ),
	_encoding( Encoding::Get(encoding) )
{
	_buffer.SetSize( BUFFER_SIZE );
	_buffer2.SetSize( BUFFER_SIZE );
}

TextReader::TextReader( IStream* stream ) :
	StreamReader( stream ),
	_buffer( A(Char), BUFFER_SIZE ),
	_buffer2( A(Char), BUFFER_SIZE ),
	_encoding( Encoding::Get("ASCII-7") )
{
	_buffer.SetSize( BUFFER_SIZE );
	_buffer2.SetSize( BUFFER_SIZE );
}

Char TextReader::ReadChar()
{
	// Read bytes from the underlying stream.
	Byte bytes[64] = {};
	Char chars[64] = {};
	UInt srcLen = 0;
	UInt srcLenUsed = 0;
	UInt dstLenUsed = 0;

	UInt bytesRead;
	while ( (bytesRead = _stream->Read(&bytes[srcLen], 1)) > 0 )
	{
		srcLen += bytesRead;

		// Convert bytes to characters.
		if ( _encoding->Decode(bytes, srcLen, &srcLenUsed, chars, 64, &dstLenUsed) )
			return chars[0];
	}

	return CastChar( 0 );
}

String TextReader::Read( UInt num )
{
	// Test for stream end.
	if ( Eos() )
		return String::Null;

	// Read bytes from the underlying stream.
	Byte bytes[64] = {};
	Char chars[64] = {};
	UInt srcLen = 0;
	UInt srcLenUsed = 0;
	UInt dstLenUsed = 0;

	UInt bytesRead = 0; UInt i = 0;
	while ( (bytesRead = _stream->Read(&bytes[srcLen], 1)) > 0 )
	{
		srcLen += bytesRead;

		// Convert bytes to characters.
		if ( _encoding->Decode(bytes, srcLen, &srcLenUsed, chars, 64, &dstLenUsed) )
		{
			for ( UInt k = 0; k < dstLenUsed; ++k )
			{
				if ( _buffer.Size() < i+1 )
				{
					_buffer.Add( 0 );
				}
				_buffer[i++] = chars[k];
			}
			srcLen = 0;
		}
		if ( i >= num )
			break;
	}

	// Add terminating null.
	if ( _buffer.Size() < i+1 )
	{
		_buffer.Add( 0 );
	}
	_buffer[i] = 0;

	// Create a string from the character buffer.
	return String( _buffer.Begin() );
}

String TextReader::ReadLine()
{
	// Test for stream end.
	if ( Eos() )
		return String::Null;

	String str; UInt i = 0;
	while ( (str = TextReader::Read(1)).Length() == 1 )
	{
		// See if we are at the end of the line.
		if ( str[0] == L'\r' )
		{
			// Consume the remaining <LF> character.
			TextReader::Read( 1 );
			break;
		}
		else if ( str[0] == L'\n' )
		{
			break;
		}

		// Update character buffer.
		if ( _buffer2.Size() < i+1 )
		{
			_buffer2.Add( 0 );
		}
		_buffer2[i++] = str[0];
	}

	// Add terminating null.
	if ( _buffer2.Size() < i+1 )
	{
		_buffer2.Add( 0 );
	}
	_buffer2[i] = 0;

	// Create a string from the character buffer.
	return String( _buffer2.Begin() );
}

String TextReader::ReadToEnd()
{
	String res;

	String txt;
	while ( (txt = TextReader::Read(8192)) != String::Null )
	{
		res = res.Append( txt );
	}

	return res;
}


} // io


} // synkro
