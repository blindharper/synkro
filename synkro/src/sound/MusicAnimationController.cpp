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
// Purpose: Music controller implementation.
//==============================================================================
#include "config.h"
#include "MusicAnimationController.h"
#include "MusicProperty.h"
#include <sound/IMusic.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


MusicAnimationController::MusicAnimationController( IMusic* music, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	PlaybackControllerImpl<IMusicAnimationController>( animationSystem, animation, listener ),
	_music( music )
{
	SetAnimation( _animation );
}

void MusicAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<IMusicAnimationController>::Update( delta );

	// Update music.
	if ( _trackVolume != nullptr )
	{
		Int volume;
		_trackVolume->GetValue( _time, volume );
		_music->SetVolume( volume );
	}

	if ( _trackPan != nullptr )
	{
		Int pan;
		_trackPan->GetValue( _time, pan );
		_music->SetPan( pan );
	}
}

void MusicAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<IMusicAnimationController>::SetAnimation( animation );

	_trackVolume	= GetTrack( _trackVolume, MusicProperty::Volume );
	_trackPan		= GetTrack( _trackPan, MusicProperty::Pan );
}

IKeyframedIntTrack* MusicAnimationController::CreateVolumeTrack()
{
	return (_trackVolume = (_trackVolume == nullptr) ? _animation->CreateIntTrack(MusicProperty::Volume.ToString()) : _trackVolume)->AsKeyframed();
}

IKeyframedIntTrack* MusicAnimationController::CreatePanTrack()
{
	return (_trackPan = (_trackPan == nullptr) ? _animation->CreateIntTrack(MusicProperty::Pan.ToString()) : _trackPan)->AsKeyframed();
}


} // sound


} // synkro
