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
// Purpose: Obj mesh stream writer.
//==============================================================================
#include "config.h"
#include "ObjStreamWriter.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ObjStreamWriter::ObjStreamWriter( IStream* stream ) :
	_stream( stream ),
	_buffer( A(Byte) )
{
	_stream->Open( OpenMode::Write );
}

ObjStreamWriter::~ObjStreamWriter()
{
	_stream->Close();
}

void ObjStreamWriter::WriteComment( const String& comment )
{
	const char hash[] = "# ";
	_stream->Write( hash, 2 );
	WriteString( comment );
	WriteCRLF();
}

void ObjStreamWriter::WriteString( const String& value )
{
	_buffer.SetSize( value.Length()+1 );
	value.GetBytes( _buffer.Begin(), _buffer.Size() );
	_stream->Write( _buffer.Begin(), value.Length() );
}

void ObjStreamWriter::WriteFloat( Float value )
{
	char buf[32] = {};
	sprintf( buf, "%.6f;", value );
	_stream->Write( buf, CastUInt(strlen(buf)) );
}

void ObjStreamWriter::WriteUInt( UInt value )
{
	char buf[32] = {};
	sprintf( buf, "%d", value );
	_stream->Write( buf, CastUInt(strlen(buf)) );

}

void ObjStreamWriter::WriteChar( char value )
{
	_stream->Write( &value, sizeof(char) );
}

void ObjStreamWriter::WriteCRLF()
{
	const char crlf[] = "\r\n";
	_stream->Write( crlf, 2 );
}


} // scene


} // synkro
