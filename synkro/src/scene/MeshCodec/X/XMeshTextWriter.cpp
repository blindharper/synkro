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
// Purpose: Text DirectX mesh writer.
//==============================================================================
#include "config.h"
#include "XMeshTextWriter.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


XMeshTextWriter::XMeshTextWriter()
{
}

void XMeshTextWriter::Initialize( IStream* stream )
{
	_stream = stream;
	_buffer.Clear();
	_indent = 0;
}

void XMeshTextWriter::BeginTemplate( Byte type, const String& name )
{
	WriteCRLF();
	WriteIndent();

	if ( _templates.ContainsKey(type) )
	{
		String tmpl = _templates[type];
		WriteName( tmpl );
		WriteChar( ' ' );
	}

	if ( !name.IsEmpty() )
	{
		WriteName( name );
		WriteChar( ' ' );
	}
	WriteChar( '{' );
	WriteCRLF();
	++_indent;
}

void XMeshTextWriter::EndTemplate()
{
	--_indent;
	WriteIndent();
	WriteChar( '}' );
	WriteCRLF();
}

void XMeshTextWriter::WriteString( const String& str )
{
	WriteIndent();
	WriteChar( '"' );
	WriteName( str );
	WriteChar( '"' );
	WriteChar( ';' );
	WriteCRLF();
}

void XMeshTextWriter::WriteArray( const Vector<UInt>& array )
{
	char buf[32] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		WriteIndent();
		sprintf( buf, "%d", array[i] );
		_stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF();
	}
}

void XMeshTextWriter::WriteArray( const Vector<Vector2>& array )
{
	char buf[64] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		WriteIndent();
		const Vector2& vec = array[i];
		sprintf( buf, "%.6f;%.6f;", vec.x, vec.y );
		_stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF();
	}
}

void XMeshTextWriter::WriteArray( const Vector<Vector3>& array )
{
	char buf[96] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		WriteIndent();
		const Vector3& vec = array[i];
		sprintf( buf, "%.6f;%.6f;%.6f;", vec.x, vec.y, vec.z );
		_stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF();
	}
}

void XMeshTextWriter::WriteTexCoords( const Vector<Vector2>& array )
{
	WriteDword( array.Size() );
	WriteArray( array );
}

void XMeshTextWriter::WritePositions( const Vector<Vector3>& array )
{
	WriteDword( array.Size() );
	WriteArray( array );
}

void XMeshTextWriter::WriteIndices( const Vector<UInt>& array )
{
	WriteDword( array.Size()/4 );
	WriteFaces( array );
}

void XMeshTextWriter::WriteSubsets( const Vector<UInt>& array, UInt materialCount )
{
	WriteDword( materialCount );
	WriteDword( array.Size()/4 );
}

void XMeshTextWriter::WriteColors( UInt count )
{
	// Do nothing.
}

void XMeshTextWriter::WriteColorRGBA( Float r, Float g, Float b, Float a )
{
	WriteIndent();
	WriteFloat( r );
	WriteFloat( g );
	WriteFloat( b );
	WriteFloat( a );
	WriteChar( ';' );
	WriteCRLF();
}

void XMeshTextWriter::WriteColorRGB( Float r, Float g, Float b )
{
	WriteIndent();
	WriteFloat( r );
	WriteFloat( g );
	WriteFloat( b );
	WriteChar( ';' );
	WriteCRLF();
}

void XMeshTextWriter::WritePower( Float power )
{
	WriteIndent();
	WriteFloat( power );
	WriteCRLF();
}

void XMeshTextWriter::WriteFaces( const Vector<UInt>& array )
{
	char buf[128] = {};
	UInt count = array.Size()/4;
	for ( UInt i = 0; i < count; ++i )
	{
		UInt idx = 4*i;
		sprintf( buf, "%d;%d,%d,%d;", array[idx], array[idx+1], array[idx+2], array[idx+3] );
		WriteIndent();
		_stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( (i == count-1) ? ';' : ',' );
		WriteCRLF();
	}
}

void XMeshTextWriter::WriteDword( UInt value )
{
	WriteIndent();
	String str( CastInt(value) );
	_buffer.SetSize( str.Length()+1 );
	str.GetBytes( _buffer.Begin(), _buffer.Size() );
	_stream->Write( _buffer.Begin(), str.Length() );
	WriteChar( ';' );
}

void XMeshTextWriter::WriteFloat( Float value )
{
	char buf[32] = {};
	sprintf( buf, "%.6f;", value );
	_stream->Write( buf, CastUInt(strlen(buf)) );
}

void XMeshTextWriter::WriteCRLF()
{
	char crlf[] = "\r\n";
	_stream->Write( crlf, 2 );
}

void XMeshTextWriter::WriteIndent()
{
	for ( UInt i = 0; i < _indent; ++i )
	{
		WriteChar( ' ' );
	}
}

void XMeshTextWriter::WriteChar( char value )
{
	_stream->Write( &value, sizeof(char) );
}


} // scene


} // synkro
