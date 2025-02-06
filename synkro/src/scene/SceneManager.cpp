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
#include "config.h"
#include "SceneManager.h"
#include "Skeleton.h"
#include "SoftTriangleMesh.h"
#include <gfx/IGraphicsSystemEx.h>
#include <io/Path.h>
#include <io/IStreamDirectory.h>
#include <over/IOverlayManager.h>
#include <over/IOverlay.h>
#include <scene/IMeshBuilderFactory.h>
#include <scene/IMeshCodecFactory.h>
#include <scene/ITriangleSet.h>
#include <mat/ISimpleMaterial.h>
#include <mat/IMaterialMap.h>


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


SceneManager::SceneManager( IContext* context, ILog* log ) :
	_scenes( A(P(Scene)) ),
	_sceneFactories( A(FactoryEntry) ),
	_meshBuilders( A(BuilderEntry) ),
	_meshCodecs( A(CodecEntry) ),
	_context( context ),
	Logger( log, LogFacility::SceneManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating scene manager...") );
}

SceneManager::~SceneManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying scene manager...") );
}

Bool SceneManager::Update( Double delta )
{
	SynkroProfile( "SceneManager.Update" );

	// Update scenes.
	_scenes.Each( *this );

	return true;
}

ISceneEx* SceneManager::CreateScene( const SceneType& type, const String& name, const DebugMode& debugMode, Bool lit )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating scene {0,q}...", name) );
	ISceneRenderQueue* queue = _context->GetGraphicsSystem()->CreateRenderQueue();
	Scene* scene = new Scene( _sceneFactories[type]->Create(queue, lit), this, _context, name, debugMode, _log );
	_scenes.Add( scene );
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Scene {0,q} created.", name) );
	return scene;
}

ISceneEx* SceneManager::CreateScene( const String& name, const DebugMode& debugMode, Bool lit )
{
	return CreateScene( SceneType::Default, name, debugMode, lit );
}

ISkeleton* SceneManager::CreateSkeleton()
{
	return new Skeleton( this, _context->GetAnimationSystem(), _log );
}

ITriangleMesh* SceneManager::CreateTriangleMesh( ISkeleton* skeleton, UInt subsetCount )
{
	return new SoftTriangleMesh( this, skeleton, subsetCount );
}

ISkeleton* SceneManager::LoadSkeleton( IStream* stream, const MeshCodec& type )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to load skeleton. Bad stream pointer.", L"stream" );

	IMeshCodec* codec = _meshCodecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to load skeleton. Unknown mesh type '{0}'.", type.ToString()), L"type", type.ToString() );

	stream->Open( OpenMode::Read );
	ISkeleton* skeleton = codec->Load( stream );
	stream->Close();

	return skeleton;
}

ISkeleton* SceneManager::LoadSkeleton( IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return LoadSkeleton( stream, MeshCodec(type) );
	}
	return nullptr;
}

ITriangleMesh* SceneManager::LoadMesh( IStream* stream, ISkeleton* skeleton, const MeshCodec& type )
{
	assert( stream != nullptr );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to load software mesh. Bad stream pointer.", L"stream" );

	IMeshCodec* codec = _meshCodecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to load software mesh. Unknown mesh type '{0}'.", type.ToString()), L"type", type.ToString() );

	stream->Open( OpenMode::Read );
	ITriangleMesh* mesh = codec->Load( nullptr, stream, PixelFormat::Unknown, nullptr, skeleton, 0 );
	stream->Close();

	return mesh;
}

ITriangleMesh* SceneManager::LoadMesh( IStream* stream, ISkeleton* skeleton )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	if ( !type.IsEmpty() )
	{
		return LoadMesh( stream, skeleton, MeshCodec(type) );
	}
	return nullptr;
}

void SceneManager::BuildMesh( ILineMesh* mesh, const MeshBuilder& type, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	IMeshBuilder* builder = GetMeshBuilder( (IMesh*)mesh, type );
	builder->Build( mesh, param1, param2, transform );
}

void SceneManager::BuildMesh( IPointMesh* mesh, const MeshBuilder& type, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	IMeshBuilder* builder = GetMeshBuilder( (IMesh*)mesh, type );
	builder->Build( mesh, param1, param2, transform );
}

void SceneManager::BuildMesh( ITriangleMesh* mesh, const MeshBuilder& type, const Vector4& param1, const Size& param2, const Matrix4x4& transform )
{
	IMeshBuilder* builder = GetMeshBuilder( (IMesh*)mesh, type );
	builder->Build( mesh, param1, param2, transform );
}

ITriangleMesh* SceneManager::LoadMesh( IScene* scene, IStream* stream, IVisualMaterial* material, ISkeleton* skeleton, UInt instanceCapacity, const MeshCodec& type )
{
	assert( stream != nullptr );

	ITriangleMesh* mesh = nullptr;
	IMeshCodec* codec = _meshCodecs[type];
	if ( codec != nullptr )
	{
		IGraphicsSystemEx* graphicsSystem =_context->GetGraphicsSystem();
		stream->Open( OpenMode::Read );
		PixelFormat clientFormat = (graphicsSystem->GetFrameWindowCount() > 0) ? graphicsSystem->GetFrameWindow(0)->GetClientPixelFormat() : graphicsSystem->GetViewWindow(0)->GetClientPixelFormat();
		mesh = codec->Load( scene, stream, clientFormat, material, skeleton, instanceCapacity );
		stream->Close();
	}

	return mesh;
}

void SceneManager::SaveMesh( const ITriangleMesh* mesh, IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	assert( mesh != nullptr );
	assert( stream != nullptr );

	if ( mesh == nullptr )
		throw BadArgumentException( L"Failed to save mesh. Bad mesh data.", L"mesh" );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save mesh. Bad stream pointer.", L"stream" );

	IMeshCodec* codec = _meshCodecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save mesh. Unknown mesh type '{0}'.", type.ToString()), L"type", type.ToString() );

	stream->Open( OpenMode::Write );
	codec->Save( mesh, stream, mode );
	stream->Close();
}

void SceneManager::SaveSkeleton( const ISkeleton* skeleton, IStream* stream, const DataMode& mode, const MeshCodec& type )
{
	assert( skeleton != nullptr );
	assert( stream != nullptr );

	if ( skeleton == nullptr )
		throw BadArgumentException( L"Failed to save skeleton. Bad skeleton data.", L"skeleton" );

	if ( stream == nullptr )
		throw BadArgumentException( L"Failed to save skeleton. Bad stream pointer.", L"stream" );

	IMeshCodec* codec = _meshCodecs[type];
	if ( codec == nullptr )
		throw BadArgumentException( String::Format(L"Failed to save skeleton. Unknown skeleton type '{0}'.", type.ToString()), L"type", type.ToString() );

	stream->Open( OpenMode::Write );
	codec->Save( skeleton, stream, mode );
	stream->Close();
}

void SceneManager::RegisterSceneFactory( ISceneFactory* factory )
{
	assert( factory != nullptr );

	SceneType type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering scene factory {0,q}...", type.ToString()) );
	if ( !_sceneFactories.ContainsKey(type) )
	{
		try
		{
			_sceneFactories[type] = factory;
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Factory already registered.") );
	}
}

void SceneManager::RegisterMeshBuilder( IMeshBuilderFactory* factory )
{
	assert( factory != nullptr );

	MeshBuilder type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering mesh builder {0,q}...", type.ToString()) );
	if ( !_meshBuilders.ContainsKey(type) )
	{
		try
		{
			_meshBuilders[type] = factory->Create();
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Builder already registered.") );
	}
}

void SceneManager::RegisterMeshCodec( IMeshCodecFactory* factory )
{
	assert( factory != nullptr );

	MeshCodec type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering mesh codec {0,q}...", type.ToString()) );
	if ( !_meshCodecs.ContainsKey(type) )
	{
		try
		{
			_meshCodecs[type] = factory->Create( _context );
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Codec already registered.") );
	}
}

IMeshBuilder* SceneManager::GetMeshBuilder( IMesh* mesh, const MeshBuilder& type )
{
	assert( mesh != nullptr );

	if ( mesh == nullptr )
		throw BadArgumentException( L"Failed to build mesh. Bad mesh object", L"mesh" );

	IMeshBuilder* builder = _meshBuilders[type];
	if ( builder == nullptr )
		throw BadArgumentException( L"Failed to build mesh. Unknown mesh type.", L"type" );

	return builder;
}


} // scene


} // synkro
