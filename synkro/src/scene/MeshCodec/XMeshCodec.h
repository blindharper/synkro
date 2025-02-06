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
#ifndef _SYNKRO_SCENE_XMESHCODEC_
#define _SYNKRO_SCENE_XMESHCODEC_


#include "config.h"
#include "MeshCodecImpl.h"
#include <scene/IMeshCodec.h>
#include <scene/ITriangleSet.h>
#include <mat/IMultiMaterial.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/IMaterialMap.h>
#include <io/IStream.h>
#include <lang/Map.h>
#include <lang/Stack.h>
#include <lang/Vector.h>
#include <math/Vector2.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


// DirectX mesh codec implementation.
class XMeshCodec :
	public MeshCodecImpl<IMeshCodec>
{
public:
	// Constructor.
	XMeshCodec( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager, anim::IAnimationSystem* animationSystem );

	// IMeshCodec methods.
	ITriangleMesh*											Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	ISkeleton*												Load( io::IStream* stream );
	void													Save( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode );
	void													Save( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode );

private:
	enum TemplateType
	{
		TEMPLATE_ANIMATION,
		TEMPLATE_ANIMATION_KEY,
		TEMPLATE_ANIMATION_SET,
		TEMPLATE_COLOR_RGB,
		TEMPLATE_COLOR_RGBA,
		TEMPLATE_FRAME,
		TEMPLATE_FRAME_TRANSFORM_MATRIX,
		TEMPLATE_MATERIAL,
		TEMPLATE_MATRIX4X4,
		TEMPLATE_MESH,
		TEMPLATE_MESH_FACE,
		TEMPLATE_MESH_MATERIAL_LIST,
		TEMPLATE_MESH_NORMALS,
		TEMPLATE_MESH_TEXTURE_COORDS,
		TEMPLATE_SKIN_WEIGHTS,
		TEMPLATE_TEXTURE_FILENAME,
		TEMPLATE_TIMED_FLOAT_KEYS,
		TEMPLATE_VECTOR,
		TEMPLATE_XSKIN_MESH_HEADER,
	};

	enum TrackType
	{
		TRACK_ORIENTATION	= 0,
		TRACK_SCALE			= 1,
		TRACK_POSITION		= 2,
		TRACK_MATRIX		= 4,
	};

	struct FrameDesc
	{
		FrameDesc( UInt parentIndex, const lang::String& name, Byte index ) :
			ParentIndex( parentIndex ),
			Name( name ),
			Index( index ),
			WorldDirty( true )
		{
		}

		FrameDesc() :
			ParentIndex( none ),
			Index( 0 ),
			WorldDirty( false )
		{
		}

		void GetWorldTransform( const lang::Vector<FrameDesc>& frames, math::Matrix4x4& transform ) const
		{
			if ( WorldDirty )
			{
				math::Matrix4x4 parentTransform;
				if ( ParentIndex != none )
				{
					const FrameDesc& parent = frames[ParentIndex];
					parent.GetWorldTransform( frames, parentTransform );
				}
				WorldTransform = parentTransform * Transform;
				WorldDirty = false;
			}
			transform = WorldTransform;
		}

		UInt					ParentIndex;
		lang::String			Name;
		math::Matrix4x4			Transform;
		mutable math::Matrix4x4	WorldTransform;
		math::Matrix4x4			Offset;
		Byte					Index;
		mutable Bool			WorldDirty;
	};

	struct VertexDesc
	{
		VertexDesc() :
			BoneCount( 0 )
		{
		}

		Byte	Bones[16];
		Float	Weights[16];
		UInt	BoneCount;
	};

	struct SubMaterialDesc
	{
		SubMaterialDesc( UInt modelIndex, UInt materialIndex ) :
			ModelIndex( modelIndex ),
			MaterialIndex( materialIndex )
		{
		}

		SubMaterialDesc( const lang::String& name ) :
			ModelIndex( none ),
			MaterialIndex( none ),
			Name( name )
		{
		}

		SubMaterialDesc() :
			ModelIndex( none ),
			MaterialIndex( none )
		{
		}

		UInt						ModelIndex;
		UInt						MaterialIndex;
		lang::String				Name;
		P(mat::IOpaqueMaterial)	Material;
	};

	struct MaterialDesc
	{
		MaterialDesc( mat::IOpaqueMaterial* material ) :
			Colors( A(Float) )
		{
			img::Color color;
			material->GetDiffuseColor( color );
			Colors.Add( &color.R, 3 );
			Colors.Add( 1.0f );
			Colors.Add( material->GetSpecularPower() );
			material->GetSpecularColor( color );
			Colors.Add( &color.R, 3 );
			material->GetEmissiveColor( color );
			Colors.Add( &color.R, 3 );
			Texture = material->GetDiffuseMap()->GetName();
		}

		MaterialDesc() :
			Colors( A(Float) )
		{
		}

		Bool operator==( const MaterialDesc& other ) const
		{
			if ( !this->Texture.EqualsTo(other.Texture, true) )
				return false;

			if ( this->Colors.Size() != other.Colors.Size() )
				return false;

			for ( UInt i = 0; i < this->Colors.Size(); ++i )
			{
				if ( this->Colors[i] != other.Colors[i] )
					return false;
			}

			return true;
		}

		lang::Vector<Float>		Colors;
		lang::String			Texture;
	};

	struct BoneDesc
	{
		BoneDesc() :
			Indices( A(DWORD) ),
			Weights( A(Float) ),
			Offset( A(Float) )
		{
		}

		lang::Vector<DWORD>		Indices;
		lang::Vector<Float>		Weights;
		lang::Vector<Float>		Offset;
		lang::String			Name;
	};

	struct ModelDesc
	{
		ModelDesc( const scene::ITriangleSet* subset, const lang::String& name ) :
			Vertices( A(VertexDesc) ),
			Bones( A(BoneDesc) ),
			FrameIndex( none ),
			Positions( A(math::Vector3) ),
			Faces( A(DWORD) ),
			Normals( A(math::Vector3) ),
			FaceNormals( A(DWORD) ),
			TexCoords( A(math::Vector2) ),
			Subsets( A(lang::Range) ),
			Materials( A(MaterialDesc) ),
			BonesPerVertex( 0 ),
			Name( name )
		{
			Init( subset );
			// TODO: Materials
		}

		ModelDesc( const scene::ITriangleMesh* mesh ) :
			Vertices( A(VertexDesc) ),
			Bones( A(BoneDesc) ),
			FrameIndex( none ),
			Positions( A(math::Vector3) ),
			Faces( A(DWORD) ),
			Normals( A(math::Vector3) ),
			FaceNormals( A(DWORD) ),
			TexCoords( A(math::Vector2) ),
			Subsets( A(lang::Range) ),
			Materials( A(MaterialDesc) ),
			BonesPerVertex( 0 ),
			Name( mesh->GetName() )
		{
			Init( mesh->GetSubset(0)->AsTriangleSet() );
			Init( mesh->GetMaterial() );
			Subsets.SetSize( mesh->GetSubsetCount() );
			for ( UInt i = 0; i < Subsets.Size(); ++i )
			{
				mesh->GetSubset(i)->GetElementRange( Subsets[i] );
			}
		}

		ModelDesc( UInt frameIndex, const lang::String& name ) :
			Vertices( A(VertexDesc) ),
			Bones( A(BoneDesc) ),
			FrameIndex( frameIndex ),
			Positions( A(math::Vector3) ),
			Faces( A(DWORD) ),
			Normals( A(math::Vector3) ),
			FaceNormals( A(DWORD) ),
			TexCoords( A(math::Vector2) ),
			Subsets( A(lang::Range) ),
			Materials( A(MaterialDesc) ),
			BonesPerVertex( 0 ),
			Name( name )
		{
		}

		ModelDesc() :
			Vertices( A(VertexDesc) ),
			Bones( A(BoneDesc) ),
			FrameIndex( none ),
			Positions( A(math::Vector3) ),
			Faces( A(DWORD) ),
			Normals( A(math::Vector3) ),
			FaceNormals( A(DWORD) ),
			TexCoords( A(math::Vector2) ),
			Subsets( A(lang::Range) ),
			Materials( A(MaterialDesc) ),
			BonesPerVertex( 0 )
		{
		}

		void Init( const scene::ITriangleSet* subset )
		{
			lang::Vector<UInt> indices( A(UInt) );
			indices.SetSize( subset->GetIndexCount() );
			subset->GetIndices( indices.Begin(), 0, indices.Size() );
			const UInt faceCount = indices.Size()/3;
			Faces.SetSize( 4*faceCount );
			for ( UInt i = 0; i < faceCount; ++i )
			{
				Faces[4*i] = 3;
				Faces[4*i+1] = indices[3*i];
				Faces[4*i+2] = indices[3*i+1];
				Faces[4*i+3] = indices[3*i+2];
			}

			Positions.SetSize( subset->GetVertexCount() );
			subset->GetPositions( Positions.Begin(), 0, Positions.Size() );

			Normals.SetSize( subset->GetVertexCount() );
			if ( !subset->GetNormals(Normals.Begin(), 0, Normals.Size()) )
			{
				Normals.Clear();
			}

			TexCoords.SetSize( subset->GetVertexCount() );
			if ( !subset->GetTextureCoordinates(TexCoords.Begin(), 0, TexCoords.Size()) )
			{
				TexCoords.Clear();
			}
		}

		void Init( mat::IVisualMaterial* material )
		{
			if ( material->GetSubsetCount() > 1 )
			{
				mat::IMultiMaterial* multiMaterial = (mat::IMultiMaterial*)material;
				for ( UInt i = 0; i < multiMaterial->GetSubsetCount(); ++i )
				{
					Materials.Add( MaterialDesc((mat::IOpaqueMaterial*)multiMaterial->GetSubset(i)) );
				}
			}
			else
			{
				Materials.Add( MaterialDesc((mat::IOpaqueMaterial*)material) );
			}
		}

		lang::String GetName( const lang::Vector<FrameDesc>& frames )
		{
			lang::String name;
			for ( UInt idx = FrameIndex; idx != none; idx = frames[idx].ParentIndex )
			{
				name = frames[idx].Name;
				if ( !name.IsEmpty() )
					return name;
			}
			return Name;
		}

		lang::Vector<VertexDesc>		Vertices;
		lang::Vector<BoneDesc>			Bones;
		UInt							FrameIndex;
		lang::Vector<math::Vector3>		Positions;
		lang::Vector<DWORD>				Faces;
		lang::Vector<math::Vector3>		Normals;
		lang::Vector<DWORD>				FaceNormals;
		lang::Vector<math::Vector2>		TexCoords;
		lang::Vector<lang::Range>		Subsets;
		lang::Vector<MaterialDesc>		Materials;
		UInt							BonesPerVertex;
		lang::String					Name;
	};

	struct AnimationTrackDesc
	{
		AnimationTrackDesc() :
			Data( A(Byte) )
		{
		}

		lang::Vector<Byte>	Data;
	};

	struct AnimationDesc
	{
		AnimationDesc() :
			Tracks( A(AnimationTrackDesc) )
		{
		}

		lang::Vector<AnimationTrackDesc>	Tracks;
		lang::String						Name;
	};

	struct AnimationSetDesc
	{
		AnimationSetDesc( const lang::String& name ) :
			Animations( A(AnimationDesc) ),
			Name( name )
		{
		}

		AnimationSetDesc() :
			Animations( A(AnimationDesc) )
		{
		}

		lang::Vector<AnimationDesc>	Animations;
		lang::String				Name;
	};

	struct AnimationSetCollection
	{
		AnimationSetCollection() :
			Sets( A(P(anim::IAnimationSet)) )
		{
		}

		lang::Vector<P(anim::IAnimationSet)>	Sets;
	};

	typedef lang::MapPair<lang::String, MaterialDesc>		MaterialEntry;
	typedef lang::MapPair<lang::String, Byte>				IndexEntry;
	typedef lang::MapPair<Byte, lang::String>				IndexEntry2;
	typedef lang::MapPair<UInt, P(mat::IVisualMaterial)>	MaterialCacheEntry;
	typedef lang::MapPair<UInt, AnimationSetCollection>		AnimationCacheEntry;

	lang::MapCI<lang::String, MaterialDesc>					_materials;
	lang::Vector<SubMaterialDesc>							_subMaterials;
	lang::Vector<ModelDesc>									_models;
	lang::Vector<AnimationSetDesc>							_animationSets;
	lang::Vector<FrameDesc>									_frames;
	lang::Stack<UInt>										_frameStack;
	lang::MapCI<lang::String, Byte>							_templates;
	lang::Map<Byte, lang::String>							_templates2;
	lang::Map<lang::String, Byte>							_frameIndices;
	lang::Map<UInt, P(mat::IVisualMaterial)>				_materialCache;
	lang::Map<UInt, AnimationSetCollection>					_animationCache;
	lang::Vector<Byte>										_buffer;
	lang::Vector<char>										_lexem;
	lang::String											_lastMaterialName;
	UInt													_indent;
	WORD													_token;
	char													_char;

	void													RegisterTemplates();
	void													RegisterTemplate( Byte type, const lang::String& name );
	void													Put( lang::Vector<Byte>& data, DWORD value );
	void													Put( lang::Vector<Byte>& data, Float value );
	DWORD													Read( io::IStream* stream );
	void													ReadBinary( io::IStream* stream, Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	void													ReadText( io::IStream* stream, Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	WORD													PeekToken( io::IStream* stream );
	char													PeekChar( io::IStream* stream );
	WORD													GetToken( io::IStream* stream );
	void													Skip( io::IStream* stream, DWORD count );
	char													ReadChar( io::IStream* stream );
	DWORD													ReadDwordBinary( io::IStream* stream );
	DWORD													ReadDwordText( io::IStream* stream );
	Float													ReadFloatBinary( io::IStream* stream );
	Float													ReadFloatText( io::IStream* stream );
	lang::String											ReadNameBinary( io::IStream* stream );
	void													ReadArrayBinary( io::IStream* stream, lang::Vector<DWORD>& array, DWORD count );
	void													ReadArrayText( io::IStream* stream, lang::Vector<DWORD>& array, DWORD count );
	void													ReadFacesText( io::IStream* stream, lang::Vector<DWORD>& array, DWORD count );
	void													ReadArrayBinary( io::IStream* stream, lang::Vector<Float>& array, DWORD count );
	void													ReadArrayText( io::IStream* stream, lang::Vector<Float>& array, DWORD count );
	void													ReadArrayBinary( io::IStream* stream, lang::Vector<math::Vector2>& array, DWORD count );
	void													ReadArrayText( io::IStream* stream, lang::Vector<math::Vector2>& array, DWORD count );
	void													ReadArrayBinary( io::IStream* stream, lang::Vector<math::Vector3>& array, DWORD count );
	void													ReadArrayText( io::IStream* stream, lang::Vector<math::Vector3>& array, DWORD count );
	void													ReadTemplateDefinitionBinary( io::IStream* stream );
	Byte													ReadTemplateName( io::IStream* stream );
	lang::String											ReadStringBinary( io::IStream* stream );
	lang::String											ReadStringText( io::IStream* stream );
	lang::String											ReadReferenceBinary( io::IStream* stream );
	lang::String											ReadReferenceText( io::IStream* stream );
	void													ReadTemplateBinary( io::IStream* stream, Byte type, const lang::String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	void													ReadTemplateText( io::IStream* stream, Byte type, const lang::String& name, Bool loadMaterial, Bool loadSkin, Bool loadAnimations );
	void													ReadFrameText( io::IStream* stream, const lang::String& name );
	void													ReadFrameTransformMatrixText( io::IStream* stream );
	void													ReadMeshBinary( io::IStream* stream, const lang::String& name );
	void													ReadMeshText( io::IStream* stream, const lang::String& name );
	void													ReadMeshNormalsBinary( io::IStream* stream );
	void													ReadMeshNormalsText( io::IStream* stream );
	void													ReadMeshTextureCoordsBinary( io::IStream* stream );
	void													ReadMeshTextureCoordsText( io::IStream* stream );
	void													ReadMeshMaterialListBinary( io::IStream* stream );
	void													ReadMeshMaterialListText( io::IStream* stream );
	void													ReadMaterialBinary( io::IStream* stream, const lang::String& name );
	void													ReadMaterialText( io::IStream* stream, const lang::String& name, Bool load );
	void													ReadTextureFilenameBinary( io::IStream* stream );
	void													ReadTextureFilenameText( io::IStream* stream, Bool load );
	void													ReadMeshSkinHeaderText( io::IStream* stream, Bool load );
	void													ReadSkinWeightsText( io::IStream* stream, Bool load );
	void													ReadAnimationSet( io::IStream* stream, const lang::String& name, Bool load );
	void													ReadAnimation( io::IStream* stream, Bool load );
	void													ReadAnimationKeyText( io::IStream* stream, Bool load );
	void													ReadIntegerList( io::IStream* stream );
	void													ReadFloatList( io::IStream* stream );
	void													ReadUnknownBinary( io::IStream* stream );
	void													ReadUnknownText( io::IStream* stream );
	void													Write( io::IStream* stream, const core::DataMode& mode );
	void													WriteCRLF( io::IStream* stream );
	void													WriteIndent( io::IStream* stream );
	void													WriteChar( io::IStream* stream, char value );
	void													WriteToken( io::IStream* stream, WORD token );
	void													WriteDwordBinary( io::IStream* stream, DWORD value );
	void													WriteDwordText( io::IStream* stream, DWORD value );
	void													WriteFloatBinary( io::IStream* stream, FLOAT value );
	void													WriteFloatText( io::IStream* stream, FLOAT value );
	void													WriteName( io::IStream* stream, const lang::String& name );
	void													WriteArrayBinary( io::IStream* stream, const lang::Vector<DWORD>& array );
	void													WriteArrayText( io::IStream* stream, const lang::Vector<DWORD>& array );
	void													WriteFacesText( io::IStream* stream, const lang::Vector<DWORD>& array );
	void													WriteArrayBinary( io::IStream* stream, const lang::Vector<math::Vector2>& array );
	void													WriteArrayText( io::IStream* stream, const lang::Vector<math::Vector2>& array );
	void													WriteArrayBinary( io::IStream* stream, const lang::Vector<math::Vector3>& array );
	void													WriteArrayText( io::IStream* stream, const lang::Vector<math::Vector3>& array );
	void													BeginTemplateBinary( io::IStream* stream, Byte type, const lang::String& name );
	void													BeginTemplateText( io::IStream* stream, Byte type, const lang::String& name );
	void													EndTemplateBinary( io::IStream* stream );
	void													EndTemplateText( io::IStream* stream );
	void													WriteStringBinary( io::IStream* stream, const lang::String& str );
	void													WriteStringText( io::IStream* stream, const lang::String& str );
	void													WriteMeshBinary( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshText( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshNormalsBinary( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshNormalsText( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshTextureCoordsBinary( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshTextureCoordsText( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshMaterialListBinary( io::IStream* stream, const ModelDesc& desc );
	void													WriteMeshMaterialListText( io::IStream* stream, const ModelDesc& desc );
	void													WriteMaterialBinary( io::IStream* stream, const MaterialDesc& desc );
	void													WriteMaterialText( io::IStream* stream, const MaterialDesc& desc );
	void													WriteTextureFilenameBinary( io::IStream* stream, const lang::String& filename );
	void													WriteTextureFilenameText( io::IStream* stream, const lang::String& filename );
	mat::IVisualMaterial*									ChooseMaterial( io::IStream* stream, mat::IVisualMaterial* material, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMaterials( io::IStream* stream, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMesh( ITriangleMesh* mesh );
	void													PrepareSkeleton( ISkeleton* skeleton );
	void													PrepareSkin( ITriangleMesh* mesh );
	void													PrepareAnimation( io::IStream* stream, ISkeleton* skeleton );
	DWORD*													ReadTransformTrack( anim::IAnimation* animation, DWORD* ptr );
	DWORD*													ReadPositionTrack( anim::IAnimation* animation, DWORD* ptr );
	DWORD*													ReadOrientationTrack( anim::IAnimation* animation, DWORD* ptr );
	DWORD*													ReadScaleTrack( anim::IAnimation* animation, DWORD* ptr );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHCODEC_
