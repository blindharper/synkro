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


SpriteAnimationController::SpriteAnimationController( ISprite* sprite, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<ISpriteAnimationController>( animationSystem, animations, listener ),
	_sprite( sprite ),
	_trackLocation( nullptr ),
	_trackLocationX( nullptr ),
	_trackLocationY( nullptr ),
	_trackSize( nullptr ),
	_trackOrientation( nullptr ),
	_trackOpacity( nullptr ),
	_trackFrame( nullptr ),
	_trackVisibility( nullptr )
{
}

void SpriteAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ISpriteAnimationController>::Update( delta );

	// Update sprite.
	if ( _trackLocation != nullptr )
	{
		Point location;
		_trackLocation->GetValue( CurrentTime(), location );
		_sprite->SetLocation( location );
	}
	else
	{
		if ( _trackLocationX != nullptr )
		{
			Float pos;
			_trackLocationX->GetValue( CurrentTime(), pos );
			_sprite->SetLocationX( pos );
		}

		if ( _trackLocationY != nullptr )
		{
			Float pos;
			_trackLocationY->GetValue( CurrentTime(), pos );
			_sprite->SetLocationY( pos );
		}
	}

	if ( _trackSize != nullptr )
	{
		Size size;
		_trackSize->GetValue( CurrentTime(), size );
		_sprite->SetSize( size );
	}

	if ( _trackOrientation != nullptr )
	{
		Float orientation;
		_trackOrientation->GetValue( CurrentTime(), orientation );
		_sprite->SetOrientation( orientation );
	}

	if ( _trackOpacity != nullptr )
	{
		Float opacity;
		_trackOpacity->GetValue( CurrentTime(), opacity );
		_sprite->SetOpacity( opacity );
	}

	if ( _trackFrame != nullptr )
	{
		RectF frame;
		_trackFrame->GetValue( CurrentTime(), frame );
		_sprite->SetFrame( frame );
	}

	if ( _trackVisibility != nullptr )
	{
		Bool show;
		_trackVisibility->GetValue( CurrentTime(), show );
		_sprite->Show( show );
	}
}

IKeyframedPointTrack* SpriteAnimationController::CreateLocationTrack()
{
	return (_trackLocation = _animations->GetActiveAnimation()->CreatePointTrack( SpriteProperty::Location.ToString()) )->AsKeyframed();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateLocationXTrack()
{
	return (_trackLocationX = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::LocationX.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateLocationXTrack( const AnimationTrack& type )
{
	return (_trackLocationX = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::LocationX.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateLocationYTrack()
{
	return (_trackLocationY = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::LocationY.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateLocationYTrack( const AnimationTrack& type )
{
	return (_trackLocationY = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::LocationY.ToString(), type) )->AsProcedural();
}

IKeyframedSizeTrack* SpriteAnimationController::CreateSizeTrack()
{
	return (_trackSize = _animations->GetActiveAnimation()->CreateSizeTrack( SpriteProperty::Size.ToString()) )->AsKeyframed();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateOrientationTrack()
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::Orientation.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateOrientationTrack( const AnimationTrack& type )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::Orientation.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* SpriteAnimationController::CreateOpacityTrack()
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::Opacity.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SpriteAnimationController::CreateOpacityTrack( const AnimationTrack& type )
{
	return (_trackOpacity = _animations->GetActiveAnimation()->CreateFloatTrack( SpriteProperty::Opacity.ToString(), type) )->AsProcedural();
}

IKeyframedFloatRectTrack* SpriteAnimationController::CreateFrameTrack()
{
	return (_trackFrame = _animations->GetActiveAnimation()->CreateFloatRectTrack( SpriteProperty::Frame.ToString()) )->AsKeyframed();
}

IKeyframedBoolTrack* SpriteAnimationController::CreateVisibilityTrack()
{
	return (_trackVisibility = _animations->GetActiveAnimation()->CreateBoolTrack( SpriteProperty::Visibility.ToString()) )->AsKeyframed();
}

IProceduralBoolTrack* SpriteAnimationController::CreateVisibilityTrack( const AnimationTrack& type )
{
	return (_trackVisibility = _animations->GetActiveAnimation()->CreateBoolTrack( SpriteProperty::Visibility.ToString(), type) )->AsProcedural();
}

void SpriteAnimationController::UpdateTracks()
{
	_trackLocation		= GetTrack( _trackLocation, SpriteProperty::Location );
	_trackLocationX		= GetTrack( _trackLocationX, SpriteProperty::LocationX );
	_trackLocationY		= GetTrack( _trackLocationY, SpriteProperty::LocationY );
	_trackSize			= GetTrack( _trackSize, SpriteProperty::Size );
	_trackOrientation	= GetTrack( _trackOrientation, SpriteProperty::Orientation );
	_trackOpacity		= GetTrack( _trackOpacity, SpriteProperty::Opacity );
	_trackFrame			= GetTrack( _trackFrame, SpriteProperty::Frame );
	_trackVisibility	= GetTrack( _trackVisibility, SpriteProperty::Visibility );
}


} // over


} // synkro
