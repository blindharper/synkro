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
// Purpose: Audio environment implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOENVIRONMENT_
#define _SYNKRO_AUDIO_AUDIOENVIRONMENT_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/IAudioEnvironment.h>
#include <audio/ISoundEmitter.h>
#include <audio/ISoundListener.h>
#include <lang/Vector.h>


namespace synkro
{


namespace audio
{


// Audio environment implementation.
class AudioEnvironment :
	public core::ObjectImpl<IAudioEnvironment>
{
public:
	// Constructor.
	AudioEnvironment( IAudioSystemEx* audioSystem );

	// IAudioEnvironment methods.
	void													Activate();
	void													AddEmitter( ISoundEmitter* emitter );
	void													SetListener( ISoundListener* listener );
	UInt													GetEmitterCount() const;
	ISoundEmitter*											GetEmitter( UInt index ) const;
	ISoundListener*											GetListener() const;

private:
	lang::Vector<P(ISoundEmitter)>							_emitters;
	IAudioSystemEx*											_audioSystem;
	P(ISoundListener)										_listener;
};


#include "AudioEnvironment.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOENVIRONMENT_
