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
// Purpose: Logical recorder.
//==============================================================================
#include "config.h"
#include "AudioRecorder.h"
#include "VoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AudioRecorder::AudioRecorder( IAudioRecorder* recorder, UInt index ) :
	_buffers( A(IVoiceBuffer*) ),
	_recorder( recorder ),
	_index( index )
{
}

IVoiceBuffer* AudioRecorder::CreateVoiceBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	IVoiceBuffer* buffer = new VoiceBuffer( this, _recorder->CreateVoiceBuffer(format, length, chunkCount) );
	_buffers.Add( buffer );
	return buffer;
}

void AudioRecorder::RemoveBuffer( IVoiceBuffer* buffer )
{
	_buffers.Remove( buffer );
}

void AudioRecorder::Update()
{
	for ( UInt i = 0; i < _buffers.Size(); ++i )
	{
		_buffers[i]->Update();
	}
}


} // audio


} // synkro
