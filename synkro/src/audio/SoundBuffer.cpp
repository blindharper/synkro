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
// Purpose: Logical sound buffer.
//==============================================================================
#include "config.h"
#include "SoundBuffer.h"
#include "AudioPlayer.h"


//------------------------------------------------------------------------------

using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


SoundBuffer::SoundBuffer( BaseAudioPlayer* player, ISoundBuffer* buffer ) :
	AudioBufferImpl<ISoundBuffer, AudioChunk>( SoundFormat::Unknown, buffer->GetChunkCount() ),
	_player( player ),
	_buffer( buffer )
{
	_size = _buffer->GetSize();
	for ( UInt i = 0; i < _buffer->GetChunkCount(); ++i )
	{
		_chunks.Add( new AudioChunk(_buffer->GetChunk(i), false) );
	}
}

SoundBuffer::~SoundBuffer()
{
	_player->RemoveBuffer( this );
}


} // audio


} // synkro
