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
// Purpose: Generic sound emitter implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDEMITTERIMPL_
#define _SYNKRO_AUDIO_SOUNDEMITTERIMPL_


#include "config.h"
#include "SoundBufferImpl.h"
#include <math/Vector3.h>


namespace synkro
{


namespace audio
{


// Generic sound emitter implementation.
template <class T, class C>
class SoundEmitterImpl :
	public SoundBufferImpl<T, C>
{
public:
	// Constructor & destructor.
	SoundEmitterImpl( const sound::SoundFormat& format, UInt chunkCount );
	virtual ~SoundEmitterImpl();

	// ISoundEmitter methods.
	virtual void											SetPosition( const math::Vector3& position );
	virtual void											SetDirection( const math::Vector3& direction );
	virtual void											SetVelocity( const math::Vector3& velocity );
	virtual void											SetInnerAngle( Float angle );
	virtual void											SetOuterAngle( Float angle );
	virtual void											SetInnerAttenuation( Int attenuation );
	virtual void											SetOuterAttenuation( Int attenuation );
	virtual void											SetInnerReverb( Float reverb );
	virtual void											SetOuterReverb( Float reverb );
	virtual void											SetMinDistance( Float distance );
	virtual void											SetMaxDistance( Float distance );
	virtual void											GetPosition( math::Vector3& position ) const;
	virtual void											GetDirection( math::Vector3& direction ) const;
	virtual void											GetVelocity( math::Vector3& velocity ) const;
	virtual Float											GetInnerAngle() const;
	virtual Float											GetOuterAngle() const;
	virtual Int												GetInnerAttenuation() const;
	virtual Int												GetOuterAttenuation() const;
	virtual Float											GetInnerReverb() const;
	virtual Float											GetOuterReverb() const;
	virtual Float											GetMinDistance() const;
	virtual Float											GetMaxDistance() const;

protected:
	math::Vector3											_position;
	math::Vector3											_direction;
	math::Vector3											_velocity;
	Float													_innerAngle;
	Float													_outerAngle;
	Int														_innerAttenuation;
	Int														_outerAttenuation;
	Float													_innerReverb;
	Float													_outerReverb;
	Float													_minDistance;
	Float													_maxDistance;
};


#include "SoundEmitterImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDEMITTERIMPL_
