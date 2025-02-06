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
// Purpose: Scene implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_SCENE_
#define _SYNKRO_SCENE_SCENE_


#include "config.h"
#include <anim/AnimationSystem.h>
#include <audio/IAudioSystemEx.h>
#include <audio/IAudioPlayer.h>
#include <audio/IAudioEnvironment.h>
#include <scene/ISceneEx.h>
#include <scene/ISceneAnimationController.h>
#include <scene/IFog.h>
#include <io/IStreamSystem.h>
#include <img/IImage.h>
#include <img/ImageManager.h>
#include <gfx/GraphicsDevice.h>
#include <gfx/ISkyRenderObject.h>
#include <gfx/IStructuredBuffer.h>
#include <core/IContext.h>
#include "DebugHelper.h"
#include "BaseSceneManager.h"
#include "BaseScene.h"
#include "BaseMeshBatch.h"
#include "BaseLight.h"


namespace synkro
{


namespace scene
{


// Scene node implementation.
class Scene :
	public core::ObjectImpl<ISceneEx>,
	public BaseScene,
	public Logger
{
public:
	// Constructor.
	Scene( IScene* scene, BaseSceneManager* sceneManager, core::IContext* context, const lang::String& name, const DebugMode& debugMode, diag::ILog* log );

	// IScene methods.
	ITriangleMesh*											CreateTriangleMesh( INode* parent, const lang::String& name, mat::IVisualMaterial* material, ISkeleton* skeleton );
	ITriangleMeshBatch*										CreateTriangleMeshBatch( mat::IVisualMaterial* material, ISkeleton* skeleton, UInt capacity );
	ITriangleMesh*											PickMesh( const math::Vector3& origin, const math::Vector3& direction, Float* distance ) const;
	gfx::ISceneRenderQueue*									GetRenderQueue() const;
	Bool													IsLit() const;

	// ISceneEx methods.
	ISceneAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	INode*													CreateDummy( INode* parent, const lang::String& name );
	ICurve*													CreateCurve( INode* parent, const lang::String& name );
	ICamera*												CreateCamera( INode* parent, const lang::String& name );
	IOmniLight*												CreateOmniLight( INode* parent, const lang::String& name );
	IConeLight*												CreateConeLight( INode* parent, const lang::String& name );
	IDirectLight*											CreateDirectLight( INode* parent, const lang::String& name );
	IOmniSound*												CreateOmniSound( INode* parent, const lang::String& name, io::IStream* stream, const sound::SoundCodec& type );
	IOmniSound*												CreateOmniSound( INode* parent, const lang::String& name, io::IStream* stream );
	IConeSound*												CreateConeSound( INode* parent, const lang::String& name, io::IStream* stream, const sound::SoundCodec& type );
	IConeSound*												CreateConeSound( INode* parent, const lang::String& name, io::IStream* stream );
	IPointMesh*												CreatePointMesh( INode* parent, const lang::String& name );
	IPointMeshBatch*										CreatePointMeshBatch( UInt capacity );
	ILineMesh*												CreateLineMesh( INode* parent, const lang::String& name );
	ILineMeshBatch*											CreateLineMeshBatch( UInt capacity );
	ITriangleMesh*											LoadMesh( io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type );
	ITriangleMesh*											LoadMesh( io::IStream* stream, mat::IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity );
	void													SetAmbientLightColor( const img::Color& color );
	void													SetAmbientLightIntensity( Float intensity );
	void													SetSky( img::IImage* map, Float size );
	INode*													GetNode( const lang::String& name ) const;
	INode*													GetNode( UInt id ) const;
	INode*													GetRoot() const;
	IFog*													GetFog() const;
	void													GetAmbientLightColor( img::Color& color ) const;
	Float													GetAmbientLightIntensity() const;
	audio::IAudioEnvironment*								GetAudioEnvironment() const;
	lang::String											GetName() const;
	DebugMode												GetDebugMode() const;

	// BaseScene methods.
	void													Update();
	void													IncrementCameraCount();
	void													DecrementCameraCount();
	lang::String											GetDummyName( const lang::String& name );
	lang::String											GetCameraName( const lang::String& name );
	lang::String											GetCurveName( const lang::String& name );
	lang::String											GetLightName( const lang::String& name );
	lang::String											GetSoundName( const lang::String& name );
	lang::String											GetLineMeshName( const lang::String& name );
	lang::String											GetPointMeshName( const lang::String& name );
	lang::String											GetTriangleMeshName( const lang::String& name );
	gfx::IParameterSet*										GetVertexParams() const;
	gfx::IResourceSet*										GetVertexResources() const;
	gfx::IParameterSet*										GetFragmentParams() const;

	// Other methods.
	Bool													Call( BaseMeshBatch* batch );

private:
	friend class SceneManager;

	typedef lang::MapPair<UInt, INode*>						NodeIdEntry;
	typedef lang::MapPair<lang::String, INode*>				NodeNameEntry;
	typedef lang::MapPair<UInt, ITriangleMesh*>				TriangleMeshEntry;

	P(IScene)												_scene;
	lang::Map<UInt, INode*>									_nodeIds;
	lang::MapCI<lang::String, INode*>						_nodeNames;
	lang::Map<UInt, ITriangleMesh*>							_triangleMeshes;
	lang::Vector<LightState>								_lights;
	lang::Vector<BaseMeshBatch*>							_batches;
	core::IContext*											_context;
	BaseSceneManager*										_sceneManager;
	P(ISceneAnimationController)							_ctrlAnimation;
	P(audio::IAudioEnvironment)								_audioEnvironment;
	P(gfx::IProgram)										_program;
	math::Vector4											_ambientLightColor;
	Float													_ambientLightIntensity;
	P(INode)												_root;
	mutable P(IFog)											_fog;
	P(gfx::ISkyRenderObject)								_skybox;
	P(gfx::ISkyRenderObject)								_skysphere;
	lang::String											_name;
	DebugMode												_debugMode;
	UInt													_cameraCount;
	UInt													_indexDummy;
	UInt													_indexCamera;
	UInt													_indexCurve;
	UInt													_indexLight;
	UInt													_indexSound;
	UInt													_indexLineMesh;
	UInt													_indexPointMesh;
	UInt													_indexTriangleMesh;

	P(gfx::IParameterSet)									_vertexParams;
	gfx::ProgramParam*										_paramLightAmbient;
	gfx::ProgramParam*										_paramLightCount;
	P(gfx::IParameterSet)									_fragmentParams;
	gfx::ProgramParam*										_paramFog;
	P(gfx::IResourceSet)									_vertexResources;
	P(gfx::IStructuredBuffer)								_lightsBuffer;
	
	mutable DebugHelper										_ray;

	lang::String											GetNodeName( const lang::String& name, const Char* fmt, UInt& idx );
	void													RegisterNode( INode* node );
	void													VerifyLit();
};


#include "Scene.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SCENE_
