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
#include "../MeshCodecImpl.h"
#include "ObjMaterial.h"
#include "ObjMesh.h"
#include <lang/Map.h>
#include <scene/IMeshCodec.h>
#include <scene/NormalBuilder.h>


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
	ObjMeshCodec( ISceneManager* sceneManager, mat::IMaterialManager* materialManager, img::IImageManager* imageManager );

	// IMeshCodec methods.
	ITriangleMeshSet*										Load( IScene* scene, io::IStreamSet* streams, const img::PixelFormat& format );
	ITriangleMesh*											Load( IScene* scene, io::IStream* stream, const img::PixelFormat& format, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	void													Save( const ITriangleMesh* mesh, io::IStream* stream );

private:
	typedef lang::MapPair<UInt, P(mat::IVisualMaterial)>	MaterialCacheEntry;

	lang::Vector<ObjMaterial>								_materials;
	lang::Vector<ObjModelDesc>								_models;
	lang::Map<UInt, P(mat::IVisualMaterial)>				_materialCache;

	UInt													GetMaterialIndex( const lang::String& name );
	mat::IVisualMaterial*									ChooseMaterial( io::IStream* stream, mat::IVisualMaterial* material, const img::PixelFormat& format, Bool loadMaps );
	void													PrepareMaterials( io::IStream* stream, const img::PixelFormat& format, Bool loadMaps );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OBJMESHCODEC_
