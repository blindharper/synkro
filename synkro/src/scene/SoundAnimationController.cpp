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


SoundAnimationController::SoundAnimationController( ISound* sound, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	NodeAnimationControllerImpl<ISoundAnimationController>( sound, animationSystem, animations, listener ),
	_sound( sound )
{
}

void SoundAnimationController::Update( Double delta )
{
	// Call base implementation.
	NodeAnimationControllerImpl<ISoundAnimationController>::Update( delta );

	// Update sound.
	if ( _trackAvailability != nullptr )
	{
		Bool enabled;
		_trackAvailability->GetValue( CurrentTime(), enabled );
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
			_trackInnerVolume->GetValue( CurrentTime(), volume );
			cone->SetInnerVolume( volume );
		}

		if ( _trackOuterVolume != nullptr )
		{
			Float volume;
			_trackOuterVolume->GetValue( CurrentTime(), volume );
			cone->SetOuterVolume( volume );
		}
	}
}

ISoundAnimationController* SoundAnimationController::AsSound() const
{
	return (ISoundAnimationController*)this;
}

IKeyframedFloatTrack* SoundAnimationController::CreateInnerVolumeTrack()
{
	return (_trackInnerVolume = _animations->GetActiveAnimation()->CreateFloatTrack( SoundProperty::InnerVolume.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SoundAnimationController::CreateInnerVolumeTrack( const AnimationTrack& type )
{
	return (_trackInnerVolume = _animations->GetActiveAnimation()->CreateFloatTrack( SoundProperty::InnerVolume.ToString(), type) )->AsProcedural();
}

IKeyframedFloatTrack* SoundAnimationController::CreateOuterVolumeTrack()
{
	return (_trackOuterVolume = _animations->GetActiveAnimation()->CreateFloatTrack( SoundProperty::OuterVolume.ToString()) )->AsKeyframed();
}

IProceduralFloatTrack* SoundAnimationController::CreateOuterVolumeTrack( const AnimationTrack& type )
{
	return (_trackOuterVolume = _animations->GetActiveAnimation()->CreateFloatTrack( SoundProperty::OuterVolume.ToString(), type) )->AsProcedural();
}

IKeyframedBoolTrack* SoundAnimationController::CreateAvailabilityTrack()
{
	return (_trackAvailability = _animations->GetActiveAnimation()->CreateBoolTrack( SoundProperty::Availability.ToString()) )->AsKeyframed();
}

void SoundAnimationController::UpdateTracks()
{
	// Call base implementation.
	NodeAnimationControllerImpl<ISoundAnimationController>::UpdateTracks();

	_trackInnerVolume	= GetTrack( _trackInnerVolume, SoundProperty::InnerVolume );
	_trackOuterVolume	= GetTrack( _trackOuterVolume, SoundProperty::OuterVolume );
	_trackAvailability	= GetTrack( _trackAvailability, SoundProperty::Availability );	
}


} // scene


} // synkro
