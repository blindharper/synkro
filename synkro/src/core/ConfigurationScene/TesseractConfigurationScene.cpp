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
#include "TesseractConfigurationScene.h"
#include <scene/ISceneManager.h>
#include <scene/IScene.h>
#include <scene/ILineSet.h>
#include <scene/INodeAnimationController.h>
#include <internal/SizeOf.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::math;
using namespace synkro::view;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


TesseractConfigurationScene::TesseractConfigurationScene( ISynkro* synkro ) :
	ConfigurationScene( synkro, false )
{
	// Setup camera and viewport.
	_camera->SetPosition( Vector3(-4.0f, 4.0f, -4.0f) );
	_camera->LookAt( Vector3::Origin );

	// Setup post-processing filters.
	_blurFilter = _viewport->CreateFilter( ViewportFilter::Blur )->AsKernel3x3();
	_blurFilter->SetPassCount( 5 );

	_contrastFilter = _viewport->CreateFilter( ViewportFilter::Contrast )->AsSimple();
	_contrastFilter->SetValue( 15.0f );

	// Create geometry.
	_tesseract = _scene->CreateLineMesh( nullptr, L"Tesseract" );
	_tesseract->CreateLineList4D( L"Tesseract", 16, 64, false, ColorMode::Colored, Matrix4x4::Identity );
	ILineSet* tess = _tesseract->GetSubset( 0 )->AsLineSet();

	// Set positions.
	constexpr Float s = 0.5f;
	Vector4 positions[16] =
	{
		Vector4( s, s, s, s ),
		Vector4( -s, s, s, s ),
		Vector4( s, -s, s, s ),
		Vector4( -s, -s, s, s ),
		Vector4( s, s, -s, s ),
		Vector4( -s, s, -s, s ),
		Vector4( s, -s, -s, s ),
		Vector4( -s, -s, -s, s ),
		Vector4( s, s, s, -s ),
		Vector4( -s, s, s, -s ),
		Vector4( s, -s, s, -s ),
		Vector4( -s, -s, s, -s ),
		Vector4( s, s, -s, -s ),
		Vector4( -s, s, -s, -s ),
		Vector4( s, -s, -s, -s ),
		Vector4( -s, -s, -s, -s ),
	};
	tess->SetPositions( positions, 0, SizeOf(positions) );

	// Paint internal and external cubes with complementary colors.
	Color colors[16] = {};
	const Color color1 = Color::Green;
	const Color color2 = color1.Complementary();
	for ( UInt i = 0; i < 16; ++i )
	{
		colors[i] = (i < 8) ? color1 : color2;
	}
	tess->SetColors( colors, 0, SizeOf(colors) );

	// Set indices.
	UInt indices[64] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		0, 2, 1, 3, 4, 6, 5, 7, 8, 10, 9, 11, 12, 14, 13, 15,
		0, 4, 1, 5, 2, 6, 3, 7, 8, 12, 9, 13, 10, 14, 11, 15,
		0, 8, 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15,
	};
	tess->SetIndices( indices, 0, SizeOf(indices) );

	// Rotate tesseract in two planes.
	INodeAnimationController* ctrl = _tesseract->CreateAnimationController( nullptr, nullptr );
	ctrl->CreateTransformTrack( L"float t = 0.5*time; float s = sin(t); float c = cos(t); return matrix4x4(c, -s, 0.0, 0.0, s, c, 0.0, 0.0, 0.0, 0.0, c, -s, 0.0, 0.0, s, c);" );
	ctrl->SetMode( AnimationMode::Loop );
	ctrl->Start( true );
}


} // core


} // synkro
