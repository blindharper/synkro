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
#include "VirusConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <anim/INoiseColorTrack.h>
#include <lang/Random.h>
#include <core/IResource.h>
#include <core/ResourceReader.h>
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <scene/SceneManager.h>
#include <scene/INodeAnimationController.h>
#include <mat/ISimpleMaterialAnimationController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::view;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


VirusConfigurationScene::VirusConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro )
{
	// Setup camera and viewport.
	_camera->SetPosition( Vector3(0.0f, 50.0f, -150.0f) );
	_camera->LookAt( Vector3::Origin );

	// Setup post-processing filters.
	_filter = _viewport->CreateFilter( ViewportFilter::Laplacian )->AsKernel3x3();

	// Load model resource.
	P(IStreamDirectory) res; P(IStream) streamModel;
	core::IResource* unknown = synkro->GetResource( SceneManager::ID_RESOURCE_MODELS );
	if ( unknown != nullptr )
	{
		res = unknown->Load();
		ResourceReader rd( res);
		streamModel = rd.GetResource( L"model.cytovirus" );
	}

	// Load mesh.
	_virus = _scene->LoadMesh( streamModel );
	const Float sphere = _virus->GetBoundSphere();
	_virus->SetScale( 60.0f/sphere );

	// Create controllers.
	INodeAnimationController* ctrlMesh = _virus->CreateAnimationController( nullptr, nullptr );
	IWaveFloatTrack* trackYaw = ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::SawtoothUp );
	trackYaw->SetAmplitude( Math::TwoPi );
	trackYaw->SetFrequency( 0.125f );
	IWaveFloatTrack* trackPitch = ctrlMesh->CreateOrientationPitchTrack( AnimationTrack::FloatWave )->AsWave();
	trackPitch->SetType( WaveType::SawtoothUp );
	trackPitch->SetAmplitude( Math::TwoPi );
	trackPitch->SetFrequency( 0.125f );
	IWaveFloatTrack* trackRoll = ctrlMesh->CreateOrientationRollTrack( AnimationTrack::FloatWave )->AsWave();
	trackRoll->SetType( WaveType::SawtoothUp );
	trackRoll->SetAmplitude( Math::TwoPi );
	trackRoll->SetFrequency( 0.125f );

	Random rnd;
	ISimpleMaterialAnimationController* ctrlMat = _virus->GetMaterial()->CreateAnimationController( nullptr, nullptr )->AsSimple();
	INoiseColorTrack* trackDiffuse = ctrlMat->CreateDiffuseColorTrack( AnimationTrack::ColorNoise )->AsNoise();
	trackDiffuse->SetSeed( rnd.GetUInt() );

	// Start animations.
	ctrlMesh->SetMode( AnimationMode::Loop );
	ctrlMesh->Start( true );

	ctrlMat->SetMode( AnimationMode::Loop );
	ctrlMat->Start( true );
}


} // core


} // synkro
