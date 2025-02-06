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
#include "config.h"
#include "Scene.h"
#include "Dummy.h"
#include "Camera.h"
#include "Curve.h"
#include "OmniLight.h"
#include "ConeLight.h"
#include "DirectLight.h"
#include "OmniSound.h"
#include "ConeSound.h"
#include "LineMesh.h"
#include "LineMeshBatch.h"
#include "PointMesh.h"
#include "PointMeshBatch.h"
#include "TriangleMesh.h"
#include "TriangleMeshBatch.h"
#include "BaseNode.h"
#include "Fog.h"
#include "SceneAnimationController.h"
#include <mat/IMaterialManager.h>
#include <gfx/IProgramStage.h>
#include <gfx/IGraphicsSystemEx.h>
#include <scene/SceneManager.h>
#include <sound/ISoundManager.h>
#include <io/IStream.h>
#include <io/Path.h>
#include <img/BaseImage.h>
#include <lang/Convert.h>
#include <core/CallStack.h>
#include <math/Intersection.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Scene::Scene( IScene* scene, BaseSceneManager* sceneManager, IContext* context, const String& name, const DebugMode& debugMode, ILog* log ) :
	_scene( scene ),
	_nodeIds( A(NodeIdEntry) ),
	_nodeNames( A(NodeNameEntry) ),
	_triangleMeshes( A(TriangleMeshEntry) ),
	_lights( A(LightState) ),
	_batches( A(BaseMeshBatch*) ),
	_context( context ),
	_sceneManager( sceneManager ),
	_program( _context->GetGraphicsSystem()->GetProgram(_scene->IsLit() ? L"scene.lit" : L"scene")),
	_ambientLightColor( ToVector(Color(0.2f)) ),
	_ambientLightIntensity( 1.0f ),
	_name( name ),
	_debugMode( debugMode ),
	_cameraCount( 0 ),
	_indexDummy( 1 ),
	_indexCamera( 1 ),
	_indexCurve( 1 ),
	_indexLight( 1 ),
	_indexSound( 1 ),
	_indexLineMesh( 1 ),
	_indexPointMesh( 1 ),
	_indexTriangleMesh( 1 ),
	Logger( log, LogFacility::SceneManager )
{
	// Retrieve shared scene parameters.
	_vertexParams		= _program->GetVertexStage()->GetParameters()->Clone( this->ID(), true );
	_paramLightAmbient	= _vertexParams->GetParam( L"sp_lightAmbient" );
	_paramLightCount	= _vertexParams->GetParam( L"sp_lightCount" );
	_fragmentParams		= _program->GetFragmentStage()->GetParameters()->Clone( this->ID(), true );
	_paramFog			= _fragmentParams->GetParam( L"sp_fog" );

	// Retrieve scene resources.
	if ( IsLit() )
	{
		_lightsBuffer = _context->GetGraphicsSystem()->GetDevice()->CreateStructuredBuffer( DataUsage::Dynamic, sizeof(LightState), 2 );
		_vertexResources = _program->GetVertexStage()->GetResources()->Clone( this->ID() );
		_vertexResources->Set( 0, _lightsBuffer );
	}

	// Create root node.
	_root = new Dummy( this, _context, L"World", false );

	// Create audio scene.
	if ( _context->GetAudioSystem() != nullptr )
	{
		_audioEnvironment = _context->GetAudioSystem()->CreateEnvironment();
	}
}

ITriangleMesh* Scene::CreateTriangleMesh( INode* parent, const String& name, IVisualMaterial* material, ISkeleton* skeleton )
{
	ITriangleMesh* m = _scene->CreateTriangleMesh( parent, name, material, skeleton );
	ITriangleMesh* mesh = new TriangleMesh( m, this, _context, name, skeleton );
	mesh->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( mesh );
	_triangleMeshes[m->ID()] = mesh;
	return mesh;
}

ITriangleMeshBatch* Scene::CreateTriangleMeshBatch( IVisualMaterial* material, ISkeleton* skeleton, UInt capacity )
{
	ITriangleMeshBatch* b = _scene->CreateTriangleMeshBatch( material, skeleton, capacity );
	TriangleMeshBatch* batch = new TriangleMeshBatch( b, this, _context, String::Empty, skeleton, capacity );
	_batches.Add( batch );
	return batch;
}

ITriangleMesh* Scene::PickMesh( const Vector3& origin, const Vector3& direction, Float* distance ) const
{
	LogInfo( MessagePriority::Normal, Formatter::Format(L"Picking mesh...") );

	if ( !_ray.IsCreated() )
	{
		_ray.Create( _context->GetGraphicsSystem(), const_cast<Scene*>(this), 2, 0, Color::Black );
		_ray.SetTransform( Matrix4x4::Identity );
	}

	Vector3 points[] =
	{
		origin,
		origin - direction*5000.0f,
	};
	_ray.SetVertices( points, 2 );

	Float dist = 0.0f;
	ITriangleMesh* m = _scene->PickMesh( origin, direction, &dist );

	if ( m != nullptr )
	{
		// Look up logical mesh by underlying mesh id.
		ITriangleMesh* mesh = _triangleMeshes[m->ID()];
		LogInfo( MessagePriority::Normal, Formatter::Format(L"Picked {0,q} at distance {1,#.######}.", mesh->GetName(), CastDouble(dist)) );
		if ( distance != nullptr )
		{
			*distance = dist;
		}
		return mesh;
	}
	else
	{
		LogInfo( MessagePriority::Normal, Formatter::Format(L"Picked nothing.") );
		return nullptr;
	}
}

ISceneAnimationController* Scene::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SceneAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

INode* Scene::CreateDummy( INode* parent, const String& name )
{
	INode* dummy = new Dummy( this, _context, name, true );
	dummy->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( dummy );
	return dummy;
}

ICurve* Scene::CreateCurve( INode* parent, const lang::String& name )
{
	ICurve* curve = new Curve( this, _context, name );
	curve->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( curve );
	return curve;
}

ICamera* Scene::CreateCamera( INode* parent, const String& name )
{
	IAudioPlayer* player = (_context->GetAudioSystem() != nullptr) ? _context->GetAudioSystem()->CreatePlayer( 0 ) : nullptr;
	ISoundListener* listener = (player != nullptr) ? player->GetListener()->Clone() : nullptr;
	ICamera* camera = new Camera( this, _context, name, _audioEnvironment, listener );
	camera->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( camera );
	return camera;
}

IOmniLight* Scene::CreateOmniLight( INode* parent, const String& name )
{
	VerifyLit();
	
	IOmniLight* light = new OmniLight( this, _context, name );
	light->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( light );
	return light;
}

IConeLight* Scene::CreateConeLight( INode* parent, const String& name )
{
	VerifyLit();

	IConeLight* light = new ConeLight( this, _context, name );
	light->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( light );
	return light;
}

IDirectLight* Scene::CreateDirectLight( INode* parent, const String& name )
{
	VerifyLit();

	IDirectLight* light = new DirectLight( this, _context, name );
	light->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( light );
	return light;
}

IOmniSound* Scene::CreateOmniSound( INode* parent, const String& name, IStream* stream, const SoundCodec& type )
{
	ISound3D* sound3D = _context->GetSoundManager()->LoadSound3D( stream, type );
	IOmniSound* sound = new OmniSound( this, _context, name, sound3D );
	sound->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( sound );
	return sound;
}

IOmniSound* Scene::CreateOmniSound( INode* parent, const String& name, IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return CreateOmniSound( parent, name, stream, SoundCodec(type) );
	}
	return nullptr;
}

IConeSound* Scene::CreateConeSound( INode* parent, const String& name, IStream* stream, const SoundCodec& type )
{
	ISound3D* sound3D = _context->GetSoundManager()->LoadSound3D( stream, type );
	IConeSound* sound = new ConeSound( this, _context, name, sound3D );
	sound->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( sound );
	return sound;
}

IConeSound* Scene::CreateConeSound( INode* parent, const String& name, IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return CreateConeSound( parent, name, stream, SoundCodec(type) );
	}
	return nullptr;
}

IPointMesh* Scene::CreatePointMesh( INode* parent, const String& name )
{
	IPointMesh* mesh = new PointMesh( this, _context, name );
	mesh->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( mesh );
	return mesh;
}

IPointMeshBatch* Scene::CreatePointMeshBatch( UInt capacity )
{
	PointMeshBatch* batch = new PointMeshBatch( this, _context, String::Empty, capacity );
	_batches.Add( batch );
	return batch;
}

ILineMesh* Scene::CreateLineMesh( INode* parent, const String& name )
{
	ILineMesh* mesh = new LineMesh( this, _context, name );
	mesh->SetParent( (parent != nullptr) ? parent : _root );
	RegisterNode( mesh );
	return mesh;
}

ILineMeshBatch* Scene::CreateLineMeshBatch( UInt capacity )
{
	LineMeshBatch* batch = new LineMeshBatch( this, _context, String::Empty, capacity );
	_batches.Add( batch );
	return batch;
}

ITriangleMesh* Scene::LoadMesh( IStream* stream, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type )
{
	assert( stream != nullptr );

	SynkroCall( "Scene.LoadMesh", stream->GetName() );

	return _sceneManager->LoadMesh( this, stream, material, skeleton, instanceCapacity, type );
}

ITriangleMesh* Scene::LoadMesh( IStream* stream, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return LoadMesh( stream, material, skeleton, instanceCapacity, MeshCodec(type) );
	}
	return nullptr;
}

void Scene::SetSky( IImage* map, Float size )
{
	assert( map != nullptr );

	AsBaseImage( map )->WaitLoad();
	UInt elementCount = map->GetElementCount();
	AsBaseImage( map )->SignalLoad();

	if ( elementCount == 6 )
	{
		_skysphere = nullptr;

		if ( _skybox == nullptr )
		{
			_skybox = _scene->GetRenderQueue()->CreateSkyboxObject();
			IResourceSet* resources = _skybox->GetProgram()->GetFragmentStage()->GetResources()->Clone( this->ID() );
			_skybox->SetFragmentResources( resources );

			ISamplerStateSet* samplers = _skybox->GetProgram()->GetFragmentStage()->GetSamplers()->Clone( this->ID() );
			samplers->Get(0)->SetFilter( TextureFilter::Linear );
			samplers->Get(0)->SetAddress( TextureAddress::Clamp );
			_skybox->SetFragmentSamplers( samplers );
		}

		PixelFormat format = (_context->GetGraphicsSystem()->GetFrameWindowCount() > 0) ? _context->GetGraphicsSystem()->GetFrameWindow(0)->GetPixelFormat() : _context->GetGraphicsSystem()->GetViewWindow(0)->GetPixelFormat();
		map->Prepare( format, 1 );
		_skybox->GetFragmentResources()->Set( 0, map->AsResource() );
	}
	else if ( elementCount == 1 )
	{
		_skybox = nullptr;

		if ( _skysphere == nullptr )
		{
			_skysphere = _scene->GetRenderQueue()->CreateSkysphereObject( size );
			IResourceSet* resources = _skysphere->GetProgram()->GetFragmentStage()->GetResources()->Clone( this->ID() );
			_skysphere->SetFragmentResources( resources );

			ISamplerStateSet* samplers = _skysphere->GetProgram()->GetFragmentStage()->GetSamplers()->Clone( this->ID() );
			samplers->Get(0)->SetFilter( TextureFilter::Linear );
			samplers->Get(0)->SetAddress( TextureAddress::Clamp );
			_skysphere->SetFragmentSamplers( samplers );
		}

		PixelFormat format = (_context->GetGraphicsSystem()->GetFrameWindowCount() > 0) ? _context->GetGraphicsSystem()->GetFrameWindow(0)->GetPixelFormat() : _context->GetGraphicsSystem()->GetViewWindow(0)->GetPixelFormat();
		map->Prepare( format, 1 );
		_skysphere->GetFragmentResources()->Set( 0, map->AsResource() );
	}
}

INode* Scene::GetNode( const String& name ) const
{
	return _nodeNames.ContainsKey(name) ? _nodeNames[name] : nullptr;
}

INode* Scene::GetNode( UInt id ) const
{
	return _nodeIds.ContainsKey(id) ? _nodeIds[id] : nullptr;
}

IFog* Scene::GetFog() const
{
	if ( _fog == nullptr )
	{
		_fog = new Fog( _context );
	}
	return _fog;
}

void Scene::Update()
{
	// Skip update if no active cameras associated with the scene.
	if ( _cameraCount == 0 )
		return;

	// Update lights and meshes.
	_lights.Clear();
	BaseNode* base = nullptr;
	BaseLight* light = nullptr;
	LightState lightState;
	for ( INode* node = _root; node != nullptr; node = ((NodeImpl<INode>*)node)->GetNextNode() )
	{
		if ( (base = AsBaseNode(node)) != nullptr )
		{
			// NB: Update node only if it's visible???

			base->Update();
		}
		
		if ( IsLit() )
		{
			ILight* l = node->AsLight();
			if ( (l != nullptr) && l->IsEnabled() && ((light = AsBaseLight(node)) != nullptr) )
			{
				light->GetState( lightState );
				_lights.Add( lightState );
			}
		}
	}

	// Update mesh batches.
	_batches.Each( *this );

	// Commit parameters.
	if ( IsLit() )
	{
		_vertexParams->Set( _paramLightAmbient, _ambientLightColor*_ambientLightIntensity );
		_vertexParams->Set( _paramLightCount, CastInt(_lights.Size()) );

		// Reallocate lights buffer, if needed.
		if ( _lights.Size() > _lightsBuffer->GetSize() )
		{
			_lightsBuffer = _context->GetGraphicsSystem()->GetDevice()->CreateStructuredBuffer( DataUsage::Dynamic, sizeof(LightState), _lights.Size() );
			_vertexResources->Set( 0, _lightsBuffer );
		}
		_lightsBuffer->Set( (const Byte*)_lights.Begin(), _lights.Size()*sizeof(LightState) );
	}

	// Commit fog state.
	FogState fogState;
	fogState.Type = FogType::None.Value();
	if ( (_fog != nullptr) && (_fog->GetType() != FogType::None) )
	{
		BaseFog* fog = AsBaseFog( _fog.AsPtr() );
		fog->GetState( fogState );
	}
	_fragmentParams->Set( _paramFog, (const Byte*)&fogState, sizeof(FogState) );
}

void Scene::IncrementCameraCount()
{
	if ( ++_cameraCount > 0 )
	{
		_scene->GetRenderQueue()->Enable( true );
	}
}

void Scene::DecrementCameraCount()
{
	if ( --_cameraCount == 0 )
	{
		_scene->GetRenderQueue()->Enable( false );
	}
}

Bool Scene::Call( BaseMeshBatch* batch )
{
	batch->Update();
	return true;
}

String Scene::GetNodeName( const String& name, const Char* fmt, UInt& idx )
{
	String str = name.IsEmpty() ? String::Format(fmt, idx++) : name;
	while ( _nodeNames.ContainsKey(str) )
	{
		str = String::Format( fmt, idx++ );
	}
	return str;
}

void Scene::RegisterNode( INode* node )
{
	assert( node != nullptr );

	_nodeIds[node->ID()] = node;
	_nodeNames[node->GetName()] = node;
}

void Scene::VerifyLit()
{
	if ( !IsLit() )
		throw InvalidOperationException( L"Cannot create a light source in an unlit scene." );
}


} // scene


} // synkro
