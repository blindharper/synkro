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
// Purpose: Obj mesh writer.
//==============================================================================
#include "config.h"
#include "ObjWriter.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ObjWriter::ObjWriter( IStream* stream ) :
	ObjStreamWriter( stream )
{
}

void ObjWriter::WriteMaterialLibrary( const String& name )
{
	WriteString( String::Format(L"mtllib {0}", name) );
	WriteCRLF();
}

void ObjWriter::WriteMaterial( const String& name )
{
	WriteString( String::Format(L"usemtl {0}", name) );
	WriteCRLF();
}

void ObjWriter::WriteSubset( const String& name )
{
	WriteChar( 'g' );
	WriteChar( ' ' );
	WriteString( name );
	WriteCRLF();
}

void ObjWriter::WriteTexCoords( const Vector<Vector2>& array )
{
	if ( array.IsEmpty() )
		return;

	WriteComment( String::Format(L"{0} texture coordinates", array.Size()) );
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Vector2& vec = array[i];
		WriteChar( 'v' );
		WriteChar( 't' );
		WriteChar( ' ' );
		WriteFloat( vec.x );
		WriteChar( ' ' );
		WriteFloat( 1.0f-vec.y );
		WriteCRLF();
	}
}

void ObjWriter::WritePositions( const Vector<Vector3>& array )
{
	WriteComment( String::Format(L"{0} vertices", array.Size()) );
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Vector3& vec = array[i];
		WriteChar( 'v' );
		WriteChar( ' ' );
		WriteFloat( vec.x );
		WriteChar( ' ' );
		WriteFloat( vec.y );
		WriteChar( ' ' );
		WriteFloat( vec.z );
		WriteCRLF();
	}
}

void ObjWriter::WriteNormals( const Vector<Vector3>& array )
{
	if ( array.IsEmpty() )
		return;

	WriteComment( String::Format(L"{0} normals", array.Size()) );
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Vector3& vec = array[i];
		WriteChar( 'v' );
		WriteChar( 'n' );
		WriteChar( ' ' );
		WriteFloat( vec.x );
		WriteChar( ' ' );
		WriteFloat( vec.y );
		WriteChar( ' ' );
		WriteFloat( vec.z );
		WriteCRLF();
	}
}

void ObjWriter::WriteFaces( const Vector<Face>& array )
{
	WriteComment( String::Format(L"{0} faces", array.Size()) );
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Face& face = array[i];
		WriteChar( 'f' );
		WriteChar( ' ' );
		WriteUInt( face.IdxPos );
		if ( (face.IdxTex != none) && (face.IdxNorm != none) )
		{
			WriteChar( '/' );
			WriteUInt( face.IdxTex );
			WriteChar( '/' );
			WriteUInt( face.IdxNorm );
		}
		else if ( (face.IdxTex != none) )
		{
			WriteChar( '/' );
			WriteUInt( face.IdxTex );
		}
		else if ( (face.IdxNorm != none) )
		{
			WriteChar( '/' );
			WriteChar( '/' );
			WriteUInt( face.IdxNorm );
		}
		WriteCRLF();
	}
}


} // scene


} // synkro
