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
// Purpose: Voice implementation.
//==============================================================================
#include "config.h"
#include "Voice.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::audio;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


Voice::Voice( BaseSoundManager* soundManager, IAudioRecorder* recorder, ISoundCodec* codec, IStream* stream, const SoundFormat& format ) :
	_data( A(Byte) ),
	_soundManager( soundManager ),
	_soundContext( nullptr ),
	_recorder( recorder ),
	_stream( stream ),
	_codec( codec ),
	_length( 0.0 ),
	_recording( false ),
	_chunkIndex( 0 ),
	_bytesPerSecond( 0 )
{
	_soundContext = new SoundCodecContext( stream, true );
	_codec->Save( _soundContext, format );
	_buffer = _recorder->CreateVoiceBuffer( format, 1.0, 10 );
	_bytesPerSecond = format.ChannelCount * format.SamplesPerSecond * format.BytesPerSample();
	_soundManager->AddVoice( this );
}

Voice::~Voice()
{
	_soundManager->RemoveVoice( this );
	SafeDelete( _soundContext );
}

void Voice::Record( Bool record )
{
	_buffer->Process( record, false );
	_recording = record;
}

void Voice::Update()
{
	if ( !IsRecording() )
		return;

	for ( UInt i = 0; i < _buffer->GetChunkCount(); ++i )
	{
		IAudioChunk* chunk = _buffer->GetChunk( _chunkIndex++ );
		_chunkIndex %= _buffer->GetChunkCount();
		if ( chunk->IsProcessing() )
			break;

		// Capture sound.
		_data.SetSize( chunk->GetSize() );
		chunk->Read( _data.Begin(), _data.Size() );
		_codec->Encode( _soundContext, _data.Begin(), _data.Size() );
		
		// Update length.
		const Double delta = CastDouble(_data.Size()) / CastDouble(_bytesPerSecond);
		_length += delta;
	}
}


} // sound


} // synkro
