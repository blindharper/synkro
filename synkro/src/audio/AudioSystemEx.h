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
// Purpose: Extended audio system.
//=============================================================================
#ifndef _SYNKRO_AUDIO_AUDIOSYSTEMEX_
#define _SYNKRO_AUDIO_AUDIOSYSTEMEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <audio/IAudioSystemEx.h>
#include <lang/Vector.h>
#include "AudioPlayer.h"
#include "AudioRecorder.h"


namespace synkro
{


namespace audio
{


// Extended audio system.
class AudioSystemEx :
	public core::ObjectImpl<IAudioSystemEx>,
	public Logger
{
public:
	// Constructor.
	AudioSystemEx( const sound::SoundFormat& format, diag::ILog* log );

	// ISystem methods.
	Bool													Update( Double delta );

	// IAudioSystem methods.
	IAudioPlayer*											CreatePlayer( UInt index );
	IAudioRecorder*											CreateRecorder( UInt index );
	UInt													GetTotalPlayerCount() const;
	void													GetPlayerDesc( UInt index, PlayerDesc& desc ) const;
	UInt													GetTotalRecorderCount() const;
	void													GetRecorderDesc( UInt index, RecorderDesc& desc ) const;

	// IAudioSystemEx methods.
	IAudioEnvironment*										CreateEnvironment();
	IAudioEnvironment*										GetActiveEnvironment() const;
	UInt													GetPlayerCount() const;
	IAudioPlayer*											GetPlayer( UInt index ) const;
	IAudioPlayer*											GetPlayer( const sound::SoundFormat& soundFormat ) const;
	IAudioPlayer*											GetPlayer() const;
	UInt													GetRecorderCount() const;
	IAudioRecorder*											GetRecorder( UInt index ) const;
	IAudioRecorder*											GetRecorder() const;

	// Other methods.
	void													SetActiveEnvironment( IAudioEnvironment* environment );
	void													Initialize( IAudioSystemFactory* factory, const sound::SoundFormat& format, win::IWindowSystemEx* windowSystem );
	void													Finalize();

private:
	IAudioSystemFactory*									_factory;
	P(IAudioSystem)											_audioSystem;
	IAudioEnvironment*										_activeEnvironment;
	lang::Vector<P(AudioPlayer)>							_players;
	lang::Vector<P(AudioRecorder)>							_recorders;
};


#include "AudioSystemEx.inl"


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_AUDIOSYSTEMEX_
