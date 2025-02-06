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
// Purpose: Generic audio buffer implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOBUFFERIMPL_
#define _SYNKRO_AUDIO_AUDIOBUFFERIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <audio/AudioException.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


// Generic audio buffer implementation.
template <class T, class C>
class AudioBufferImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	AudioBufferImpl( const sound::SoundFormat& format, UInt chunkCount );
	virtual ~AudioBufferImpl();

	// IAudioBuffer methods.
	virtual void											GetFormat( sound::SoundFormat& format ) const;
	virtual UInt											GetChunkCount() const;
	virtual IAudioChunk*									GetChunk( UInt index ) const;
	virtual UInt											GetSize() const;

protected:
	lang::Vector<P(C)>										_chunks;
	sound::SoundFormat										_format;
	UInt													_size;
};


#include "AudioBufferImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOBUFFERIMPL_
