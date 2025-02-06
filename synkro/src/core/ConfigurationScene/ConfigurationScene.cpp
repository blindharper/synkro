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
#include "ConfigurationScene.h"
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <scene/ISceneManager.h>
#include <view/IViewportManager.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::scene;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ConfigurationScene::ConfigurationScene( ISynkro* synkro, Bool lit ) :
	_synkro( synkro )
{
	// Create scene.
	_scene = _synkro->GetSceneManager()->CreateScene( L"Configuration", DebugMode::None, lit );

	// Setup camera and viewport.
	_camera = _scene->CreateCamera( nullptr, L"Camera" );
	_camera->SetHorizontalFieldOfView( Math::QuarterPi );
	_camera->SetFront( 0.1f );
	_camera->SetBack( 500.0f );

	_viewport = _synkro->GetViewportManager()->GetViewport( _synkro->GetGraphicsSystem()->GetViewWindow(1)->GetView() );
	_viewport->SetCamera( _camera );
	_viewport->SetColor( Color::Black );
}


} // core


} // synkro
