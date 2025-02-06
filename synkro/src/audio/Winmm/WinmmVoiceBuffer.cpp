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
// Purpose: WinMM voice buffer.
//==============================================================================
#include "config.h"
#include "WinmmVoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


WinmmVoiceBuffer::WinmmVoiceBuffer( HWAVEIN device, const SoundFormat& format, Double length, UInt chunkCount ) :
	VoiceBufferImpl<IVoiceBuffer, WinmmAudioChunk>( format, chunkCount, false, false ),
	_device( device ),
	_chunkIndex( 0 )
{
	UInt chunkSize = (UInt)(length * (Double)_format.SamplesPerSecond * (Double)_format.ChannelCount * (Double)(_format.BitsPerSample >> 3) / (Double)chunkCount);
	_size = chunkSize * chunkCount;
	for ( UInt i = 0; i < chunkCount; ++i )
	{
		_chunks.Add( new WinmmAudioChunk(_device, i*chunkSize, chunkSize) );
	}
}

void WinmmVoiceBuffer::Update()
{
	for ( UInt i = 0; i < _chunks.Size(); ++i )
	{
		if ( _chunks[_chunkIndex]->_chunk.dwFlags & WHDR_DONE )
		{
			_chunks[_chunkIndex]->_chunk.dwFlags &= ~WHDR_DONE;
			Winmm::WaveInPrepareHeader( _device, &_chunks[i]->_chunk, sizeof(WAVEHDR) );
			Winmm::WaveInAddBuffer( _device, &_chunks[i]->_chunk, sizeof(WAVEHDR) );
		}
		if ( ++_chunkIndex == _chunks.Size()-1 )
		{
			_chunkIndex = 0;
		}
	}
}

void WinmmVoiceBuffer::Process( Bool start, Bool loop )
{
	if ( start )
	{
		for ( UInt i = 0; i < _chunks.Size(); ++i )
		{
			Winmm::WaveInPrepareHeader( _device, &_chunks[i]->_chunk, sizeof(WAVEHDR) );
			Winmm::WaveInAddBuffer( _device, &_chunks[i]->_chunk, sizeof(WAVEHDR) );
		}
		Winmm::WaveInStart( _device );
	}
	else
	{
		Winmm::WaveInStop( _device );
	}
}


} // audio


} // synkro
