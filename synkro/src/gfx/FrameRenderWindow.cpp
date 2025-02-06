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
// Purpose: Extended frame rendering window.
//==============================================================================
#include "config.h"
#include "FrameRenderWindow.h"
#include "GraphicsDevice.h"
#include "BlendState.h"
#include "DepthStencilState.h"
#include "RasterizerState.h"
#include "SamplerStateSet.h"
#include <win/IFrameWindow.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


FrameRenderWindow::FrameRenderWindow( GraphicsDevice* device, IFrameRenderWindow* window, IProgram* programScreen, IProgram* programView, UInt sampleCount, ILog* log ) :
	BaseRenderWindowImpl<BaseRenderWindow>( device, window, window->GetWidth(), window->GetHeight(), programScreen, programView, sampleCount),
	_window( window ),
	_target( nullptr ),
	Logger( log, LogFacility::WindowSystem )
{
	// Create default view.
	CreateView( 0, 0, window->GetWidth(), window->GetHeight(), sampleCount, Vector4(0.0f, 0.0f, 0.0f, 1.0f) );
}

Bool FrameRenderWindow::SetDisplayMode( const DisplayMode& displayMode )
{
	// See if we really need to change anything.
	DisplayMode oldMode; _window->GetDisplayMode( oldMode );
	if ( displayMode == oldMode )
		return true;

	// Try applying new display mode.
	LogInfoStart( MessagePriority::Normal, Formatter::Format(Str::SettingDisplayMode, displayMode.ToString(DisplayModeFormat::Complete)) );
	Bool ok = _window->SetDisplayMode( displayMode );
	if ( ok )
	{
		Resize();
		LogInfoEnd( Formatter::Format(Str::Done) );
	}
	else
	{
		LogInfoEnd( String::Empty );
		LogWarning( MessagePriority::Normal, Formatter::Format(Str::DisplayModeFail) );
		_window->SetDisplayMode( oldMode );
	}

	// Set window mode.
	Bool fullscreen = ok ? displayMode.Fullscreen : oldMode.Fullscreen;
	GetWindow()->SetPopup( fullscreen );
	if ( !fullscreen )
	{
		GetWindow()->Center();
	}

	return ok;
}

IRenderView* FrameRenderWindow::CreateView( Int left, Int top, UInt width, UInt height, UInt sampleCount, const Vector4& color )
{
	RenderView* view = new RenderView( _device, this, _programScreen, _programView, _blendStateEnabled, _blendStateDisabled, _window->GetPixelFormat(), _device->GetDepthFormat(), left, top, width, height, sampleCount, color );
	_views.Add( view );
	return view;
}

void FrameRenderWindow::EnableOverlay()
{
	BaseRenderWindowImpl<BaseRenderWindow>::CreateOverlay();
}


} // gfx


} // synkro
