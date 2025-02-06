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
// Purpose: Logical voice buffer.
//==============================================================================
#include "config.h"
#include "VoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


VoiceBuffer::VoiceBuffer( BaseAudioRecorder* recorder, IVoiceBuffer* buffer ) :
	AudioBufferImpl<IVoiceBuffer, AudioChunk>( SoundFormat::Unknown, buffer->GetChunkCount() ),
	_recorder( recorder ),
	_buffer( buffer )
{
	_size = _buffer->GetSize();
	for ( UInt i = 0; i < _buffer->GetChunkCount(); ++i )
	{
		_chunks.Add( new AudioChunk(_buffer->GetChunk(i), true) );
	}
}

VoiceBuffer::~VoiceBuffer()
{
	_recorder->RemoveBuffer( this );
}


} // audio


} // synkro
