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
// Purpose: Banner displayed in the configuration editor.
//==============================================================================
#include "config.h"
#include "ConfigurationBanner.h"
#include <core/ISynkro.h>
#include <anim/IKeyframedFloatTrack.h>
#include <anim/IKeyframedColorGradientTrack.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IGraphicsDeviceEx.h>
#include <gfx/IViewRenderWindowEx.h>
#include <gfx/IOverlayRenderQueue.h>
#include <gfx/IVector4Stream.h>
#include <gfx/IPrimitiveEx.h>
#include <over/IOverlayManager.h>
#include <over/IOverlay.h>
#include <over/IFont.h>
#include <over/ITextAnimationController.h>
#include <view/IViewportManager.h>
#include <view/IViewport.h>
#include <internal/ToVector.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::over;
using namespace synkro::view;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ConfigurationBanner::ConfigurationBanner( ISynkro* synkro ) :
	_synkro( synkro )
{
	// Setup viewport.
	IViewRenderWindowEx* window = _synkro->GetGraphicsSystem()->GetViewWindow( 0 );
	IViewport* viewport = synkro->GetViewportManager()->GetViewport( window->GetView() );
	_synkro->GetOverlayManager()->CreateFont( L"ConfigBannerText", _synkro->GetLanguage(), L"Arial", FontStyle::Bold, 28 );
	
	// Create background.
	IProgram* program = _synkro->GetGraphicsSystem()->GetProgram( L"overlay.colored" );
	IPrimitive* data = _synkro->GetGraphicsSystem()->GetDevice()->CreatePrimitive( program, DataUsage::Dynamic, DataAccess::WriteOnly, PrimitiveType::TriangleStrip, IndexType::None, 4, 0, 0, 0, true, false );
	_back = window->GetOverlayQueue()->CreateObject( data );
	_back->SetOrder( Order::GetValue(Order::Lowest, Order::Low) );
	
	P(IVector4Stream) streamPositions = (IVector4Stream*)_back->GetData()->GetVertexStream( DataStream::Position2D, 0 );
	if ( (streamPositions != nullptr) && streamPositions->Open(OpenMode::Write) )
	{
		const Float width = CastFloat(window->GetWidth());
		const Float height = CastFloat(window->GetHeight());
		Vector4 pos[] =
		{
			Vector4( 0.0f,	0.0f,	0.0f, 1.0f ),
			Vector4( 0.0f,	height,	0.0f, 1.0f ),
			Vector4( width,	0.0f,	0.0f, 1.0f ),
			Vector4( width,	height,	0.0f, 1.0f ),
		};
		streamPositions->Write( pos, 4 );
		streamPositions->Close();
	}

	P(IVector4Stream) streamColors = (IVector4Stream*)_back->GetData()->GetVertexStream( DataStream::Color, 0 );
	if ( (streamColors != nullptr) && streamColors->Open(OpenMode::Write) )
	{
		const Color start = Color::DarkGreen;
		const Color end = Color::White;
		Vector4 colors[] =
		{
			ToVector( start ),
			ToVector( start ),
			ToVector( end ),
			ToVector( end ),
		};
		streamColors->Write( colors, 4 );
		streamColors->Close();
	}

	// Create text.
	IOverlay* overlay = _synkro->GetOverlayManager()->GetOverlay( window );
	IFont* font = overlay->GetFont( L"ConfigBannerText" );
	_text = font->CreateText( ColorGradient(GradientType::Vertical, Color::Violet, Color::Lime), Point(3, 3), L"SYNKRO", Order::Highest, Order::High );

	// Create text animation.
	ITextAnimationController* ctrlText = _text->CreateAnimationController( nullptr, nullptr );
	IKeyframedColorGradientTrack* trackGradient = ctrlText->CreateColorGradientTrack();
	trackGradient->SetKey( 0.0, ColorGradient(GradientType::Vertical, Color::Violet, Color::Lime) );
	trackGradient->SetKey( 3.0, ColorGradient(GradientType::Vertical, Color::Yellow, Color::Red) );
	trackGradient->SetKey( 6.0, ColorGradient(GradientType::Vertical, Color::Violet, Color::Lime) );

	Size sz; font->GetTextSize( _text->GetText(), sz );
	IKeyframedFloatTrack* trackPosition = ctrlText->CreateLocationXTrack();
	trackPosition->SetKey( 0.0, CastFloat(window->GetWidth()) );
	trackPosition->SetKey( 6.0, -CastFloat(sz.Width) );
	
	// Start animating text.
	ctrlText->SetMode( AnimationMode::Loop );
	ctrlText->Start( true );
}


} // core


} // synkro
