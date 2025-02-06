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
// Purpose: Generic sound buffer implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_SOUNDBUFFERIMPL_
#define _SYNKRO_AUDIO_SOUNDBUFFERIMPL_


#include "config.h"
#include "AudioBufferImpl.h"


namespace synkro
{


namespace audio
{


// Generic sound buffer implementation.
template <class T, class C>
class SoundBufferImpl :
	public AudioBufferImpl<T, C>
{
public:
	// Constructor & destructor.
	SoundBufferImpl( const sound::SoundFormat& format, UInt chunkCount );
	virtual ~SoundBufferImpl();

	// ISoundBuffer methods.
	virtual void											SetPan( Int pan );
	virtual void											SetAttenuation( Int attenuation );
	virtual void											SetFrequency( UInt frequency );
	virtual Int												GetPan() const;
	virtual Int												GetAttenuation() const;
	virtual UInt											GetFrequency() const;

protected:
	Bool													_dirty;
	Int														_pan;
	Int														_attenuation;
	UInt													_frequency;
};


#include "SoundBufferImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_SOUNDBUFFERIMPL_
