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
// Purpose: DirectSound 8 sound buffer.
//==============================================================================
#include "config.h"
#include "Ds8SoundBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


Ds8SoundBuffer::Ds8SoundBuffer( IDirectSound8* device, const SoundFormat& format, Double length, UInt chunkCount ) :
	SoundBufferImpl<ISoundBuffer, Ds8AudioChunk>( format, chunkCount ),
	_buffer( nullptr ),
	_ptr1( nullptr ),
	_bytes1( 0 ),
	_ptr2( nullptr ),
	_bytes2( 0 )
{
	HRESULT hr = DS_OK;

	// Setup audio format.
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

	// Create buffer.
	DSBUFFERDESC desc;
	desc.dwSize			= sizeof(DSBUFFERDESC);
	desc.dwBufferBytes	= _size;
	desc.lpwfxFormat	= &fmt;
	desc.guid3DAlgorithm = DS3DALG_DEFAULT;
	desc.dwFlags		= 0;
	desc.dwReserved		= 0;
	IDirectSoundBuffer* buffer;
	if ( FAILED(hr = device->CreateSoundBuffer(&desc, &buffer, nullptr)) )
		throw AudioException( String::Format(Str::SoundBufferCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSound8::CreateSoundBuffer()"), Ds8::ToString(hr) );

	// Obtain IDirectSoundBuffer8 interface.
	if ( FAILED(hr = buffer->QueryInterface( IID_IDirectSoundBuffer8, (void**)&_buffer )) )
		throw AudioException( String::Format(Str::SoundBufferCreateFail, format.ToString()), String::Format(Str::CallFail, L"IDirectSoundBuffer::QueryInterface()"), Ds8::ToString(hr) );
	buffer->Release();

	// Create chunks.
	for ( UInt i = 0; i < chunkCount; ++i )
	{
		_chunks.Add( new Ds8AudioChunk(this, i*chunkSize, chunkSize) );
	}
}

Ds8SoundBuffer::~Ds8SoundBuffer()
{
	SafeRelease( _buffer );
}

void Ds8SoundBuffer::Process( Bool start, Bool loop )
{
	HRESULT hr = S_OK;

	if ( start )
	{
		const DWORD flags = loop ? DSBPLAY_LOOPING : 0;
		hr = _buffer->Play( 0, 0, flags );
	}
	else
	{
		hr = _buffer->Stop();
		_buffer->SetCurrentPosition( 0 );
	}
}

Bool Ds8SoundBuffer::Map( UInt offset, UInt size, Byte** data )
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

Bool Ds8SoundBuffer::Unmap( Byte* data, UInt size )
{
	assert( _ptr1 != nullptr );
	assert( _ptr1 == data );
	assert( _bytes1 == size );

	const Bool ok = SUCCEEDED( _buffer->Unlock(_ptr1, _bytes1, _ptr2, _bytes2) );
	_ptr1 = _ptr2 = nullptr;
	return ok;
}

void Ds8SoundBuffer::GetPosition( UInt* read, UInt* write ) const
{
	UInt readPosition; UInt writePosition;
	HRESULT hr = _buffer->GetCurrentPosition( (DWORD*)&readPosition, (DWORD*)&writePosition );
	*read = readPosition;
	*write = writePosition;
}


} // audio


} // synkro
