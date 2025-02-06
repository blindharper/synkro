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
#ifndef _SYNKRO_UI_WIDGETEFFECT_
#define _SYNKRO_UI_WIDGETEFFECT_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <anim/IPlaybackAnimationController.h>
#include <anim/IKeyframedColorTrack.h>
#include <gfx/IOverlayRenderObject.h>
#include <over/IText.h>


namespace synkro
{


namespace ui
{


// Widget effect implementation.
class WidgetEffect :
	public anim::PlaybackControllerImpl<anim::IPlaybackAnimationController>
{
public:
	// Constructor.
	WidgetEffect( gfx::IOverlayRenderObject* widget, gfx::IOverlayRenderObject* widget2, over::IText* text, anim::IAnimationSystem* animationSystem, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// Other methods.
	void													Fade( const img::Color& from, const img::Color& to, const img::Color& textFrom = img::Color::Black, const img::Color& textTo = img::Color::Black );
	void													SetOpacity( Float opacity );

private:
	gfx::IOverlayRenderObject*								_widget;
	gfx::IOverlayRenderObject*								_widget2;
	over::IText*											_text;
	gfx::ProgramParam*										_paramColor;
	gfx::ProgramParam*										_paramColor2;
	anim::IAnimationColorTrack*								_trackColor;
	anim::IAnimationColorTrack*								_trackColor2;
	anim::IAnimationColorTrack*								_trackTextColor;
	Float													_opacity;

	anim::IKeyframedColorTrack*								CreateColorTrack();
	anim::IKeyframedColorTrack*								CreateColor2Track();
	anim::IKeyframedColorTrack*								CreateTextColorTrack();
	void													Setup( anim::IKeyframedColorTrack* track, const img::Color& from, const img::Color& to );
};


} // ui


} // synkro


#endif // _SYNKRO_UI_WIDGETEFFECT_
