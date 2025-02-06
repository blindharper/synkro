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
// Purpose: Extended view rendering window.
//==============================================================================
#include "config.h"
#include "ViewRenderWindow.h"
#include "GraphicsDevice.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


ViewRenderWindow::ViewRenderWindow( GraphicsDevice* device, IViewRenderWindow* window, IProgram* programScreen, IProgram* programView, UInt sampleCount ) :
	BaseRenderWindowImpl<BaseRenderWindow>( device, window, window->GetWidth(), window->GetHeight(), programScreen, programView, sampleCount ),
	_window( window )
{
	// Create default view.
	_views.Add( new RenderView(device, this, _programScreen, _programView, _blendStateEnabled, _blendStateDisabled, _window->GetPixelFormat(), _device->GetDepthFormat(), 0, 0, window->GetWidth(), window->GetHeight(), sampleCount, Vector4(0.0f, 0.0f, 0.0f, 1.0f)) );
}

void ViewRenderWindow::EnableOverlay()
{
	BaseRenderWindowImpl<BaseRenderWindow>::CreateOverlay();
}


} // gfx


} // synkro
