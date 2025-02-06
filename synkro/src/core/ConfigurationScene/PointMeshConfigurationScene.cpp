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
#include "PointMeshConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <anim/IKeyframedColorTrack.h>
#include <anim/IKeyframedRangeTrack.h>
#include <scene/ISceneManager.h>
#include <scene/IScene.h>
#include <scene/IPointSet.h>
#include <scene/IPointSetAnimationController.h>
#include <scene/INodeAnimationController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::view;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


PointMeshConfigurationScene::PointMeshConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, false )
{
	// Setup camera and viewport.
	_camera->LookAt( Vector3(0.0f, -5.0f, -300.0f) );

	// Setup post-processing filters.
	_blurFilter = _viewport->CreateFilter( ViewportFilter::Blur )->AsKernel3x3();
	_blurFilter->SetPassCount( 2 );

	_contrastFilter = _viewport->CreateFilter( ViewportFilter::Contrast )->AsSimple();
	_contrastFilter->SetValue( 4.0f );

	// Create geometry.
	constexpr Float RADIUS = 30.0f;
	_sphere = _scene->CreatePointMesh( nullptr, L"Sphere" );
	_sphere->SetPosition( Vector3(0.0f, 0.0f, -100.0f) );
	synkro->GetSceneManager()->BuildMesh( _sphere, MeshBuilder::Ellipsoid, Vector4(RADIUS, RADIUS, RADIUS, 0.0f), Size(60, 60), Matrix4x4::Identity );

	// Create controllers.
	INodeAnimationController* ctrlSphere = _sphere->CreateAnimationController( nullptr, nullptr );
	IPointSetAnimationController* ctrlPoints = _sphere->GetSubset( 0 )->CreateAnimationController( nullptr, nullptr )->AsPointSet();

	// Setup orientation animation.
	IWaveFloatTrack* trackYaw = ctrlSphere->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::SawtoothDown );
	trackYaw->SetAmplitude( Math::TwoPi );
	trackYaw->SetFrequency( 0.125f );
	
	// Setup scale animation.
	IWaveFloatTrack* trackScale = ctrlSphere->CreateScaleUniformTrack( AnimationTrack::FloatWave )->AsWave();
	trackScale->SetType( WaveType::Sine );
	trackScale->SetAmplitude( 0.2f );
	trackScale->SetFrequency( 0.25f );
	trackScale->SetOffset( 1.0f );

	// Setup points color animation.
	IKeyframedColorTrack* trackColor = ctrlPoints->CreateColorTrack();
	trackColor->SetKey( 0.0, Color::Random() );
	trackColor->SetKey( 2.0, Color::Random() );
	trackColor->SetKey( 4.0, Color::Random() );
	trackColor->SetKey( 6.0, Color::Random() );
	trackColor->SetKey( 12.0, Color::Random() );
	trackColor->SetKey( 15.0, Color::Random() );
	trackColor->SetKey( 19.0, Color::Random() );
	trackColor->SetKey( 25.12, Color::Random() );

	// Setup points range animation.
	UInt count = _sphere->GetSubset( 0 )->GetElementCount();
	IKeyframedRangeTrack* trackRange = ctrlPoints->CreateElementRangeTrack();
	trackRange->SetKey( 0.0, Range() );
	trackRange->SetKey( 12.56, Range(0, count) );
	trackRange->SetKey( 25.12, Range(count, 0) );

	// Start animation.
	ctrlSphere->SetMode( AnimationMode::Loop );
	ctrlSphere->Start( true );

	ctrlPoints->SetMode( AnimationMode::PingPong );
	ctrlPoints->Start( true );
}


} // core


} // synkro
