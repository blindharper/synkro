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
#ifndef _SYNKRO_SCENE_OBJMESHCODEC_
#define _SYNKRO_SCENE_OBJMESHCODEC_


#include "config.h"
#include "MeshCodecImpl.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <lang/Formatter.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <scene/IMeshCodec.h>
#include <scene/NormalBuilder.h>
#include <mat/IOpaqueMaterial.h>


namespace synkro
{


namespace scene
{


// Wavefront Advanced Visualizer mesh codec.
class ObjMeshCodec :
	public MeshCodecImpl<IMeshCodec>,
	public NormalBuilder
{
public:
	// Constructor.
	ObjMeshCodec( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager, anim::IAnimationSystem* animationSystem );

	// IMeshCodec methods.
	ITriangleMesh*											Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	void													Save( const ITriangleMesh* mesh, io::IStream* stream );

private:
	struct MaterialDesc
	{
		MaterialDesc( const lang::String& name ) :
			Name( name )
		{
		}

		MaterialDesc()
		{
		}

		lang::String				Name;
		img::Color					Ambient;
		img::Color					Diffuse;
		img::Color					Emissive;
		img::Color					Specular;
		Float						SpecularPower;
		lang::String				DiffuseTexture;
		P(mat::IOpaqueMaterial)	Material;
	};

	struct ModelDesc
	{
		ModelDesc( const lang::String& name ) :
			Positions( A(math::Vector3) ),
			Normals( A(math::Vector3) ),
			TexCoords( A(math::Vector2) ),
			Indices( A(UInt) ),
			Name( name ),
			Material( none )
		{
		}

		ModelDesc() :
			Positions( A(math::Vector3) ),
			Normals( A(math::Vector3) ),
			TexCoords( A(math::Vector2) ),
			Indices( A(UInt) ),
			Material( none )
		{
		}

		lang::Vector<math::Vector3>	Positions;
		lang::Vector<math::Vector3>	Normals;
		lang::Vector<math::Vector2>	TexCoords;
		lang::Vector<UInt>			Indices;
		lang::String				Name;
		UInt						Material;
	};

	struct Face
	{
		Face() :
			IdxPos( none ),
			IdxTex( none ),
			IdxNorm( none )
		{
		}

		UInt IdxPos;
		UInt IdxTex;
		UInt IdxNorm;
	};

	typedef lang::MapPair<UInt, P(mat::IVisualMaterial)>	MaterialCacheEntry;

	lang::Vector<MaterialDesc>								_materials;
	lang::Vector<ModelDesc>									_models;
	lang::Map<UInt, P(mat::IVisualMaterial)>				_materialCache;
	lang::Vector<char>										_lexem;
	lang::Vector<char>										_lexemCache;
	char													_char;

	void													ReadMaterials( io::IStream* stream, const img::PixelFormat& format );
	UInt													GetMaterialIndex( const lang::String& name );
	mat::IVisualMaterial*									ChooseMaterial( io::IStream* stream, mat::IVisualMaterial* material, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMaterials( io::IStream* stream, const img::PixelFormat& format, Bool loadMaps );
	bool													GetFace( io::IStream* stream, Face& face );
	lang::String											GetString( io::IStream* stream );
	Float													GetFloat( io::IStream* stream );
	bool													GetLexem( io::IStream* stream );
	bool													PeekLexem( io::IStream* stream );
	void													SkipComment( io::IStream* stream );
	char													ReadChar( io::IStream* stream );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJMESHCODEC_
