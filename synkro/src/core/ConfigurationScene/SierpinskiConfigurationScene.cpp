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
#include "SierpinskiConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <mat/IMaterialManager.h>
#include <scene/ISceneManager.h>
#include <scene/INodeAnimationController.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::mat;
using namespace synkro::math;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


SierpinskiConfigurationScene::SierpinskiConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, false ),
	_pyramids( A(P(ITriangleMesh)), CAPACITY )
{
	// Setup camera and viewport.
	_viewport->SetWireframe( true );
	_camera->SetPosition( Vector3(0.0f, 250.0f, -1200.0f) );
	_camera->LookAt( Vector3(0.0f, 220.0f, 0.0f) );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 10000.0f );

	// Create material.
	_material = CreateMaterial( Color::White );

	// Create geometry.
	_center = _scene->CreateDummy( nullptr, L"Center" );

	// Create pyramid.
	_pyramid = _scene->CreateTriangleMeshBatch( _material, nullptr, CAPACITY );
	Build( 2 );

	// Create controllers.
	INodeAnimationController* ctrl = _center->CreateAnimationController( nullptr, nullptr );
	IWaveFloatTrack* track = ctrl->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	track->SetType( WaveType::SawtoothUp );
	track->SetAmplitude( Math::TwoPi );
	track->SetFrequency( 0.125f );

	// Start animation.
	ctrl->SetMode( AnimationMode::Loop );
	ctrl->Start( true );
}

void SierpinskiConfigurationScene::Build( UInt steps )
{
	constexpr Float size = 500.0f;
	Float sz = size;
	for ( UInt i = 0; i < steps; ++i )
	{
		sz *= 0.5f;
	}

	_synkro->GetSceneManager()->BuildMesh( _pyramid, MeshBuilder::Pyramid, Vector4(sz, sz, sz, 0.0f), Size(), Matrix4x4::Identity );
	Split( steps, size, 0.0f, 0.0f, 0.0f, Color::Orange );
	_pyramid->SetRange( Range(0, _pyramids.Size()) );
}

void SierpinskiConfigurationScene::Split( UInt step, Float size, Float x, Float y, Float z, const Color& color )
{
	if ( step == 0 )
	{
		Matrix4x4 trans;
		trans.SetTranslation( Vector3(x, y, z) );
		_pyramids.Add( _pyramid->CreateInstance(_center, trans, color) );
	}
	else
	{
		--step;
		size *= 0.5f;
		Split( step, size, -size*0.5f+x, y, -size*0.5f+z, Color::Red );
		Split( step, size, -size*0.5f+x, y,  size*0.5f+z, Color::Green );
		Split( step, size,  size*0.5f+x, y, -size*0.5f+z, Color::RoyalBlue );
		Split( step, size,  size*0.5f+x, y,  size*0.5f+z, Color::Yellow );
		Split( step, size,	          x, y+size,	   z, Color::Orange );
	}
}

IOpaqueMaterial* SierpinskiConfigurationScene::CreateMaterial( const Color& color )
{
	IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Unknown );
	material->SetDiffuseColor( color );
	return material;
}


} // core


} // synkro
