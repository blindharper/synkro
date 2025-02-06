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
// Purpose: Defines audio environment.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOENVIRONMENT_
#define _SYNKRO_AUDIO_IAUDIOENVIRONMENT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace audio
{


/**
 * Audio environment. Stores sound emitters and listener.
 */
iface IAudioEnvironment :
	public core::IObject
{
public:
	/**
	 * Activates environment.
	 */
	virtual void											Activate() = 0;

	/**
	 * Adds an emitter to the environment.
	 * @param emitter Emitter to add.
	 * @exception BadArgumentException Emitter is null.
	 */
	virtual void											AddEmitter( ISoundEmitter* emitter ) = 0;

	/**
	 * Sets sound listener.
	 * @param listener Sound listener.
	 */
	virtual void											SetListener( ISoundListener* listener ) = 0;

	/**
	 * Retrieves the total number of emitters in the environment.
	 */
	virtual UInt											GetEmitterCount() const = 0;

	/**
	 * Retrieves emitter by index.
	 * @param index Index of the emitter.
	 * @return Requested emitter.
	 */
	virtual ISoundEmitter*									GetEmitter( UInt index ) const = 0;

	/**
	 * Retrieves sound listener.
	 */
	virtual ISoundListener*									GetListener() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOENVIRONMENT_
