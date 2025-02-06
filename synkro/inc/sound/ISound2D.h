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
// Purpose: Defines 2D sound object.
//==============================================================================
#ifndef _SYNKRO_SOUND_ISOUND2D_
#define _SYNKRO_SOUND_ISOUND2D_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace sound
{


/**
 * 2D sound object.
 */
iface ISound2D :
	public core::IObject
{
public:
	/**
	 * Starts or stops playing the sound.
	 * @param play Set to true to start playback or to false to stop it.
	 */
	virtual void											Play( Bool play ) = 0;

	/**
	 * Sets sound track volume.
	 * @param volume Sound volume.
	 */
	virtual void											SetVolume( Int volume ) = 0;

	/**
	 * Retrieves sound playing state.
	 */
	virtual Bool											IsPlaying() const = 0;

	/**
	 * Retrieves sound volume.
	 */
	virtual Int												GetVolume() const = 0;

	/**
	 * Retrieves sound duration, in seconds.
	 */
	virtual Double											GetLength() const = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_ISOUND2D_
