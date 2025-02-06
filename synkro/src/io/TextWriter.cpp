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
// Purpose: Defines text writer.
//==============================================================================
#include "config.h"
#include "TextWriter.h"
#include <core/Platform.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace io
{

TextWriter::TextWriter( IStream* stream, const char* encoding, Bool append, Bool autoFlush ) :
	StreamWriter( stream, append, autoFlush ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get(encoding) )
{
}

TextWriter::TextWriter( IStream* stream, const char* encoding, Bool append ) :
	StreamWriter( stream, append ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get(encoding) )
{
}

TextWriter::TextWriter( IStream* stream, const char* encoding ) :
	StreamWriter( stream ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get(encoding) )
{
}

TextWriter::TextWriter( IStream* stream, Bool append, Bool autoFlush ) :
	StreamWriter( stream, append, autoFlush ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get("ASCII-7") )
{
}

TextWriter::TextWriter( IStream* stream, Bool append ) :
	StreamWriter( stream, append ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get("ASCII-7") )
{
}

TextWriter::TextWriter( IStream* stream ) :
	StreamWriter( stream ),
	_buffer( A(Byte), BUFFER_CAPACITY ),
	_encoding( Encoding::Get("ASCII-7") )
{
}

void TextWriter::Write( const String& text )
{
	_buffer.Clear();

	Byte bytes[64] = {};
	UInt srcLenUsed = 0;
	UInt dstLenUsed = 0;
	const UInt len = text.Length();
	for ( UInt i = 0; i < len; ++i )
	{
		const Char ch = text[i];
		if ( _encoding->Encode(&ch, 1, &srcLenUsed, bytes, 64, &dstLenUsed) )
			_buffer.Add( bytes, dstLenUsed );
	}
	StreamWriter::Write( _buffer.Begin(), _buffer.Size() );
}

void TextWriter::WriteLine( const String& text )
{
	Write( text );
	Write( Platform::LineDelimiter );
}


} // io


} // synkro
