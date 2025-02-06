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
#include "RubikCubeConfigurationScene.h"
#include <anim/IWaveFloatTrack.h>
#include <mat/IMaterialManager.h>
#include <scene/ISceneManager.h>
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


RubikCubeConfigurationScene::RubikCubeConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, false ),
	_cubes( A(P(ITriangleMesh)) ),
	_materials( A(P(IMultiMaterial)) ),
	_coloredMaterials( A(P(IOpaqueMaterial)) ),
	_owners( A(OwnerEntry) )
{
	CreateMaterials();

	// Setup camera and viewport.
	_camera->SetPosition( Vector3(15.0f, 15.0f, -25.0f) );
	_camera->LookAt( Vector3::Origin );
	_viewport->SetColor( Color::RoyalBlue );

	// Create cube.
	constexpr Float CUBE_SIDE = 14.0f;
	constexpr Float DELTA = 0.5f;
	const Float side = (CUBE_SIDE - DELTA*(CastFloat(SIDE_LENGTH)-1.0f))/CastFloat(SIDE_LENGTH);
	_center = _scene->CreateDummy( nullptr, L"Center" );

	_cubes.SetSize( COUNT );
	const Float start = -(CastFloat(SIDE_LENGTH)-1.0f)*(side+DELTA)*0.5f;
	Float y = start; Matrix4x4 trans; UInt idx = 0;
	for ( UInt i = 0; i < SIDE_LENGTH; ++i )
	{
		Float x = start;
		for ( UInt j = 0; j < SIDE_LENGTH; ++j )
		{
			Float z = start;
			for ( UInt k = 0; k < SIDE_LENGTH; ++k )
			{
				const UInt idx = SIDE_LENGTH*(SIDE_LENGTH*i+j)+k;
				trans.SetTranslation( Vector3(x, y, z) );
				ITriangleMesh* cube = _scene->CreateTriangleMesh( _center, String(CastInt(idx)), _materials[idx], nullptr );
				_synkro->GetSceneManager()->BuildMesh( cube, MeshBuilder::Box, Vector4(side, side, side, 0.0f), Size(), trans );
				_cubes[idx] = cube;
				z += side+DELTA;
			}
			x += side+DELTA;
		}
		y += side+DELTA;
	}

	// Create controllers.
	INodeAnimationController* ctrlCenter = _center->CreateAnimationController( nullptr, nullptr );

	// Setup orientation animation.
	IWaveFloatTrack* trackYaw = ctrlCenter->CreateOrientationYawTrack( AnimationTrack::FloatWave )->AsWave();
	trackYaw->SetType( WaveType::SawtoothDown );
	trackYaw->SetAmplitude( Math::TwoPi );
	trackYaw->SetFrequency( 0.125f );

	// Setup timer.
	_synkro->CreateTimer( 300, this );

	// Start animation.
	ctrlCenter->SetMode( AnimationMode::Loop );
	ctrlCenter->Start( true );
}

void RubikCubeConfigurationScene::OnTimerTick( UInt timer )
{
	const UInt idx1 = _random.GetInt( CastInt(_coloredMaterials.Size()-1) );
	const UInt idx2 = _random.GetInt( CastInt(_coloredMaterials.Size()-1) );

	IOpaqueMaterial* material1 = _coloredMaterials[idx1];
	IOpaqueMaterial* material2 = _coloredMaterials[idx2];
	IMultiMaterial* owner1 = _owners[material1->ID()];
	IMultiMaterial* owner2 = _owners[material2->ID()];
	if ( owner1 != owner2 )
	{
		Color color1; material1->GetDiffuseColor( color1 );
		Color color2; material2->GetDiffuseColor( color2 );
		if ( !HasColor(owner1, color2) && !HasColor(owner2, color1) )
		{
			material1->SetDiffuseColor( color2 );
			material2->SetDiffuseColor( color1 );
		}
	}
}

Bool RubikCubeConfigurationScene::HasColor( IMultiMaterial* material, const Color& color )
{
	const UInt count = material->GetSubsetCount();
	for ( UInt i = 0; i < count; ++i )
	{
		Color col; material->GetSubset( i )->GetDiffuseColor( col );
		if ( col == color )
			return true;
	}
	return false;
}

IOpaqueMaterial* RubikCubeConfigurationScene::CreateMaterial( IMultiMaterial* owner, UInt face )
{
	Color color = Color::Black;
	switch ( face )
	{
		case FACE_RIGHT:	color = Color::Red; break;
		case FACE_LEFT:		color = Color::DarkOrange; break;
		case FACE_TOP:		color = Color::White; break;
		case FACE_BOTTOM:	color = Color::Yellow; break;
		case FACE_BACK:		color = Color::Blue; break;
		case FACE_FRONT:	color = Color::Green; break;
		default:			return _blackMaterial;
	}
	IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Unknown );
	material->SetDiffuseColor( color );
	_coloredMaterials.Add( material );
	_owners[material->ID()] = owner;
	return material;
}

IMultiMaterial* RubikCubeConfigurationScene::CreateMaterial( UInt right, UInt left, UInt top, UInt bottom, UInt back, UInt front )
{
	IMultiMaterial* material = _synkro->GetMaterialManager()->CreateMultiMaterial( 6 );
	material->SetSubset( FACE_RIGHT, CreateMaterial(material, right) );
	material->SetSubset( FACE_LEFT, CreateMaterial(material, left) );
	material->SetSubset( FACE_TOP, CreateMaterial(material, top) );
	material->SetSubset( FACE_BOTTOM, CreateMaterial(material, bottom) );
	material->SetSubset( FACE_BACK, CreateMaterial(material, back) );
	material->SetSubset( FACE_FRONT, CreateMaterial(material, front) );
	return material;
}

void RubikCubeConfigurationScene::CreateMaterials()
{
	_blackMaterial = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Unknown );
	_blackMaterial->SetDiffuseColor( Color::Black );

	_materials.SetSize( COUNT );
	for ( UInt i = 0; i < SIDE_LENGTH; ++i )
	{
		for ( UInt j = 0; j < SIDE_LENGTH; ++j )
		{
			for ( UInt k = 0; k < SIDE_LENGTH; ++k )
			{
				const UInt idx = SIDE_LENGTH*(SIDE_LENGTH*i+j)+k;
				const UInt right = (j == SIDE_LENGTH-1) ? FACE_RIGHT : FACE_NONE;
				const UInt left = (j == 0) ? FACE_LEFT : FACE_NONE;
				const UInt top = (i == SIDE_LENGTH-1) ? FACE_TOP : FACE_NONE;
				const UInt bottom = (i == 0) ? FACE_BOTTOM : FACE_NONE;
				const UInt back = (k == SIDE_LENGTH-1) ? FACE_BACK : FACE_NONE;
				const UInt front = (k == 0) ? FACE_FRONT : FACE_NONE;
				_materials[idx] = CreateMaterial( right, left, top, bottom, back, front );
			}
		}
	}
}


} // core


} // synkro
