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
// Purpose: Defines sound format.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUNDFORMAT_
#define _SYNKRO_SOUND_SOUNDFORMAT_


#include "config.h"
#include <sound/SoundChannel.h>


namespace synkro
{


namespace sound
{


/**
 * Sound format.
 */
class SYNKRO_API SoundFormat
{
public:
	// Well-known formats.
	static const SoundFormat Unknown;
	static const SoundFormat Stereo44kHz16bit;
	static const SoundFormat Mono44kHz16bit;
	static const SoundFormat Stereo44kHz8bit;
	static const SoundFormat Mono44kHz8bit;
	static const SoundFormat Stereo22kHz16bit;
	static const SoundFormat Mono22kHz16bit;
	static const SoundFormat Stereo22kHz8bit;
	static const SoundFormat Mono22kHz8bit;
	static const SoundFormat Stereo11kHz16bit;
	static const SoundFormat Mono11kHz16bit;
	static const SoundFormat Stereo11kHz8bit;
	static const SoundFormat Mono11kHz8bit;

	/**
	 * Creates sound format with default channel mapping and channel count.
	 * If channelCount is less than the number of mapped channels, then the extra mappings are ignored.
	 * If channelCount is greater than the number of mapped channels, then extra channels are not mapped.
	 * @param samplesPerSecond Sample rate, in Hertz.
	 * @param bitsPerSample Bitrate.
	 * @param channels Channel mapping.
	 * @param channelCount Number of channels.
	 */
	SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, const SoundChannel& channels, UInt channelCount );

	/**
	 * Creates sound format with the specified channel mapping. The number of channels is derived from channel mapping.
	 * @param samplesPerSecond Sample rate, in Hertz.
	 * @param bitsPerSample Bitrate.
	 * @param channels Channel mapping.
	 * @exception BadArgumentException Bad sound format channels.
	 */
	SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, const SoundChannel& channels );

	/**
	 * Creates sound format with default channel mapping.
	 * @param samplesPerSecond Sample rate, in Hertz.
	 * @param bitsPerSample Bitrate.
	 * @param channelCount Number of channels.
	 */
	SoundFormat( UInt samplesPerSecond, UInt bitsPerSample, UInt channelCount );

	/**
	 * Creates sound format from a string.
	 * @param format String representation of the sound format, e.g. 44kHz16bit2Ch.
	 */
	SoundFormat( const lang::String& format );

	/**
	 * Creates default sound format.
	 */
	SoundFormat();

	/**
	 * Returns true if two sound formats are equal.
	 */
	Bool													operator==( const SoundFormat& other ) const;

	/**
	 * Returns true if two sound formats are not equal.
	 */
	Bool													operator!=( const SoundFormat& other ) const;

	/**
	 * Number of bytes per channel sample.
	 */
	UInt													BytesPerSample() const;

	/**
	 * Converts sound format to a string.
	 */
	lang::String											ToString() const;

	/**
	 * Retrieves the number of sound formats supported by the system.
	 */
	static UInt												GetFormatCount();

	/**
	 * Retrieves sound format by index.
	 */
	static void												GetFormat( UInt index, SoundFormat& format );

	/**
	 * Number of samples per second, in Hertz.
	 */
	UInt													SamplesPerSecond;

	/**
	 * Number of bits per channel sample.
	 */
	UInt													BitsPerSample;

	/**
	 * Number of channels.
	 */
	UInt													ChannelCount;

	/**
	 * Sound channels.
	 */
	SoundChannel											Channels;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDFORMAT_
