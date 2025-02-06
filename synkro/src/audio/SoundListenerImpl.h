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
// Purpose: Generic sound listener implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDLISTENERIMPL_
#define _SYNKRO_AUDIO_SOUNDLISTENERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <math/Vector3.h>
#include <audio/AudioException.h>


namespace synkro
{


namespace audio
{


// Generic sound listener implementation.
template <class T>
class SoundListenerImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	SoundListenerImpl();
	virtual ~SoundListenerImpl();

	// ISoundListener methods.
	virtual void											SetPosition( const math::Vector3& position );
	virtual void											SetDirection( const math::Vector3& direction );
	virtual void											SetVelocity( const math::Vector3& velocity );
	virtual void											SetRolloffFactor( Float factor );
	virtual void											SetDopplerFactor( Float factor );
	virtual void											GetPosition( math::Vector3& position ) const;
	virtual void											GetDirection( math::Vector3& direction ) const;
	virtual void											GetVelocity( math::Vector3& velocity ) const;
	virtual Float											GetRolloffFactor() const;
	virtual Float											GetDopplerFactor() const;

protected:
	Bool													_dirty;
	math::Vector3											_position;
	math::Vector3											_direction;
	math::Vector3											_velocity;
	Float													_rolloffFactor;
	Float													_dopplerFactor;
};


#include "SoundListenerImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDLISTENERIMPL_
