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
// Purpose: Defines recorder device.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IAUDIORECORDER_
#define _SYNKRO_AUDIO_IAUDIORECORDER_


#include "config.h"
#include <core/IObject.h>
#include <audio/RecorderDesc.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


/**
 * Audio recorder device.
 */
iface IAudioRecorder :
	public core::IObject
{
public:
	/**
	 * Creates voice buffer of the specified duration.
	 * @param format Buffer format.
	 * @param length Buffer length, in seconds.
	 * @param chunkCount Number of chunks to split the buffer into.
	 * @return Created voice buffer.
	 */
	virtual IVoiceBuffer*									CreateVoiceBuffer( const sound::SoundFormat& format, Double length, UInt chunkCount ) = 0;

	/**
	 * Retrieves recorder description.
	 * @param [out] desc Recorder description.
	 */
	virtual void											GetDesc( RecorderDesc& desc ) const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IAUDIORECORDER_
