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
// Purpose: Generic recorder implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIORECORDERIMPL_
#define _SYNKRO_AUDIO_AUDIORECORDERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/RecorderDesc.h>
#include <audio/AudioException.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


// Generic recorder implementation.
template <class T>
class AudioRecorderImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	AudioRecorderImpl( const sound::SoundFormat& format, const RecorderDesc& desc );
	virtual ~AudioRecorderImpl();

	// IAudioRecorder methods.
	virtual void											GetDesc( RecorderDesc& desc ) const;

protected:
	RecorderDesc											_desc;
	sound::SoundFormat										_format;
};


#include "AudioRecorderImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIORECORDERIMPL_
