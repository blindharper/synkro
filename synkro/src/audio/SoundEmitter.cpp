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
// Purpose: Logical sound emitter.
//==============================================================================
#include "config.h"
#include "SoundEmitter.h"


//------------------------------------------------------------------------------

using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


SoundEmitter::SoundEmitter( ISoundEmitter* emitter ) :
	AudioBufferImpl<ISoundEmitter, AudioChunk>( SoundFormat::Unknown, emitter->GetChunkCount() ),
	_emitter( emitter )
{
	_size = _emitter->GetSize();
	for ( UInt i = 0; i < _emitter->GetChunkCount(); ++i )
	{
		_chunks.Add( new AudioChunk(_emitter->GetChunk(i), false) );
	}
}


} // audio


} // synkro
