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
// Purpose: Logical player.
//==============================================================================
#include "config.h"
#include "AudioPlayer.h"
#include "SoundBuffer.h"
#include "SoundEmitter.h"
#include "SoundListener.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AudioPlayer::AudioPlayer( IAudioPlayer* player, UInt index ) :
	_buffers( A(ISoundBuffer*) ),
	_player( player ),
	_listener( new SoundListener(player->GetListener()) ),
	_index( index )
{
}

ISoundBuffer* AudioPlayer::CreateSoundBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	ISoundBuffer* buffer = new SoundBuffer( this, _player->CreateSoundBuffer(format, length, chunkCount) );
	if ( chunkCount > 1 )
	{
		_buffers.Add( buffer );
	}
	return buffer;
}

ISoundEmitter* AudioPlayer::CreateSoundEmitter( const SoundFormat& format, Double length )
{
	return new SoundEmitter( _player->CreateSoundEmitter(format, length) );
}

void AudioPlayer::RemoveBuffer( ISoundBuffer* buffer )
{
	_buffers.Remove( buffer );
}

void AudioPlayer::Update()
{
	for ( UInt i = 0; i < _buffers.Size(); ++i )
	{
		_buffers[i]->Update();
	}
}


} // audio


} // synkro
