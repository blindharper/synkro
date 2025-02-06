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
// Purpose: Defines audio system.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOSYSTEM_
#define _SYNKRO_AUDIO_IAUDIOSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <audio/PlayerDesc.h>
#include <audio/RecorderDesc.h>


namespace synkro
{


namespace audio
{


/**
 * Audio system. Provides access to various audio devices.
 */
iface IAudioSystem :
	public core::ISystem
{
public:
	/**
	 * Initializes one of the players installed in the system.
	 * @param index Index of the player to intialize.
	 * @return Created player.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAudioPlayer*									CreatePlayer( UInt index ) = 0;

	/**
	 * Initializes one of the recorders installed in the system.
	 * @param index Index of the recorder to intialize.
	 * @return Created recorder.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAudioRecorder*									CreateRecorder( UInt index ) = 0;

	/**
	 * Retrieves the total number of player devices installed in the system.
	 */
	virtual UInt											GetTotalPlayerCount() const = 0;

	/**
	 * Retrieves player device description.
	 * @param index Index of the player device.
	 * @param [out] desc Player description.
	 */
	virtual void											GetPlayerDesc( UInt index, PlayerDesc& desc ) const = 0;

	/**
	 * Retrieves the total number of recorders installed in the system.
	 */
	virtual UInt											GetTotalRecorderCount() const = 0;

	/**
	 * Retrieves recorder device description.
	 * @param index Index of the recorder device.
	 * @param [out] desc Recorder description.
	 */
	virtual void											GetRecorderDesc( UInt index, RecorderDesc& desc ) const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOSYSTEM_
