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
// Purpose: OpenAL sound listener implementation.
//==============================================================================
#include "config.h"
#include "AlSoundListener.h"
#include <audio/AudioException.h>


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlSoundListener::AlSoundListener()
{
}

AlSoundListener::AlSoundListener( const AlSoundListener& other )
{
	_position		= other._position;
	_direction		= other._direction;
	_velocity		= other._velocity;
	_rolloffFactor	= other._rolloffFactor;
	_dopplerFactor	= other._dopplerFactor;
}

void AlSoundListener::Bind()
{
	if ( _dirty )
	{
		ALfloat orient[6];
		orient[0] = _direction.x; orient[1] = _direction.y; orient[2] = _direction.z;
		orient[3] = Vector3::Y.x; orient[4] = Vector3::Y.y; orient[5] = Vector3::Y.z;
		Al::Listenerfv( AL_ORIENTATION, orient );
		Al::Listener3f( AL_POSITION, _position.x, _position.y, _position.z );
		Al::Listener3f( AL_VELOCITY, _velocity.x, _velocity.y, _velocity.z );
		Al::DopplerFactor( _dopplerFactor );
		_dirty = false;
	}
}

ISoundListener* AlSoundListener::Clone() const
{
	return new AlSoundListener( *this );
}


} // audio


} // synkro
