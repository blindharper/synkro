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
// Purpose: Defines sound buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_ISOUNDBUFFER_
#define _SYNKRO_AUDIO_ISOUNDBUFFER_


#include "config.h"
#include <audio/IAudioBuffer.h>


namespace synkro
{


namespace audio
{


/**
 * Sound buffer.
 */
iface ISoundBuffer :
	public IAudioBuffer
{
public:
	/**
	 * Sets relative volume of the left and right channels.
	 * @param pan Relative volume of the left and right channels.
	 */
	virtual void											SetPan( Int pan ) = 0;

	/**
	 * Sets sound attenuation, in hundredths of a decibel.
	 * @param attenuation Sound attenuation.
	 */
	virtual void											SetAttenuation( Int attenuation ) = 0;

	/**
	 * Sets the rate at which audio samples in the buffer are played, in Hertz.
	 * @param frequency Frequency value.
	 */
	virtual void											SetFrequency( UInt frequency ) = 0;

	/**
	 * Retrieves relative volume of the left and right channels.
	 */
	virtual Int												GetPan() const = 0;

	/**
	 * Retrieves sound attenuation, in hundredths of a decibel.
	 */
	virtual Int												GetAttenuation() const = 0;

	/**
	 * Retrieves the rate at which audio samples in the buffer are played, in Hertz.
	 */
	virtual UInt											GetFrequency() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_ISOUNDBUFFER_
