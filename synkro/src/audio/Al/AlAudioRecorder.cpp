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
// Purpose: OpenAL recorder.
//==============================================================================
#include "config.h"
#include "AlAudioRecorder.h"
#include "AlVoiceBuffer.h"
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


AlAudioRecorder::AlAudioRecorder( const SoundFormat& format, const RecorderDesc& desc ) :
	AudioRecorderImpl<IAudioRecorder>( format, desc ),
	_device( 0 )
{
	ALCenum err = ALC_NO_ERROR;

	const UInt SIZE = 200;
	ALchar name[SIZE];
	desc.Name.GetBytes( name, SIZE );
	if ( (_device = Alc::CaptureOpenDevice(name, format.SamplesPerSecond, Al::Convert(format), 44100)) == nullptr )
	{
		err = Alc::GetError( nullptr );
		throw AudioException( String::Format(Str::RecorderCreateFail, desc.Name), String::Format(Str::CallFail, L"alcCaptureOpenDevice()"), Alc::ToString(err) );
	}
}

AlAudioRecorder::~AlAudioRecorder()
{
	if ( _device != 0 )
	{
		Alc::CaptureCloseDevice( _device );
		_device = 0;
	}
}

IVoiceBuffer* AlAudioRecorder::CreateVoiceBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new AlVoiceBuffer( _device, format, length, chunkCount );
}


} // audio


} // synkro
