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
// Purpose: Virtual rendering window.
//==============================================================================
#include "config.h"
#include "VirtualRenderWindow.h"
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


VirtualRenderWindow::VirtualRenderWindow( GraphicsDevice* device, UInt width, UInt height, const PixelFormat& format, IProgram* programScreen, IProgram* programView, UInt sampleCount, UInt sampleQuality ) :
	BaseRenderWindowImpl<BaseRenderWindow>( device, nullptr, width, height, programScreen, programView, sampleCount )
{
	// Create target.
	_target = device->CreateRenderTexture( width, height, format, sampleCount, sampleQuality );

	// Create default view.
	_views.Add( new RenderView(device, this, _programScreen, _programView, _blendStateEnabled, _blendStateDisabled, format, _device->GetDepthFormat(), 0, 0, width, height, sampleCount, Vector4(0.0f, 0.0f, 0.0f, 1.0f)) );
}

void VirtualRenderWindow::EnableOverlay()
{
	BaseRenderWindowImpl<BaseRenderWindow>::CreateOverlay();
}


} // gfx


} // synkro
