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
// Purpose: DirectX mesh description.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESH_
#define _SYNKRO_SCENE_XMESH_


#include "config.h"
#include <mat/IMultiMaterial.h>
#include <mat/IOpaqueMaterial.h>
#include <mat/IMaterialMap.h>
#include <scene/IMeshCodec.h>
#include <scene/ITriangleSet.h>
#include <io/IStream.h>
#include <core/DataMode.h>
#include <lang/Map.h>
#include <lang/Stack.h>
#include <lang/Vector.h>
#include <math/Vector2.h>
#include <math/Matrix4x4.h>
#include "../MeshCodecImpl.h"


#define XOFFILE_FORMAT_MAGIC ((long)'x' + ((long)'o' << 8) + ((long)'f' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_VERSION ((long)'0' + ((long)'3' << 8) + ((long)'0' << 16) + ((long)'3' << 24))
#define XOFFILE_FORMAT_BINARY ((long)'b' + ((long)'i' << 8) + ((long)'n' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_BINARY_COMPRESSED ((long)'b' + ((long)'z' << 8) + ((long)'i' << 16) + ((long)'p' << 24))
#define XOFFILE_FORMAT_TEXT ((long)'t' + ((long)'x' << 8) + ((long)'t' << 16) + ((long)' ' << 24))
#define XOFFILE_FORMAT_TEXT_COMPRESSED ((long)'t' + ((long)'z' << 8) + ((long)'i' << 16) + ((long)'p' << 24))
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


namespace synkro
{


namespace scene
{


// DirectX mesh file header.
struct XMeshHeader
{
	UInt	dwMagic;
	UInt	dwVersion;
	UInt	dwFormatType;
	UInt	dwFloatSize;
};

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

	UInt					ModelIndex;
	UInt					MaterialIndex;
	lang::String			Name;
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
		Indices( A(UInt) ),
		Weights( A(Float) ),
		Offset( A(Float) )
	{
	}

	lang::Vector<UInt>		Indices;
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
		Faces( A(UInt) ),
		Normals( A(math::Vector3) ),
		FaceNormals( A(UInt) ),
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
		Faces( A(UInt) ),
		Normals( A(math::Vector3) ),
		FaceNormals( A(UInt) ),
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
		Faces( A(UInt) ),
		Normals( A(math::Vector3) ),
		FaceNormals( A(UInt) ),
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
		Faces( A(UInt) ),
		Normals( A(math::Vector3) ),
		FaceNormals( A(UInt) ),
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
	lang::Vector<UInt>				Faces;
	lang::Vector<math::Vector3>		Normals;
	lang::Vector<UInt>				FaceNormals;
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


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESH_
