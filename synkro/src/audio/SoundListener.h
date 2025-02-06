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
// Purpose: Logical sound listener.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDLISTENER_
#define _SYNKRO_AUDIO_SOUNDLISTENER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/ISoundListener.h>


namespace synkro
{


namespace audio
{


// Logical sound listener.
class SoundListener :
	public core::ObjectImpl<ISoundListener>
{
public:
	// Constructors.
	SoundListener( ISoundListener* listener );
	SoundListener( const SoundListener& other );

	// ISoundListener methods.
	void													Bind();
	void													SetPosition( const math::Vector3& position );
	void													SetDirection( const math::Vector3& direction );
	void													SetVelocity( const math::Vector3& velocity );
	void													SetRolloffFactor( Float factor );
	void													SetDopplerFactor( Float factor );
	void													GetPosition( math::Vector3& position ) const;
	void													GetDirection( math::Vector3& direction ) const;
	void													GetVelocity( math::Vector3& velocity ) const;
	Float													GetRolloffFactor() const;
	Float													GetDopplerFactor() const;
	ISoundListener*											Clone() const;

private:
	P(ISoundListener)										_listener;
	Bool													_readonly;
};


#include "SoundListener.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDLISTENER_
