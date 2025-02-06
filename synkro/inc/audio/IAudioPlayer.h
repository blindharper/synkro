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
// Purpose: Defines player device.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOPLAYER_
#define _SYNKRO_AUDIO_IAUDIOPLAYER_


#include "config.h"
#include <core/IObject.h>
#include <audio/PlayerDesc.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Audio player device.
 */
iface IAudioPlayer :
	public core::IObject
{
public:
	/**
	 * Creates sound buffer of the specified duration.
	 * @param format Buffer format. Using format other than that of the player can lead to format conversion overhead.
	 * @param length Buffer length, in seconds.
	 * @param chunkCount Number of chunks to split the buffer into.
	 * @return Created sound buffer.
	 */
	virtual ISoundBuffer*									CreateSoundBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount ) = 0;

	/**
	 * Creates sound emitter of the specified duration.
	 * @param format Buffer format. Using format other than that of the player can lead to format conversion overhead.
	 * @param length Buffer length, in seconds.
	 * @return Created emitter.
	 */
	virtual ISoundEmitter*									CreateSoundEmitter( const sound::SoundFormat& format, Double length ) = 0;

	/**
	 * Retrieves player sound format.
	 * @param [out] format Sound format.
	 */
	virtual void											GetFormat( sound::SoundFormat& format ) const = 0;

	/**
	 * Retrieves player description.
	 * @param [out] desc Player description.
	 */
	virtual void											GetDesc( PlayerDesc& desc ) const = 0;

	/**
	 * Retrieves sound listener.
	 */
	virtual ISoundListener*									GetListener() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOPLAYER_
