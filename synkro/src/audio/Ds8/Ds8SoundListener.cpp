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
// Purpose: DirectSound 8 sound listener implementation.
//==============================================================================
#include "config.h"
#include "Ds8SoundListener.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


Ds8SoundListener::Ds8SoundListener( IDirectSoundBuffer* buffer ) :
	_listener( nullptr )
{
	HRESULT hr = S_OK;

	if ( FAILED(hr = buffer->QueryInterface( IID_IDirectSound3DListener, (void**)&_listener )) )
		throw AudioException( L"Failed to create sound listener.", String::Format(Str::CallFail, L"IDirectSoundBuffer::QueryInterface()"), Ds8::ToString(hr) );
}

Ds8SoundListener::Ds8SoundListener( const Ds8SoundListener& other ) :
	_listener( other._listener )
{
	_dirty			= true;
	_position		= other._position;
	_direction		= other._direction;
	_velocity		= other._velocity;
	_rolloffFactor	= other._rolloffFactor;
	_dopplerFactor	= other._dopplerFactor;
}

void Ds8SoundListener::Bind()
{
	if ( _dirty )
	{
		DS3DLISTENER desc;
		desc.dwSize = sizeof(desc);
		Ds8::Convert( _position, desc.vPosition );
		Ds8::Convert( _direction, desc.vOrientFront );
		Ds8::Convert( Vector3::Y, desc.vOrientTop );
		Ds8::Convert( _velocity, desc.vVelocity );
		desc.flDistanceFactor	= 1.0f;
		desc.flRolloffFactor	= _rolloffFactor;
		desc.flDopplerFactor	= _dopplerFactor;
		_listener->SetAllParameters( &desc, DS3D_IMMEDIATE );
		_dirty = false;
	}
}

ISoundListener* Ds8SoundListener::Clone() const
{
	return new Ds8SoundListener( *this );
}


} // audio


} // synkro
