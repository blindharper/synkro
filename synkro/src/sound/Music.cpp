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
// Purpose: Music track implementation.
//==============================================================================
#include "config.h"
#include "Music.h"
#include "MusicAnimationController.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


Music::Music( BaseSoundManager* soundManager, IContext* context, ISoundCodec* codec, IStream* stream ) :
	_data( A(Byte) ),
	_soundManager( soundManager ),
	_context( context ),
	_soundContext( nullptr ),
	_player( nullptr ),
	_stream( stream ),
	_codec( codec ),
	_mode( PlaybackMode::Unknown ),
	_loopCount( 1 ),
	_chunkIndex( 0 ),
	_playing( false ),
	_length( 0.0 )
{
	// Create sound buffer.
	SoundFormat soundFormat;
	_soundContext = new SoundCodecContext( stream, false );
	_length = _codec->Load( _soundContext, soundFormat );
	_player = _context->GetAudioSystem()->GetPlayer(soundFormat);
	_buffer = _player->CreateSoundBuffer( soundFormat, 1.0, 10 );

	// Fill buffer with data.
	for ( UInt i = 0; i < _buffer->GetChunkCount(); ++i )
	{
		IAudioChunk* chunk = _buffer->GetChunk( i );
		_data.SetSize( chunk->GetSize() );
		Byte* d = _data.Begin();
		const UInt size = _codec->Decode( _soundContext, &d, _data.Size() );
		chunk->Write( d, size );
	}
	_soundManager->AddMusic( this );
}

Music::~Music()
{
	_soundManager->RemoveMusic( this );
	SafeDelete( _soundContext );
}

IMusicAnimationController* Music::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new MusicAnimationController( this, _context->GetAnimationSystem(), animation, listener) : _ctrlAnimation;
}

void Music::Play( Bool play )
{
	_buffer->Process( play, (_mode == PlaybackMode::Loop) );
	_playing = play;
	if ( !play )
	{
		_chunkIndex = 0;
	}
}

void Music::Update()
{
	if ( !IsPlaying() )
		return;

	for ( UInt i = 0; i < _buffer->GetChunkCount(); ++i )
	{
		IAudioChunk* chunk = _buffer->GetChunk( _chunkIndex++ );
		_chunkIndex %= _buffer->GetChunkCount();
		if ( chunk->IsProcessing() )
			break;

		_data.SetSize( chunk->GetSize() );
		Byte* d = _data.Begin();
		const UInt size = _codec->Decode( _soundContext, &d, _data.Size() );
		chunk->Write( d, size );
	}
}


} // sound


} // synkro
