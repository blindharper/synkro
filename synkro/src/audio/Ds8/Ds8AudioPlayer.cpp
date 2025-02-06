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
// Purpose: DirectSound 8 player.
//==============================================================================
#include "config.h"
#include "Ds8AudioPlayer.h"
#include "Ds8SoundBuffer.h"
#include "Ds8SoundEmitter.h"
#include "Ds8SoundListener.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


Ds8AudioPlayer::Ds8AudioPlayer( LPGUID guid, const SoundFormat& format, HWND window, const PlayerDesc& desc ) :
	AudioPlayerImpl<IAudioPlayer>( format, desc ),
	_device( nullptr ),
	_primaryBuffer( nullptr )
{
	HRESULT hr = DS_OK;

	// Create device.
	if ( FAILED(hr = Ds8::DirectSoundCreate8(guid, &_device, nullptr)) )
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"DirectSoundCreate8()"), Ds8::ToString(hr) );

	if ( FAILED(hr = _device->SetCooperativeLevel(window, DSSCL_PRIORITY)) )
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"IDirectSound8::SetCooperativeLevel()"), Ds8::ToString(hr) );

	// Create primary buffer.
	DSBUFFERDESC bd;
	Zero( &bd );
	bd.dwSize	= sizeof(DSBUFFERDESC);
	bd.dwFlags	= DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRL3D | DSBCAPS_CTRLVOLUME;
	if ( FAILED(hr = _device->CreateSoundBuffer(&bd, &_primaryBuffer, nullptr)) )
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"IDirectSound8::CreateSoundBuffer()"), Ds8::ToString(hr) );

	// Set primary buffer format.
	WAVEFORMATEX fmt = {};
	fmt.wFormatTag      = WAVE_FORMAT_PCM;
	fmt.nChannels       = (WORD)_format.ChannelCount;
	fmt.nSamplesPerSec  = _format.SamplesPerSecond; 
	fmt.wBitsPerSample  = (WORD)_format.BitsPerSample; 
	fmt.nBlockAlign     = (WORD)((fmt.wBitsPerSample >> 3) * fmt.nChannels);
	fmt.nAvgBytesPerSec = fmt.nSamplesPerSec * fmt.nBlockAlign;
	fmt.cbSize			= 0;
	if ( FAILED(hr = _primaryBuffer->SetFormat(&fmt)) )
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"IDirectSoundBuffer::SetFormat()"), Ds8::ToString(hr) );

	// Get the actual primary buffer format as it may differ from requesed one depending on the current hardware.
	hr = _primaryBuffer->GetFormat( &fmt, sizeof(fmt), nullptr );
	_format.SamplesPerSecond = fmt.nSamplesPerSec;
	_format.BitsPerSample = CastUInt( fmt.wBitsPerSample );
	_format.ChannelCount = CastUInt( fmt.nChannels );

	// Create listener.
	_listener = new Ds8SoundListener( _primaryBuffer );
}

Ds8AudioPlayer::~Ds8AudioPlayer()
{
	SafeRelease( _primaryBuffer );
	SafeRelease( _device );
}

ISoundBuffer* Ds8AudioPlayer::CreateSoundBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new Ds8SoundBuffer( _device, format, length, chunkCount );
}

ISoundEmitter* Ds8AudioPlayer::CreateSoundEmitter( const SoundFormat& format, Double length )
{
	assert( length > 0.0 );

	return new Ds8SoundEmitter( _device, format, length );
}


} // audio


} // synkro
