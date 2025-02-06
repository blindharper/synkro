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
// Purpose: DirectSound 8 recorder.
//==============================================================================
#include "config.h"
#include "Ds8AudioRecorder.h"
#include "Ds8VoiceBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


Ds8AudioRecorder::Ds8AudioRecorder( LPGUID guid, const SoundFormat& format, const RecorderDesc& desc ) :
	AudioRecorderImpl<IAudioRecorder>( format, desc ),
	_device( nullptr )
{
	HRESULT hr = DS_OK;

	// Create device.
	if ( FAILED(hr = Ds8::DirectSoundCaptureCreate8(guid, &_device, nullptr)) )
		throw AudioException( String::Format(Str::RecorderCreateFail, desc.Name), String::Format(Str::CallFail, L"DirectSoundCaptureCreate8()"), Ds8::ToString(hr) );
}

Ds8AudioRecorder::~Ds8AudioRecorder()
{
	SafeRelease( _device );
}

IVoiceBuffer* Ds8AudioRecorder::CreateVoiceBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new Ds8VoiceBuffer( _device, format, length, chunkCount );
}


} // audio


} // synkro
