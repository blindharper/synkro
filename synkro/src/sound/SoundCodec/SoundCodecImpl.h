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
// Purpose: Generic sound codec implementation.
//==============================================================================
#ifndef _SYNKRO_SOUND_SOUNDCODECIMPL_
#define _SYNKRO_SOUND_SOUNDCODECIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <sound/SoundFormat.h>
#include <sound/SoundCodecContext.h>


namespace synkro
{


namespace sound
{


// Generic sound codec implementation.
template <class T>
class SoundCodecImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	SoundCodecImpl();
	virtual ~SoundCodecImpl();

	// ISoundCodec methods.
	virtual Double											Load( SoundCodecContext* context, SoundFormat& format );
	virtual void											Save( SoundCodecContext* context, const SoundFormat& format );
};


#include "SoundCodecImpl.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDCODECIMPL_
