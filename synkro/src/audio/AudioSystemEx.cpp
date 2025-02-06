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
#include "config.h"
#include "AudioSystemEx.h"
#include "AudioEnvironment.h"
#include <audio/ISoundEmitter.h>
#include <audio/ISoundListener.h>
#include <audio/IAudioSystemFactory.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::sound;
using namespace synkro::win;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AudioSystemEx::AudioSystemEx( const SoundFormat& format, ILog* log ) :
	_factory( nullptr ),
	_activeEnvironment( nullptr ),
	_players( A(P(AudioPlayer)) ),
	_recorders( A(P(AudioRecorder)) ),
	Logger( log, LogFacility::AudioSystem )
{
}

Bool AudioSystemEx::Update( Double delta )
{
	SynkroProfile( "AudioSystemEx.Update" );

	// Update players.
	for ( UInt i = 0; i < _players.Size(); ++i )
	{
		_players[i]->Update();
	}

	// Update recorders.
	for ( UInt i = 0; i < _recorders.Size(); ++i )
	{
		_recorders[i]->Update();
	}

	// Update active environment.
	if ( _activeEnvironment != nullptr )
	{
		for ( UInt i = 0; i < _activeEnvironment->GetEmitterCount(); ++i )
		{
			_activeEnvironment->GetEmitter(i)->Bind();
		}
		_activeEnvironment->GetListener()->Bind();
	}

	return true;
}

IAudioPlayer* AudioSystemEx::CreatePlayer( UInt index )
{
	for ( UInt i = 0; i < _players.Size(); ++i )
	{
		if ( _players[i]->GetIndex() == i )
			return _players[i];
	}

	AudioPlayer* player = new AudioPlayer( _audioSystem->CreatePlayer(index), index );
	_players.Add( player );
	return player;
}

IAudioRecorder* AudioSystemEx::CreateRecorder( UInt index )
{
	for ( UInt i = 0; i < _recorders.Size(); ++i )
	{
		if ( _recorders[i]->GetIndex() == i )
			return _recorders[i];
	}

	AudioRecorder* recorder = new AudioRecorder( _audioSystem->CreateRecorder(index), index );
	_recorders.Add( recorder );
	return recorder;
}

IAudioEnvironment* AudioSystemEx::CreateEnvironment()
{
	return new AudioEnvironment( this );
}

IAudioPlayer* AudioSystemEx::GetPlayer( const SoundFormat& soundFormat ) const
{
	UInt idxFullMatch = none;
	UInt idxSamplesMatch = none;
	UInt idxChannelSamplesMatch = none;

	for ( UInt i = 0; i < _players.Size(); ++i )
	{
		SoundFormat playerFormat;
		IAudioPlayer* player = _players[i];
		player->GetFormat( playerFormat );
		if ( playerFormat == soundFormat )
		{
			idxFullMatch = i;
			break;
		}

		if ( playerFormat.SamplesPerSecond == soundFormat.SamplesPerSecond )
		{
			if ( playerFormat.ChannelCount == soundFormat.ChannelCount )
			{
				if ( idxChannelSamplesMatch == none )
					idxChannelSamplesMatch = i;			
			}
			else
			{
				if ( idxSamplesMatch == none )
					idxSamplesMatch = i;
			}
		}
	}

	UInt idx = 0;
	if ( idxFullMatch != none )
	{
		idx = idxFullMatch;
	}
	else if ( idxChannelSamplesMatch != none )
	{
		idx = idxChannelSamplesMatch;
	}
	else if ( idxSamplesMatch != none )
	{
		idx = idxSamplesMatch;
	}
	return _players[idx];
}

void AudioSystemEx::SetActiveEnvironment( IAudioEnvironment* environment )
{
	// Deactivate previously active environment.
	if ( _activeEnvironment != nullptr )
	{
		for ( UInt i = 0; i < _activeEnvironment->GetEmitterCount(); ++i )
		{
			_activeEnvironment->GetEmitter(i)->Process( false, false );
		}
	}
	_activeEnvironment = environment;
	
	// Activate new environment.
	if ( _activeEnvironment != nullptr )
	{
		for ( UInt i = 0; i < _activeEnvironment->GetEmitterCount(); ++i )
		{
			_activeEnvironment->GetEmitter(i)->Process( true, true );
		}
	}
}

void AudioSystemEx::Initialize( IAudioSystemFactory* factory, const SoundFormat& format, IWindowSystemEx* windowSystem )
{
	if ( factory != _factory )
	{
		_factory = factory;
		_audioSystem = nullptr;
		_audioSystem = factory->Create( format, windowSystem, _log );
	}
}

void AudioSystemEx::Finalize()
{
	_players.Clear();
	_recorders.Clear();
	_audioSystem = nullptr;
	_factory = nullptr;
}


} // audio


} // synkro
