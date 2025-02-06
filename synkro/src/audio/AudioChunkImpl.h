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
// Purpose: Generic audio buffer chunk implementation.
//==============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOCHUNKIMPL_
#define _SYNKRO_AUDIO_AUDIOCHUNKIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace audio
{


// Generic audio buffer chunk implementation.
template <class T>
class AudioChunkImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor.
	AudioChunkImpl( UInt size );

	// IAudioChunk methods.
	UInt													GetSize() const;

protected:
	UInt													_size;
};


#include "AudioChunkImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOCHUNKIMPL_
