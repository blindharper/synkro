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
// Purpose: Implements DirectX mesh codec.
//==============================================================================
#include "config.h"
#include "XMeshCodec.h"
#include <scene/BoneProperty.h>
#include <scene/ISkeleton.h>
#include <io/BinaryReader.h>
#include <io/IStreamDirectory.h>
#include <img/IImage.h>
#include <img/IImageManager.h>
#include <core/CallStack.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::io;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


#define XOFFILE_FORMAT_MAGIC ((long)'x' + ((long)'o' << 8) + ((long)'f' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_VERSION ((long)'0' + ((long)'3' << 8) + ((long)'0' << 16) + ((long)'3' << 24))
#define XOFFILE_FORMAT_BINARY ((long)'b' + ((long)'i' << 8) + ((long)'n' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_TEXT ((long)'t' + ((long)'x' << 8) + ((long)'t' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_COMPRESSED ((long)'c' + ((long)'m' << 8) + ((long)'p' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_FLOAT_BITS_32 ((long)'0' + ((long)'0' << 8) + ((long)'3' << 16) + ((long)'2' << 24))
#define XOFFILE_FORMAT_FLOAT_BITS_64 ((long)'0' + ((long)'0' << 8) + ((long)'6' << 16) + ((long)'4' << 24))

#define TOKEN_NONE         0xffff
#define TOKEN_NAME         1
#define TOKEN_STRING       2
#define TOKEN_INTEGER      3
#define TOKEN_GUID         5
#define TOKEN_INTEGER_LIST 6
#define TOKEN_FLOAT_LIST   7
#define TOKEN_OBRACE      10
#define TOKEN_CBRACE      11
#define TOKEN_OPAREN      12
#define TOKEN_CPAREN      13
#define TOKEN_OBRACKET    14
#define TOKEN_CBRACKET    15
#define TOKEN_OANGLE      16
#define TOKEN_CANGLE      17
#define TOKEN_DOT         18
#define TOKEN_COMMA       19
#define TOKEN_SEMICOLON   20
#define TOKEN_TEMPLATE    31
#define TOKEN_WORD        40
#define TOKEN_DWORD       41
#define TOKEN_FLOAT       42
#define TOKEN_DOUBLE      43
#define TOKEN_CHAR        44
#define TOKEN_UCHAR       45
#define TOKEN_SWORD       46
#define TOKEN_SDWORD      47
#define TOKEN_VOID        48
#define TOKEN_LPSTR       49
#define TOKEN_UNICODE     50
#define TOKEN_CSTRING     51
#define TOKEN_ARRAY       52


// DirectX mesh file header.
struct XMeshHeader
{
	DWORD	dwMagic;
	DWORD	dwVersion;
	DWORD	dwFormatType;
	DWORD	dwFloatSize;
};


namespace synkro
{


namespace scene
{


XMeshCodec::XMeshCodec( ISceneManager* sceneManager, IMaterialManager* materialManager, IImageManager* imageManager, IAnimationSystem* animationSystem ) :
	MeshCodecImpl<IMeshCodec>( sceneManager, materialManager, imageManager, animationSystem ),
	_materials( A(MaterialEntry) ),
	_subMaterials( A(SubMaterialDesc) ),
	_models( A(ModelDesc) ),
	_animationSets( A(AnimationSetDesc) ),
	_frames( A(FrameDesc) ),
	_frameStack( A(UInt) ),
	_templates( A(IndexEntry) ),
	_templates2( A(IndexEntry2) ),
	_frameIndices( A(IndexEntry) ),
	_materialCache( A(MaterialCacheEntry) ),
	_animationCache( A(AnimationCacheEntry) ),
	_buffer( A(Byte) ),
	_lexem( A(char) )
{
	RegisterTemplates();
}

ITriangleMesh* XMeshCodec::Load( IScene* scene, IStream* stream, const PixelFormat& format, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	SynkroCall( "XMeshCodec::Load", stream->GetName() );

	SynkroProfile( "XMeshCodec.Load" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Load( scene, stream, format, material, skeleton, instanceCapacity );

	// Initialize data structures.
	_materials.Clear();
	_subMaterials.Clear();
	_models.Clear();
	_animationSets.Clear();
	_frameStack.Clear();
	_frames.Clear();
	_frameIndices.Clear();
	_lastMaterialName = String::Empty;
	_indent = 0;
	_token = 0;
	_char = 0;

	// Load data into internal data structures.
	const Bool loadMaterial = (material == nullptr) && !_materialCache.ContainsKey( stream->ID() );
	Bool loadSkin = (skeleton != nullptr);
	const Bool loadAnimations = (skeleton != nullptr) && (skeleton->GetAnimationSetCount() == 0);
	const DWORD fmt = Read( stream );
	switch ( fmt )
	{
		case XOFFILE_FORMAT_BINARY:
			ReadBinary( stream, loadMaterial, loadSkin, loadAnimations );
			break;

		case XOFFILE_FORMAT_TEXT:
			ReadText( stream, loadMaterial, loadSkin, loadAnimations );
			break;

		default:
			throw Exception( L"Unsupported mesh format." );
	}

	// Nullify skeleton, if no bones found.
	loadSkin = (skeleton != nullptr) && (skeleton->GetBoneCount() == 0);
	if ( loadSkin && (_models.IsEmpty() || (_models.Last()->BonesPerVertex == 0)) )
	{
		skeleton = nullptr;
	}

	// Create right type of mesh.
	ITriangleMesh* mesh = nullptr;
	const Bool soft = (scene == nullptr);
	if ( soft )
	{
		mesh = _sceneManager->CreateTriangleMesh( skeleton, _subMaterials.Size() );
		if ( _subMaterials.Size() == 1 )
		{
			_subMaterials[0].Material = mesh->GetMaterial()->AsSimple()->AsOpaque();
		}
		else
		{
			IMultiMaterial* material = mesh->GetMaterial()->AsMulti();
			for ( UInt i = 0; i < _subMaterials.Size(); ++i )
			{
				_subMaterials[i].Material = material->GetSubset( i )->AsOpaque();
			}
		}
	}

	// Choose material.
	material = ChooseMaterial( stream, material, format, !soft );

	// Create skeleton and animation, if we have a skeleton.
	if ( skeleton != nullptr )
	{
		PrepareSkeleton( skeleton );
		PrepareAnimation( stream, skeleton );
	}

	// Create mesh.
	if ( !soft )
	{
		if ( instanceCapacity > 0 )
			mesh = (ITriangleMesh*)scene->CreateTriangleMeshBatch( material, skeleton, instanceCapacity );
		else
			mesh = scene->CreateTriangleMesh( nullptr, stream->GetName(), material, skeleton );
	}
	PrepareMesh( mesh );

	// Set skeleton bones weights.
	if ( skeleton != nullptr )
	{
		PrepareSkin( mesh );
	}

	return mesh;
}

ISkeleton* XMeshCodec::Load( IStream* stream )
{
	SynkroProfile( "XMeshCodec.Load" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Load( stream );

	// Initialize data structures.
	_materials.Clear();
	_subMaterials.Clear();
	_models.Clear();
	_animationSets.Clear();
	_frameStack.Clear();
	_frames.Clear();
	_frameIndices.Clear();
	_lastMaterialName = String::Empty;
	_indent = 0;
	_token = 0;
	_char = 0;

	// TODO:
	return nullptr;
}

void XMeshCodec::Save( const ITriangleMesh* mesh, IStream* stream, const DataMode& mode )
{
	SynkroProfile( "XMeshCodec.Save" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Save( mesh, stream, mode );

	// Initialize data structures.
	_materials.Clear();
	_subMaterials.Clear();
	_models.Clear();
	_animationSets.Clear();
	_frameStack.Clear();
	_frames.Clear();
	_frameIndices.Clear();

	Write( stream, mode );
	ModelDesc desc( mesh );
	if ( mode == DataMode::Binary )
	{
		WriteMeshBinary( stream, desc );
	}
	else if ( mode == DataMode::Text )
	{
		WriteMeshText( stream, desc );
	}
}

void XMeshCodec::Save( const ISkeleton* skeleton, IStream* stream, const DataMode& mode )
{
	SynkroProfile( "XMeshCodec.Save" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Save( skeleton, stream, mode );

	Write( stream, mode );

	// TODO:
}

void XMeshCodec::RegisterTemplates()
{
	RegisterTemplate( TEMPLATE_ANIMATION, L"Animation" );
	RegisterTemplate( TEMPLATE_ANIMATION_KEY, L"AnimationKey" );
	RegisterTemplate( TEMPLATE_ANIMATION_SET, L"AnimationSet" );
	RegisterTemplate( TEMPLATE_COLOR_RGB, L"ColorRGB" );
	RegisterTemplate( TEMPLATE_COLOR_RGBA, L"ColorRGBA" );
	RegisterTemplate( TEMPLATE_FRAME, L"Frame" );
	RegisterTemplate( TEMPLATE_FRAME_TRANSFORM_MATRIX, L"FrameTransformMatrix" );
	RegisterTemplate( TEMPLATE_MATERIAL, L"Material" );
	RegisterTemplate( TEMPLATE_MATRIX4X4, L"Matrix4x4" );
	RegisterTemplate( TEMPLATE_MESH, L"Mesh" );
	RegisterTemplate( TEMPLATE_MESH_FACE, L"MeshFace" );
	RegisterTemplate( TEMPLATE_MESH_MATERIAL_LIST, L"MeshMaterialList" );
	RegisterTemplate( TEMPLATE_MESH_NORMALS, L"MeshNormals" );
	RegisterTemplate( TEMPLATE_MESH_TEXTURE_COORDS, L"MeshTextureCoords" );
	RegisterTemplate( TEMPLATE_SKIN_WEIGHTS, L"SkinWeights" );
	RegisterTemplate( TEMPLATE_TEXTURE_FILENAME, L"TextureFilename" );
	RegisterTemplate( TEMPLATE_TIMED_FLOAT_KEYS, L"TimedFloatKeys" );
	RegisterTemplate( TEMPLATE_VECTOR, L"Vector" );
	RegisterTemplate( TEMPLATE_XSKIN_MESH_HEADER, L"XSkinMeshHeader" );
}

void XMeshCodec::RegisterTemplate( Byte type, const String& name )
{
	_templates[name] = type;
	_templates2[type] = name;
}

void XMeshCodec::Put( Vector<Byte>& data, DWORD value )
{
	data.Add( (const Byte*)&value, sizeof(DWORD) );
}

void XMeshCodec::Put( Vector<Byte>& data, Float value )
{
	data.Add( (const Byte*)&value, sizeof(Float) );
}

DWORD XMeshCodec::Read( IStream* stream )
{
	XMeshHeader hdr;
	const UInt count = stream->Read( &hdr, sizeof(hdr) );
	if ( count != sizeof(hdr) )
		throw Exception( L"X mesh file header is too short." );

	if ( hdr.dwMagic != XOFFILE_FORMAT_MAGIC )
		throw Exception( L"Bad X mesh file." );

	return hdr.dwFormatType;
}

void XMeshCodec::ReadBinary( IStream* stream, Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	Byte tmpl = 0xff; WORD token = TOKEN_NONE; String name;
	while ( (token = GetToken(stream)) != TOKEN_NONE )
	{
		switch ( token )
		{
			case TOKEN_TEMPLATE:
				ReadTemplateDefinitionBinary( stream );
				break;

			case TOKEN_NAME:
				tmpl = ReadTemplateName( stream );
				token = PeekToken( stream );
				if ( token == TOKEN_NAME )
				{
					GetToken( stream );
					name = ReadNameBinary( stream );
				}
				else
				{
					name = String::Empty;
				}
				ReadTemplateBinary( stream, tmpl, name, loadMaterial, loadSkin, loadAnimations );
				break;

			default:
				break;
		}
	}
}

void XMeshCodec::ReadText( IStream* stream, Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	String str; Byte temp = 0;
	char ch = 0; char old = 0; Byte tmpl = 0xff;
	String name; Bool comment = false;
	Stack<Byte> templates( A(Byte) );
	_lexem.Clear();
	while ( (ch = ReadChar(stream)) != 0 )
	{
		if ( comment )
		{
			if ( (ch == '\r') || (ch == '\n') )
			{
				comment = false;
			}
			continue;
		}

		switch ( ch )
		{
			case '\t': case '\r': case '\n':
				break;

			case ' ':
				if ( _lexem.IsEmpty() )
					continue;

				_lexem.Add( 0 );
				str = String( _lexem.Begin() );
				_lexem.Clear();
				if ( _templates.ContainsKey(str) )
				{
					tmpl = _templates[str];
				}
				else if ( !_strcmpi(_lexem.Begin(), "template") )
				{
					ReadUnknownText( stream );
					_lexem.Clear();
					name = String::Empty;
					tmpl = 0xff;
				}
				else
				{
					name = str;
				}
				break;

			case '/':
				if ( old == '/' )
				{
					comment = true;
				}
				break;

			case '{':
				if ( tmpl != 0xff )
				{
					ReadTemplateText( stream, tmpl, name, loadMaterial, loadSkin, loadAnimations );
					if ( tmpl != TEMPLATE_ANIMATION_KEY )
					{
						templates.Push( tmpl );
					}
				}
				else
				{
					ReadUnknownText( stream );
				}
				_lexem.Clear();
				name = String::Empty;
				tmpl = 0xff;
				break;

			case '}':
				temp = templates.Top();
				templates.Pop();
				if ( temp == TEMPLATE_FRAME )
				{
					_frameStack.Pop();
				}
				break;

			default:
				if ( ch != ';' )
				{
					_lexem.Add( ch );
				}
				break;
		}
		old = ch;
	}
}

WORD XMeshCodec::PeekToken( IStream* stream )
{
	return (_token != 0) ? _token : _token = GetToken( stream );
}

char XMeshCodec::PeekChar( IStream* stream )
{
	if (_char != 0)
		return _char;
	
	char ch = 0;
	Bool exit = false;
	while ( !exit && (stream->Read(&ch, 1) == 1) )
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

WORD XMeshCodec::GetToken( IStream* stream )
{
	WORD token = 0;
	if ( _token != 0 )
	{
		token = _token;
		_token = 0;
		return token;
	}

	const UInt size = sizeof( WORD );
	const UInt count = stream->Read( &token, size );
	return (count == size) ? token : TOKEN_NONE;
}

void XMeshCodec::Skip( IStream* stream, DWORD count )
{
	stream->Seek( CastInt(count), SeekOrigin::Current );
}

char XMeshCodec::ReadChar( IStream* stream )
{
	char ch = 0;
	if ( _char != 0 )
	{
		ch = _char;
		_char = 0;
		return ch;
	}
	
	if ( stream->Read(&ch, 1) == 1 )
		return ch;
	else
		return 0;
}

DWORD XMeshCodec::ReadDwordBinary( IStream* stream )
{
	DWORD dw = 0;
	stream->Read( &dw, sizeof(DWORD) );
	return dw;
}

DWORD XMeshCodec::ReadDwordText( IStream* stream )
{
	DWORD dw = 0;	
	char ch = 0;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (stream->Read(&ch, 1) == 1) )
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

Float XMeshCodec::ReadFloatBinary( IStream* stream )
{
	Float f = 0.0f;
	stream->Read( &f, sizeof(Float) );
	return f;
}

Float XMeshCodec::ReadFloatText( IStream* stream )
{
	FLOAT f = 0;
	char ch = 0;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (stream->Read(&ch, 1) == 1) )
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

String XMeshCodec::ReadNameBinary( IStream* stream )
{
	const DWORD count = ReadDwordBinary( stream );
	Vector<char> name( A(char) );
	name.SetSize( count+1 );
	stream->Read( name.Begin(), count );
	name[name.Size()-1] = 0;
	return name.Begin();
}

void XMeshCodec::ReadArrayBinary( IStream* stream, Vector<DWORD>& array, DWORD count )
{
	array.SetSize( count );
	stream->Read( array.Begin(), count*sizeof(DWORD) );
}

void XMeshCodec::ReadArrayText( IStream* stream, Vector<DWORD>& array, DWORD count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const DWORD dw = ReadDwordText( stream );
		array.Add( dw );
	}
}

void XMeshCodec::ReadFacesText( IStream* stream, Vector<DWORD>& array, DWORD count )
{
	DWORD dw = 0;
	for ( UInt i = 0; i < count; ++i )
	{
		dw = ReadDwordText( stream );
		array.Add( dw );
		for ( UInt j = 0; j < dw; ++j )
		{
			const DWORD f = ReadDwordText( stream );
			array.Add( f );
		}
		ReadChar( stream );
	}
}

void XMeshCodec::ReadArrayBinary( IStream* stream, Vector<Float>& array, DWORD count )
{
	array.SetSize( count );
	stream->Read( array.Begin(), count*sizeof(Float) );
}

void XMeshCodec::ReadArrayText( IStream* stream, Vector<Float>& array, DWORD count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float f = ReadFloatText( stream );
		array.Add( f );
	}
}

void XMeshCodec::ReadArrayBinary( IStream* stream, Vector<Vector2>& array, DWORD count )
{
	array.SetSize( count );
	stream->Read( array.Begin(), count*sizeof(Vector2) );
}

void XMeshCodec::ReadArrayText( IStream* stream, Vector<Vector2>& array, DWORD count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float x = ReadFloatText( stream );
		const Float y = ReadFloatText( stream );
		ReadChar( stream );
		array.Add( Vector2(x, y) );
	}
}

void XMeshCodec::ReadArrayBinary( IStream* stream, Vector<Vector3>& array, DWORD count )
{
	array.SetSize( count );
	stream->Read( array.Begin(), count*sizeof(Vector3) );
}

void XMeshCodec::ReadArrayText( IStream* stream, Vector<Vector3>& array, DWORD count )
{
	for ( UInt i = 0; i < count; ++i )
	{
		const Float x = ReadFloatText( stream );
		const Float y = ReadFloatText( stream );
		const Float z = ReadFloatText( stream );
		ReadChar( stream );
		array.Add( Vector3(x, y, z) );
	}
}

void XMeshCodec::ReadTemplateDefinitionBinary( IStream* stream )
{
	DWORD dw = 0;
	WORD token = GetToken( stream );
	const DWORD count = ReadDwordBinary( stream );
	Skip( stream, count );
	token = GetToken( stream );
	token = GetToken( stream );
	Skip( stream, 16 );

	while ( (token = GetToken(stream)) != TOKEN_CBRACE )
	{
		switch ( token )
		{
			case TOKEN_NAME:
				dw = ReadDwordBinary( stream );
				Skip( stream, dw );
				break;

			default:
				break;
		}
	}
}

Byte XMeshCodec::ReadTemplateName( IStream* stream )
{
	String str = ReadNameBinary( stream );
	return _templates.ContainsKey(str) ? _templates[str] : (Byte)-1;
}

String XMeshCodec::ReadStringBinary( IStream* stream )
{
	String str = ReadNameBinary( stream );
	GetToken( stream );
	return str;
}

String XMeshCodec::ReadStringText( IStream* stream )
{
	char ch = 0;
	String str;
	Bool inside = false;
	Bool exit = false;
	_lexem.Clear();
	while ( !exit && (stream->Read(&ch, 1) == 1) )
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
					ReadChar( stream );
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

String XMeshCodec::ReadReferenceBinary( IStream* stream )
{
	GetToken( stream );
	GetToken( stream );
	String ref = ReadNameBinary( stream );
	GetToken( stream );
	return ref;
}

String XMeshCodec::ReadReferenceText( IStream* stream )
{
	char ch = 0; String str;
	Bool exit = false;
	ReadChar( stream );
	_lexem.Clear();
	while ( !exit && (stream->Read(&ch, 1) == 1) )
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

void XMeshCodec::ReadTemplateBinary( IStream* stream, Byte type, const String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	switch ( type )
	{
		case TEMPLATE_ANIMATION_SET:		ReadAnimationSet( stream, name, loadAnimations ); break;
		case TEMPLATE_ANIMATION:			ReadAnimation( stream, loadAnimations ); break;
		case TEMPLATE_MESH:					ReadMeshBinary( stream, name ); break;
		case TEMPLATE_MESH_NORMALS:			ReadMeshNormalsBinary( stream ); break;
		case TEMPLATE_MESH_TEXTURE_COORDS:	ReadMeshTextureCoordsBinary( stream ); break;
		case TEMPLATE_MESH_MATERIAL_LIST:	ReadMeshMaterialListBinary( stream ); break;
		case TEMPLATE_MATERIAL:				ReadMaterialBinary( stream, name ); break;
		case TEMPLATE_TEXTURE_FILENAME:		ReadTextureFilenameBinary( stream ); break;
		default:							ReadUnknownBinary( stream ); break;
	}
}

void XMeshCodec::ReadTemplateText( IStream* stream, Byte type, const String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	switch ( type )
	{
		case TEMPLATE_ANIMATION_SET:			ReadAnimationSet( stream, name, loadAnimations ); break;
		case TEMPLATE_ANIMATION:				ReadAnimation( stream, loadAnimations ); break;
		case TEMPLATE_ANIMATION_KEY:			ReadAnimationKeyText( stream, loadAnimations ); break;
		case TEMPLATE_FRAME:					ReadFrameText( stream, name ); break;
		case TEMPLATE_FRAME_TRANSFORM_MATRIX:	ReadFrameTransformMatrixText( stream ); break;
		case TEMPLATE_MESH:						ReadMeshText( stream, name ); break;
		case TEMPLATE_MESH_NORMALS:				ReadMeshNormalsText( stream ); break;
		case TEMPLATE_MESH_TEXTURE_COORDS:		ReadMeshTextureCoordsText( stream ); break;
		case TEMPLATE_MESH_MATERIAL_LIST:		ReadMeshMaterialListText( stream ); break;
		case TEMPLATE_MATERIAL:					ReadMaterialText( stream, name, loadMaterial ); break;
		case TEMPLATE_TEXTURE_FILENAME:			ReadTextureFilenameText( stream, loadMaterial ); break;
		case TEMPLATE_XSKIN_MESH_HEADER:		ReadMeshSkinHeaderText( stream, loadSkin ); break;
		case TEMPLATE_SKIN_WEIGHTS:				ReadSkinWeightsText( stream, loadSkin ); break;
		default:								ReadUnknownText( stream ); break;
	}
}

void XMeshCodec::ReadFrameText( IStream* stream, const String& name )
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

void XMeshCodec::ReadFrameTransformMatrixText( IStream* stream )
{
	if ( _frameStack.Size() > 0 )
	{
		FrameDesc* frame = &_frames[_frameStack.Top()];
		Vector<Float> mat( A(Float), 16 );
		ReadArrayText( stream, mat, 16 );
		frame->Transform = Matrix4x4( mat.Begin() );
	}
}

void XMeshCodec::ReadMeshBinary( IStream* stream, const String& name )
{
	_models.Add( ModelDesc((_frameStack.Size() > 0) ? _frameStack.Top() : none, name) );

	WORD token = GetToken( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	const DWORD nVertices = ReadDwordBinary( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	ReadArrayBinary( stream, _models.Last()->Positions, nVertices );
	token = GetToken( stream );
	const DWORD nFaces = ReadDwordBinary( stream );
	ReadArrayBinary( stream, _models.Last()->Faces, nFaces );
}

void XMeshCodec::ReadMeshText( IStream* stream, const String& name )
{
	_models.Add( ModelDesc((_frameStack.Size() > 0) ? _frameStack.Top() : none, name) );

	const DWORD nVertices = ReadDwordText( stream );
	ReadArrayText( stream, _models.Last()->Positions, nVertices );
	const DWORD nFaces = ReadDwordText( stream );
	_models.Last()->Faces.Add( nFaces );
	ReadFacesText( stream, _models.Last()->Faces, nFaces );
}

void XMeshCodec::ReadMeshNormalsBinary( IStream* stream )
{
	WORD token = GetToken( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	const DWORD nNormals = ReadDwordBinary( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	ReadArrayBinary( stream, _models.Last()->Normals, nNormals );
	token = GetToken( stream );
	const DWORD nFaceNormals = ReadDwordBinary( stream );
	ReadArrayBinary( stream, _models.Last()->FaceNormals, nFaceNormals );
}

void XMeshCodec::ReadMeshNormalsText( IStream* stream )
{
	const DWORD nNormals = ReadDwordText( stream );
	ReadArrayText( stream, _models.Last()->Normals, nNormals );
	const DWORD nFaceNormals = ReadDwordText( stream );
	ReadFacesText( stream, _models.Last()->FaceNormals, nFaceNormals );
}

void XMeshCodec::ReadMeshTextureCoordsBinary( IStream* stream )
{
	WORD token = GetToken( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	const DWORD nTextureCoords = ReadDwordBinary( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	ReadArrayBinary( stream, _models.Last()->TexCoords, nTextureCoords );
}

void XMeshCodec::ReadMeshTextureCoordsText( IStream* stream )
{
	const DWORD nTextureCoords = ReadDwordText( stream );
	ReadArrayText( stream, _models.Last()->TexCoords, nTextureCoords );
}

void XMeshCodec::ReadMeshMaterialListBinary( IStream* stream )
{
	UInt start = 0; UInt count = 0;
	WORD token = GetToken( stream );
	token = GetToken( stream );
	ReadDwordBinary( stream );
	const DWORD nMaterials = ReadDwordBinary( stream );
	const DWORD nFaceIndexes = ReadDwordBinary( stream );
	if ( nFaceIndexes > 1 )
	{
		DWORD oldIdx = 0;
		for ( DWORD i = 0; i < nFaceIndexes; ++i )
		{
			const DWORD idx = ReadDwordBinary( stream );
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
		ReadDwordBinary( stream );
	}
	_models.Last()->Subsets.Add( Range(3*start, 3*count) );

	token = PeekToken( stream );
	if ( token == TOKEN_OBRACE )
	{
		for ( DWORD i = 0; i < nMaterials; ++i )
		{
			String name = ReadReferenceBinary( stream );
			if ( i < _models.Last()->Subsets.Size() )
			{
				_subMaterials.Add( SubMaterialDesc(name) );
			}
		}
	}
}

void XMeshCodec::ReadMeshMaterialListText( IStream* stream )
{
	UInt start = 0; UInt count = 0;
	const DWORD nMaterials = ReadDwordText( stream );
	const DWORD nFaceIndexes = ReadDwordText( stream );
	if ( nFaceIndexes > 1 )
	{
		DWORD oldIdx = 0; 
		for ( DWORD i = 0; i < nFaceIndexes; ++i )
		{
			const DWORD idx = ReadDwordText( stream );
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
		ReadDwordText( stream );
	}
	_models.Last()->Subsets.Add( Range(3*start, 3*count) );

	if ( PeekChar(stream) == '{' )
	{
		for ( DWORD i = 0; i < nMaterials; ++i )
		{
			PeekChar( stream );
			String name = ReadReferenceText( stream );
			if ( i < _models.Last()->Subsets.Size() )
			{
				_subMaterials.Add( SubMaterialDesc(name) );
			}
		}
	}
}

void XMeshCodec::ReadMaterialBinary( IStream* stream, const String& name )
{
	_lastMaterialName = name;
	WORD token = GetToken( stream );
	token = GetToken( stream );
	const DWORD nCount = ReadDwordBinary( stream );
	
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
			Skip( stream, nCount*sizeof(Float) );
		}
	}
	else
	{
		_materials[name] = MaterialDesc();
		colors = &_materials[name].Colors;
	}

	if ( colors != nullptr )
	{
		ReadArrayBinary( stream, *colors, nCount );
	}
}

void XMeshCodec::ReadMaterialText( IStream* stream, const String& name, Bool load )
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

	ReadArrayText( stream, *colors, 11 );
	ReadChar( stream );
}

void XMeshCodec::ReadTextureFilenameBinary( IStream* stream )
{
	WORD token = GetToken( stream );
	token = GetToken( stream );
	String filename = ReadStringBinary( stream );

	if ( !_lastMaterialName.IsEmpty() )
		_materials[_lastMaterialName].Texture = filename;
	else
		_models.Last()->Materials.Last()->Texture = filename;
}

void XMeshCodec::ReadTextureFilenameText( IStream* stream, Bool load )
{
	String filename = ReadStringText( stream );
	if ( load )
	{
		if ( !_lastMaterialName.IsEmpty() )
			_materials[_lastMaterialName].Texture = filename;
		else
			_models.Last()->Materials.Last()->Texture = filename;
	}
}

void XMeshCodec::ReadMeshSkinHeaderText( IStream* stream, Bool load )
{
	const DWORD dw = ReadDwordText( stream );
	ReadDwordText( stream );
	ReadDwordText( stream );

	if ( load )
	{
		_models.Last()->BonesPerVertex = dw;
	}
}

void XMeshCodec::ReadSkinWeightsText( IStream* stream, Bool load )
{
	Vector<DWORD> indices( A(DWORD) );
	Vector<Float> weights( A(Float) );
	Vector<Float> offset( A(Float) );

	Vector<DWORD>* boneIndices = &indices;
	Vector<Float>* boneWeights = &weights;
	Vector<Float>* boneOffset = &offset;

	String name = ReadStringText( stream );
	const DWORD nWeights = ReadDwordText( stream );
	if ( load )
	{
		_models.Last()->Bones.Add( BoneDesc() );
		BoneDesc* bone = _models.Last()->Bones.Last();
		bone->Name = name;
		boneIndices = &bone->Indices;
		boneWeights = &bone->Weights;
		boneOffset = &bone->Offset;
	}

	ReadArrayText( stream, *boneIndices, nWeights );
	ReadArrayText( stream, *boneWeights, nWeights );
	ReadArrayText( stream, *boneOffset, 16 );
	ReadChar( stream );
}

void XMeshCodec::ReadAnimationSet( IStream* stream, const String& name, Bool load )
{
	if ( load )
	{
		_animationSets.Add( AnimationSetDesc(name) );
	}
}

void XMeshCodec::ReadAnimation( IStream* stream, Bool load )
{
	if ( load )
	{
		_animationSets.Last()->Animations.Add( AnimationDesc() );
	}
}

void XMeshCodec::ReadAnimationKeyText( IStream* stream, Bool load )
{
	Vector<Byte> buf( A(Byte) );
	Vector<Byte>* data = &buf;

	if ( load )
	{
		AnimationDesc* animation = _animationSets.Last()->Animations.Last();
		animation->Tracks.Add( AnimationTrackDesc() );
		data = &animation->Tracks.Last()->Data;
	}

	Put( *data, ReadDwordText(stream) );
	const DWORD nKeys = ReadDwordText( stream );
	Put( *data, nKeys );
	DWORD nValues = 0; Float f = 0.0f;
	for ( DWORD i = 0; i < nKeys; ++i )
	{
		Put( *data, ReadDwordText(stream) );
		nValues = ReadDwordText( stream );
		Put( *data, nValues );
		for ( DWORD j = 0; j < nValues; ++j )
		{
			f = ReadFloatText( stream );
			Put( *data, f );
		}
		ReadChar( stream );
		ReadChar( stream );
	}
	ReadChar( stream );

	// Read closing '}'.
	PeekChar( stream );
	ReadChar( stream );

	PeekChar( stream );
	String name = ReadReferenceText( stream );
	if ( load )
	{
		_animationSets.Last()->Animations.Last()->Name = name;
	}
}

void XMeshCodec::ReadIntegerList( IStream* stream )
{
	const DWORD nCount = ReadDwordBinary( stream );
	for ( DWORD i = 0; i < nCount; ++i )
	{
		ReadDwordBinary( stream );
	}
}

void XMeshCodec::ReadFloatList( IStream* stream )
{
	const DWORD nCount = ReadDwordBinary( stream );
	for ( DWORD i = 0; i < nCount; ++i )
	{
		ReadFloatBinary( stream );
	}
}

void XMeshCodec::ReadUnknownBinary( IStream* stream )
{
	WORD token = TOKEN_NONE;
	while ( (token = GetToken(stream)) != TOKEN_CBRACE )
	{
		switch ( token )
		{
			case TOKEN_NAME:
				ReadNameBinary( stream );
				break;

			case TOKEN_INTEGER_LIST:
				ReadIntegerList( stream );
				break;

			case TOKEN_FLOAT_LIST:
				ReadFloatList( stream );
				break;

			default:
				break;
		}
	}
}

void XMeshCodec::ReadUnknownText( IStream* stream )
{
	char ch = 0;
	while ( (stream->Read(&ch, 1) == 1) )
	{
		if ( ch == '}' )
			break;
	}
}

void XMeshCodec::Write( IStream* stream, const DataMode& mode )
{
	XMeshHeader hdr;
	hdr.dwMagic			= XOFFILE_FORMAT_MAGIC;
	hdr.dwVersion		= XOFFILE_FORMAT_VERSION;
	hdr.dwFormatType	= (mode == DataMode::Text) ? XOFFILE_FORMAT_TEXT : XOFFILE_FORMAT_BINARY;
	hdr.dwFloatSize		= XOFFILE_FORMAT_FLOAT_BITS_32;
	stream->Write( &hdr, sizeof(hdr) );
}

void XMeshCodec::WriteCRLF( IStream* stream )
{
	char crlf[] = "\r\n";
	stream->Write( crlf, 2 );
}

void XMeshCodec::WriteIndent( IStream* stream )
{
	for ( UInt i = 0; i < _indent; ++i )
	{
		WriteChar( stream, ' ' );
	}
}

void XMeshCodec::WriteChar( IStream* stream, char value )
{
	stream->Write( &value, sizeof(char) );
}

void XMeshCodec::WriteToken( IStream* stream, WORD token )
{
	stream->Write( &token, sizeof(WORD) );
}

void XMeshCodec::WriteDwordBinary( IStream* stream, DWORD value )
{
	stream->Write( &value, sizeof(DWORD) );
}

void XMeshCodec::WriteDwordText( IStream* stream, DWORD value )
{
	WriteIndent( stream );
	String str( CastInt(value) );
	_buffer.SetSize( str.Length()+1 );
	str.GetBytes( _buffer.Begin(), _buffer.Size() );
	stream->Write( _buffer.Begin(), str.Length() );
	WriteChar( stream, ';' );
}

void XMeshCodec::WriteFloatBinary( IStream* stream, FLOAT value )
{
	stream->Write( &value, sizeof(FLOAT) );
}

void XMeshCodec::WriteFloatText( IStream* stream, FLOAT value )
{
	char buf[32] = {};
	sprintf( buf, "%.6f;", value );
	stream->Write( buf, CastUInt(strlen(buf)) );
}

void XMeshCodec::WriteName( IStream* stream, const String& name )
{
	_buffer.SetSize( name.Length()+1 );
	name.GetBytes( _buffer.Begin(), _buffer.Size() );
	stream->Write( _buffer.Begin(), name.Length() );
}

void XMeshCodec::WriteArrayBinary( IStream* stream, const Vector<DWORD>& array )
{
	stream->Write( array.Begin(), array.Size()*sizeof(DWORD) );
}

void XMeshCodec::WriteArrayText( IStream* stream, const Vector<DWORD>& array )
{
	char buf[32] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		sprintf( buf, "%d", array[i] );
		WriteIndent( stream );
		stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( stream, (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF( stream );
	}
}

void XMeshCodec::WriteFacesText( IStream* stream, const Vector<DWORD>& array )
{
	char buf[128] = {};
	UInt count = array.Size()/4;
	for ( UInt i = 0; i < count; ++i )
	{
		UInt idx = 4*i;
		sprintf( buf, "%d;%d,%d,%d;", array[idx], array[idx+1], array[idx+2], array[idx+3] );
		WriteIndent( stream );
		stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( stream, (i == count-1) ? ';' : ',' );
		WriteCRLF( stream );
	}
}

void XMeshCodec::WriteArrayBinary( IStream* stream, const Vector<Vector2>& array )
{
	stream->Write( array.Begin(), array.Size()*sizeof(Vector2) );
}

void XMeshCodec::WriteArrayText( IStream* stream, const Vector<Vector2>& array )
{
	char buf[64] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Vector2& vec = array[i];
		WriteIndent( stream );
		sprintf( buf, "%.6f;%.6f;", vec.x, vec.y );
		stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( stream, (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF( stream );
	}
}

void XMeshCodec::WriteArrayBinary( IStream* stream, const Vector<Vector3>& array )
{
	stream->Write( array.Begin(), array.Size()*sizeof(Vector3) );
}

void XMeshCodec::WriteArrayText( IStream* stream, const Vector<Vector3>& array )
{
	char buf[96] = {};
	for ( UInt i = 0; i < array.Size(); ++i )
	{
		const Vector3& vec = array[i];
		WriteIndent( stream );
		sprintf( buf, "%.6f;%.6f;%.6f;", vec.x, vec.y, vec.z );
		stream->Write( buf, CastUInt(strlen(buf)) );
		WriteChar( stream, (i == array.Size()-1) ? ';' : ',' );
		WriteCRLF( stream );
	}
}

void XMeshCodec::BeginTemplateBinary( IStream* stream, Byte type, const String& name )
{
	if ( _templates2.ContainsKey(type) )
	{
		String tmpl = _templates2[type];
		WriteToken( stream, TOKEN_NAME );
		WriteDwordBinary( stream, tmpl.Length() );
		WriteName( stream, tmpl );
	}

	if ( !name.IsEmpty() )
	{
		WriteToken( stream, TOKEN_NAME );
		WriteDwordBinary( stream, name.Length() );
		WriteName( stream, name );
	}

	WriteToken( stream, TOKEN_OBRACE );
}

void XMeshCodec::BeginTemplateText( IStream* stream, Byte type, const String& name )
{
	WriteCRLF( stream );
	WriteIndent( stream );

	if ( _templates2.ContainsKey(type) )
	{
		String tmpl = _templates2[type];
		WriteName( stream, tmpl );
		WriteChar( stream, ' ' );
	}

	if ( !name.IsEmpty() )
	{
		WriteName( stream, name );
		WriteChar( stream, ' ' );
	}
	WriteChar( stream, '{' );
	WriteCRLF( stream );
	++_indent;
}

void XMeshCodec::EndTemplateBinary( IStream* stream )
{
	WriteToken( stream, TOKEN_CBRACE );
}

void XMeshCodec::EndTemplateText( IStream* stream )
{
	--_indent;
	WriteIndent( stream );
	WriteChar( stream, '}' );
	WriteCRLF( stream );
}

void XMeshCodec::WriteStringBinary( IStream* stream, const String& str )
{
	WriteToken( stream, TOKEN_STRING );
	WriteDwordBinary( stream, str.Length() );
	WriteName( stream, str );
	WriteToken( stream, TOKEN_SEMICOLON );
}

void XMeshCodec::WriteStringText( IStream* stream, const String& str )
{
	WriteIndent( stream );
	WriteChar( stream, '"' );
	WriteName( stream, str );
	WriteChar( stream, '"' );
	WriteChar( stream, ';' );
	WriteCRLF( stream );
}

void XMeshCodec::WriteMeshBinary( IStream* stream, const ModelDesc& desc )
{
	BeginTemplateBinary( stream, TEMPLATE_MESH, desc.Name );

	// Positions.
	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, 1 );
	WriteDwordBinary( stream, desc.Positions.Size() );
	WriteToken( stream, TOKEN_FLOAT_LIST );
	WriteDwordBinary( stream, 3*desc.Positions.Size() );
	WriteArrayBinary( stream, desc.Positions );

	// Indices.
	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, desc.Faces.Size()+1 );
	WriteDwordBinary( stream, desc.Faces.Size()/4 );
	WriteArrayBinary( stream, desc.Faces );

	// Normals.
	WriteMeshNormalsBinary( stream, desc );

	// Texture coordinates.
	WriteMeshTextureCoordsBinary( stream, desc );

	// Materials.
	WriteMeshMaterialListBinary( stream, desc );

	EndTemplateBinary( stream );
}

void XMeshCodec::WriteMeshText( IStream* stream, const ModelDesc& desc )
{
	BeginTemplateText( stream, TEMPLATE_MESH, desc.Name );
	
	// Positions.
	WriteDwordText( stream, desc.Positions.Size() );
	WriteCRLF( stream );
	WriteArrayText( stream, desc.Positions );

	// Indices.
	WriteDwordText( stream, desc.Faces.Size()/4 );
	WriteCRLF( stream );
	WriteFacesText( stream, desc.Faces );

	// Normals.
	WriteMeshNormalsText( stream, desc );

	// Texture coordinates.
	WriteMeshTextureCoordsText( stream, desc );

	// Materials.
	WriteMeshMaterialListText( stream, desc );

	EndTemplateText( stream );
}

void XMeshCodec::WriteMeshNormalsBinary( IStream* stream, const ModelDesc& desc )
{
	if ( desc.Normals.IsEmpty() )
		return;

	BeginTemplateBinary( stream, TEMPLATE_MESH_NORMALS, String::Empty );

	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, 1 );
	WriteDwordBinary( stream, desc.Normals.Size() );

	WriteToken( stream, TOKEN_FLOAT_LIST );
	WriteDwordBinary( stream, 3*desc.Normals.Size() );
	WriteArrayBinary( stream, desc.Normals );

	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, desc.Faces.Size()+1 );
	WriteDwordBinary( stream, desc.Faces.Size()/4 );
	WriteArrayBinary( stream, desc.Faces );

	EndTemplateBinary( stream );
}

void XMeshCodec::WriteMeshNormalsText( IStream* stream, const ModelDesc& desc )
{
	if ( desc.Normals.IsEmpty() )
		return;

	BeginTemplateText( stream, TEMPLATE_MESH_NORMALS, String::Empty );

	// Normals.
	WriteDwordText( stream, desc.Normals.Size() );
	WriteCRLF( stream );
	WriteArrayText( stream, desc.Normals );

	// Faces.
	WriteDwordText( stream, desc.Faces.Size()/4 );
	WriteCRLF( stream );
	WriteFacesText( stream, desc.Faces );

	EndTemplateText( stream );
}

void XMeshCodec::WriteMeshTextureCoordsBinary( IStream* stream, const ModelDesc& desc )
{
	if ( desc.TexCoords.IsEmpty() )
		return;

	BeginTemplateBinary( stream, TEMPLATE_MESH_TEXTURE_COORDS, String::Empty );

	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, 1 );
	WriteDwordBinary( stream, desc.TexCoords.Size() );

	WriteToken( stream, TOKEN_FLOAT_LIST );
	WriteDwordBinary( stream, 2*desc.TexCoords.Size() );
	WriteArrayBinary( stream, desc.TexCoords );

	EndTemplateBinary( stream );
}

void XMeshCodec::WriteMeshTextureCoordsText( IStream* stream, const ModelDesc& desc )
{
	if ( desc.TexCoords.IsEmpty() )
		return;

	BeginTemplateText( stream, TEMPLATE_MESH_TEXTURE_COORDS, String::Empty );

	WriteDwordText( stream, desc.TexCoords.Size() );
	WriteCRLF( stream );
	WriteArrayText( stream, desc.TexCoords );

	EndTemplateText( stream );
}

void XMeshCodec::WriteMeshMaterialListBinary( IStream* stream, const ModelDesc& desc )
{
	BeginTemplateBinary( stream, TEMPLATE_MESH_MATERIAL_LIST, String::Empty );

	// Write mesh subsets.
	Vector<DWORD> faces( A(DWORD) );
	WriteToken( stream, TOKEN_INTEGER_LIST );
	WriteDwordBinary( stream, desc.Faces.Size()/4+2 );
	WriteDwordBinary( stream, desc.Materials.Size() );
	WriteDwordBinary( stream, desc.Faces.Size()/4 );
	if ( desc.Subsets.Size() == 1 )
	{
		faces.SetSize( desc.Faces.Size()/4, 0 );
	}
	else
	{
		for ( UInt i = 0; i < desc.Subsets.Size(); ++i )
		{
			faces.SetSize( faces.Size()+desc.Subsets[i].Length/3, i );
		}
	}
	WriteArrayBinary( stream, faces );
	
	// Write sub-materials.
	for ( UInt i = 0; i < desc.Materials.Size(); ++i )
	{
		WriteMaterialBinary( stream, desc.Materials[i] );
	}

	EndTemplateBinary( stream );
}

void XMeshCodec::WriteMeshMaterialListText( IStream* stream, const ModelDesc& desc )
{
	BeginTemplateText( stream, TEMPLATE_MESH_MATERIAL_LIST, String::Empty );

	// Write mesh subsets.
	Vector<DWORD> faces( A(DWORD) );
	WriteDwordText( stream, desc.Materials.Size() );
	WriteCRLF( stream );
	WriteDwordText( stream, desc.Faces.Size()/4 );
	WriteCRLF( stream );
	if ( desc.Subsets.Size() == 1 )
	{
		faces.SetSize( desc.Faces.Size()/4, 0 );
	}
	else
	{
		for ( UInt i = 0; i < desc.Subsets.Size(); ++i )
		{
			faces.SetSize( faces.Size()+desc.Subsets[i].Length/3, i );
		}
	}
	WriteArrayText( stream, faces );

	// Write sub-materials.
	for ( UInt i = 0; i < desc.Materials.Size(); ++i )
	{
		WriteMaterialText( stream, desc.Materials[i] );
	}

	EndTemplateText( stream );
}

void XMeshCodec::WriteMaterialBinary( IStream* stream, const MaterialDesc& desc )
{
	BeginTemplateBinary( stream, TEMPLATE_MATERIAL, String::Empty );

	WriteToken( stream, TOKEN_FLOAT_LIST );
	WriteDwordBinary( stream, desc.Colors.Size() );
	for ( UInt i = 0; i < desc.Colors.Size(); ++i )
	{
		WriteFloatBinary( stream, desc.Colors[i] );
	}
	if ( !desc.Texture.IsEmpty() )
	{
		WriteTextureFilenameBinary( stream, desc.Texture );
	}
	
	EndTemplateBinary( stream );
}

void XMeshCodec::WriteMaterialText( IStream* stream, const MaterialDesc& desc )
{
	BeginTemplateText( stream, TEMPLATE_MATERIAL, String::Empty );

	// Diffuse color.
	WriteIndent( stream );
	WriteFloatText( stream, desc.Colors[0] );
	WriteFloatText( stream, desc.Colors[1] );
	WriteFloatText( stream, desc.Colors[2] );
	WriteFloatText( stream, desc.Colors[3] );
	WriteChar( stream, ';' );
	WriteCRLF( stream );

	// Power.
	WriteIndent( stream );
	WriteFloatText( stream, desc.Colors[4] );
	WriteCRLF( stream );

	// Specular color.
	WriteIndent( stream );
	WriteFloatText( stream, desc.Colors[5] );
	WriteFloatText( stream, desc.Colors[6] );
	WriteFloatText( stream, desc.Colors[7] );
	WriteChar( stream, ';' );
	WriteCRLF( stream );

	// Emissive color.
	WriteIndent( stream );
	WriteFloatText( stream, desc.Colors[8] );
	WriteFloatText( stream, desc.Colors[9] );
	WriteFloatText( stream, desc.Colors[10] );
	WriteChar( stream, ';' );
	WriteCRLF( stream );

	if ( !desc.Texture.IsEmpty() )
	{
		WriteTextureFilenameText( stream, desc.Texture );
	}

	EndTemplateText( stream );
}

void XMeshCodec::WriteTextureFilenameBinary( IStream* stream, const String& filename )
{
	BeginTemplateBinary( stream, TEMPLATE_TEXTURE_FILENAME, String::Empty );
	WriteStringBinary( stream, filename );
	EndTemplateBinary( stream );
}

void XMeshCodec::WriteTextureFilenameText( IStream* stream, const String& filename )
{
	BeginTemplateText( stream, TEMPLATE_TEXTURE_FILENAME, String::Empty );
	WriteStringText( stream, filename );
	EndTemplateText( stream );
}

IVisualMaterial* XMeshCodec::ChooseMaterial( IStream* stream, IVisualMaterial* material, const PixelFormat& format, Bool loadMaps )
{
	SynkroCall( "XMeshCodec::ChooseMaterial", stream->GetName() );

	if ( material != nullptr )
		return material;
	
	if ( _materialCache.ContainsKey(stream->ID()) )
	{
		material = _materialCache[stream->ID()];
	}
	else
	{
		PrepareMaterials( stream, format, loadMaps );
		if ( _subMaterials.Size() > 1 )
		{
			IMultiMaterial* multiMaterial = _materialManager->CreateMultiMaterial( _subMaterials.Size() );
			for ( UInt i = 0; i < _subMaterials.Size(); ++i )
			{
				multiMaterial->SetSubset( i, _subMaterials[i].Material );
			}
			material = multiMaterial;
		}
		else if ( _subMaterials.Size() == 1 )
		{
			material = _subMaterials[0].Material;
		}
		else if ( loadMaps )
		{
			material = (IVisualMaterial*)_materialManager->CreateOpaqueMaterial( LightingModel::Gouraud );
		}
		_materialCache[stream->ID()] = material;
	}

	return material;
}

void XMeshCodec::PrepareMaterials( IStream* stream, const PixelFormat& format, Bool loadMaps )
{
	SynkroCall( "XMeshCodec::PrepareMaterials", stream->GetName() );

	for ( UInt i = 0; i < _subMaterials.Size(); ++i )
	{
		SubMaterialDesc& sub = _subMaterials[i];

		if ( _subMaterials[i].Material == nullptr )
		{
			_subMaterials[i].Material = _materialManager->CreateOpaqueMaterial( LightingModel::Gouraud );
		}
		IOpaqueMaterial* material = _subMaterials[i].Material;
		const MaterialDesc& desc = !sub.Name.IsEmpty() ? _materials[sub.Name] : _models[sub.ModelIndex].Materials[sub.MaterialIndex];

		// Set colors.
		Float* p = desc.Colors.Begin();
		Float opacity = p[3];
		if ( opacity == 0.0f )
		{
			opacity = 1.0f;
		}
		material->SetDiffuseColor( Color(p[0], p[1], p[2]) );
		material->SetAmbientColor( Color(p[0], p[1], p[2]) );
		material->SetSpecularPower( p[4] );
		material->SetSpecularColor( Color(p[5], p[6], p[7]) );
		material->SetEmissiveColor( Color(p[8], p[9], p[10]) );

		// Set texture, if any.
		if ( !desc.Texture.IsEmpty() )
		{
			IImage* image = nullptr;
			if ( loadMaps )
			{
				IStream* streamTexture = stream->GetDirectory()->GetStream( desc.Texture );
				if ( streamTexture == nullptr )
					throw Exception( String::Format(L"Failed to load mesh. File {0} not found.", desc.Texture) );

				PixelFormat fmt = format;
				image = _imageManager->LoadImageAsync( streamTexture, fmt, nullptr );
				material->GetDiffuseMap()->SetImage( image );
			}
			material->GetDiffuseMap()->SetName( desc.Texture );
			material->GetDiffuseMap()->SetAmount( 1.0f );
		}
	}
}

void XMeshCodec::PrepareMesh( ITriangleMesh* mesh )
{
	SynkroCall( "XMeshCodec::PrepareMesh", mesh->GetName() );

	SynkroProfile( "XMeshCodec.PrepareMesh" );

	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		ModelDesc& desc = _models[i];

		// Fix index data.
		UInt face[3];
		UInt faceCount = desc.Faces[0];
		Vector<UInt> indices( A(UInt), 3*faceCount );
		DWORD* pFace = desc.Faces.Get( 1 );
		for ( DWORD* p = pFace; faceCount > 0; --faceCount )
		{
			UInt count = *p++;
			for ( UInt f = 0; f < count-2; ++f )
			{
				face[0]	= p[0];
				face[1]	= p[f+1];
				face[2]	= p[f+2];
				indices.Add( face, 3 );
			}
			p += count;
		}

		// Create and fill in model.
		Matrix4x4 transform;
		if ( desc.FrameIndex != none )
		{
			_frames[desc.FrameIndex].GetWorldTransform( _frames, transform );
		}
		UInt vertexCount = desc.Positions.Size();
		String name = (desc.Subsets.Size() <= 1) ? desc.GetName(_frames) : String::Null;
		ITriangleSet* subset = mesh->CreateTriangleList( name, vertexCount, indices.Size(), false, transform );
		if ( desc.Subsets.Size() > 1 )
		{
			for ( UInt s = 0; s < desc.Subsets.Size(); ++s )
			{
				mesh->CreateTriangleSet( String::Format(L"Subset {0}", s), desc.Subsets[s] );
			}
		}
		subset->SetPositions( desc.Positions.Begin(), 0, vertexCount );
		subset->SetIndices( indices.Begin(), 0, indices.Size() );

		// Set normals.
		IScene* scene = mesh->GetScene();
		if ( !desc.Normals.IsEmpty() && (scene != nullptr) && scene->IsLit() )
		{
			Vector<Vector3> normals( A(Vector3) );
			normals.SetSize( vertexCount );
			faceCount = desc.Faces[0];
			pFace = desc.Faces.Get( 1 );
			DWORD* pNormal = desc.FaceNormals.Get( 0 );
			for ( DWORD* p = pFace; faceCount > 0; --faceCount )
			{
				pNormal++;
				UInt count = *p++;
				for ( UInt n = 0; n < count; ++n )
				{
					const UInt idx = p[n];
					const UInt idxNormal = pNormal[n];
					normals[idx] = desc.Normals[idxNormal];
				}
				p += count;
				pNormal += count;
			}
			subset->SetNormals( normals.Begin(), 0, vertexCount );
		}

		// Set texture coordinates.
		if ( !desc.TexCoords.IsEmpty() )
		{
			subset->SetTextureCoordinates( desc.TexCoords.Begin(), 0, vertexCount );
		}
	}
}

void XMeshCodec::PrepareSkeleton( ISkeleton* skeleton )
{
	SynkroCall( "XMeshCodec::PrepareSkeleton", String::Empty );

	SynkroProfile( "XMeshCodec.PrepareSkeleton" );

	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		ModelDesc& desc = _models[i];

		// Allocate vertices info.
		UInt vertexCount = desc.Positions.Size();
		desc.Vertices.SetSize( vertexCount );

		// Accumulate bone indices and weights.
		for ( UInt j = 0; j < desc.Bones.Size(); ++j )
		{
			SynkroProfile( "XMeshCodec.PrepareSkeleton.Accumulate" );

			BoneDesc& bone = desc.Bones[j];
			assert( _frameIndices.ContainsKey(bone.Name) );
			const Byte boneIndex = _frameIndices[bone.Name];
			for ( UInt k = 0; k < bone.Indices.Size(); ++k )
			{
				const DWORD vertex = bone.Indices[k];
				const Float weight = bone.Weights[k];
				VertexDesc& vd = desc.Vertices[vertex];
				vd.Bones[vd.BoneCount] = boneIndex;
				vd.Weights[vd.BoneCount] = weight;
				vd.BoneCount++;
			}
			_frames[boneIndex].Offset = Matrix4x4( bone.Offset.Begin() );
		}
	}

	// Create bones, if needed.
	if ( skeleton->GetBoneCount() == 0 )
	{
		for ( UInt i = 0; i < _frames.Size(); ++i )
		{
			const FrameDesc& desc = _frames[i];
			String parentName = (desc.ParentIndex != none) ? _frames[desc.ParentIndex].Name : String::Empty;
			IBone* parent = skeleton->GetBone( parentName );
			skeleton->CreateBone( parent, desc.Name, desc.Transform, desc.Offset );
		}
	}
}

void XMeshCodec::PrepareSkin( ITriangleMesh* mesh )
{
	SynkroCall( "XMeshCodec::PrepareSkin", String::Empty );

	SynkroProfile( "XMeshCodec.PrepareSkin" );

	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		ModelDesc& desc = _models[i];
		ITriangleSet* model = mesh->GetSubset( i )->AsTriangleSet();
		if ( !model->BeginSetBoneWeights() )
			throw Exception( L"Failed to load mesh. Unable to set skin weights." );

		for ( UInt j = 0; j < desc.Vertices.Size(); ++j )
		{
			const VertexDesc& vd = desc.Vertices[j];
			model->SetBoneWeights( j, vd.Bones, vd.Weights, vd.BoneCount );
		}

		model->EndSetBoneWeights();
	}
}

void XMeshCodec::PrepareAnimation( IStream* stream, ISkeleton* skeleton )
{
	SynkroCall( "XMeshCodec::PrepareAnimation", String::Empty );

	SynkroProfile( "XMeshCodec.PrepareAnimation" );

	// Update animation cache.
	if ( !_animationCache.ContainsKey(stream->ID()) )
	{
		if ( !_animationSets.IsEmpty() )
		{
			AnimationSetCollection coll;
			for ( UInt i = 0; i < _animationSets.Size(); ++i )
			{
				// Create animation set.
				AnimationSetDesc& desc = _animationSets[i];
				IAnimationSet* set = _animationSystem->CreateAnimationSet( desc.Name );
				for ( UInt j = 0; j < desc.Animations.Size(); ++j )
				{
					// Create animation.
					AnimationDesc& ad = desc.Animations[j];
					IAnimation* animation = set->CreateAnimation( ad.Name );
					for ( UInt k = 0; k < ad.Tracks.Size(); ++k )
					{
						// Create animation track.
						AnimationTrackDesc& at = ad.Tracks[k];
						DWORD* ptr = (DWORD*)at.Data.Begin();
						switch ( (TrackType)*ptr++ )
						{
							case TRACK_MATRIX:
								ptr = ReadTransformTrack( animation, ptr );
								break;

							case TRACK_POSITION:
								ptr = ReadPositionTrack( animation, ptr );
								break;

							case TRACK_ORIENTATION:
								ptr = ReadOrientationTrack( animation, ptr );
								break;

							case TRACK_SCALE:
								ptr = ReadScaleTrack( animation, ptr );
								break;
						}
					}
				}
				coll.Sets.Add( set );
			}
			_animationCache[stream->ID()] = coll;
		}
	}

	// Add animation sets to the skeleton, if needed.
	if ( (skeleton->GetAnimationSetCount() == 0) && (_animationCache.ContainsKey(stream->ID())) )
	{
		AnimationSetCollection& coll = _animationCache[stream->ID()];
		for ( UInt i = 0; i < coll.Sets.Size(); ++i )
		{
			skeleton->AddAnimationSet( coll.Sets[i] );
		}
	}
}

DWORD* XMeshCodec::ReadTransformTrack( IAnimation* animation, DWORD* ptr )
{
	IKeyframedMatrix4x4Track* track = animation->CreateMatrix4x4Track(BoneProperty::Transform.ToString());
	const UInt keyCount = CastUInt(*ptr++);
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		DWORD count = *ptr++;
		track->SetKey( time, Matrix4x4((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}

DWORD* XMeshCodec::ReadPositionTrack( IAnimation* animation, DWORD* ptr )
{
	IKeyframedVector3Track* track = animation->CreateVector3Track( BoneProperty::Position.ToString() );
	const UInt keyCount = CastUInt(*ptr++);
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		DWORD count = *ptr++;
		track->SetKey( time, Vector3((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}

DWORD* XMeshCodec::ReadOrientationTrack( IAnimation* animation, DWORD* ptr )
{
	IKeyframedQuaternionTrack* track = animation->CreateQuaternionTrack( BoneProperty::Orientation.ToString() );
	const UInt keyCount = CastUInt(*ptr++);
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		DWORD count = *ptr++;
		Float* p = (Float*)ptr;
		track->SetKey( time, Quaternion(p[1], p[2], p[3], p[0]).Conjugate() );
		ptr += count;
	}
	return ptr;
}

DWORD* XMeshCodec::ReadScaleTrack( IAnimation* animation, DWORD* ptr )
{
	IKeyframedVector3Track* track = animation->CreateVector3Track( BoneProperty::Scale.ToString() );
	const UInt keyCount = CastUInt(*ptr++);
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		DWORD count = *ptr++;
		track->SetKey( time, Vector3((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}


} // scene


} // synkro
