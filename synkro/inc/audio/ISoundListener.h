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
// Purpose: Defines sound listener in 3D space.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ISOUNDLISTENER_
#define _SYNKRO_AUDIO_ISOUNDLISTENER_


#include "config.h"
#include <core/IObject.h>
#include <math/Vector3.h>


namespace synkro
{


namespace audio
{


/**
 * Point of 3D audio reception.
 */
iface ISoundListener :
	public core::IObject
{
public:
	/**
	 * Activates the listener.
	 */
	virtual void											Bind() = 0;

	/** 
	 * Sets listener's position in 3D space.
	 * @param position Listener's position.
	 */
	virtual void											SetPosition( const math::Vector3& position ) = 0;

	/** 
	 * Sets listener's front direction in 3D space.
	 * @param direction Listener's front direction.
	 */
	virtual void											SetDirection( const math::Vector3& direction ) = 0;

	/** 
	 * Sets listener's velocity.
	 * @param velocity Listener's velocity.
	 */
	virtual void											SetVelocity( const math::Vector3& velocity ) = 0;

	/** 
	 * Sets the rate of sound attenuation over distance. Default is 1.0f.
	 * @param factor Rolloff factor.
	 */
	virtual void											SetRolloffFactor( Float factor ) = 0;

	/** 
	 * Sets the multiplier for the Doppler effect. Default is 1.0f.
	 * @param factor Doppler factor.
	 */
	virtual void											SetDopplerFactor( Float factor ) = 0;

	/** 
	 * Retrieves listener's position in 3D space.
	 * @param [out] position Listener's position.
	 */
	virtual void											GetPosition( math::Vector3& position ) const = 0;

	/** 
	 * Retrieves listener's front direction in 3D space.
	 * @param [out] direction Listener's front direction.
	 */
	virtual void											GetDirection( math::Vector3& direction ) const = 0;

	/** 
	 * Retrieves listener's velocity.
	 * @param [out] velocity Listener's velocity.
	 */
	virtual void											GetVelocity( math::Vector3& velocity ) const = 0;

	/** 
	 * Retrieves the rate of sound attenuation over distance.
	 */
	virtual Float											GetRolloffFactor() const = 0;

	/** 
	 * Retrieves the multiplier for the Doppler effect.
	 */
	virtual Float											GetDopplerFactor() const = 0;

	/**
	 * Produces an exact copy of sound listener.
	 * @return Newly created sound listener.
	 */
	virtual ISoundListener*									Clone() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ISOUNDLISTENER_
