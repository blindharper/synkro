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
#include "MorphingConfigurationScene.h"
#include <anim/INoiseFloatTrack.h>
#include <anim/INoiseColorTrack.h>
#include <anim/IKeyframedFloatTrack.h>
#include <lang/Random.h>
#include <scene/ISceneManager.h>
#include <scene/ILineSet.h>
#include <scene/ILineSetAnimationController.h>
#include <scene/INodeAnimationController.h>
#include <scene/IPrimitiveMorphController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
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


MorphingConfigurationScene::MorphingConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, false )
{
	// Setup camera and viewport.
	_camera->SetPosition( Vector3(0.0f, 0.0f, -120.0f) );
	_camera->LookAt( Vector3::Origin );

	// Setup post-processing filters.
	_blurFilter = _viewport->CreateFilter( ViewportFilter::Blur )->AsKernel3x3();
	_blurFilter->SetPassCount( 2 );

	_contrastFilter = _viewport->CreateFilter( ViewportFilter::Contrast )->AsSimple();
	_contrastFilter->SetValue( 4.0f );

	// Create mesh.
	constexpr UInt SEGMENT_COUNT = 25;
	_mesh = _scene->CreateLineMesh(nullptr, L"Morpher");
	_synkro->GetSceneManager()->BuildMesh( _mesh, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(SEGMENT_COUNT, SEGMENT_COUNT), Matrix4x4::Identity );

	_sphere = _scene->CreateLineMesh( nullptr, L"Sphere" );
	_synkro->GetSceneManager()->BuildMesh( _sphere, MeshBuilder::Ellipsoid, Vector4(30.0f, 30.0f, 30.0f, 0.0f), Size(SEGMENT_COUNT, SEGMENT_COUNT), Matrix4x4::Identity );
	_sphere->Show( false );

	_torus = _scene->CreateLineMesh( nullptr, L"Torus" );
	_synkro->GetSceneManager()->BuildMesh( _torus, MeshBuilder::Torus, Vector4(10.0f, 30.0f, 30.0f, 0.0f), Size(SEGMENT_COUNT, SEGMENT_COUNT), Matrix4x4::Identity );
	_torus->Show( false );

	_cylinder = _scene->CreateLineMesh( nullptr, L"Cylinder" );
	_synkro->GetSceneManager()->BuildMesh( _cylinder, MeshBuilder::Cylinder, Vector4(30.0f, 30.0f, 0.0f, 0.0f), Size(SEGMENT_COUNT, SEGMENT_COUNT), Matrix4x4::Identity );
	_cylinder->Show( false );

	_cone = _scene->CreateLineMesh( nullptr, L"Cone" );
	_synkro->GetSceneManager()->BuildMesh( _cone, MeshBuilder::Cone, Vector4(30.0f, 30.0f, 0.0f, 0.0f), Size(SEGMENT_COUNT, SEGMENT_COUNT), Matrix4x4::Identity );
	_cone->Show( false );

	// Create controllers.
	IPrimitiveMorphController* ctrlMorph = _mesh->GetSubset( 0 )->CreateMorphController( nullptr, nullptr );
	ctrlMorph->AddChannel( L"Sphere", _sphere->GetSubset(0) );
	ctrlMorph->AddChannel( L"Torus", _torus->GetSubset(0) );
	ctrlMorph->AddChannel( L"Cylinder", _cylinder->GetSubset(0) );
	ctrlMorph->AddChannel( L"Cone", _cone->GetSubset(0) );

	IKeyframedFloatTrack* trackSphere = ctrlMorph->CreateChannelWeightTrack( L"Sphere" );
	trackSphere->SetKey( 0.0, 1.0 );
	trackSphere->SetKey( 2.0, 1.0 );
	trackSphere->SetKey( 4.0, 0.0 );
	trackSphere->SetKey( 14.0, 0.0 );
	trackSphere->SetKey( 16.0, 1.0 );

	IKeyframedFloatTrack* trackTorus = ctrlMorph->CreateChannelWeightTrack( L"Torus" );
	trackTorus->SetKey( 0.0, 0.0 );
	trackTorus->SetKey( 2.0, 0.0 );
	trackTorus->SetKey( 4.0, 1.0 );
	trackTorus->SetKey( 6.0, 1.0 );
	trackTorus->SetKey( 8.0, 0.0 );
	trackTorus->SetKey( 16.0, 0.0 );

	IKeyframedFloatTrack* trackCylinder = ctrlMorph->CreateChannelWeightTrack( L"Cylinder" );
	trackCylinder->SetKey( 0.0, 0.0 );
	trackCylinder->SetKey( 6.0, 0.0 );
	trackCylinder->SetKey( 8.0, 1.0 );
	trackCylinder->SetKey( 10.0, 1.0 );
	trackCylinder->SetKey( 12.0, 0.0 );
	trackCylinder->SetKey( 16.0, 0.0 );

	IKeyframedFloatTrack* trackCone = ctrlMorph->CreateChannelWeightTrack( L"Cone" );
	trackCone->SetKey( 0.0, 0.0 );
	trackCone->SetKey( 10.0, 0.0 );
	trackCone->SetKey( 12.0, 1.0 );
	trackCone->SetKey( 14.0, 1.0 );
	trackCone->SetKey( 16.0, 0.0 );

	INodeAnimationController* ctrlMesh = _mesh->CreateAnimationController( nullptr, nullptr );

	Random rnd;
	INoiseFloatTrack* trackYaw = ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackYaw->SetMagnitude( Math::TwoPi );
	trackYaw->SetSeed( rnd.GetUInt() );
	INoiseFloatTrack* trackPitch = ctrlMesh->CreateOrientationPitchTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackPitch->SetMagnitude( Math::TwoPi );
	trackPitch->SetSeed( rnd.GetUInt() );
	INoiseFloatTrack* trackRoll = ctrlMesh->CreateOrientationRollTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackRoll->SetMagnitude( Math::TwoPi );
	trackRoll->SetSeed( rnd.GetUInt() );

	ILineSetAnimationController* ctrlLines = _mesh->GetSubset( 0 )->CreateAnimationController( nullptr, nullptr )->AsLineSet();
	INoiseColorTrack* trackColor = ctrlLines->CreateColorTrack( AnimationTrack::ColorNoise )->AsNoise();
	trackColor->SetSeed( rnd.GetUInt() );

	// Start animation.
	ctrlMesh->SetMode( AnimationMode::Loop );
	ctrlMesh->SetSpeed( 0.5 );
	ctrlMesh->Start( true );

	ctrlLines->SetMode( AnimationMode::Loop );
	ctrlLines->Start( true );

	ctrlMorph->SetMode( AnimationMode::Loop );
	ctrlMorph->Start( true );
}


} // core


} // synkro
