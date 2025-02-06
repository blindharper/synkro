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
#include "ProjectorsConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <mat/IMaterialManager.h>
#include <scene/ISceneManager.h>
#include <scene/IScene.h>
#include <scene/INodeAnimationController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
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


ProjectorsConfigurationScene::ProjectorsConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, true )
{
	// Setup camera and viewport.
	_camera->SetPosition( Vector3(0.0f, 120.0f, -120.0f) );
	_camera->LookAt( Vector3::Origin );

	// Setup material.
	_material = synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	_material->SetAmbientColor( Color::DimGray );
	_material->SetDiffuseColor( Color::White );

	// Create geometry.
	constexpr Float FLOOR_SIZE = 100.0f;
	_floor = _scene->CreateTriangleMesh( nullptr, L"Floor", _material, nullptr );
	synkro->GetSceneManager()->BuildMesh( _floor, MeshBuilder::Plane, Vector4(FLOOR_SIZE, FLOOR_SIZE, 0.0f, 0.0f), Size(100, 0), Matrix4x4::Identity );

	// Create helpers.
	_target = _scene->CreateDummy( nullptr, L"Target" );
	_target2 = _scene->CreateDummy( nullptr, L"Target2" );
	_target3 = _scene->CreateDummy( nullptr, L"Target3" );

	// Create controllers.
	INodeAnimationController* targetCtrl = _target->CreateAnimationController( nullptr, nullptr );
	INodeAnimationController* targetCtrl2 = _target2->CreateAnimationController( nullptr, nullptr );
	INodeAnimationController* targetCtrl3 = _target3->CreateAnimationController( nullptr, nullptr );

	// Setup animations.
	IWaveFloatTrack* trackPositionX = targetCtrl->CreatePositionXTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionX->SetType( WaveType::Sine );
	trackPositionX->SetAmplitude( 50.0f );
	trackPositionX->SetFrequency( 1.0f/Math::Pi );

	IWaveFloatTrack* trackPositionZ = targetCtrl->CreatePositionZTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionZ->SetType( WaveType::Sine );
	trackPositionZ->SetAmplitude( 50.0f );
	trackPositionZ->SetFrequency( 2.0f/Math::Pi );

	IWaveFloatTrack* trackPositionX2 = targetCtrl2->CreatePositionXTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionX2->SetType( WaveType::Sine );
	trackPositionX2->SetAmplitude( 50.0f );
	trackPositionX2->SetFrequency( 1.0f/Math::Pi );

	IWaveFloatTrack* trackPositionZ2 = targetCtrl2->CreatePositionZTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionZ2->SetType( WaveType::Sine );
	trackPositionZ2->SetPhase( Math::HalfPi );
	trackPositionZ2->SetAmplitude( 50.0f );
	trackPositionZ2->SetFrequency( 1.0f/Math::Pi );

	IWaveFloatTrack* trackPositionX3 = targetCtrl3->CreatePositionXTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionX3->SetType( WaveType::Sine );
	trackPositionX3->SetAmplitude( 50.0f );
	trackPositionX3->SetFrequency( 2.0f/Math::Pi );

	IWaveFloatTrack* trackPositionZ3 = targetCtrl3->CreatePositionZTrack( AnimationTrack::FloatWave )->AsWave();
	trackPositionZ3->SetType( WaveType::Sine );
	trackPositionZ3->SetAmplitude( 50.0f );
	trackPositionZ3->SetFrequency( 1.0f/Math::Pi );
	
	// Setup projectors.
	_projector = _scene->CreateConeLight( nullptr, L"Projector" );
	_projector->SetAmbientColor( Color::Red );
	_projector->SetDiffuseColor( Color::Red );
	_projector->SetInnerAngle( Math::ToRadians(15.0f) );
	_projector->SetOuterAngle( Math::ToRadians(30.0f) );
	_projector->SetPosition( Vector3(0.0f, 40.0f, 0.0f) );
	_projector->CreateLookAtConstraint( _target );

	_projector2 = _scene->CreateConeLight( nullptr, L"Projector2" );
	_projector2->SetAmbientColor( Color::Lime );
	_projector2->SetDiffuseColor( Color::Lime );
	_projector2->SetInnerAngle( Math::ToRadians(15.0f) );
	_projector2->SetOuterAngle( Math::ToRadians(30.0f) );
	_projector2->SetPosition( Vector3(0.0f, 40.0f, 0.0f) );
	_projector2->CreateLookAtConstraint( _target2 );

	_projector3 = _scene->CreateConeLight( nullptr, L"Projector3" );
	_projector3->SetAmbientColor( Color::Blue );
	_projector3->SetDiffuseColor( Color::Blue );
	_projector3->SetInnerAngle( Math::ToRadians(15.0f) );
	_projector3->SetOuterAngle( Math::ToRadians(30.0f) );
	_projector3->SetPosition( Vector3(0.0f, 40.0f, 0.0f) );
	_projector3->CreateLookAtConstraint( _target3 );

	// Start animation.
	targetCtrl->SetMode( AnimationMode::Loop );
	targetCtrl->SetSpeed( 2.0 );
	targetCtrl->Start( true );

	targetCtrl2->SetMode( AnimationMode::Loop );
	targetCtrl2->SetSpeed( 2.0 );
	targetCtrl2->Start( true );

	targetCtrl3->SetMode( AnimationMode::Loop );
	targetCtrl3->SetSpeed( 2.0 );
	targetCtrl3->Start( true );
}


} // core


} // synkro
