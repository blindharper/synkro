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
// Purpose: Defines audio buffer chunk.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIOCHUNK_
#define _SYNKRO_AUDIO_IAUDIOCHUNK_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace audio
{


/**
 * Audio buffer chunk.
 */
iface IAudioChunk :
	public core::IObject
{
public:
	/**
	 * Sets chunk data.
	 * @param data Chunk data.
	 * @param size Chunk data size.
	 */
	virtual void											Write( const Byte* data, UInt size ) = 0;

	/**
	 * Retrieves chunk data.
	 * @param [out] data Chunk data.
	 * @param size Chunk data size.
	 */
	virtual void											Read( Byte* data, UInt size ) const = 0;

	/**
	 * Retrieves chunk size, in bytes.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves data chunk processing state.
	 * @return True, if the chunk is currently being processed, false otherwise.
	 */
	virtual Bool											IsProcessing() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIOCHUNK_
