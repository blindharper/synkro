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
// Purpose: Animation controller for sprite.
//==============================================================================
#include "config.h"
#include "SpriteAnimationController.h"
#include "SpriteProperty.h"
#include <over/ISprite.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace over
{


SpriteAnimationController::SpriteAnimationController( ISprite* sprite, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<ISpriteAnimationController>( animationSystem, animation, listener ),
	_sprite( sprite )
{
	SetAnimation( _animation );
}

void SpriteAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ISpriteAnimationController>::Update( delta );

	// Update sprite.
	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( _time, location );
		_sprite->SetLocation( location );
	}
	else
	{
		if ( _trackLocationX != nullptr )
		{
			Float pos;
			_trackLocationX->GetValue( _time, pos );
			_sprite->SetLocationX( pos );
		}

		if ( _trackLocationY != nullptr )
		{
			Float pos;
			_trackLocationY->GetValue( _time, pos );
			_sprite->SetLocationY( pos );
		}
	}

	if ( _trackSize != nullptr )
	{
		Size size;
		_trackSize->GetValue( _time, size );
		_sprite->SetSize( size );
	}

	if ( _trackOrientation != nullptr )
	{
		Float orientation;
		_trackOrientation->GetValue( _time, orientation );
		_sprite->SetOrientation( orientation );
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( _time, opacity );
		_sprite->SetOpacity( opacity );
	}

	if ( _trackFrame != nullptr )
	{
		RectF frame;
		_trackFrame->GetValue( _time, frame );
		_sprite->SetFrame( frame );
	}

	if ( _trackVisibility != nullptr )
	{
		Bool show;
		_trackVisibility->GetValue( _time, show );
		_sprite->Show( show );
	}
}

void SpriteAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<ISpriteAnimationController>::SetAnimation( animation );

	_trackLocation		= GetTrack( _trackLocation, SpriteProperty::Location );
	_trackLocationX		= GetTrack( _trackLocationX, SpriteProperty::LocationX );
	_trackLocationY		= GetTrack( _trackLocationY, SpriteProperty::LocationY );
	_trackSize			= GetTrack( _trackSize, SpriteProperty::Size );
	_trackOrientation	= GetTrack( _trackOrientation, SpriteProperty::Orientation );
	_trackOpacity		= GetTrack( _trackOpacity, SpriteProperty::Opacity );
	_trackFrame			= GetTrack( _trackFrame, SpriteProperty::Frame );
	_trackVisibility	= GetTrack( _trackVisibility, SpriteProperty::Visibility );
}

IKeyframedPointTrack* SpriteAnimationController::CreateLocationTrack()
{
	return (_trackLocation = (_trackLocation == nullptr) ? _animation->CreatePointTrack(SpriteProperty::Location.ToString()) : _trackLocation)->AsKeyframed();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateLocationXTrack()
{
	return (_trackLocationX = (_trackLocationX == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::LocationX.ToString()) : _trackLocationX)->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateLocationXTrack( const AnimationTrack& type )
{
	return (_trackLocationX = (_trackLocationX == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::LocationX.ToString(), type) : _trackLocationX)->AsProcedural();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateLocationYTrack()
{
	return (_trackLocationY = (_trackLocationY == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::LocationY.ToString()) : _trackLocationY)->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateLocationYTrack( const AnimationTrack& type )
{
	return (_trackLocationY = (_trackLocationY == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::LocationY.ToString(), type) : _trackLocationY)->AsProcedural();
}

IKeyframedSizeTrack* SpriteAnimationController::CreateSizeTrack()
{
	return (_trackSize = (_trackSize == nullptr) ? _animation->CreateSizeTrack(SpriteProperty::Size.ToString()) : _trackSize)->AsKeyframed();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateOrientationTrack()
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::Orientation.ToString()) : _trackOrientation)->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateOrientationTrack( const AnimationTrack& type )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::Orientation.ToString(), type) : _trackOrientation)->AsProcedural();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::Opacity.ToString()) : _trackOpacity)->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = (_trackOpacity == nullptr) ? _animation->CreateFloatTrack(SpriteProperty::Opacity.ToString(), type) : _trackOpacity)->AsProcedural();
}

IKeyframedFloatRectTrack* SpriteAnimationController::CreateFrameTrack()
{
	return (_trackFrame = (_trackFrame == nullptr) ? _animation->CreateFloatRectTrack(SpriteProperty::Frame.ToString()) : _trackFrame)->AsKeyframed();
}

IKeyframedBoolTrack* SpriteAnimationController::CreateVisibilityTrack()
{
	return (_trackVisibility = (_trackVisibility == nullptr) ? _animation->CreateBoolTrack(SpriteProperty::Visibility.ToString()) : _trackVisibility)->AsKeyframed();
}


} // over


} // synkro
