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
// Purpose: Defines extended audio system.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOSYSTEMEX_
#define _SYNKRO_AUDIO_IAUDIOSYSTEMEX_


#include "config.h"
#include <audio/IAudioSystem.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Extended audio system.
 */
iface IAudioSystemEx :
	public IAudioSystem
{
public:
	/**
	 * Creates audio environment.
	 */
	virtual IAudioEnvironment*								CreateEnvironment() = 0;

	/**
	 * Retrieves active environment.
	 */
	virtual IAudioEnvironment*								GetActiveEnvironment() const = 0;

	/**
	 * Retrieves the total number of player devices.
	 * @return Number of player devices in the system.
	 */
	virtual UInt											GetPlayerCount() const = 0;

	/**
	 * Retrieves player by index.
	 * @param index Index of the player to retrieve.
	 * @return Requested player.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAudioPlayer*									GetPlayer( UInt index ) const = 0;

	/**
	 * Retrieves player that better suits given sound format.
	 * @param soundFormat Sound format.
	 * @return Requested player.
	 */
	virtual IAudioPlayer*									GetPlayer( const sound::SoundFormat& soundFormat ) const = 0;

	/**
	 * Retrieves default player.
	 * @return Player device.
	 */
	virtual IAudioPlayer*									GetPlayer() const = 0;

	/**
	 * Retrieves the total number of recorders.
	 * @return Number of recorders in the system.
	 */
	virtual UInt											GetRecorderCount() const = 0;

	/**
	 * Retrieves recorder by index.
	 * @param index Index of the recorder to retrieve.
	 * @return Requested recorder.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAudioRecorder*									GetRecorder( UInt index ) const = 0;

	/**
	 * Retrieves default recorder.
	 * @return Recorder device.
	 */
	virtual IAudioRecorder*									GetRecorder() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOSYSTEMEX_
