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
// Purpose: Wavefront Advanced Visualizer mesh codec.
//==============================================================================
#include "config.h"
#include "ObjMeshCodec.h"
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <core/CallStack.h>
#include <scene/IMesh.h>
#include <scene/ITriangleSet.h>
#include <mat/IMaterialMap.h>
#include <mat/IMultiMaterial.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ObjMeshCodec::ObjMeshCodec( ISceneManager* sceneManager, IMaterialManager* materialManager, IImageManager* imageManager, IAnimationSystem* animationSystem ) :
	MeshCodecImpl<IMeshCodec>( sceneManager, materialManager, imageManager, animationSystem ),
	_materials( A(MaterialDesc) ),
	_models( A(ModelDesc) ),
	_materialCache( A(MaterialCacheEntry) ),
	_lexem( A(char) ),
	_lexemCache( A(char) )
{
}

ITriangleMesh* ObjMeshCodec::Load( IScene* scene, IStream* stream, const PixelFormat& format, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	SynkroCall( "ObjMeshCodec::Load", stream->GetName() );

	_char = 0;
	_models.Clear();
	_materials.Clear();

	Vector<Vector3> positions( A(Vector3) );
	Vector<Vector2> texCoords( A(Vector2) );
	Vector<Vector3> normals( A(Vector3) );
	Vector<Face> faces( A(Face) );
	UInt idxMaterial = none;
	
	while ( GetLexem(stream) )
	{
		if ( !_strcmpi(_lexem.Begin(), "mtllib") )
		{
			String matLib = GetString( stream );
			IStream* streamMatLib = stream->GetDirectory()->GetStream( matLib );
			ReadMaterials( streamMatLib, format );
		}
		else if ( !_strcmpi(_lexem.Begin(), "usemtl") )
		{
			String name = GetString( stream );
			idxMaterial = GetMaterialIndex( name );
			if ( idxMaterial == none )
				throw Exception( String::Format(L"Failed to load mesh. Unknown material name {0,q}.", name) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "g") || !_strcmpi(_lexem.Begin(), "o") )
		{
			String name = GetString( stream );
			ModelDesc desc( name );
			_models.Add( desc );
		}
		else if ( !_strcmpi(_lexem.Begin(), "v") )
		{
			const Float x = GetFloat( stream );
			const Float y = GetFloat( stream );
			const Float z = GetFloat( stream );
			positions.Add( Vector3(x, y, z) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "vt") )
		{
			const Float x = GetFloat( stream );
			const Float y = GetFloat( stream );
			texCoords.Add( Vector2(x, 1.0f-y) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "vn") )
		{
			const Float x = GetFloat( stream );
			const Float y = GetFloat( stream );
			const Float z = GetFloat( stream );
			normals.Add( Vector3(x, y, -z) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "f") )
		{
			if ( _models.Size() == 0 )
			{
				_models.Add( ModelDesc(L"Default") );
			}

			ModelDesc& desc = _models.LastValue();
			desc.Material = idxMaterial;
			faces.Clear();

			Face f;
			while ( GetFace(stream, f) )
			{
				faces.Add( f );
			}

			// Split faces to triangles, if needed.
			UInt face[3] = {};
			const UInt idx = desc.Positions.Size();
			for ( UInt i = 0; i < faces.Size()-2; ++i )
			{
				face[0] = idx;
				face[1] = idx+i+1;
				face[2] = idx+i+2;
				desc.Indices.Add( face, 3 );
			}

			for ( UInt i = 0; i < faces.Size(); ++i )
			{
				desc.Positions.Add( positions[faces[i].IdxPos-1] );
				if ( faces[i].IdxNorm != none )
				{
					desc.Normals.Add( normals[faces[i].IdxNorm-1] );
				}
				if ( faces[i].IdxTex != none )
				{
					desc.TexCoords.Add( texCoords[faces[i].IdxTex-1] );
				}
			}
		}
	}

	// Create right type of mesh.
	ITriangleMesh* mesh = nullptr;
	const Bool soft = (scene == nullptr);
	if ( soft )
	{
		mesh = _sceneManager->CreateTriangleMesh( skeleton, _materials.Size() );
		if ( _materials.Size() == 1 )
		{
			_materials[0].Material = mesh->GetMaterial()->AsSimple()->AsOpaque();
		}
		else
		{
			IMultiMaterial* material = mesh->GetMaterial()->AsMulti();
			for ( UInt i = 0; i < _materials.Size(); ++i )
			{
				_materials[i].Material = material->GetSubset( i )->AsOpaque();
			}
		}
	}

	// Choose material.
	material = ChooseMaterial( stream, material, format, !soft );

	// Nullify skeleton, if any.
	if ( skeleton != nullptr )
	{
		skeleton = nullptr;
	}

	// Create mesh.
	if ( !soft )
	{
		if ( instanceCapacity > 0 )
			mesh = (ITriangleMesh*)scene->CreateTriangleMeshBatch( material, skeleton, instanceCapacity );
		else
			mesh = scene->CreateTriangleMesh( nullptr, stream->GetName(), material, skeleton );
	}

	// Prepare mesh.
	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		ModelDesc& desc = _models[i];
		const UInt vertexCount = desc.Positions.Size();
		const UInt indexCount = desc.Indices.Size();
		ITriangleSet* subset = mesh->CreateTriangleList( desc.Name, vertexCount, indexCount, false, Matrix4x4::Identity );
		subset->SetPositions (desc.Positions.Begin(), 0, vertexCount );
		subset->SetIndices( desc.Indices.Begin(), 0, indexCount );
		
		// Set normals.
		IScene* scene = mesh->GetScene();
		if ( (scene != nullptr) && scene->IsLit() )
		{
			if ( !desc.Normals.IsEmpty() )
			{
				subset->SetNormals( desc.Normals.Begin(), 0, desc.Normals.Size() );
			}
			else
			{
				Vector<Vector3> normals( A(Vector3) );
				normals.SetSize( desc.Positions.Size() );
				GenerateNormals( desc.Indices.Begin(), desc.Indices.Size(), desc.Positions.Begin(), normals.Begin(), false );
				subset->SetNormals( normals.Begin(), 0, normals.Size() );
			}
		}

		// Set texture coordinates.
		if ( !desc.TexCoords.IsEmpty() )
		{
			subset->SetTextureCoordinates( desc.TexCoords.Begin(), 0, desc.TexCoords.Size() );
		}
	}

	return mesh;
}

void ObjMeshCodec::Save( const ITriangleMesh* mesh, IStream* stream )
{
}


void ObjMeshCodec::ReadMaterials( IStream* stream, const PixelFormat& format )
{
	_char = 0;

	stream->Open( OpenMode::Read );
	while ( GetLexem(stream) )
	{
		if ( !_strcmpi(_lexem.Begin(), "newmtl") )
		{
			String name = GetString( stream );
			_materials.Add( MaterialDesc(name) );
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ka") )
		{
			const Float r = GetFloat( stream );
			const Float g = GetFloat( stream );
			const Float b = GetFloat( stream );
			_materials.Last()->Ambient = Color(r, g, b);
		}
		else if ( !_strcmpi(_lexem.Begin(), "Kd") )
		{
			const Float r = GetFloat( stream );
			const Float g = GetFloat( stream );
			const Float b = GetFloat( stream );
			_materials.Last()->Diffuse = Color(r, g, b);
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ke") )
		{
			const Float r = GetFloat( stream );
			const Float g = GetFloat( stream );
			const Float b = GetFloat( stream );
			_materials.Last()->Emissive = Color(r, g, b);
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ks") )
		{
			const Float r = GetFloat( stream );
			const Float g = GetFloat( stream );
			const Float b = GetFloat( stream );
			_materials.Last()->Specular = Color(r, g, b);
		}
		else if ( !_strcmpi(_lexem.Begin(), "Ns") )
		{
			const Float power = GetFloat( stream );
			_materials.Last()->SpecularPower = power;
		}
		else if ( !_strcmpi(_lexem.Begin(), "map_Kd") )
		{
			String mapDiffuse = GetString( stream );
			_materials.Last()->DiffuseTexture = mapDiffuse.StartsWith(L"map_") ? String::Empty : mapDiffuse;
		}
	}
	stream->Close();
}

UInt ObjMeshCodec::GetMaterialIndex( const String& name )
{
	for ( UInt i = 0; i < _materials.Size(); ++i )
	{
		if ( _materials[i].Name == name )
			return i;
	}
	return none;
}

IVisualMaterial* ObjMeshCodec::ChooseMaterial( IStream* stream, IVisualMaterial* material, const PixelFormat& format, Bool loadMaps )
{
	SynkroCall( "ObjMeshCodec::ChooseMaterial", stream->GetName() );

	if ( material != nullptr )
		return material;

	if ( _materialCache.ContainsKey(stream->ID()) )
	{
		material = _materialCache[stream->ID()];
	}
	else
	{
		PrepareMaterials( stream, format, loadMaps );
		if ( _materials.Size() > 1 )
		{
			IMultiMaterial* multiMaterial = _materialManager->CreateMultiMaterial( _models.Size() );
			for ( UInt i = 0; i < _models.Size(); ++i )
			{
				UInt idxMaterial = _models[i].Material;
				multiMaterial->SetSubset( i, _materials[idxMaterial].Material );
			}
			material = multiMaterial;
		}
		else if ( _materials.Size() == 1 )
		{
			material = _materials[0].Material;
		}
		else if (loadMaps)
		{
			material = (IVisualMaterial*)_materialManager->CreateOpaqueMaterial( LightingModel::Gouraud );
		}
		_materialCache[stream->ID()] = material;
	}

	return material;
}

void ObjMeshCodec::PrepareMaterials( IStream* stream, const PixelFormat& format, Bool loadMaps )
{
	SynkroCall( "ObjMeshCodec::PrepareMaterials", stream->GetName() );

	for ( UInt i = 0; i < _materials.Size(); ++i )
	{
		MaterialDesc& desc = _materials[i];

		if (_materials[i].Material == nullptr)
		{
			desc.Material = _materialManager->CreateOpaqueMaterial( LightingModel::Gouraud );
		}
		IOpaqueMaterial* material = desc.Material;

		// Set colors.
		material->SetAmbientColor( (desc.Ambient == Color::Black) ? desc.Diffuse : desc.Ambient );
		material->SetDiffuseColor( desc.Diffuse );
		material->SetEmissiveColor( desc.Emissive );
		material->SetSpecularColor( desc.Specular );
		material->SetSpecularPower( desc.SpecularPower );

		// Set texture, if any.
		if ( !desc.DiffuseTexture.IsEmpty() )
		{
			IImage* image = nullptr;
			if ( loadMaps )
			{
				IStream* streamTexture = stream->GetDirectory()->GetStream( desc.DiffuseTexture );
				if ( streamTexture == nullptr )
					throw Exception( String::Format(L"Failed to load mesh. File {0} not found.", desc.DiffuseTexture) );

				PixelFormat fmt = format;
				image = _imageManager->LoadImageAsync( streamTexture, fmt, nullptr );
				material->GetDiffuseMap()->SetImage( image );
			}
			material->GetDiffuseMap()->SetName( desc.DiffuseTexture );
			material->GetDiffuseMap()->SetAmount( 1.0f );
		}
	}
}

bool ObjMeshCodec::GetFace( IStream* stream, Face& face )
{
	int ret = 0;
	
	if ( PeekLexem(stream) )
	{
		ret = sscanf( _lexemCache.Begin(), "%d/%d/%d", &face.IdxPos, &face.IdxTex, &face.IdxNorm );
		if ( ret == 3 )
		{
			GetLexem( stream );
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d//%d", &face.IdxPos, &face.IdxNorm );
		if ( ret == 2 )
		{
			face.IdxTex = none;
			GetLexem( stream );
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d/%d", &face.IdxPos, &face.IdxTex );
		if ( ret == 2 )
		{
			face.IdxNorm = none;
			GetLexem( stream );
			return true;
		}

		ret = sscanf( _lexemCache.Begin(), "%d", &face.IdxPos );
		if ( ret == 1 )
		{
			face.IdxTex = none;
			face.IdxNorm = none;
			GetLexem( stream );
			return true;
		}
	}

	return false;
}

String ObjMeshCodec::GetString( IStream* stream )
{
	GetLexem( stream );
	return String( _lexem.Begin() );
}

Float ObjMeshCodec::GetFloat( IStream* stream )
{
	Float f;
	GetLexem( stream );
	sscanf( _lexem.Begin(), "%f", &f );
	return f;
}

bool ObjMeshCodec::GetLexem( IStream* stream )
{
	if ( !_lexemCache.IsEmpty() )
	{
		_lexem.SetSize( _lexemCache.Size() );
		for ( UInt i = 0; i < _lexem.Size(); ++i )
		{
			_lexem[i] = _lexemCache[i];
		}
		_lexemCache.Clear();
		return true;
	}

	char ch = 0;
	_lexem.Clear();

	while ( (ch = ReadChar(stream)) != 0 )
	{
		if ( ch == '#' )
		{
			SkipComment( stream );
			continue;
		}

		switch ( ch )
		{
			case ' ': case '\t': case '\r': case '\n':
				if ( _lexem.IsEmpty() )
					continue;

				_lexem.Add( 0 );
				return true;

			default:
				_lexem.Add( ch );
				break;
		}
	}

	return false;
}

bool ObjMeshCodec::PeekLexem( IStream* stream )
{
	if ( !_lexemCache.IsEmpty() )
		return true;

	char ch = 0;
	while ( (ch = ReadChar(stream)) != 0 )
	{
		if ( ch == '#' )
		{
			SkipComment( stream );
			continue;
		}

		switch ( ch )
		{
			case ' ': case '\t': case '\r': case '\n':
				if (_lexemCache.IsEmpty() )
					continue;

				_lexemCache.Add( 0 );
				return true;

			default:
				_lexemCache.Add( ch );
				break;
		}
	}

	return false;
}

void ObjMeshCodec::SkipComment( IStream* stream )
{
	char ch = 0;

	while ( (ch = ReadChar(stream)) != 0 )
	{
		if ( ch == '\r' )
		{
			ReadChar( stream );
			break;
		}
		else if ( ch == '\n')
		{
			break;
		}
	}
}

char ObjMeshCodec::ReadChar( IStream* stream )
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


} // scene


} // synkro
