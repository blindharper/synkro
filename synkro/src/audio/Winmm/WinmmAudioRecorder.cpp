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
// Purpose: WinMM audio recorder.
//==============================================================================
#include "config.h"
#include "WinmmAudioRecorder.h"
#include "WinmmVoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


WinmmAudioRecorder::WinmmAudioRecorder( UINT_PTR id, const SoundFormat& format, const RecorderDesc& desc ) :
	AudioRecorderImpl<IAudioRecorder>( format, desc ),
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
	if ( (res = Winmm::WaveInOpen(&_device, id, &fmt, null, null, CALLBACK_NULL)) != MMSYSERR_NOERROR )
		throw AudioException( String::Format(Str::RecorderCreateFail, desc.Name), String::Format(Str::CallFail, L"waveInOpen()"), Winmm::ToString(res) );
}

WinmmAudioRecorder::~WinmmAudioRecorder()
{
	if ( _device != nullptr )
	{
		Winmm::WaveInClose( _device );
		_device = nullptr;
	}
}

IVoiceBuffer* WinmmAudioRecorder::CreateVoiceBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new WinmmVoiceBuffer( _device, format, length, chunkCount );
}


} // audio


} // synkro
