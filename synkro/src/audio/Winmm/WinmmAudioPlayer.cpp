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
// Purpose: WinMM audio player.
//==============================================================================
#include "config.h"
#include "WinmmAudioPlayer.h"
#include "WinmmSoundListener.h"
#include "WinmmSoundBuffer.h"
#include <audio/AudioException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


WinmmAudioPlayer::WinmmAudioPlayer( UINT_PTR id, const SoundFormat& format, const PlayerDesc& desc ) :
	AudioPlayerImpl<IAudioPlayer>( format, desc ),
	_device( nullptr )
{
	MMRESULT res = MMSYSERR_NOERROR;

	// Create device.
	WAVEFORMATEX fmt;
	fmt.wFormatTag		= WAVE_FORMAT_PCM;
	fmt.nChannels		= _format.ChannelCount;
	fmt.nSamplesPerSec	= _format.SamplesPerSecond;
	fmt.wBitsPerSample	= _format.BitsPerSample;
	fmt.nBlockAlign		= fmt.nChannels * fmt.wBitsPerSample >> 3;
	fmt.nAvgBytesPerSec = fmt.nSamplesPerSec * fmt.nBlockAlign;
	fmt.cbSize			= 0;
	if ( (res = Winmm::WaveOutOpen(&_device, id, &fmt, null, null, CALLBACK_NULL)) != MMSYSERR_NOERROR )
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"waveOutOpen()"), Winmm::ToString(res) );

	// Create listener.
	_listener = new WinmmSoundListener();
}

WinmmAudioPlayer::~WinmmAudioPlayer()
{
	if ( _device != nullptr )
	{
		Winmm::WaveOutClose( _device );
		_device = nullptr;
	}
}

ISoundBuffer* WinmmAudioPlayer::CreateSoundBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new WinmmSoundBuffer( _device, format, length, chunkCount );
}

ISoundEmitter* WinmmAudioPlayer::CreateSoundEmitter( const SoundFormat& format, Double length )
{
	throw lang::NotSupportedException( L"WinMM does not support sound emitters." );
}


} // audio


} // synkro
