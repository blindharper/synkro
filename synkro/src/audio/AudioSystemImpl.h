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
// Purpose: Generic audio system implementation.
//=============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOSYSTEMIMPL_
#define _SYNKRO_AUDIO_AUDIOSYSTEMIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <audio/AudioException.h>
#include <audio/PlayerDesc.h>
#include <audio/RecorderDesc.h>
#include <sound/SoundFormat.h>


namespace synkro
{


namespace audio
{


// Generic audio system implementation.
template <class T>
class AudioSystemImpl :
	public core::ObjectImpl<T>,
	public Logger
{
public:
	// Constructor & destructor.
	AudioSystemImpl( const sound::SoundFormat& format, diag::ILog* log );
	virtual ~AudioSystemImpl();

	// ISystem methods.
	virtual Bool											Update( Double delta );

	// IAudioSystem methods.
	virtual UInt											GetTotalPlayerCount() const;
	virtual void											GetPlayerDesc( UInt index, PlayerDesc& desc ) const;
	virtual UInt											GetTotalRecorderCount() const;
	virtual void											GetRecorderDesc( UInt index, RecorderDesc& desc ) const;

protected:
	lang::Vector<PlayerDesc>								_players;
	lang::Vector<RecorderDesc>								_recorders;
	sound::SoundFormat										_format;
};


#include "AudioSystemImpl.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOSYSTEMIMPL_
