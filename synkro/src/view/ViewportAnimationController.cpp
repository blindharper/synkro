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
// Purpose: Animation controller for viewport.
//==============================================================================
#include "config.h"
#include "ViewportAnimationController.h"
#include "ViewportProperty.h"
#include <view/IViewport.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


ViewportAnimationController::ViewportAnimationController( IViewport* viewport, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<IViewportAnimationController>( animationSystem, animations, listener ),
	_viewport( viewport ),
	_trackLocation( nullptr ),
	_trackSize( nullptr ),
	_trackRect( nullptr ),
	_trackColor( nullptr ),
	_trackOpacity( nullptr )
{
}

void ViewportAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IViewportAnimationController>::Update( delta );

	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( CurrentTime(), location );
		_viewport->SetLocation( location );
	}

	if ( _trackSize != nullptr )
	{
		Size size;
		_trackSize->GetValue( CurrentTime(), size );
		_viewport->SetSize( size );
	}

	if ( _trackRect != nullptr )
	{
		Rect rect;
		_trackRect->GetValue( CurrentTime(), rect );
		_viewport->SetRect( rect );
	}

	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( CurrentTime(), color );
		_viewport->SetColor( color );
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( CurrentTime(), opacity );
		_viewport->SetOpacity( opacity );
	}
}

IKeyframedPointTrack* ViewportAnimationController::CreateLocationTrack()
{
	return (_trackLocation = _animations->GetActiveAnimation()->CreatePointTrack( ViewportProperty::Location.ToString()) )->AsKeyframed();
}

IKeyframedSizeTrack* ViewportAnimationController::CreateSizeTrack()
{
	return (_trackSize = _animations->GetActiveAnimation()->CreateSizeTrack( ViewportProperty::Size.ToString()) )->AsKeyframed();
}

IKeyframedRectTrack* ViewportAnimationController::CreateRectTrack()
{
	return (_trackRect = _animations->GetActiveAnimation()->CreateRectTrack( ViewportProperty::Rect.ToString()) )->AsKeyframed();
}

IKeyframedColorTrack* ViewportAnimationController::CreateColorTrack()
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( ViewportProperty::Color.ToString()) )->AsKeyframed();
}

IProceduralColorTrack* ViewportAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = _animations->GetActiveAnimation()->CreateColorTrack( ViewportProperty::Color.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* ViewportAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( ViewportProperty::Opacity.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* ViewportAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( ViewportProperty::Opacity.ToString(), type) )->AsProcedural();
}

void ViewportAnimationController::UpdateTracks()
{
	_trackLocation	= GetTrack( _trackLocation, ViewportProperty::Location );
	_trackSize		= GetTrack( _trackSize, ViewportProperty::Size );
	_trackRect		= GetTrack( _trackRect, ViewportProperty::Rect );
	_trackColor		= GetTrack( _trackColor, ViewportProperty::Color );
	_trackOpacity	= GetTrack( _trackOpacity, ViewportProperty::Opacity );
}


} // view


} // synkro
