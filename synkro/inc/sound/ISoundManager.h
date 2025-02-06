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
// Purpose: Defines sound manager.
//==============================================================================
#ifndef _SYNKRO_SOUND_ISOUNDMANAGER_
#define _SYNKRO_SOUND_ISOUNDMANAGER_


#include "config.h"
#include <core/ISystem.h>
#include <sound/SoundFormat.h>
#include <sound/SoundCodec.h>


namespace synkro
{


namespace sound
{


/**
 * Sound manager.
 */
iface ISoundManager :
	public core::ISystem
{
public:
	/**
	 * Creates an empty voice of the given format.
	 * @param stream Stream to which to save voice.
	 * @param format Voice voice format.
	 * @param type Voice codec type.
	 * @return Created voice if succeeded, or null otherwise.
	 */
	virtual IVoice*											CreateVoice( io::IStream* stream, const SoundFormat& format, const SoundCodec& type ) = 0;

	/**
	 * Creates an empty voice of the given format. Voice type is guessed from stream name.
	 * @param stream Stream to which to save voice.
	 * @param format Voice voice format.
	 * @return Created voice if succeeded, or null otherwise.
	 */
	virtual IVoice*											CreateVoice( io::IStream* stream, const SoundFormat& format ) = 0;

	/**
	 * Loads 2D sound from a stream.
	 * @param stream Stream from which to load sound.
	 * @param type Sound codec type.
	 * @return Created sound if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual ISound2D*										LoadSound2D( io::IStream* stream, const SoundCodec& type ) = 0;

	/**
	 * Loads 2D sound from a stream. Sound type is guessed from stream name.
	 * @param stream Stream from which to load sound.
	 * @return Created sound if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual ISound2D*										LoadSound2D( io::IStream* stream ) = 0;

	/**
	 * Loads 3D sound from a stream.
	 * @param stream Stream from which to load sound.
	 * @param type Sound codec type.
	 * @return Created sound if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual ISound3D*										LoadSound3D( io::IStream* stream, const SoundCodec& type ) = 0;

	/**
	 * Loads 3D sound from a stream. Sound type is guessed from stream name.
	 * @param stream Stream from which to load sound.
	 * @return Created sound if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong sound type.
	 */
	virtual ISound3D*										LoadSound3D( io::IStream* stream ) = 0;

	/**
	 * Loads music track from a stream.
	 * @param stream Stream from which to load music.
	 * @param type Music codec type.
	 * @return Created music if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong music type.
	 */
	virtual IMusic*											LoadMusic( io::IStream* stream, const SoundCodec& type ) = 0;

	/**
	 * Loads music track from a stream. Music type is guessed from stream name.
	 * @param stream Stream from which to load music.
	 * @return Created music if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong music type.
	 */
	virtual IMusic*											LoadMusic( io::IStream* stream ) = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_ISOUNDMANAGER_
