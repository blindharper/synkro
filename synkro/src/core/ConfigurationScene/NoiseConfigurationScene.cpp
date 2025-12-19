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
#include "NoiseConfigurationScene.h"
#include <anim/INoiseFloatTrack.h>
#include <anim/INoiseColorTrack.h>
#include <lang/Random.h>
#include <core/IResource.h>
#include <core/ResourceReader.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <img/IImageManager.h>
#include <img/IImage.h>
#include <io/IStreamDirectory.h>
#include <io/IStream.h>
#include <mat/MaterialManager.h>
#include <mat/IMaterialMap.h>
#include <mat/ISimpleMaterialAnimationController.h>
#include <scene/ISceneManager.h>
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


NoiseConfigurationScene::NoiseConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, true )
{
	// Create light source.
	_light = _scene->CreateDirectLight( nullptr, L"Light" );
	_light->SetAmbientColor( Color::DimGray );
	_light->SetDiffuseColor( Color::DimGray );
	_light->SetSpecularColor( Color::DimGray );
	_light->LookAt( Vector3(0.0f, 0.0f, -1.0f) );

	// Setup camera and viewport.
	_camera->SetPosition( Vector3(0.0f, 0.0f, -120.0f) );
	_camera->LookAt( Vector3::Origin );

	// Load texture resource.
	P(IStreamDirectory) res; P(IStream) streamImage;
	core::IResource* unknown = synkro->GetResource( mat::MaterialManager::ID_RESOURCE_TEXTURES );
	if ( unknown != nullptr )
	{
		res = unknown->Load();
		ResourceReader rd( res );
		streamImage = rd.GetResource( L"texture.checkers" );
	}
	PixelFormat format = _synkro->GetGraphicsSystem()->GetViewWindow( 0 )->GetClientPixelFormat();
	P(IImage) diffuse = _synkro->GetImageManager()->LoadImage( streamImage, format );

	// Create material.
	_material = CreateMaterial( diffuse, Color::OrangeAerospace );

	// Create mesh.
	_mesh = _scene->CreateTriangleMesh( nullptr, String::Empty, _material, nullptr );
	_synkro->GetSceneManager()->BuildMesh( _mesh, MeshBuilder::Ellipsoid, Vector4(40.0f, 20.0f, 30.0f, 0.0f), Size(40, 40), Matrix4x4::Identity );

	// Create controllers.
	INodeAnimationController* ctrlMesh = _mesh->CreateAnimationController( nullptr, nullptr );

	Random rnd;
	INoiseFloatTrack* trackYaw = ctrlMesh->CreateOrientationYawTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackYaw->SetMagnitude( Math::Pi );
	trackYaw->SetSeed( rnd.GetUInt() );
	INoiseFloatTrack* trackPitch = ctrlMesh->CreateOrientationPitchTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackPitch->SetMagnitude( Math::Pi );
	trackPitch->SetSeed( rnd.GetUInt() );
	INoiseFloatTrack* trackRoll = ctrlMesh->CreateOrientationRollTrack( AnimationTrack::FloatNoise )->AsNoise();
	trackRoll->SetMagnitude( Math::Pi );
	trackRoll->SetSeed( rnd.GetUInt() );

	ISimpleMaterialAnimationController* ctrlMaterial = _material->CreateAnimationController( nullptr, nullptr )->AsSimple();
	INoiseColorTrack* trackColor = ctrlMaterial->CreateDiffuseAmbientColorTrack( AnimationTrack::ColorNoise )->AsNoise();
	trackColor->SetSeed( rnd.GetUInt() );

	// Start animation.
	ctrlMesh->SetMode( AnimationMode::Loop );
	ctrlMesh->Start( true );

	ctrlMaterial->SetMode( AnimationMode::Loop );
	ctrlMaterial->Start( true );
}

IOpaqueMaterial* NoiseConfigurationScene::CreateMaterial( IImage* diffuse, const Color& color )
{
	IOpaqueMaterial* material = _synkro->GetMaterialManager()->CreateOpaqueMaterial( LightingModel::Gouraud );
	material->GetDiffuseMap()->SetImage( diffuse );
	material->SetAmbientColor( color );
	material->SetDiffuseColor( color );
	material->SetSpecularColor( Color::White );
	material->SetSpecularPower( 10.0f );
	material->SetTilingHorizontal( 8 );
	material->SetTilingVertical( 8 );

	return material;
}


} // core


} // synkro
