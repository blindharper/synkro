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
// Purpose: Defines audio buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOBUFFER_
#define _SYNKRO_AUDIO_IAUDIOBUFFER_


#include "config.h"
#include <core/IObject.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Audio buffer.
 */
iface IAudioBuffer :
	public core::IObject
{
public:
	/**
	 * Polls internal buffer state.
	 */
	virtual void											Update() = 0;

	/**
	 * Starts or stops buffer data processing.
	 * @param start True to start processing, false to stop it.
	 * @param loop True to re-start processing from the beginning when the buffer reaches the end.
	 */
	virtual void											Process( Bool start, Bool loop ) = 0;

	/**
	 * Retrieves buffer format.
	 * @param [out] format Sound format.
	 */
	virtual void											GetFormat( sound::SoundFormat& format ) const = 0;

	/**
	 * Retrieves the number of chunks in the buffer.
	 */
	virtual UInt											GetChunkCount() const = 0;

	/**
	 * Gets buffer chunk by index.
	 * @param index Chunk index.
	 * @return Requested chunk.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAudioChunk*									GetChunk( UInt index ) const = 0;

	/**
	 * Retrieves buffer size, in bytes.
	 */
	virtual UInt											GetSize() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOBUFFER_
