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
// Purpose: Defines abstract sound codec.
//==============================================================================
#ifndef _SYNKRO_SOUND_ISOUNDCODEC_
#define _SYNKRO_SOUND_ISOUNDCODEC_


#include "config.h"
#include <core/IObject.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace sound
{


/**
 * Abstract sound codec.
 */
iface ISoundCodec :
	public core::IObject
{
public:
	/**
	 * Loads sound resource and repositions context stream to the sound data.
	 * @param context Decoding context.
	 * @param [out] format Sound resource format.
	 * @return Sound length, in seconds.
	 * @exception BadArgumentException Bad context stream.
	 */
	virtual Double											Load( SoundCodecContext* context, SoundFormat& format ) = 0;

	/**
	 * Begins saving sound resource. Writes format-specific information to the context stream.
	 * @param context Encoding context.
	 * @param format Sound resource format.
	 * @exception BadArgumentException Bad context stream.
	 */
	virtual void											Save( SoundCodecContext* context, const SoundFormat& format ) = 0;

	/**
	 * Decodes sound data.
	 * @param context Decoding context.
	 * @param [out] data Destination buffer.
	 * @param [in] size Destination buffer length, in bytes.
	 * @return Number of bytes written to destination buffer, or zero if end of data stream is reached.
	 */
	virtual UInt											Decode( SoundCodecContext* context, Byte** data, UInt size ) = 0;

	/**
	 * Encodes sound data.
	 * @param context Encoding context.
	 * @param data Source buffer. Null data indicates the last data chunk.
	 * @param size Source buffer length, in bytes. Zero size indicates the last data chunk.
	 * @return Number of bytes read from source buffer.
	 */
	virtual UInt											Encode( SoundCodecContext* context, const Byte* data, UInt size ) = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_ISOUNDCODEC_
