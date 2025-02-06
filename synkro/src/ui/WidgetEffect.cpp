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
// Purpose: Widget effect implementation.
//==============================================================================
#include "config.h"
#include "WidgetEffect.h"
#include <gfx/IParameterSet.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::gfx;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::over;

//------------------------------------------------------------------------------


namespace synkro
{


namespace ui
{


WidgetEffect::WidgetEffect( IOverlayRenderObject* widget, IOverlayRenderObject* widget2, IText* text, IAnimationSystem* animationSystem, AnimationListener* listener ) :
	PlaybackControllerImpl<IPlaybackAnimationController>( animationSystem, nullptr, listener ),
	_widget( widget ),
	_widget2( widget2 ),
	_text( text ),
	_trackColor( nullptr ),
	_trackColor2( nullptr ),
	_trackTextColor( nullptr ),
	_opacity( 1.0f )
{
	assert( _widget != nullptr );

	_paramColor = _widget->GetFragmentParameters()->GetParam( L"p_color" );
	_paramColor2 = (_widget2 != nullptr) ? _widget2->GetFragmentParameters()->GetParam( L"p_color" ) : nullptr;
	_trackColor = CreateColorTrack();
	_trackColor2 = CreateColor2Track();
	_trackTextColor = CreateTextColorTrack();
}

void WidgetEffect::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IPlaybackAnimationController>::Update( delta );

	// Animate widget parameters.
	Color color;
	if ( _trackColor != nullptr )
	{
		_trackColor->GetValue( _time, color );
		_widget->GetFragmentParameters()->Set( _paramColor, ToVector(color, _opacity) );
	}

	if ( _trackColor2 != nullptr )
	{
		_trackColor2->GetValue( _time, color );
		_widget2->GetFragmentParameters()->Set( _paramColor2, ToVector(color, _opacity) );
	}

	if ( _trackTextColor != nullptr )
	{
		_trackTextColor->GetValue( _time, color );
		if ( _text != nullptr )
		{
			_text->SetColor( color );
		}
	}
}

void WidgetEffect::Fade( const Color& from, const Color& to, const Color& textFrom, const Color& textTo )
{
	Setup( CreateColorTrack(), from, to );
	Setup( CreateColor2Track(), from, to );
	Setup( CreateTextColorTrack(), textFrom, textTo );
	Reset();
	Start( true );
}

void WidgetEffect::SetOpacity( Float opacity )
{
	_opacity = opacity;
}

IKeyframedColorTrack* WidgetEffect::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack( L"Color" ) : _trackColor)->AsKeyframed();
}

IKeyframedColorTrack* WidgetEffect::CreateColor2Track()
{
	if ( _widget2 == nullptr )
		return nullptr;

	return (_trackColor2 = (_trackColor2 == nullptr) ? _animation->CreateColorTrack( L"Color2" ) : _trackColor2)->AsKeyframed();
}

IKeyframedColorTrack* WidgetEffect::CreateTextColorTrack()
{
	return (_trackTextColor = (_trackTextColor == nullptr) ? _animation->CreateColorTrack( L"TextColor" ) : _trackTextColor)->AsKeyframed();
}

void WidgetEffect::Setup( IKeyframedColorTrack* track, const Color& from, const Color& to )
{
	if ( track != nullptr )
	{
		track->Clear();
		track->SetKey( 0.0, from );
		track->SetKey( 0.3, to );
	}
}


} // ui


} // synkro
