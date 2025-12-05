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
// Purpose: Binary DirectX mesh reader.
//==============================================================================
#include "config.h"
#include "XMeshBinaryReader.h"


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


XMeshBinaryReader::XMeshBinaryReader() :
	_token( 0 )
{
}

void XMeshBinaryReader::Initialize( IStream* stream )
{
	_stream = stream;
	_materials.Clear();
	_subMaterials.Clear();
	_models.Clear();
	_animationSets.Clear();
	_frameStack.Clear();
	_frames.Clear();
	_frameIndices.Clear();
	_lastMaterialName = String::Empty;
	_token = 0;
}

UShort XMeshBinaryReader::PeekToken()
{
	return (_token != 0) ? _token : _token = GetToken();
}

UShort XMeshBinaryReader::GetToken()
{
	UShort token = 0;
	if ( _token != 0 )
	{
		token = _token;
		_token = 0;
		return token;
	}

	constexpr UInt size = sizeof( UShort );
	const UInt count = _stream->Read( &token, size );
	return (count == size) ? token : TOKEN_NONE;
}

void XMeshBinaryReader::ReadTemplateDefinition()
{
	UInt dw = 0;
	UShort token = GetToken();
	const UInt count = ReadDword();
	Skip( count );
	token = GetToken();
	token = GetToken();
	Skip( 16 );

	while ( (token = GetToken()) != TOKEN_CBRACE )
	{
		switch ( token )
		{
			case TOKEN_NAME:
				dw = ReadDword();
				Skip( dw );
				break;

			default:
				break;
		}
	}
}

Byte XMeshBinaryReader::ReadTemplateName()
{
	String str = ReadName();
	return _templates.ContainsKey(str) ? _templates[str] : (Byte)-1;
}

String XMeshBinaryReader::ReadName()
{
	const UInt count = ReadDword();
	Vector<char> name( A(char) );
	name.SetSize( count+1 );
	_stream->Read( name.Begin(), count );
	name[name.Size()-1] = 0;
	return name.Begin();
}

void XMeshBinaryReader::ReadMesh( const String& name )
{
	_models.Add( ModelDesc((_frameStack.Size() > 0) ? _frameStack.Top() : none, name) );

	UShort token = GetToken();
	token = GetToken();
	ReadDword();
	const UInt nVertices = ReadDword();
	token = GetToken();
	ReadDword();
	ReadArray( _models.Last()->Positions, nVertices );
	token = GetToken();
	const UInt nFaces = ReadDword();
	ReadArray( _models.Last()->Faces, nFaces );
}

void XMeshBinaryReader::ReadMeshNormals()
{
	UShort token = GetToken();
	token = GetToken();
	ReadDword();
	const UInt nNormals = ReadDword();
	token = GetToken();
	ReadDword();
	ReadArray( _models.Last()->Normals, nNormals );
	token = GetToken();
	const UInt nFaceNormals = ReadDword();
	ReadArray( _models.Last()->FaceNormals, nFaceNormals );
}

void XMeshBinaryReader::ReadMeshTextureCoords()
{
	UShort token = GetToken();
	token = GetToken();
	ReadDword();
	const UInt nTextureCoords = ReadDword();
	token = GetToken();
	ReadDword();
	ReadArray( _models.Last()->TexCoords, nTextureCoords );
}

void XMeshBinaryReader::ReadMeshMaterialList()
{
	UInt start = 0; UInt count = 0;
	UShort token = GetToken();
	token = GetToken();
	ReadDword();
	const UInt nMaterials = ReadDword();
	const UInt nFaceIndexes = ReadDword();
	if ( nFaceIndexes > 1 )
	{
		UInt oldIdx = 0;
		for ( UInt i = 0; i < nFaceIndexes; ++i )
		{
			const UInt idx = ReadDword();
			if ( idx == oldIdx )
			{
				++count;
			}
			else
			{
				_models.Last()->Subsets.Add( Range(3*start, 3*count) );
				start = i;
				count = 1;
			}
			oldIdx = idx;
		}
	}
	else if ( nFaceIndexes == 1 )
	{
		ReadDword();
	}
	_models.Last()->Subsets.Add( Range(3*start, 3*count) );

	token = PeekToken();
	if ( token == TOKEN_OBRACE )
	{
		for ( UInt i = 0; i < nMaterials; ++i )
		{
			String name = ReadReference();
			if ( i < _models.Last()->Subsets.Size() )
			{
				_subMaterials.Add( SubMaterialDesc(name) );
			}
		}
	}
}

void XMeshBinaryReader::ReadMaterial( const String& name, Bool load )
{
	_lastMaterialName = name;
	UShort token = GetToken();
	token = GetToken();
	const UInt nCount = ReadDword();
	
	Vector<Float>* colors = nullptr;
	if ( !_models.IsEmpty() )
	{
		if ( _models.Last()->Materials.Size() < _models.Last()->Subsets.Size() )
		{
			_models.Last()->Materials.Add( MaterialDesc() );
			_subMaterials.Add( SubMaterialDesc(_models.Size()-1, _models.Last()->Materials.Size()-1) );
			colors = &_models.Last()->Materials.Last()->Colors;
		}
		else
		{
			Skip( nCount*sizeof(Float) );
		}
	}
	else
	{
		_materials[name] = MaterialDesc();
		colors = &_materials[name].Colors;
	}

	if ( colors != nullptr )
	{
		ReadArray( *colors, nCount );
	}
}

void XMeshBinaryReader::ReadTextureFilename( Bool load )
{
	UShort token = GetToken();
	token = GetToken();
	String filename = ReadString();

	if ( !_lastMaterialName.IsEmpty() )
		_materials[_lastMaterialName].Texture = filename;
	else
		_models.Last()->Materials.Last()->Texture = filename;
}

void XMeshBinaryReader::ReadUnknown()
{
	UShort token = TOKEN_NONE;
	while ( (token = GetToken()) != TOKEN_CBRACE )
	{
		switch ( token )
		{
			case TOKEN_NAME:
				ReadName();
				break;

			case TOKEN_INTEGER_LIST:
				ReadIntegerList();
				break;

			case TOKEN_FLOAT_LIST:
				ReadFloatList();
				break;

			default:
				break;
		}
	}
}

void XMeshBinaryReader::Skip( UInt count )
{
	_stream->Seek( CastInt(count), SeekOrigin::Current );
}

UInt XMeshBinaryReader::ReadDword()
{
	UInt dw = 0;
	_stream->Read( &dw, sizeof(UInt) );
	return dw;
}

void XMeshBinaryReader::ReadIntegerList()
{
	const UInt nCount = ReadDword();
	for ( UInt i = 0; i < nCount; ++i )
	{
		ReadDword();
	}
}

void XMeshBinaryReader::ReadFloatList()
{
	const UInt nCount = ReadDword();
	for ( UInt i = 0; i < nCount; ++i )
	{
		ReadFloat();
	}
}

Float XMeshBinaryReader::ReadFloat()
{
	Float f = 0.0f;
	_stream->Read( &f, sizeof(Float) );
	return f;
}

void XMeshBinaryReader::ReadArray( Vector<UInt>& array, UInt count )
{
	array.SetSize( count );
	_stream->Read( array.Begin(), count*sizeof(UInt) );
}

void XMeshBinaryReader::ReadArray( Vector<Float>& array, UInt count )
{
	array.SetSize( count );
	_stream->Read( array.Begin(), count*sizeof(Float) );
}

void XMeshBinaryReader::ReadArray( Vector<Vector2>& array, UInt count )
{
	array.SetSize( count );
	_stream->Read( array.Begin(), count*sizeof(Vector2) );
}

void XMeshBinaryReader::ReadArray( Vector<Vector3>& array, UInt count )
{
	array.SetSize( count );
	_stream->Read( array.Begin(), count*sizeof(Vector3) );
}

String XMeshBinaryReader::ReadReference()
{
	GetToken();
	GetToken();
	String ref = ReadName();
	GetToken();
	return ref;
}

String XMeshBinaryReader::ReadString()
{
	String str = ReadName();
	GetToken();
	return str;
}


} // scene


} // synkro
