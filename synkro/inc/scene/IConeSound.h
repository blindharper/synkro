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
// Purpose: Defines cone sound node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICONESOUND_
#define _SYNKRO_SCENE_ICONESOUND_


#include "config.h"
#include <scene/ISound.h>


namespace synkro
{


namespace scene
{


/**
 * Cone sound node.
 */
iface IConeSound :
	public ISound
{
public:
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
	 * Sets the volume of the sound within the inner angle of the sound projection cone.
	 * @param volume Cone inner volume. Valid range is [0.0-2.0].
	 */
	virtual void											SetInnerVolume( Float volume ) = 0;

	/** 
	 * Sets the volume of the sound outside the outside angle of the sound projection cone.
	 * @param volume Cone outer volume. Valid range is [0.0-2.0].
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
	 * Retrieves the angle within which the sound is at its normal volume.
	 */
	virtual Float											GetInnerAngle() const = 0;

	/** 
	 * Retrieves the angle outside of which the sound is at its outside volume.
	 */
	virtual Float											GetOuterAngle() const = 0;

	/** 
	 * Retrieves the volume of the sound within the inner angle of the sound projection cone.
	 */
	virtual Float											GetInnerVolume() const = 0;

	/** 
	 * Retrieves the volume of the sound outside the outside angle of the sound projection cone.
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
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICONESOUND_
