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
// Purpose: Overlay manager implementation.
//==============================================================================
#include "config.h"
#include "OverlayManager.h"
#include "Overlay.h"
#include "FontEx.h"
#include <io/IStreamDirectory.h>
#include <img/IImageManager.h>
#include <img/IImage.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IFrameRenderWindowEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IVirtualRenderWindow.h>
#include <gfx/IBlendStateSet.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::input;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


OverlayManager::OverlayManager( IContext* context, ILog* log ) :
	_overlays( A(OverlayEntry) ),
	_fonts( A(TemplateEntry) ),
	_context( context ),
	Logger( log, LogFacility::OverlayManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating overlay manager...") );
}

OverlayManager::~OverlayManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying overlay manager...") );
}

Bool OverlayManager::Update( Double delta )
{
	SynkroProfile( "OverlayManager.Update" );

	MapIterator<UInt, P(Overlay)> itOverlay = _overlays.Begin();
	MapIterator<UInt, P(Overlay)> itOverlayEnd = _overlays.End();
	for ( ; itOverlay != itOverlayEnd ; ++itOverlay )
	{
		((Overlay*)(IOverlay*)itOverlay.Value())->Update();
	}
	return true;
}

IOverlay* OverlayManager::CreateOverlay( IVirtualRenderWindow* window )
{
	assert( window != nullptr );

	IRenderWindow* wnd = (IRenderWindow*)window;
	UInt key = wnd->ID();
	if ( _overlays.ContainsKey(key) )
		return _overlays[key];

	window->EnableOverlay();
	Overlay* overlay = new Overlay( this, wnd, window->GetOverlayQueue(), _context );
	_overlays[key] = overlay;
	return overlay;
}

IOverlay* OverlayManager::CreateOverlay( IImage* image )
{
	assert( image != nullptr );
	assert( image->AsPlainRenderTexture() != nullptr );

	if ( image->AsPlainRenderTexture() == nullptr )
		throw BadArgumentException( L"Invalid image", L"image", L"nullptr" );

	UInt key = image->ID();
	if ( _overlays.ContainsKey(key) )
		return _overlays[key];

	Overlay* overlay = new Overlay( this, image, _context );
	_overlays[key] = overlay;
	return overlay;
}

void OverlayManager::CreateFont( const String& name, const Language& language, const String& family, const FontStyle& style, UInt size )
{
	assert( !_fonts.ContainsKey(name) );

	if ( _fonts.ContainsKey(name) )
		throw BadArgumentException( String::Format(L"Font {0,q} already exists.", name), L"name", name );

	_fonts[name] = FontTemplate( language, _context->GetImageManager(), family, style, size);
}

IFont* OverlayManager::CreateFont( const String& name, IOverlay* overlay )
{
	if ( _fonts.ContainsKey(name) )
	{
		_fonts[name].Prepare();
		return new FontEx( &_fonts[name], (Overlay*)overlay );
	}
	return nullptr;
}

void OverlayManager::Init()
{
	IGraphicsSystemEx* graphicsSystem = _context->GetGraphicsSystem();

	// Initialize shared font stuff.
	_fontProgram = graphicsSystem->GetProgram(L"overlay.textured.colored");

	_blendStates = graphicsSystem->GetDevice()->GetBlendStates()->Clone();
	IBlendState* state = _blendStates->Get( 0 );
	state->Enable( true );
	state->SetSrcMode( BlendMode::SrcAlpha );
	state->SetDstMode( BlendMode::InvSrcAlpha );

	// Create an overlay for each rendering window.
	_fonts.Clear();
	_overlays.Clear();
	for ( UInt i = 0; i < graphicsSystem->GetFrameWindowCount(); ++i )
	{
		IFrameRenderWindowEx* window = graphicsSystem->GetFrameWindow( i );
		IRenderWindow* wnd = (IRenderWindow*)(IFrameRenderWindow*)window;
		window->EnableOverlay();
		_overlays[wnd->ID()] = new Overlay( this, wnd, window->GetOverlayQueue(), _context );
	}
	for ( UInt i = 0; i < graphicsSystem->GetViewWindowCount(); ++i )
	{
		IViewRenderWindowEx* window = graphicsSystem->GetViewWindow( i );
		IRenderWindow* wnd = (IRenderWindow*)(IViewRenderWindow*)window;
		window->EnableOverlay();
		_overlays[wnd->ID()] = new Overlay( this, wnd, window->GetOverlayQueue(), _context );
	}
}


} // over


} // synkro
