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
// Purpose: Defines 3D sound object.
//==============================================================================
#ifndef _SYNKRO_SOUND_ISOUND3D_
#define _SYNKRO_SOUND_ISOUND3D_


#include "config.h"
#include <sound/ISound2D.h>
#include <math/Vector3.h>


namespace synkro
{


namespace sound
{


/**
 * 3D sound object.
 */
iface ISound3D :
	public ISound2D
{
public:
	/** 
	 * Sets sound position in 3D space.
	 * @param position Sound position.
	 */
	virtual void											SetPosition( const math::Vector3& position ) = 0;

	/** 
	 * Sets sound projection cone direction.
	 * @param direction Sound projection cone direction.
	 */
	virtual void											SetDirection( const math::Vector3& direction ) = 0;

	/** 
	 * Sets sound velocity.
	 * @param velocity Sound velocity.
	 */
	virtual void											SetVelocity( const math::Vector3& velocity ) = 0;

	/** 
	 * Sets the angle within which the sound is at its normal volume.
	 * @param angle Inner cone angle, in degrees. Valid range is [0.0-2PI].
	 */
	virtual void											SetInnerAngle( Float angle ) = 0;

	/** 
	 * Sets the angle outside of which the sound is at its outside volume.
	 * @param angle Outer cone angle, in degrees. Valid range is [Inner angle-2PI].
	 */
	virtual void											SetOuterAngle( Float angle ) = 0;

	/** 
	 * Sets the attenuation of the sound inside the inner angle of the sound projection cone.
	 * @param volume Cone inner attenuation, in hundredths of a decibel.
	 */
	virtual void											SetInnerVolume( Float volume ) = 0;

	/** 
	 * Sets the attenuation of the sound outside the outer angle of the sound projection cone.
	 * @param volume Cone outside volume, in hundredths of a decibel.
	 */
	virtual void											SetOuterVolume( Float volume ) = 0;

	/** 
	 * Sets the reverb level of the sound within the inner angle of the sound projection cone.
	 * @param reverb Cone inner reverb. Valid range is [0.0-2.0].
	 */
	virtual void											SetInnerReverb( Float reverb ) = 0;

	/** 
	 * Sets the reverb level of the sound outside the outside angle of the sound projection cone.
	 * @param reverb Cone outer reverb. Valid range is [0.0-2.0].
	 */
	virtual void											SetOuterReverb( Float reverb ) = 0;

	/** 
	 * Sets the minimum distance from the listener, at which sound begins to be attenuated.
	 * @param distance Minimum distance value.
	 */
	virtual void											SetMinDistance( Float distance ) = 0;

	/** 
	 * Sets the maximum distance from the listener, at which sound is no longer attenuated.
	 * @param distance Maximum distance value.
	 */
	virtual void											SetMaxDistance( Float distance ) = 0;

	/** 
	 * Retrieves sound position in 3D space.
	 * @param [out] position Sound position.
	 */
	virtual void											GetPosition( math::Vector3& position ) const = 0;

	/** 
	 * Retrieves sound direction in 3D space.
	 * @param [out] direction Sound direction.
	 */
	virtual void											GetDirection( math::Vector3& direction ) const = 0;

	/** 
	 * Retrieves sound velocity.
	 * @param [out] velocity Sound velocity.
	 */
	virtual void											GetVelocity( math::Vector3& velocity ) const = 0;

	/** 
	 * Retrieves the angle within which the sound is at its normal volume.
	 */
	virtual Float											GetInnerAngle() const = 0;

	/** 
	 * Retrieves the angle outside of which the sound is at its outside volume.
	 */
	virtual Float											GetOuterAngle() const = 0;

	/** 
	 * Retrieves the attenuation of the sound inside the inner angle of the sound projection cone.
	 */
	virtual Float											GetInnerVolume() const = 0;

	/** 
	 * Retrieves the attenuation of the sound outside the outside angle of the sound projection cone.
	 */
	virtual Float											GetOuterVolume() const = 0;

	/** 
	 * Retrieves the reverb level of the sound within the inner angle of the sound projection cone.
	 */
	virtual Float											GetInnerReverb() const = 0;

	/** 
	 * Retrieves the reverb level of the sound outside the outside angle of the sound projection cone.
	 */
	virtual Float 											GetOuterReverb() const = 0;

	/** 
	 * Retrieves the minimum distance from the listener, at which sound begins to be attenuated.
	 */
	virtual Float											GetMinDistance() const = 0;

	/** 
	 * Retrieves the maximum distance from the listener, at which sound is no longer attenuated.
	 */
	virtual Float											GetMaxDistance() const = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_ISOUND3D_
