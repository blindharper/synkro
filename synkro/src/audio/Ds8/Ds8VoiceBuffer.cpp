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
// Purpose: DirectSound 8 voice buffer.
//==============================================================================
#include "config.h"
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


Ds8VoiceBuffer::Ds8VoiceBuffer( IDirectSoundCapture8* device, const SoundFormat& format, Double length, UInt chunkCount ) :
	VoiceBufferImpl<IVoiceBuffer, Ds8AudioChunk>( format, chunkCount, false, false ),
	_effectEcho( nullptr ),
	_effectNoise( nullptr ),
	_ptr1( nullptr ),
	_bytes1( 0 ),
	_ptr2( nullptr ),
	_bytes2( 0 )
{
	HRESULT hr = DS_OK;

	// Create buffer.
	WAVEFORMATEX fmt;
	fmt.wFormatTag		= WAVE_FORMAT_PCM;
	fmt.nChannels		= format.ChannelCount;
	fmt.nSamplesPerSec	= format.SamplesPerSecond;
	fmt.wBitsPerSample	= format.BitsPerSample;
	fmt.nBlockAlign		= fmt.nChannels * fmt.wBitsPerSample >> 3;
	fmt.nAvgBytesPerSec = fmt.nSamplesPerSec * fmt.nBlockAlign;
	fmt.cbSize			= 0;

	const UInt chunkSize = length * CastDouble(fmt.nAvgBytesPerSec) / CastDouble(chunkCount);
	_size = chunkSize * chunkCount;

	DSCEFFECTDESC effects[] =
	{
		{ sizeof(DSCEFFECTDESC), 0, GUID_DSCFX_CLASS_AEC, GUID_DSCFX_MS_AEC, 0, 0 },
		{ sizeof(DSCEFFECTDESC), 0, GUID_DSCFX_CLASS_NS, GUID_DSCFX_MS_NS, 0, 0 },
	};
	DSCBUFFERDESC desc;
	desc.dwSize			= sizeof(DSBUFFERDESC);
	desc.dwFlags		= DSCBCAPS_WAVEMAPPED | DSCBCAPS_CTRLFX;
	desc.dwBufferBytes	= _size;
	desc.dwReserved		= 0;
	desc.dwFXCount		= sizeof(effects)/sizeof(effects[0]);
	desc.lpDSCFXDesc	= effects;
	desc.lpwfxFormat	= &fmt;
	IDirectSoundCaptureBuffer* buffer;
	if ( FAILED(hr = device->CreateCaptureBuffer(&desc, &buffer, nullptr)) )
		throw AudioException( String::Format(Str::VoiceBufferCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSoundCaptureBuffer::QueryInterface()"), Ds8::ToString(hr) );

	// Obtain IDirectSoundCaptureBuffer8 interface.
	if ( FAILED(hr = buffer->QueryInterface( IID_IDirectSoundCaptureBuffer8, (void**)&_buffer )) )
		throw AudioException( String::Format(Str::VoiceBufferCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSoundCaptureBuffer::QueryInterface()"), Ds8::ToString(hr) );
	buffer->Release();

	// Retrieve effects.
	_buffer->GetObjectInPath( GUID_DSCFX_CLASS_AEC, 0, IID_IDirectSoundCaptureFXAec8, (void**)&_effectEcho );
	_buffer->GetObjectInPath( GUID_DSCFX_CLASS_NS, 0, IID_IDirectSoundCaptureFXNoiseSuppress8, (void**)&_effectNoise );
	SuppressEcho( false );
	SuppressNoise( false );

	// Create chunks.
	for ( UInt i = 0; i < chunkCount; ++i )
	{
		_chunks.Add( new Ds8AudioChunk(this, i*chunkSize, chunkSize) );
	}
}

Ds8VoiceBuffer::~Ds8VoiceBuffer()
{
	SafeRelease( _effectEcho );
	SafeRelease( _effectNoise );
	SafeRelease( _buffer );
}

void Ds8VoiceBuffer::Update()
{
	// Do nothing.
}

void Ds8VoiceBuffer::Process( Bool start, Bool loop )
{
	HRESULT hr = S_OK;

	if ( start )
	{
		const DWORD flags = loop ? DSBPLAY_LOOPING : 0;
		hr = _buffer->Start( flags );
	}
	else
	{
		hr = _buffer->Stop();
	}
}

void Ds8VoiceBuffer::SuppressEcho( Bool suppress )
{
	if ( _effectEcho != nullptr )
	{
		DSCFXAec params;
		params.fEnable = suppress;
		params.fNoiseFill = TRUE;
		params.dwMode = DSCFX_AEC_MODE_FULL_DUPLEX;
		_effectEcho->SetAllParameters( &params );
		_suppressEcho = suppress;
	}
}

void Ds8VoiceBuffer::SuppressNoise( Bool suppress )
{
	if ( _effectNoise != nullptr )
	{
		DSCFXNoiseSuppress params;
		params.fEnable = suppress;
		_effectNoise->SetAllParameters( &params );
		_suppressNoise = suppress;
	}
}

Bool Ds8VoiceBuffer::Map( UInt offset, UInt size, Byte** data )
{
	assert( _ptr1 == nullptr );

	HRESULT hr = DS_OK;
	if ( SUCCEEDED(_buffer->Lock(offset, size, &_ptr1, &_bytes1, &_ptr2, &_bytes2, 0)) )
	{
		assert( _ptr2 == nullptr );
		assert( _bytes1 == size );

		*data = (Byte*)_ptr1;
		return true;
	}

	return false;
}

Bool Ds8VoiceBuffer::Unmap( Byte* data, UInt size )
{
	assert( _ptr1 != nullptr );
	assert( _ptr1 == data );
	assert( _bytes1 == size );

	const Bool ok = SUCCEEDED( _buffer->Unlock(_ptr1, _bytes1, _ptr2, _bytes2) );
	_ptr1 = _ptr2 = nullptr;
	return ok;
}

void Ds8VoiceBuffer::GetPosition( UInt* read, UInt* write ) const
{
	UInt readPosition; UInt writePosition;
	HRESULT hr = _buffer->GetCurrentPosition( (DWORD*)&writePosition, (DWORD*)&readPosition );

	*read = readPosition;
	*write = writePosition;
}


} // audio


} // synkro
