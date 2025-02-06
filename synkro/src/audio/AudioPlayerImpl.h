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
// Purpose: Generic player implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOPLAYERIMPL_
#define _SYNKRO_AUDIO_AUDIOPLAYERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/ISoundListener.h>
#include <audio/PlayerDesc.h>
#include <audio/AudioException.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


// Generic player implementation.
template <class T>
class AudioPlayerImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	AudioPlayerImpl( const sound::SoundFormat& format, const PlayerDesc& desc );
	virtual ~AudioPlayerImpl();

	// IAudioPlayer methods.
	virtual void											GetFormat( sound::SoundFormat& format ) const;
	virtual void											GetDesc( PlayerDesc& desc ) const;
	virtual ISoundListener*									GetListener() const;

protected:
	PlayerDesc												_desc;
	sound::SoundFormat										_format;
	P(ISoundListener)										_listener;
};


#include "AudioPlayerImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOPLAYERIMPL_
