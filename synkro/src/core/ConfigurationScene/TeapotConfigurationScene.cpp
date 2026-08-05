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
// Purpose: Scene displayed in the configuration editor.
//==============================================================================
#include "config.h"
#include "TeapotConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <anim/INoiseColorTrack.h>
#include <lang/Random.h>
#include <core/IResource.h>
#include <core/ResourceReader.h>
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <mat/MaterialManager.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include <scene/SceneManager.h>
#include <scene/INodeAnimationController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


TeapotConfigurationScene::TeapotConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, true )
{
	// Create light source.
	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetAmbientColor( Color::DimGray );
	_light->SetDiffuseColor( Color::DimGray );
	_light->SetSpecularColor( Color::DimGray );
	_light->LookAt( Vector3(0.0f, 0.0f, -1.0f) );

	// Setup camera and viewport.
	_camera->SetPosition( Vector3(0.0f, 0.0f, -90.0f) );
	_camera->LookAt( Vector3::Origin );

	// Create material.
	_material = CreateMaterial( Color::White );

	// Load model resource.
	P(IStreamDirectory) res; P(IStream) streamModel;
	core::IResource* unknown = synkro->GetResource( SceneManager::ID_RESOURCE_MODELS );
	if ( unknown != nullptr )
	{
		res = unknown->Load();
		ResourceReader rd( res);
		streamModel = rd.GetResource( L"model.teapot" );
	}

	// Load mesh.
	_teapot = _scene->LoadMesh( streamModel, _material, nullptr, 0 );
	const Float sphere = _teapot->GetBoundSphere();
	_teapot->SetScale( 35.0f/sphere );

	// Create controllers.
	INodeAnimationController* ctrl = _teapot->CreateAnimationController( nullptr, nullptr );
	IWaveFloatTrack* track = ctrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	track->SetType( WaveType::SawtoothUp );
	track->SetAmplitude( Math::TwoPi );
	track->SetFrequency( 0.125f );

	Random rnd;
	ISimpleMaterialAnimationController* ctrlMaterial = _material->CreateAnimationController( nullptr, nullptr )->AsSimple();
	INoiseColorTrack* trackColor = ctrlMaterial->CreateDiffuseAmbientColorTrack( AnimationTrack::ColorNoise )->AsNoise();
	trackColor->SetSeed( rnd.GetUInt() );

	// Start animation.
	ctrl->SetMode( AnimationMode::Loop );
	ctrl->Start( true );

	ctrlMaterial->SetMode( AnimationMode::Loop );
	ctrlMaterial->Start( true );
}

IOpaqueMaterial* TeapotConfigurationScene::CreateMaterial( const Color& color )
{
	IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	material->SetAmbientColor( color );
	material->SetDiffuseColor( color );
	material->SetSpecularColor( Color::White );
	material->SetSpecularPower( 10.0f );
	material->SetTiling( 8 );
	material->SetWireframe( true );
	material->SetTwoSided( true );

	return material;
}


} // core


} // synkro
