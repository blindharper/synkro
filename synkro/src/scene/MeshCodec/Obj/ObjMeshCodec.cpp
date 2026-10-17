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
#include "ObjReader.h"
#include "ObjWriter.h"
#include "MtlReader.h"
#include "MtlWriter.h"
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <io/Path.h>
#include <core/CallStack.h>
#include <scene/ITriangleMeshSet.h>
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


ObjMeshCodec::ObjMeshCodec( ISceneManager* sceneManager, IMaterialManager* materialManager, IImageManager* imageManager ) :
	MeshCodecImpl<IMeshCodec>( sceneManager, materialManager, imageManager, nullptr ),
	_materials( A(ObjMaterial) ),
	_models( A(ObjModelDesc) ),
	_materialCache( A(MaterialCacheEntry) )
{
}

ITriangleMeshSet* ObjMeshCodec::Load( IScene* scene, IStreamSet* streams, const PixelFormat& format )
{
	SynkroCall( "ObjMeshCodec::Load", streams->Get(0)->GetName() );

	_models.Clear();
	_materials.Clear();

	for ( UInt i = 0; i < streams->GetSize(); ++i )
	{
		// Read model.
		IStream* stream = streams->Get( i );
		ObjReader objReader( stream );
		for ( UInt i = 0; i < objReader.GetModelCount(); ++i )
		{
			ObjModelDesc model;
			objReader.GetModel( i, model );
			_models.Add( model );
			break; // Only get the very first model from each stream.
		}

		// Read material from first model.
		if ( i == 0 )
		{
			String matLib = objReader.GetMaterialLibrary();
			IStream* streamMatLib = stream->GetDirectory()->GetStream( matLib );
			if ( streamMatLib == nullptr )
				throw Exception( String::Format(L"Failed to load mesh. Material library {0,q} not found.", matLib) );

			ObjMaterial descMaterial;
			MtlReader reader( streamMatLib );
			for ( UInt m = 0; m < reader.GetMaterialCount(); ++m )
			{
				reader.GetMaterial( m, descMaterial );
				_materials.Add( descMaterial );
			}
		}
	}

	// Assign material indices to models.
	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		UInt idxMaterial = GetMaterialIndex( _models[i].MaterialName );
		if ( idxMaterial == none )
			throw Exception( String::Format(L"Failed to load mesh. Unknown material {0,q}.", _models[i].MaterialName) );

		_models[i].Material = idxMaterial;
	}

	// Prepare material.
	IOpaqueMaterial* material = _materialManager->CreateOpaqueMaterial( LightingModel::Gouraud, true );

	// Set colors.
	ObjMaterial& desc = _materials[0];
	material->SetAmbientColor( (desc.Ambient == Color::Black) ? desc.Diffuse : desc.Ambient );
	material->SetDiffuseColor( desc.Diffuse );
	material->SetEmissiveColor( desc.Emissive );
	material->SetSpecularColor( desc.Specular );
	material->SetSpecularPower( desc.SpecularPower );

	// Set texture, if any.
	if ( !desc.DiffuseTexture.IsEmpty() )
	{
		IImage* image = nullptr;
		IStream* streamTexture = streams->Get(0)->GetDirectory()->GetStream( desc.DiffuseTexture );
		if ( streamTexture == nullptr )
			throw Exception( String::Format(L"Failed to load mesh. File {0} not found.", desc.DiffuseTexture) );

		PixelFormat fmt = format;
		image = _imageManager->LoadImageAsync( streamTexture, fmt, nullptr );
		material->GetDiffuseMap()->SetImage( image );
		material->GetDiffuseMap()->SetName( desc.DiffuseTexture );
		material->GetDiffuseMap()->SetAmount( 1.0f );
	}

	// Prepare geometry.
	ITriangleMeshSet* meshSet = scene->CreateTriangleMeshSet( nullptr, streams->Get(0)->GetName(), material );

	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		const ObjModelDesc& desc = _models[i];
		const UInt vertexCount = desc.Positions.Size();
		const UInt indexCount = desc.Indices.Size();
		ITriangleSet* subset = meshSet->CreateTriangleList( desc.Name, vertexCount, indexCount, false, Matrix4x4::Identity );
		subset->SetPositions (desc.Positions.Begin(), 0, vertexCount );
		subset->SetIndices( desc.Indices.Begin(), 0, indexCount );
		
		// Set normals.
		const IScene* scene = meshSet->GetScene();
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

	return meshSet;
}

ITriangleMesh* ObjMeshCodec::Load( IScene* scene, IStream* stream, const PixelFormat& format, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	SynkroCall( "ObjMeshCodec::Load", stream->GetName() );

	_models.Clear();
	_materials.Clear();

	// Read models.
	ObjReader objReader( stream );
	for ( UInt i = 0; i < objReader.GetModelCount(); ++i )
	{
		ObjModelDesc model;
		objReader.GetModel( i, model );
		_models.Add( model );
	}

	// Read materials.
	String matLib = objReader.GetMaterialLibrary();
	IStream* streamMatLib = stream->GetDirectory()->GetStream( matLib );
	if ( streamMatLib == nullptr )
		throw Exception( String::Format(L"Failed to load mesh. Material library {0,q} not found.", matLib) );

	ObjMaterial descMaterial;
	MtlReader reader( streamMatLib );
	for ( UInt m = 0; m < reader.GetMaterialCount(); ++m )
	{
		reader.GetMaterial( m, descMaterial );
		_materials.Add( descMaterial );
	}

	// Assign material indices to models.
	for ( UInt i = 0; i < _models.Size(); ++i )
	{
		UInt idxMaterial = GetMaterialIndex( _models[i].MaterialName );
		if ( idxMaterial == none )
			throw Exception( String::Format(L"Failed to load mesh. Unknown material {0,q}.", _models[i].MaterialName) );

		_models[i].Material = idxMaterial;
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
		const ObjModelDesc& desc = _models[i];
		const UInt vertexCount = desc.Positions.Size();
		const UInt indexCount = desc.Indices.Size();
		ITriangleSet* subset = mesh->CreateTriangleList( desc.Name, vertexCount, indexCount, false, Matrix4x4::Identity );
		subset->SetPositions (desc.Positions.Begin(), 0, vertexCount );
		subset->SetIndices( desc.Indices.Begin(), 0, indexCount );
		
		// Set normals.
		const IScene* scene = mesh->GetScene();
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
	// Write materials.
	Path path( stream->GetName() );
	String mtlName = path.GetNameWoExtension().Append( L".mtl" );
	P(IStream) streamMtl = stream->GetDirectory()->CreateStream( mtlName );
	MtlWriter mtlWriter( streamMtl );
	IVisualMaterial* material = mesh->GetMaterial();
	mtlWriter.WriteComment( L"Written by Synkro" );
	mtlWriter.WriteComment( L"https://github.com/blindharper/synkro" );
	mtlWriter.WriteComment( String::Format(L"Material Count: {0}", material->GetSubsetCount()) );
	mtlWriter.WriteCRLF();

	Vector<IOpaqueMaterial*> materials( A(IOpaqueMaterial*) );
	if ( material->GetSubsetCount() > 1 )
	{
		IMultiMaterial* multiMaterial = material->AsMulti();
		for ( UInt i = 0; i < multiMaterial->GetSubsetCount(); ++i )
		{
			materials.Add( multiMaterial->GetSubset( i )->AsSimple()->AsOpaque() );
		}
	}
	else
	{
		materials.Add( material->AsSimple()->AsOpaque() );
	}
	for ( UInt i = 0; i < materials.Size(); ++i )
	{
		ObjMaterial desc( materials[i] );
		mtlWriter.Write( desc );
	}

	// Write mesh.
	ObjWriter objWriter( stream );
	objWriter.WriteComment( L"Written by Synkro" );
	objWriter.WriteComment( L"https://github.com/blindharper/synkro" );
	objWriter.WriteCRLF();
	objWriter.WriteMaterialLibrary( mtlName );

	for ( UInt i = 0; i < mesh->GetSubsetCount(); ++i )
	{
		ITriangleSet* subset = mesh->GetSubset( i )->AsTriangleSet();
		ObjModelDesc desc( subset, mesh->GetSubsetName(i) );
		objWriter.WriteSubset( desc.Name );
		objWriter.WritePositions( desc.Positions );
		objWriter.WriteTexCoords( desc.TexCoords );
		objWriter.WriteNormals( desc.Normals );
		objWriter.WriteMaterial( materials[i]->GetName() );
		// TODO: Faces.
	}
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
		else if ( loadMaps )
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
		ObjMaterial& desc = _materials[i];

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


} // scene


} // synkro
