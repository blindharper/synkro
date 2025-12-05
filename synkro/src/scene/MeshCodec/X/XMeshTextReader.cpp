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
// Purpose: Text DirectX mesh reader.
//==============================================================================
#include "config.h"
#include "XMeshTextReader.h"


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


XMeshTextReader::XMeshTextReader() :
	_lexem( A(char) )
{
}

void XMeshTextReader::Initialize( IStream* stream )
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
	_char = 0;
}

UShort XMeshTextReader::PeekToken()
{
	return TOKEN_NONE;
}

UShort XMeshTextReader::GetToken()
{
	return TOKEN_NONE;
}

char XMeshTextReader::ReadChar()
{
	char ch = 0;
	if ( _char != 0 )
	{
		ch = _char;
		_char = 0;
		return ch;
	}
	
	if ( _stream->Read(&ch, 1) == 1 )
		return ch;
	else
		return 0;
}

void XMeshTextReader::ReadTemplateDefinition()
{
	// Do nothing.
}

Byte XMeshTextReader::ReadTemplateName()
{
	return 0xff;
}

String XMeshTextReader::ReadName()
{
	return L"";
}

void XMeshTextReader::ReadAnimationKey( Bool load )
{
	Vector<Byte> buf( A(Byte) );
	Vector<Byte>* data = &buf;

	if ( load )
	{
		AnimationDesc* animation = _animationSets.Last()->Animations.Last();
		animation->Tracks.Add( AnimationTrackDesc() );
		data = &animation->Tracks.Last()->Data;
	}

	Put( *data, ReadDword() );
	const UInt nKeys = ReadDword();
	Put( *data, nKeys );
	UInt nValues = 0; Float f = 0.0f;
	for ( UInt i = 0; i < nKeys; ++i )
	{
		Put( *data, ReadDword() );
		nValues = ReadDword();
		Put( *data, nValues );
		for ( UInt j = 0; j < nValues; ++j )
		{
			f = ReadFloat();
			Put( *data, f );
		}
		ReadChar();
		ReadChar();
	}
	ReadChar();

	// Read closing '}'.
	PeekChar();
	ReadChar();

	PeekChar();
	String name = ReadReference();
	if ( load )
	{
		_animationSets.Last()->Animations.Last()->Name = name;
	}
}

void XMeshTextReader::ReadFrame( const String& name )
{
	UInt parentIndex = none;
	if ( _frameStack.Size() > 0 )
	{
		parentIndex = _frameStack.Top();
	}
	UInt frameIndex = _frames.Size();
	FrameDesc desc( parentIndex, name, frameIndex );
	_frameIndices[name] = frameIndex;
	_frames.Add( desc );
	_frameStack.Push( frameIndex );
}

void XMeshTextReader::PopFrame()
{
	_frameStack.Pop();
}

void XMeshTextReader::ReadFrameTransformMatrix()
{
	if ( _frameStack.Size() > 0 )
	{
		FrameDesc* frame = &_frames[_frameStack.Top()];
		Vector<Float> mat( A(Float), 16 );
		ReadArray( mat, 16 );
		frame->Transform = Matrix4x4( mat.Begin() );
	}
}

void XMeshTextReader::ReadMesh( const String& name )
{
	_models.Add( ModelDesc((_frameStack.Size() > 0) ? _frameStack.Top() : none, name) );

	const UInt nVertices = ReadDword();
	ReadArray( _models.Last()->Positions, nVertices );
	const UInt nFaces = ReadDword();
	_models.Last()->Faces.Add( nFaces );
	ReadFaces( _models.Last()->Faces, nFaces );
}

void XMeshTextReader::ReadMeshNormals()
{
	const UInt nNormals = ReadDword();
	ReadArray( _models.Last()->Normals, nNormals );
	const UInt nFaceNormals = ReadDword();
	ReadFaces( _models.Last()->FaceNormals, nFaceNormals );
}

void XMeshTextReader::ReadMeshTextureCoords()
{
	const UInt nTextureCoords = ReadDword();
	ReadArray( _models.Last()->TexCoords, nTextureCoords );
}

void XMeshTextReader::ReadMeshMaterialList()
{
	UInt start = 0; UInt count = 0;
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

	if ( PeekChar() == '{' )
	{
		for ( UInt i = 0; i < nMaterials; ++i )
		{
			PeekChar();
			String name = ReadReference();
			if ( i < _models.Last()->Subsets.Size() )
			{
				_subMaterials.Add( SubMaterialDesc(name) );
			}
		}
	}
}

void XMeshTextReader::ReadMaterial( const String& name, Bool load )
{
	Vector<Float> data( A(Float) );
	Vector<Float>* colors = &data;

	if ( load )
	{
		_lastMaterialName = name;
		if ( !_models.IsEmpty() )
		{
			if ( _models.Last()->Materials.Size() < _models.Last()->Subsets.Size() )
			{
				_models.Last()->Materials.Add( MaterialDesc() );
				_subMaterials.Add( SubMaterialDesc(_models.Size()-1, _models.Last()->Materials.Size()-1) );
				colors = &_models.Last()->Materials.Last()->Colors;
			}
		}
		else
		{
			_materials[name] = MaterialDesc();
			colors = &_materials[name].Colors;
		}
	}

	ReadArray( *colors, 11 );
	ReadChar();
}

void XMeshTextReader::ReadTextureFilename( Bool load )
{
	String filename = ReadString();
	if ( load )
	{
		if ( !_lastMaterialName.IsEmpty() )
			_materials[_lastMaterialName].Texture = filename;
		else
			_models.Last()->Materials.Last()->Texture = filename;
	}
}

void XMeshTextReader::ReadMeshSkinHeader( Bool load )
{
	const UInt dw = ReadDword();
	ReadDword();
	ReadDword();

	if ( load )
	{
		_models.Last()->BonesPerVertex = dw;
	}
}

void XMeshTextReader::ReadSkinWeights( Bool load )
{
	Vector<UInt> indices( A(UInt) );
	Vector<Float> weights( A(Float) );
	Vector<Float> offset( A(Float) );

	Vector<UInt>* boneIndices = &indices;
	Vector<Float>* boneWeights = &weights;
	Vector<Float>* boneOffset = &offset;

	String name = ReadString();
	const UInt nWeights = ReadDword();
	if ( load )
	{
		_models.Last()->Bones.Add( BoneDesc() );
		BoneDesc* bone = _models.Last()->Bones.Last();
		bone->Name = name;
		boneIndices = &bone->Indices;
		boneWeights = &bone->Weights;
		boneOffset = &bone->Offset;
	}

	ReadArray( *boneIndices, nWeights );
	ReadArray( *boneWeights, nWeights );
	ReadArray( *boneOffset, 16 );
	ReadChar();
}

void XMeshTextReader::ReadUnknown()
{
	char ch = 0;
	while ( (_stream->Read(&ch, 1) == 1) )
	{
		if ( ch == '}' )
			break;
	}
}

void XMeshTextReader::Put( Vector<Byte>& data, UInt value )
{
	data.Add( (const Byte*)&value, sizeof(UInt) );
}

void XMeshTextReader::Put( Vector<Byte>& data, Float value )
{
	data.Add( (const Byte*)&value, sizeof(Float) );
}

char XMeshTextReader::PeekChar()
{
	if ( _char != 0 )
		return _char;
	
	char ch = 0;
	Bool exit = false;
	while ( !exit && (_stream->Read(&ch, 1) == 1) )
	{
		switch ( ch )
		{
			case '\r': case '\n': case '\t': case ' ':
				break;

			default:
				exit = true;
				break;
		}
	}

	return _char = ch;
}

Float XMeshTextReader::ReadFloat()
{
	Float f = 0;
	char ch = 0;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (_stream->Read(&ch, 1) == 1) )
	{
		switch ( ch )
		{
			case '\r': case '\n': case ' ':
				break;

			case ';': case ',':
				if ( !_lexem.IsEmpty() )
				{
					_lexem.Add( 0 );
					sscanf( _lexem.Begin(), "%f", &f );
					exit = true;
				}
				break;

			default:
				_lexem.Add( ch );
				break;
		}
	}
	return f;
}

UInt XMeshTextReader::ReadDword()
{
	UInt dw = 0;	
	char ch = 0;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (_stream->Read(&ch, 1) == 1) )
	{
		switch ( ch )
		{
			case '\r': case '\n': case ' ':
				break;

			case ';': case ',':
				_lexem.Add( 0 );
				sscanf( _lexem.Begin(), "%d", &dw );
				exit = true;
				break;

			default:
				_lexem.Add( ch );
				break;
		}
	}
	return dw;
}

String XMeshTextReader::ReadReference()
{
	char ch = 0; String str;
	Bool exit = false;
	ReadChar();
	_lexem.Clear();
	while ( !exit && (_stream->Read(&ch, 1) == 1) )
	{
		switch ( ch )
		{
			case ' ':
				break;

			case '}':
				_lexem.Add( 0 );
				str = String( _lexem.Begin() );
				exit = true;
				break;

			default:
				_lexem.Add( ch );
				break;
		}
	}
	return str;
}

String XMeshTextReader::ReadString()
{
	char ch = 0;
	String str;
	Bool inside = false;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (_stream->Read(&ch, 1) == 1) )
	{
		switch ( ch )
		{
			case '\r': case '\n': case ' ':
				break;

			case '"':
				if ( inside )
				{
					_lexem.Add( 0 );
					str = String( _lexem.Begin() );
					ReadChar();
					exit = true;
				}
				else
				{
					inside = true;
				}
				break;

			default:
				if ( inside )
				{
					_lexem.Add( ch );
				}
				break;
		}
	}
	return str;
}

void XMeshTextReader::ReadFaces( Vector<UInt>& array, UInt count )
{
	UInt dw = 0;
	for ( UInt i = 0; i < count; ++i )
	{
		dw = ReadDword();
		array.Add( dw );
		for ( UInt j = 0; j < dw; ++j )
		{
			const UInt f = ReadDword();
			array.Add( f );
		}
		ReadChar();
	}
}

void XMeshTextReader::ReadArray( Vector<UInt>& array, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const UInt dw = ReadDword();
		array.Add( dw );
	}
}

void XMeshTextReader::ReadArray( Vector<Float>& array, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float f = ReadFloat();
		array.Add( f );
	}
}

void XMeshTextReader::ReadArray( Vector<Vector2>& array, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float x = ReadFloat();
		const Float y = ReadFloat();
		ReadChar();
		array.Add( Vector2(x, y) );
	}
}

void XMeshTextReader::ReadArray( Vector<Vector3>& array, UInt count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float x = ReadFloat();
		const Float y = ReadFloat();
		const Float z = ReadFloat();
		ReadChar();
		array.Add( Vector3(x, y, z) );
	}
}


} // scene


} // synkro
