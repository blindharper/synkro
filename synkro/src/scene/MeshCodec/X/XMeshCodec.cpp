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
#include "MsZipStream.h"
#include <scene/BoneProperty.h>
#include <scene/ISkeleton.h>
#include <io/IStreamDirectory.h>
#include <img/IImage.h>
#include <img/IImageManager.h>
#include <core/CallStack.h>
#include <internal/SafeDelete.h>


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


namespace synkro
{


namespace scene
{


XMeshCodec::XMeshCodec( ISceneManager* sceneManager, IMaterialManager* materialManager, IImageManager* imageManager, IAnimationSystem* animationSystem ) :
	MeshCodecImpl<IMeshCodec>( sceneManager, materialManager, imageManager, animationSystem ),
	_templates( A(IndexEntry) ),
	_materialCache( A(MaterialCacheEntry) ),
	_animationCache( A(AnimationCacheEntry) ),
	_lexem( A(char) ),
	_reader( nullptr ),
	_textReader( nullptr ),
	_binaryReader( nullptr ),
	_writer( nullptr ),
	_textWriter( nullptr ),
	_binaryWriter( nullptr )
{
	RegisterTemplates();
}

XMeshCodec::~XMeshCodec()
{
	SafeDelete( _textReader );
	SafeDelete( _binaryReader );
	SafeDelete( _textWriter );
	SafeDelete( _binaryWriter );
}

ITriangleMesh* XMeshCodec::Load( IScene* scene, IStream* stream, const PixelFormat& format, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	SynkroCall( "XMeshCodec::Load", stream->GetName() );

	SynkroProfile( "XMeshCodec.Load" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Load( scene, stream, format, material, skeleton, instanceCapacity );

	// Load data into internal data structures.
	const Bool loadMaterial = (material == nullptr) && !_materialCache.ContainsKey( stream->ID() );
	Bool loadSkin = (skeleton != nullptr);
	const Bool loadAnimations = (skeleton != nullptr) && (skeleton->GetAnimationSetCount() == 0);
	const UInt fmt = ReadHeader( stream );
	CreateReader( fmt );
	_reader->Initialize( stream );

	Bool binary = false;
	Bool compressed = false;

	switch ( fmt )
	{
		case XOFFILE_FORMAT_BINARY:
			binary = true;
			compressed = false;
			break;

		case XOFFILE_FORMAT_BINARY_COMPRESSED:
			binary = true;
			compressed = true;
			break;

		case XOFFILE_FORMAT_TEXT:
			binary = false;
			compressed = false;
			break;
		
		case XOFFILE_FORMAT_TEXT_COMPRESSED:
			binary = false;
			compressed = true;
			break;
		
		default:
			throw Exception( L"Unsupported mesh format." );
	}
	
	// Handle compressed data.
	P(IStream) streamDecompressed;
	if ( compressed )
	{
		MsZipStream compressed( stream, binary, -MAX_WBITS );
		streamDecompressed = compressed.Decompress();
		_reader->Initialize( streamDecompressed );
	}

	// Read mesh data.
	if ( binary )
	{
		ReadBinary( loadMaterial, loadSkin, loadAnimations );
	}
	else
	{
		ReadText( loadMaterial, loadSkin, loadAnimations );
	}

	// Retrieve read data.
	_reader->GetModels( &_models );
	_reader->GetMaterials( &_materials );
	_reader->GetSubMaterials( &_subMaterials );
	_reader->GetAnimations( &_animationSets );
	_reader->GetFrames( &_frames );
	_reader->GetFrameIndices( &_frameIndices );

	// Nullify skeleton, if no bones found.
	loadSkin = (skeleton != nullptr) && (skeleton->GetBoneCount() == 0);
	if ( loadSkin && (_models->IsEmpty() || (_models->Last()->BonesPerVertex == 0)) )
	{
		skeleton = nullptr;
	}

	// Create right type of mesh.
	ITriangleMesh* mesh = nullptr;
	const Bool soft = (scene == nullptr);
	if ( soft )
	{
		mesh = _sceneManager->CreateTriangleMesh( skeleton, _subMaterials->Size() );
		if ( _subMaterials->Size() == 1 )
		{
			(*_subMaterials)[0].Material = mesh->GetMaterial()->AsSimple()->AsOpaque();
		}
		else
		{
			IMultiMaterial* material = mesh->GetMaterial()->AsMulti();
			for ( UInt i = 0; i < _subMaterials->Size(); ++i )
			{
				(*_subMaterials)[i].Material = material->GetSubset( i )->AsOpaque();
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

void XMeshCodec::Save( const ITriangleMesh* mesh, IStream* stream, const DataMode& mode )
{
	SynkroProfile( "XMeshCodec.Save" );

	// Call base implementation.
	MeshCodecImpl<IMeshCodec>::Save( mesh, stream, mode );

	// Initialize mesh writer.
	CreateWriter( mode );

	// Write mesh data.
	ModelDesc desc( mesh );
	WriteHeader( stream, mode );
	_writer->Initialize( stream );
	_writer->BeginTemplate( TEMPLATE_MESH, desc.Name );
	
	// Write positions.
	_writer->WritePositions( desc.Positions );

	// Write indices.
	_writer->WriteIndices( desc.Faces );

	// Write normals.
	if ( !desc.Normals.IsEmpty() )
	{
		_writer->BeginTemplate( TEMPLATE_MESH_NORMALS, String::Empty );

		// Normals.
		_writer->WritePositions( desc.Normals );

		// Faces.
		_writer->WriteIndices( desc.Faces );

		_writer->EndTemplate(); // TEMPLATE_MESH_NORMALS
	}

	// Write texture coordinates.
	if ( !desc.TexCoords.IsEmpty() )
	{
		_writer->BeginTemplate( TEMPLATE_MESH_TEXTURE_COORDS, String::Empty );
		_writer->WriteTexCoords( desc.TexCoords );
		_writer->EndTemplate(); // TEMPLATE_MESH_TEXTURE_COORDS
	}

	// Write materials.
	_writer->BeginTemplate( TEMPLATE_MESH_MATERIAL_LIST, String::Empty );

	// Write mesh subsets.
	_writer->WriteSubsets( desc.Faces, desc.Materials.Size() );
	Vector<UInt> faces( A(UInt) );
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
	_writer->WriteArray( faces );

	// Write sub-materials.
	for ( UInt i = 0; i < desc.Materials.Size(); ++i )
	{
		const Vector<Float>& colors = desc.Materials[i].Colors;

		_writer->BeginTemplate( TEMPLATE_MATERIAL, String::Empty );
		_writer->WriteColors( colors.Size() );

		// Write diffuse color.
		_writer->WriteColorRGBA( colors[0], colors[1], colors[2], colors[3] );

		// Write specular power.
		_writer->WritePower( colors[4] );

		// Write specular color.
		_writer->WriteColorRGB( colors[5], colors[6], colors[7] );

		// Write emissive color.
		_writer->WriteColorRGB( colors[8], colors[9], colors[10] );

		// Write material texture.
		if ( !desc.Materials[i].Texture.IsEmpty() )
		{
			_writer->BeginTemplate( TEMPLATE_TEXTURE_FILENAME, String::Empty );
			_writer->WriteString( desc.Materials[i].Texture );
			_writer->EndTemplate(); // TEMPLATE_TEXTURE_FILENAME
		}

		_writer->EndTemplate(); // TEMPLATE_MATERIAL
	}

	_writer->EndTemplate(); // TEMPLATE_MESH_MATERIAL_LIST

	_writer->EndTemplate(); // TEMPLATE_MESH
}

void XMeshCodec::CreateReader( UInt format )
{
	switch ( format )
	{
		case XOFFILE_FORMAT_BINARY:
		case XOFFILE_FORMAT_BINARY_COMPRESSED:
			if ( _binaryReader == nullptr )
			{
				_binaryReader = new XMeshBinaryReader();
			}
			_reader = _binaryReader;
			break;

		case XOFFILE_FORMAT_TEXT:
		case XOFFILE_FORMAT_TEXT_COMPRESSED:
			if ( _textReader == nullptr )
			{
				_textReader = new XMeshTextReader();
			}
			_reader = _textReader;
			break;
	}
}

void XMeshCodec::CreateWriter( const DataMode& mode )
{
	if ( mode == DataMode::Binary )
	{
		if ( _binaryWriter == nullptr )
		{
			_binaryWriter = new XMeshBinaryWriter();
		}
		_writer = _binaryWriter;
	}
	else if ( mode == DataMode::Text )
	{
		if ( _textWriter == nullptr )
		{
			_textWriter = new XMeshTextWriter();
		}
		_writer = _textWriter;
	}
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
}

UInt XMeshCodec::ReadHeader( IStream* stream )
{
	XMeshHeader hdr;
	const UInt count = stream->Read( &hdr, sizeof(hdr) );
	if ( count != sizeof(hdr) )
		throw Exception( L"X mesh file header is too short." );

	if ( hdr.dwMagic != XOFFILE_FORMAT_MAGIC )
		throw Exception( L"Bad X mesh file." );

	return hdr.dwFormatType;
}

void XMeshCodec::ReadBinary( Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	Byte tmpl = 0xff; UShort token = TOKEN_NONE; String name;
	while ( (token = _reader->GetToken()) != TOKEN_NONE )
	{
		switch ( token )
		{
			case TOKEN_TEMPLATE:
				_reader->ReadTemplateDefinition();
				break;

			case TOKEN_NAME:
				tmpl = _reader->ReadTemplateName();
				token = _reader->PeekToken();
				if ( token == TOKEN_NAME )
				{
					_reader->GetToken();
					name = _reader->ReadName();
				}
				else
				{
					name = String::Empty;
				}
				ReadTemplate( tmpl, name, loadMaterial, loadSkin, loadAnimations );
				break;

			default:
				break;
		}
	}
}

void XMeshCodec::ReadText( Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	String str; Byte temp = 0;
	char ch = 0; char old = 0; Byte tmpl = 0xff;
	String name; Bool comment = false;
	Stack<Byte> templates( A(Byte) );
	_lexem.Clear();
	while ( (ch = _reader->ReadChar()) != 0 )
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
					_reader->ReadUnknown();
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
					ReadTemplate( tmpl, name, loadMaterial, loadSkin, loadAnimations );
					if ( tmpl != TEMPLATE_ANIMATION_KEY )
					{
						templates.Push( tmpl );
					}
				}
				else
				{
					_reader->ReadUnknown();
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
					_reader->PopFrame();
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

void XMeshCodec::ReadTemplate( Byte type, const String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations )
{
	switch ( type )
	{
		case TEMPLATE_ANIMATION_SET:			_reader->ReadAnimationSet( name, loadAnimations ); break;
		case TEMPLATE_ANIMATION:				_reader->ReadAnimation( loadAnimations ); break;
		case TEMPLATE_ANIMATION_KEY:			_reader->ReadAnimationKey( loadAnimations ); break;
		case TEMPLATE_FRAME:					_reader->ReadFrame( name ); break;
		case TEMPLATE_FRAME_TRANSFORM_MATRIX:	_reader->ReadFrameTransformMatrix(); break;
		case TEMPLATE_MESH:						_reader->ReadMesh( name ); break;
		case TEMPLATE_MESH_NORMALS:				_reader->ReadMeshNormals(); break;
		case TEMPLATE_MESH_TEXTURE_COORDS:		_reader->ReadMeshTextureCoords(); break;
		case TEMPLATE_MESH_MATERIAL_LIST:		_reader->ReadMeshMaterialList(); break;
		case TEMPLATE_MATERIAL:					_reader->ReadMaterial( name, loadMaterial ); break;
		case TEMPLATE_TEXTURE_FILENAME:			_reader->ReadTextureFilename( loadMaterial ); break;
		case TEMPLATE_XSKIN_MESH_HEADER:		_reader->ReadMeshSkinHeader( loadSkin ); break;
		case TEMPLATE_SKIN_WEIGHTS:				_reader->ReadSkinWeights( loadSkin ); break;
		default:								_reader->ReadUnknown(); break;
	}
}

void XMeshCodec::WriteHeader( IStream* stream, const DataMode& mode )
{
	XMeshHeader hdr;
	hdr.dwMagic			= XOFFILE_FORMAT_MAGIC;
	hdr.dwVersion		= XOFFILE_FORMAT_VERSION;
	hdr.dwFormatType	= (mode == DataMode::Text) ? XOFFILE_FORMAT_TEXT : XOFFILE_FORMAT_BINARY;
	hdr.dwFloatSize		= XOFFILE_FORMAT_FLOAT_BITS_32;
	stream->Write( &hdr, sizeof(hdr) );
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
		if ( _subMaterials->Size() > 1 )
		{
			IMultiMaterial* multiMaterial = _materialManager->CreateMultiMaterial( _subMaterials->Size() );
			for ( UInt i = 0; i < _subMaterials->Size(); ++i )
			{
				multiMaterial->SetSubset( i, (*_subMaterials)[i].Material );
			}
			material = multiMaterial;
		}
		else if ( _subMaterials->Size() == 1 )
		{
			material = (*_subMaterials)[0].Material;
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

	for ( UInt i = 0; i < _subMaterials->Size(); ++i )
	{
		SubMaterialDesc& sub = (*_subMaterials)[i];

		if ( (*_subMaterials)[i].Material == nullptr )
		{
			(*_subMaterials)[i].Material = _materialManager->CreateOpaqueMaterial( LightingModel::Gouraud );
		}
		IOpaqueMaterial* material = (*_subMaterials)[i].Material;
		const MaterialDesc& desc = !sub.Name.IsEmpty() ? (*_materials)[sub.Name] : ((*_models)[sub.ModelIndex]).Materials[sub.MaterialIndex];

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

	for ( UInt i = 0; i < _models->Size(); ++i )
	{
		ModelDesc& desc = (*_models)[i];

		// Fix index data.
		UInt face[3];
		UInt faceCount = desc.Faces[0];
		Vector<UInt> indices( A(UInt), 3*faceCount );
		UInt* pFace = desc.Faces.Get( 1 );
		for ( UInt* p = pFace; faceCount > 0; --faceCount )
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
			(*_frames)[desc.FrameIndex].GetWorldTransform( *_frames, transform );
		}
		UInt vertexCount = desc.Positions.Size();
		String name = (desc.Subsets.Size() <= 1) ? desc.GetName(*_frames) : String::Null;
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
			UInt* pNormal = desc.FaceNormals.Get( 0 );
			for ( UInt* p = pFace; faceCount > 0; --faceCount )
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

	for ( UInt i = 0; i < _models->Size(); ++i )
	{
		ModelDesc& desc = (*_models)[i];

		// Allocate vertices info.
		UInt vertexCount = desc.Positions.Size();
		desc.Vertices.SetSize( vertexCount );

		// Accumulate bone indices and weights.
		for ( UInt j = 0; j < desc.Bones.Size(); ++j )
		{
			SynkroProfile( "XMeshCodec.PrepareSkeleton.Accumulate" );

			BoneDesc& bone = desc.Bones[j];
			assert( _frameIndices->ContainsKey(bone.Name) );
			const Byte boneIndex = (*_frameIndices)[bone.Name];
			for ( UInt k = 0; k < bone.Indices.Size(); ++k )
			{
				const UInt vertex = bone.Indices[k];
				const Float weight = bone.Weights[k];
				VertexDesc& vd = desc.Vertices[vertex];
				vd.Bones[vd.BoneCount] = boneIndex;
				vd.Weights[vd.BoneCount] = weight;
				vd.BoneCount++;
			}
			(*_frames)[boneIndex].Offset = Matrix4x4( bone.Offset.Begin() );
		}
	}

	// Create bones, if needed.
	if ( skeleton->GetBoneCount() == 0 )
	{
		for ( UInt i = 0; i < _frames->Size(); ++i )
		{
			const FrameDesc& desc = (*_frames)[i];
			String parentName = (desc.ParentIndex != none) ? (*_frames)[desc.ParentIndex].Name : String::Empty;
			IBone* parent = skeleton->GetBone( parentName );
			skeleton->CreateBone( parent, desc.Name, desc.Transform, desc.Offset );
		}
	}
}

void XMeshCodec::PrepareSkin( ITriangleMesh* mesh )
{
	SynkroCall( "XMeshCodec::PrepareSkin", String::Empty );

	SynkroProfile( "XMeshCodec.PrepareSkin" );

	for ( UInt i = 0; i < _models->Size(); ++i )
	{
		ModelDesc& desc = (*_models)[i];
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
		if ( !_animationSets->IsEmpty() )
		{
			AnimationSetCollection coll;
			for ( UInt i = 0; i < _animationSets->Size(); ++i )
			{
				// Create animation set.
				AnimationSetDesc& desc = (*_animationSets)[i];
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
						UInt* ptr = (UInt*)at.Data.Begin();
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

UInt* XMeshCodec::ReadTransformTrack( IAnimation* animation, UInt* ptr )
{
	IKeyframedMatrix4x4Track* track = animation->CreateMatrix4x4Track( BoneProperty::Transform.ToString() );
	const UInt keyCount = *ptr++;
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		UInt count = *ptr++;
		track->SetKey( time, Matrix4x4((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}

UInt* XMeshCodec::ReadPositionTrack( IAnimation* animation, UInt* ptr )
{
	IKeyframedVector3Track* track = animation->CreateVector3Track( BoneProperty::Position.ToString() );
	const UInt keyCount = *ptr++;
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		UInt count = *ptr++;
		track->SetKey( time, Vector3((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}

UInt* XMeshCodec::ReadOrientationTrack( IAnimation* animation, UInt* ptr )
{
	IKeyframedQuaternionTrack* track = animation->CreateQuaternionTrack( BoneProperty::Orientation.ToString() );
	const UInt keyCount = *ptr++;
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		UInt count = *ptr++;
		Float* p = (Float*)ptr;
		track->SetKey( time, Quaternion(p[1], p[2], p[3], p[0]).Conjugate() );
		ptr += count;
	}
	return ptr;
}

UInt* XMeshCodec::ReadScaleTrack( IAnimation* animation, UInt* ptr )
{
	IKeyframedVector3Track* track = animation->CreateVector3Track( BoneProperty::Scale.ToString() );
	const UInt keyCount = *ptr++;
	for ( UInt i = 0; i < keyCount; ++i )
	{
		const Double time = 0.001*CastDouble(*ptr++);
		UInt count = *ptr++;
		track->SetKey( time, Vector3((Float*)ptr) );
		ptr += count;
	}
	return ptr;
}


} // scene


} // synkro
