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
// Purpose: Animation controller for sound source.
//==============================================================================
#include "config.h"
#include "SoundAnimationController.h"
#include "SoundProperty.h"
#include <scene/IConeSound.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


SoundAnimationController::SoundAnimationController( ISound* sound, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	NodeAnimationControllerImpl<ISoundAnimationController>( sound, animationSystem, animation, listener ),
	_sound( sound )
{
	SetAnimation( _animation );
}

void SoundAnimationController::Update( Double delta )
{
	// Call base implementation.
	NodeAnimationControllerImpl<ISoundAnimationController>::Update( delta );

	// Update sound.
	if ( _trackAvailability != nullptr )
	{
		Bool enabled;
		_trackAvailability->GetValue( _time, enabled );
		_sound->Enable( enabled );
	}

	if ( !_sound->IsEnabled() )
		return;

	IConeSound* cone = _sound->AsCone();
	if ( cone != nullptr )
	{
		if ( _trackInnerVolume != nullptr )
		{
			Float volume;
			_trackInnerVolume->GetValue( _time, volume );
			cone->SetInnerVolume( volume );
		}

		if ( _trackOuterVolume != nullptr )
		{
			Float volume;
			_trackOuterVolume->GetValue( _time, volume );
			cone->SetOuterVolume( volume );
		}
	}
}

void SoundAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	NodeAnimationControllerImpl<ISoundAnimationController>::SetAnimation( animation );

	_trackInnerVolume	= GetTrack( _trackInnerVolume, SoundProperty::InnerVolume );
	_trackOuterVolume	= GetTrack( _trackOuterVolume, SoundProperty::OuterVolume );
	_trackAvailability	= GetTrack( _trackAvailability, SoundProperty::Availability );	
}

ISoundAnimationController* SoundAnimationController::AsSound() const
{
	return (ISoundAnimationController*)this;
}

IKeyframedFloatTrack* SoundAnimationController::CreateInnerVolumeTrack()
{
	return (_trackInnerVolume = (_trackInnerVolume == nullptr) ? _animation->CreateFloatTrack(SoundProperty::InnerVolume.ToString()) : _trackInnerVolume)->AsKeyframed();
}

IProceduralFloatTrack* SoundAnimationController::CreateInnerVolumeTrack( const AnimationTrack& type )
{
	return (_trackInnerVolume = (_trackInnerVolume == nullptr) ? _animation->CreateFloatTrack(SoundProperty::InnerVolume.ToString(), type) : _trackInnerVolume)->AsProcedural();
}

IKeyframedFloatTrack* SoundAnimationController::CreateOuterVolumeTrack()
{
	return (_trackOuterVolume = (_trackOuterVolume == nullptr) ? _animation->CreateFloatTrack(SoundProperty::OuterVolume.ToString()) : _trackOuterVolume)->AsKeyframed();
}

IProceduralFloatTrack* SoundAnimationController::CreateOuterVolumeTrack( const AnimationTrack& type )
{
	return (_trackOuterVolume = (_trackOuterVolume == nullptr) ? _animation->CreateFloatTrack(SoundProperty::OuterVolume.ToString(), type) : _trackOuterVolume)->AsProcedural();
}

IKeyframedBoolTrack* SoundAnimationController::CreateAvailabilityTrack()
{
	return (_trackAvailability = (_trackAvailability == nullptr) ? _animation->CreateBoolTrack(SoundProperty::Availability.ToString()) : _trackAvailability)->AsKeyframed();
}


} // scene


} // synkro
