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


ViewportAnimationController::ViewportAnimationController( IViewport* viewport, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<IViewportAnimationController>( animationSystem, animation, listener ),
	_viewport( viewport )
{
	SetAnimation( _animation );
}

void ViewportAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IViewportAnimationController>::Update( delta );

	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( _time, location );
		_viewport->SetLocation( location );
	}

	if ( _trackSize != nullptr )
	{
		Size size;
		_trackSize->GetValue( _time, size );
		_viewport->SetSize( size );
	}

	if ( _trackRect != nullptr )
	{
		Rect rect;
		_trackRect->GetValue( _time, rect );
		_viewport->SetRect( rect );
	}

	if ( _trackColor != nullptr )
	{
		Color color;
		_trackColor->GetValue( _time, color );
		_viewport->SetColor( color );
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( _time, opacity );
		_viewport->SetOpacity( opacity );
	}
}

void ViewportAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<IViewportAnimationController>::SetAnimation( animation );

	_trackLocation	= GetTrack( _trackLocation, ViewportProperty::Location );
	_trackSize		= GetTrack( _trackSize, ViewportProperty::Size );
	_trackRect		= GetTrack( _trackRect, ViewportProperty::Rect );
	_trackColor		= GetTrack( _trackColor, ViewportProperty::Color );
	_trackOpacity	= GetTrack( _trackOpacity, ViewportProperty::Opacity );
}

IKeyframedPointTrack* ViewportAnimationController::CreateLocationTrack()
{
	return (_trackLocation = (_trackLocation == nullptr) ? _animation->CreatePointTrack(ViewportProperty::Location.ToString()) : _trackLocation)->AsKeyframed();
}

IKeyframedSizeTrack* ViewportAnimationController::CreateSizeTrack()
{
	return (_trackSize = (_trackSize == nullptr) ? _animation->CreateSizeTrack(ViewportProperty::Size.ToString()) : _trackSize)->AsKeyframed();
}

IKeyframedRectTrack* ViewportAnimationController::CreateRectTrack()
{
	return (_trackRect = (_trackRect == nullptr) ? _animation->CreateRectTrack(ViewportProperty::Rect.ToString()) : _trackRect)->AsKeyframed();
}

IKeyframedColorTrack* ViewportAnimationController::CreateColorTrack()
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(ViewportProperty::Color.ToString()) : _trackColor)->AsKeyframed();
}

IProceduralColorTrack* ViewportAnimationController::CreateColorTrack( const AnimationTrack& type )
{
	return (_trackColor = (_trackColor == nullptr) ? _animation->CreateColorTrack(ViewportProperty::Color.ToString(), type) : _trackColor)->AsProcedural();
}

IKeyframedFloatTrack* ViewportAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(ViewportProperty::Opacity.ToString()) : _trackOpacity)->AsKeyframed();
}

IProceduralFloatTrack* ViewportAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(ViewportProperty::Opacity.ToString(), type) : _trackOpacity)->AsProcedural();
}


} // view


} // synkro
