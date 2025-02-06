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
// Purpose: WinMM sound buffer.
//==============================================================================
#include "config.h"
#include "WinmmSoundBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


WinmmSoundBuffer::WinmmSoundBuffer( HWAVEOUT device, const SoundFormat& format, Double length, UInt chunkCount ) :
	SoundBufferImpl<ISoundBuffer, WinmmAudioChunk>( format, chunkCount ),
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

void WinmmSoundBuffer::Update()
{
	for ( UInt i = 0; i < _chunks.Size(); ++i )
	{
		if ( _chunks[_chunkIndex]->_chunk.dwFlags & WHDR_DONE )
		{
			_chunks[_chunkIndex]->_chunk.dwFlags &= ~WHDR_DONE;
		}
		if ( ++_chunkIndex == _chunks.Size()-1 )
		{
			_chunkIndex = 0;
		}
	}
}

void WinmmSoundBuffer::Process( Bool start, Bool loop )
{
	start ? Winmm::WaveOutRestart( _device ) : Winmm::WaveOutPause( _device );
}

void WinmmSoundBuffer::SetPan( Int pan )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, WinmmAudioChunk>::SetPan( pan );
}

void WinmmSoundBuffer::SetAttenuation( Int attenuation )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, WinmmAudioChunk>::SetAttenuation( attenuation );

	const WORD dwVol = _attenuation;
	const DWORD dwVolume = (dwVol << 16) | dwVol;
	Winmm::WaveOutSetVolume( _device, dwVolume );
}

void WinmmSoundBuffer::SetFrequency( UInt frequency )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, WinmmAudioChunk>::SetFrequency( frequency );

	const UShort whole = _frequency / _format.SamplesPerSecond;
	const Double frac = (CastDouble(_frequency) / CastDouble(_format.SamplesPerSecond)) - CastDouble(whole);

	const DWORD dwRate = (whole << 16) | (UShort)(CastDouble(0xFFFF) * frac);
	Winmm::WaveOutSetPlaybackRate( _device, dwRate );
}


} // audio


} // synkro
