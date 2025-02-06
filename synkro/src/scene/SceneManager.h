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
// Purpose: Scene manager implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_SCENEMANAGER_
#define _SYNKRO_SCENE_SCENEMANAGER_


#include "config.h"
#include <lang/Map.h>
#include <scene/ISceneManager.h>
#include <scene/IMeshBuilder.h>
#include <scene/IMeshCodec.h>
#include <scene/ISceneFactory.h>
#include <mat/IVisualMaterial.h>
#include "BaseSceneManager.h"
#include "Scene.h"


namespace synkro
{


namespace scene
{


// Scene manager implementation.
class SceneManager :
	public core::ObjectImpl<ISceneManager>,
	BaseSceneManager,
	public Logger
{
public:
	// Constructor & destructor.
	SceneManager( core::IContext* context, diag::ILog* log );
	~SceneManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// ISceneManager methods.
	ISceneEx*												CreateScene( const SceneType& type, const lang::String& name, const DebugMode& debugMode, Bool lit );
	ISceneEx*												CreateScene( const lang::String& name, const DebugMode& debugMode, Bool lit );
	ISkeleton*												CreateSkeleton();
	ITriangleMesh*											CreateTriangleMesh( ISkeleton* skeleton, UInt subsetCount );
	ISkeleton*												LoadSkeleton( io::IStream* stream, const MeshCodec& type );
	ISkeleton*												LoadSkeleton( io::IStream* stream );
	ITriangleMesh*											LoadMesh( io::IStream* stream, ISkeleton* skeleton, const MeshCodec& type );
	ITriangleMesh*											LoadMesh( io::IStream* stream, ISkeleton* skeleton );
	void													BuildMesh( ILineMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													BuildMesh( IPointMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													BuildMesh( ITriangleMesh* mesh, const MeshBuilder& type, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	UInt													GetSceneCount() const;
	ISceneEx*												GetScene( UInt index ) const;
	ISceneEx*												GetScene( const lang::String& name ) const;

	// BaseSceneManager methods.
	ITriangleMesh*											LoadMesh( IScene* scene, io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type );
	void													SaveMesh( const ITriangleMesh* mesh, io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													SaveSkeleton( const ISkeleton* skeleton, io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );

	// Other methods.
	void													RegisterSceneFactory( ISceneFactory* factory );
	void													RegisterMeshBuilder( IMeshBuilderFactory* factory );
	void													RegisterMeshCodec( IMeshCodecFactory* factory );
	Bool													Call( Scene* scene );

private:
	typedef lang::MapPair<UInt, ISceneFactory*>				FactoryEntry;
	typedef lang::MapPair<UInt, P(IMeshBuilder)>			BuilderEntry;
	typedef lang::MapPair<UInt, P(IMeshCodec)>				CodecEntry;

	lang::Vector<P(Scene)>									_scenes;
	lang::Map<UInt, ISceneFactory*>							_sceneFactories;
	lang::Map<UInt, P(IMeshBuilder)>						_meshBuilders;
	lang::Map<UInt, P(IMeshCodec)>							_meshCodecs;
	core::IContext*											_context;

	IMeshBuilder*											GetMeshBuilder( IMesh* mesh, const MeshBuilder& type );
};


#include "SceneManager.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SCENEMANAGER_
