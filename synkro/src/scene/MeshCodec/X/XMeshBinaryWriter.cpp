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
// Purpose: Binary DirectX mesh writer.
//==============================================================================
#include "config.h"
#include "XMeshBinaryWriter.h"


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


XMeshBinaryWriter::XMeshBinaryWriter()
{
}

void XMeshBinaryWriter::Initialize( IStream* stream )
{
	_stream = stream;
	_buffer.Clear();
}

void XMeshBinaryWriter::BeginTemplate( Byte type, const String& name )
{
	if ( _templates.ContainsKey(type) )
	{
		String tmpl = _templates[type];
		WriteToken( TOKEN_NAME );
		WriteDword( tmpl.Length() );
		WriteName( tmpl );
	}

	if ( !name.IsEmpty() )
	{
		WriteToken( TOKEN_NAME );
		WriteDword( name.Length() );
		WriteName( name );
	}

	WriteToken( TOKEN_OBRACE );
}

void XMeshBinaryWriter::EndTemplate()
{
	WriteToken( TOKEN_CBRACE );
}

void XMeshBinaryWriter::WriteString( const String& str )
{
	WriteToken( TOKEN_STRING );
	WriteDword( str.Length() );
	WriteName( str );
	WriteToken( TOKEN_SEMICOLON );
}

void XMeshBinaryWriter::WriteArray( const Vector<UInt>& array )
{
	_stream->Write( array.Begin(), array.Size()*sizeof(UInt) );
}

void XMeshBinaryWriter::WriteArray( const Vector<Vector2>& array )
{
	_stream->Write( array.Begin(), array.Size()*sizeof(Vector2) );
}

void XMeshBinaryWriter::WriteArray( const Vector<Vector3>& array )
{
	_stream->Write( array.Begin(), array.Size()*sizeof(Vector3) );
}

void XMeshBinaryWriter::WriteTexCoords( const Vector<Vector2>& array )
{
	WriteToken( TOKEN_INTEGER_LIST );
	WriteDword( 1 );
	WriteDword( array.Size() );

	WriteToken( TOKEN_FLOAT_LIST );
	WriteDword( 2*array.Size() );
	WriteArray( array );
}

void XMeshBinaryWriter::WritePositions( const Vector<Vector3>& array )
{
	WriteToken( TOKEN_INTEGER_LIST );
	WriteDword( 1 );
	WriteDword( array.Size() );
	WriteToken( TOKEN_FLOAT_LIST );
	WriteDword( 3*array.Size() );
	WriteArray( array );
}

void XMeshBinaryWriter::WriteIndices( const Vector<UInt>& array )
{
	WriteToken( TOKEN_INTEGER_LIST );
	WriteDword( array.Size()+1 );
	WriteDword( array.Size()/4 );
	WriteArray( array );
}

void XMeshBinaryWriter::WriteSubsets( const Vector<UInt>& array, UInt materialCount )
{
	WriteToken( TOKEN_INTEGER_LIST );
	WriteDword( array.Size()/4+2 );
	WriteDword( materialCount );
	WriteDword( array.Size()/4 );
}

void XMeshBinaryWriter::WriteColors( UInt count )
{
	WriteToken( TOKEN_FLOAT_LIST );
	WriteDword( count );
}

void XMeshBinaryWriter::WriteColorRGBA( Float r, Float g, Float b, Float a )
{
	WriteFloat( r );
	WriteFloat( g );
	WriteFloat( b );
	WriteFloat( a );
}

void XMeshBinaryWriter::WriteColorRGB( Float r, Float g, Float b )
{
	WriteFloat( r );
	WriteFloat( g );
	WriteFloat( b );
}

void XMeshBinaryWriter::WritePower( Float power )
{
	WriteFloat( power );
}

void XMeshBinaryWriter::WriteToken( UShort token )
{
	_stream->Write( &token, sizeof(UShort) );
}

void XMeshBinaryWriter::WriteDword( UInt value )
{
	_stream->Write( &value, sizeof(UInt) );
}

void XMeshBinaryWriter::WriteFloat( Float value )
{
	_stream->Write( &value, sizeof(Float) );
}


} // scene


} // synkro
