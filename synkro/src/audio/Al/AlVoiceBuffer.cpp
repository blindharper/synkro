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
// Purpose: OpenAL voice buffer.
//==============================================================================
#include "config.h"
#include "AlVoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlVoiceBuffer::AlVoiceBuffer( ALCdevice* device, const SoundFormat& format, Double length, UInt chunkCount ) :
	VoiceBufferImpl<IVoiceBuffer, AlAudioChunk>( format, chunkCount, false, false ),
	_data( A(Byte) ),
	_device( device ),
	_sampleCapacity( 0 ),
	_chunkIndex( 0 )
{
	UInt chunkSize = (UInt)(length * (Double)_format.SamplesPerSecond * (Double)_format.ChannelCount * (Double)(_format.BitsPerSample >> 3) / (Double)chunkCount);
	_sampleCapacity = chunkSize / (format.ChannelCount * format.BitsPerSample >> 3);
	_data.SetSize( chunkSize );
	_size = chunkSize * chunkCount;
	for ( UInt i = 0; i < chunkCount; ++i )
	{
		_chunks.Add( new AlAudioChunk(chunkSize) );
	}
}

void AlVoiceBuffer::Update()
{
	ALCint sampleCount = 0;
	Alc::GetIntegerv( _device, ALC_CAPTURE_SAMPLES, 1, &sampleCount );
	for ( UInt i = 0; i < _chunks.Size(); ++i )
	{
		if ( sampleCount < _sampleCapacity )
			break;

		Alc::CaptureSamples( _device, _data.Begin(), _sampleCapacity );
		sampleCount -= _sampleCapacity;

		AlAudioChunk* chunk = _chunks[_chunkIndex];
		chunk->_data = _data.Begin() + i*chunk->_size;
		chunk->_processing = false;

		if ( ++_chunkIndex == _chunks.Size()-1 )
		{
			_chunkIndex = 0;
		}
	}
}

void AlVoiceBuffer::Process( Bool start, Bool loop )
{
	start ? Alc::CaptureStart( _device ) : Alc::CaptureStop( _device );
}


} // audio


} // synkro
