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
// Purpose: Defines sound source node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISOUND_
#define _SYNKRO_SCENE_ISOUND_


#include "config.h"
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


/**
 * Sound source node.
 */
iface ISound :
	public INode
{
public:
	/** 
	 * Enables/disables sound source.
	 * @param enable True to turn the sound on, false to turn it off.
	 */
	virtual void											Enable( Bool enable ) = 0;

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
	 * Checks if the sound is turned on.
	 */
	virtual Bool											IsEnabled() const = 0;

	/** 
	 * Retrieves the minimum distance from the listener, at which sound begins to be attenuated.
	 */
	virtual Float											GetMinDistance() const = 0;

	/** 
	 * Retrieves the maximum distance from the listener, at which sound is no longer attenuated.
	 */
	virtual Float											GetMaxDistance() const = 0;

	/**
	 * Casts sound to cone sound.
	 * @return Non-null for cone sound, nullptr otherwise.
	 */
	virtual IConeSound*										AsCone() const = 0;

	/**
	 * Casts sound to omni sound.
	 * @return Non-null for omni sound, nullptr otherwise.
	 */
	virtual IOmniSound*										AsOmni() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISOUND_
